// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#pragma once

#include "alert.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class Alert final {
public:
    using CppType = ::Alert;
    using JniType = jobject;

    using Boxed = Alert;

    ~Alert();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    Alert();
    friend ::djinni::JniClass<Alert>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("com/wta/weather/Alert") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;JLjava/lang/String;Ljava/lang/String;)V") };
    const jfieldID field_title { ::djinni::jniGetFieldID(clazz.get(), "title", "Ljava/lang/String;") };
    const jfieldID field_expires { ::djinni::jniGetFieldID(clazz.get(), "expires", "J") };
    const jfieldID field_alertDescription { ::djinni::jniGetFieldID(clazz.get(), "alertDescription", "Ljava/lang/String;") };
    const jfieldID field_uri { ::djinni::jniGetFieldID(clazz.get(), "uri", "Ljava/lang/String;") };
};

}  // namespace djinni_generated
