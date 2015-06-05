// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#import "MTDataBlock+Private.h"
#import "DJIMarshal+Private.h"
#import "MTDataPoint+Private.h"
#include <cassert>

namespace djinni_generated {

auto DataBlock::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.summary),
            ::djinni::String::toCpp(obj.icon),
            ::djinni::List<::djinni_generated::DataPoint>::toCpp(obj.data)};
}

auto DataBlock::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[MTDataBlock alloc] initWithSummary:(::djinni::String::fromCpp(cpp.summary))
                                           icon:(::djinni::String::fromCpp(cpp.icon))
                                           data:(::djinni::List<::djinni_generated::DataPoint>::fromCpp(cpp.data))];
}

}  // namespace djinni_generated
