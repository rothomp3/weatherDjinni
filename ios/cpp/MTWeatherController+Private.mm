// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#import "MTWeatherController+Private.h"
#import "MTWeatherController.h"
#import "DJICppWrapperCache+Private.h"
#import "DJIError.h"
#import "DJIMarshal+Private.h"
#import "MTNetworkController+Private.h"
#import "MTWeatherController+Private.h"
#include <exception>
#include <utility>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@interface MTWeatherController ()

@property (nonatomic, readonly) ::djinni::DbxCppWrapperCache<::WeatherController>::Handle cppRef;

- (id)initWithCpp:(const std::shared_ptr<::WeatherController>&)cppRef;

@end

@implementation MTWeatherController

- (id)initWithCpp:(const std::shared_ptr<::WeatherController>&)cppRef
{
    if (self = [super init]) {
        _cppRef.assign(cppRef);
    }
    return self;
}

- (void)forecast:(double)latitude
       longitude:(double)longitude {
    try {
        _cppRef.get()->forecast(::djinni::F64::toCpp(latitude),
                                ::djinni::F64::toCpp(longitude));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

+ (nullable MTWeatherController *)createWithNetworkController:(nullable id<MTNetworkController>)controller {
    try {
        auto r = ::WeatherController::create_with_network_controller(::djinni_generated::NetworkController::toCpp(controller));
        return ::djinni_generated::WeatherController::fromCpp(r);
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

- (void)receiveData:(nonnull NSData *)data {
    try {
        _cppRef.get()->receiveData(::djinni::Binary::toCpp(data));
    } DJINNI_TRANSLATE_EXCEPTIONS()
}

@end

namespace djinni_generated {

auto WeatherController::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return objc.cppRef.get();
}

auto WeatherController::fromCpp(const CppType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return ::djinni::DbxCppWrapperCache<::WeatherController>::getInstance()->get(cpp, [] (const CppType& p) {
        return [[MTWeatherController alloc] initWithCpp:p];
    });
}

}  // namespace djinni_generated
