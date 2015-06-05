//
//  weatherController.cpp
//  WeatherDjinni
//
//  Created by Robert Thompson on 6/4/15.
//  Copyright (c) 2015 WillowTree Apps. All rights reserved.
//

#include "weatherControllerImpl.h"
#include <memory.h>
#include <stdlib.h>
#include "json11.hpp"
#include <string>
#include <iostream>
#include <sstream>

using namespace json11;

std::experimental::optional<double> getDoubleOrNull(Json jsonValue) {
    if (jsonValue.type() != Json::NUMBER)
    {
        return std::experimental::nullopt;
    }
    else
    {
        return jsonValue.number_value();
    }
}

std::experimental::optional<int64_t> getIntOrNull(Json jsonValue) {
    if (jsonValue.type() != Json::NUMBER)
    {
        return std::experimental::nullopt;
    }
    else
    {
        return jsonValue.number_value();
    }
}

std::experimental::optional<std::string> getStringOrNull(Json jsonValue) {
    if (jsonValue.type() != Json::STRING)
    {
        return std::experimental::nullopt;
    }
    else
    {
        return jsonValue.string_value();
    }
}

DataPoint createDataPointWithJson(Json currentlyJson) {
    int64_t time = currentlyJson["time"].number_value();
    auto summary = currentlyJson["summary"].string_value();
    auto icon = currentlyJson["icon"].string_value();
    auto sunriseTime = getIntOrNull(currentlyJson["sunriseTime"]);
    auto sunsetTime = getIntOrNull(currentlyJson["sunsetTime"]);
    auto moonPhase = getDoubleOrNull(currentlyJson["moonPhase"]);
    auto nearestStormDistance = getDoubleOrNull(currentlyJson["nearestStormDistance"]);
    auto nearestStormBearing = getDoubleOrNull(currentlyJson["nearestStormBearing"]);
    auto precipIntensity = currentlyJson["precipIntensity"].number_value();
    auto precipIntensityMax = getDoubleOrNull(currentlyJson["precipIntensityMax"]);
    auto precipIntensityMaxTime = getIntOrNull(currentlyJson["precipIntensityMaxTime"]);
    auto precipProbability = currentlyJson["precipProbability"].number_value();
    auto precipType = currentlyJson["precipType"].string_value();
    auto precipAccumulation = getDoubleOrNull(currentlyJson["precipAccumulation"]);
    auto temperature = getDoubleOrNull(currentlyJson["temperature"]);
    auto temperatureMin = getDoubleOrNull(currentlyJson["temperatureMin"]);
    auto temperatureMinTime = getIntOrNull(currentlyJson["temperatureMinTime"]);
    auto temperatureMax = getDoubleOrNull(currentlyJson["temperatureMax"]);
    auto temperatureMaxTime = getIntOrNull(currentlyJson["temperatureMaxTime"]);
    auto apparentTemperature = getDoubleOrNull(currentlyJson["apparentTemperature"]);
    auto apparentTempeartureMax = getDoubleOrNull(currentlyJson["apparentTemperatureMax"]);
    auto apparentTempeartureMaxTime = getIntOrNull(currentlyJson["apparentTemperatureMaxTime"]);
    auto apparentTemperatureMin = getDoubleOrNull(currentlyJson["apparentTemperatureMin"]);
    auto apparentTemperatureMinTime = getIntOrNull(currentlyJson["apparentTemperatureMinTime"]);
    auto dewPoint = currentlyJson["dewPoint"].number_value();
    auto windSpeed = currentlyJson["windSpeed"].number_value();
    auto windBearing = currentlyJson["windBearing"].number_value();
    auto cloudCover = currentlyJson["cloudCover"].number_value();
    auto humidity = currentlyJson["humidity"].number_value();
    auto pressure = currentlyJson["pressure"].number_value();
    auto visibility = currentlyJson["visibility"].number_value();
    auto ozone = currentlyJson["ozone"].number_value();
    
    return DataPoint(time, summary, icon, sunriseTime, sunsetTime, moonPhase, nearestStormDistance, nearestStormBearing, precipIntensity, precipIntensityMax, precipIntensityMaxTime, precipProbability, precipType, precipAccumulation, temperature, temperatureMin, temperatureMinTime, temperatureMax, temperatureMaxTime, apparentTemperature, apparentTempeartureMax, apparentTempeartureMaxTime, apparentTemperatureMin, apparentTemperatureMinTime, dewPoint, windSpeed, windBearing, cloudCover, humidity, pressure, visibility, ozone);
}

