// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#include "dataBlock.hpp"  // my header
#include "Marshal.hpp"
#include "dataPoint.hpp"

namespace djinni_generated {

DataBlock::DataBlock() = default;

DataBlock::~DataBlock() = default;

auto DataBlock::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<DataBlock>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::String::fromCpp(jniEnv, c.summary).get(),
                                                           ::djinni::String::fromCpp(jniEnv, c.icon).get(),
                                                           ::djinni::List<::djinni_generated::DataPoint>::fromCpp(jniEnv, c.data).get())};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto DataBlock::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 4);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<DataBlock>::get();
    return {::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_summary)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_icon)),
            ::djinni::List<::djinni_generated::DataPoint>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_data))};
}

}  // namespace djinni_generated
