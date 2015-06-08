// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#include "network_controller.hpp"  // my header
#include "Marshal.hpp"
#include "forecast.hpp"
#include "weatherController.hpp"

namespace djinni_generated {

NetworkController::NetworkController() : ::djinni::JniInterface<::NetworkController, NetworkController>() {}

NetworkController::~NetworkController() = default;

NetworkController::JavaProxy::JavaProxy(JniType j) : JavaProxyCacheEntry(j) { }

NetworkController::JavaProxy::~JavaProxy() = default;

void NetworkController::JavaProxy::get(const std::string & URI, const std::shared_ptr<::WeatherController> & controller) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NetworkController>::get();
    jniEnv->CallVoidMethod(getGlobalRef(), data.method_get,
                           ::djinni::String::fromCpp(jniEnv, URI).get(),
                           ::djinni_generated::WeatherController::fromCpp(jniEnv, controller).get());
    ::djinni::jniExceptionCheck(jniEnv);
}
std::vector<uint8_t> NetworkController::JavaProxy::post(const std::string & URI, const std::vector<uint8_t> & body) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NetworkController>::get();
    auto jret = (jbyteArray)jniEnv->CallObjectMethod(getGlobalRef(), data.method_post,
                                                     ::djinni::String::fromCpp(jniEnv, URI).get(),
                                                     ::djinni::Binary::fromCpp(jniEnv, body).get());
    ::djinni::jniExceptionCheck(jniEnv);
    return ::djinni::Binary::toCpp(jniEnv, jret);
}
void NetworkController::JavaProxy::callbackNative(const ::Forecast & result) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::NetworkController>::get();
    jniEnv->CallVoidMethod(getGlobalRef(), data.method_callbackNative,
                           ::djinni_generated::Forecast::fromCpp(jniEnv, result).get());
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
