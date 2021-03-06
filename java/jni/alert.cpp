// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#include "alert.hpp"  // my header
#include "Marshal.hpp"

namespace djinni_generated {

Alert::Alert() = default;

Alert::~Alert() = default;

auto Alert::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<Alert>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::String::fromCpp(jniEnv, c.title).get(),
                                                           ::djinni::I64::fromCpp(jniEnv, c.expires),
                                                           ::djinni::String::fromCpp(jniEnv, c.alert_description).get(),
                                                           ::djinni::String::fromCpp(jniEnv, c.uri).get())};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto Alert::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<Alert>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_title)),
            ::djinni::I64::toCpp(jniEnv, jniEnv->GetLongField(j, data.field_expires)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_alertDescription)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_uri))};
}

}  // namespace djinni_generated
