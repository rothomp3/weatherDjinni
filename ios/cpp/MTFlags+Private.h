// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from weather.idl

#import "MTFlags.h"
#include "flags.hpp"

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@class MTFlags;

namespace djinni_generated {

struct Flags
{
    using CppType = ::Flags;
    using ObjcType = MTFlags*;

    using Boxed = Flags;

    static CppType toCpp(ObjcType objc);
    static ObjcType fromCpp(const CppType& cpp);
};

}  // namespace djinni_generated