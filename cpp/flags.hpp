// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#pragma once

#include <experimental/optional>
#include <string>
#include <utility>
#include <vector>

struct Flags final {
    std::experimental::optional<std::string> darksky_unavailable;
    std::experimental::optional<std::vector<std::string>> darksky_stations;
    std::experimental::optional<std::vector<std::string>> datapoint_stations;
    std::experimental::optional<std::vector<std::string>> isd_stations;
    std::experimental::optional<std::vector<std::string>> lamp_stations;
    std::experimental::optional<std::vector<std::string>> metar_stations;
    std::experimental::optional<std::string> metno_license;
    std::experimental::optional<std::vector<std::string>> sources;
    std::experimental::optional<std::string> units;

    Flags(std::experimental::optional<std::string> darksky_unavailable,
          std::experimental::optional<std::vector<std::string>> darksky_stations,
          std::experimental::optional<std::vector<std::string>> datapoint_stations,
          std::experimental::optional<std::vector<std::string>> isd_stations,
          std::experimental::optional<std::vector<std::string>> lamp_stations,
          std::experimental::optional<std::vector<std::string>> metar_stations,
          std::experimental::optional<std::string> metno_license,
          std::experimental::optional<std::vector<std::string>> sources,
          std::experimental::optional<std::string> units)
    : darksky_unavailable(std::move(darksky_unavailable))
    , darksky_stations(std::move(darksky_stations))
    , datapoint_stations(std::move(datapoint_stations))
    , isd_stations(std::move(isd_stations))
    , lamp_stations(std::move(lamp_stations))
    , metar_stations(std::move(metar_stations))
    , metno_license(std::move(metno_license))
    , sources(std::move(sources))
    , units(std::move(units))
    {}
};
