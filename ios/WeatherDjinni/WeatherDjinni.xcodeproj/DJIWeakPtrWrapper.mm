//
// Copyright 2014 Dropbox, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import "DJIWeakPtrWrapper+Private.h"
static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

@implementation DBWeakPtrWrapper

- (id)initWithWeakPtr:(std::weak_ptr<void>)ptr {
    if (self = [super init]) {
        _ptr = ptr;
    }
    return self;
}

@end
