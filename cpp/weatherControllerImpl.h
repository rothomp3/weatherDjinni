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

class WeatherControllerImpl : public WeatherController {
public:
    WeatherControllerImpl(const std::shared_ptr<NetworkController>& controller);
    virtual Forecast forecast(double latitude, double longitude) override;
    
private:
    std::shared_ptr<NetworkController> network_controller;
};

#endif
