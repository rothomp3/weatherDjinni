// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#include "forecast.hpp"  // my header
#include "Marshal.hpp"
#include "alert.hpp"
#include "dataBlock.hpp"
#include "dataPoint.hpp"
#include "flags.hpp"

namespace djinni_generated {

Forecast::Forecast() = default;

Forecast::~Forecast() = default;

auto Forecast::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<Forecast>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::F64::fromCpp(jniEnv, c.latitude),
                                                           ::djinni::F64::fromCpp(jniEnv, c.longitude),
                                                           ::djinni::String::fromCpp(jniEnv, c.timezone).get(),
                                                           ::djinni::I32::fromCpp(jniEnv, c.offset),
                                                           ::djinni_generated::DataPoint::fromCpp(jniEnv, c.currently).get(),
                                                           ::djinni_generated::DataBlock::fromCpp(jniEnv, c.minutely).get(),
                                                           ::djinni_generated::DataBlock::fromCpp(jniEnv, c.hourly).get(),
                                                           ::djinni_generated::DataBlock::fromCpp(jniEnv, c.daily).get(),
                                                           ::djinni::List<::djinni_generated::Alert>::fromCpp(jniEnv, c.alerts).get(),
                                                           ::djinni_generated::Flags::fromCpp(jniEnv, c.flags).get())};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto Forecast::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 11);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<Forecast>::get();
    return {::djinni::F64::toCpp(jniEnv, jniEnv->GetDoubleField(j, data.field_latitude)),
            ::djinni::F64::toCpp(jniEnv, jniEnv->GetDoubleField(j, data.field_longitude)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_timezone)),
            ::djinni::I32::toCpp(jniEnv, jniEnv->GetIntField(j, data.field_offset)),
            ::djinni_generated::DataPoint::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_currently)),
            ::djinni_generated::DataBlock::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_minutely)),
            ::djinni_generated::DataBlock::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_hourly)),
            ::djinni_generated::DataBlock::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_daily)),
            ::djinni::List<::djinni_generated::Alert>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_alerts)),
            ::djinni_generated::Flags::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_flags))};
}

}  // namespace djinni_generated