DataBlock createDataBlockWithJson(Json blockJson) {
    std::vector<DataPoint> dataPoints;
    auto pointsJson = blockJson["data"].array_items();
    
    for (auto iter = pointsJson.begin(); iter < pointsJson.end(); iter++)
    {
        dataPoints.push_back(createDataPointWithJson(*iter));
    }
    
    return DataBlock(blockJson["summary"].string_value(), blockJson["icon"].string_value(), dataPoints);
}

Alert createAlertWithJson(Json alertJson) {
    std::string title = alertJson["title"].string_value();
    int64_t expires = alertJson["expires"].number_value();
    std::string alert_description = alertJson["description"].string_value();
    std::string uri = alertJson["uri"].string_value();
    
    return Alert(title, expires, alert_description, uri);
}

std::experimental::optional<std::vector<std::string>> createStringArrayWithJson(Json stringArray)
{
    if (stringArray.type() == Json::NUL)
    {
        return std::experimental::nullopt;
    }
    
    auto array = stringArray.array_items();
    std::vector<std::string> result;
    for (auto iter = array.begin(); iter != array.end(); iter++)
    {
        auto item = *iter;
        if (item.type() != Json::STRING)
        {
            return std::experimental::nullopt;
        }
        
        result.push_back(item.string_value());
    }
    
    return result;
}

Flags createFlagsWithJson(Json flagsJson) {
    auto darksky_unavailable = getStringOrNull(flagsJson["darksky-unavailable"]);
    auto darksky_stations_json = createStringArrayWithJson(flagsJson["darksky-stations"]);
    auto datapoint_stations = createStringArrayWithJson(flagsJson["datapoint-stations"]);
    auto isd_stations = createStringArrayWithJson(flagsJson["isd-stations"]);
    auto lamp_stations = createStringArrayWithJson(flagsJson["lamp-stations"]);
    auto metar_stations = createStringArrayWithJson(flagsJson["metar-stations"]);
    auto metno_license = getStringOrNull(flagsJson["metno-license"]);
    auto sources = createStringArrayWithJson(flagsJson["sources"]);
    auto units = getStringOrNull(flagsJson["units"]);
    
    return Flags(darksky_unavailable, darksky_stations_json, datapoint_stations, isd_stations, lamp_stations, metar_stations, metno_license, sources, units);
}

std::shared_ptr<WeatherController> WeatherController::create_with_network_controller(const std::shared_ptr<NetworkController> &controller)
{
    return std::make_shared<WeatherControllerImpl>(controller);
}

WeatherControllerImpl::WeatherControllerImpl(const std::shared_ptr<NetworkController>& controller) {
    this->network_controller = controller;
}

Forecast WeatherControllerImpl::forecast(double latitude, double longitude) {
    
    char* apiKey = getenv("RT_APIKEY");
    std::ostringstream uriStream;
    uriStream << "https://api.forecast.io/forecast/" << std::string(apiKey) << "/" << latitude << "," << longitude;

    std::vector<uint8_t> result;
    if (this->network_controller)
    {
        auto& netController = *(this->network_controller);
        result = netController.get(uriStream.str());
    }

    std::string errString;
    
    auto jsonResult = Json::parse(std::string(result.begin(), result.end()), errString);
    
    auto currentlyJson = jsonResult["currently"];
    
    DataPoint currentlyPoint = createDataPointWithJson(currentlyJson);
    double forecastLatitude = jsonResult["latitude"].number_value();
    double forecastLongitude = jsonResult["longitude"].number_value();
    std::string forecastTimezone = jsonResult["timezone"].string_value();
    
    DataBlock minutelyBlock = createDataBlockWithJson(jsonResult["minutely"]);
    DataBlock hourlyBlock = createDataBlockWithJson(jsonResult["hourly"]);
    DataBlock dailyBlock = createDataBlockWithJson(jsonResult["daily"]);
    
    std::vector<Alert> alerts;
    auto alertJson = jsonResult["alerts"].array_items();
    for (auto iter = alertJson.begin(); iter < alertJson.end(); iter++)
    {
        alerts.push_back(createAlertWithJson(*iter));
    }
    
    Flags flags = createFlagsWithJson(jsonResult["flags"]);
    
    Forecast forecast = Forecast(forecastLatitude, forecastLongitude, forecastTimezone, jsonResult["offset"].number_value(), currentlyPoint, minutelyBlock, hourlyBlock, dailyBlock, alerts, flags);
    
    return forecast;
}
