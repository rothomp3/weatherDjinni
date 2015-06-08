//
//  weatherControllerImpl.h
//  WeatherDjinni
//
//  Created by Robert Thompson on 6/4/15.
//  Copyright (c) 2015 WillowTree Apps. All rights reserved.
//

#ifndef WeatherDjinni_weatherControllerImpl_h
#define WeatherDjinni_weatherControllerImpl_h
#import "weatherController.hpp"
#import "network_controller.hpp"
#import <memory>

class WeatherControllerImpl : public WeatherController, public std::enable_shared_from_this<WeatherController> {
public:
    WeatherControllerImpl(const std::shared_ptr<NetworkController>& controller);
    virtual void forecast(double latitude, double longitude) override;
    virtual void receiveData(const std::vector<uint8_t> & data) override;
    
private:
    std::shared_ptr<NetworkController> network_controller;
    Forecast createForcast(const std::vector<uint8_t> & data);
};

#endif
