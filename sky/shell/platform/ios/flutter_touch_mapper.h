// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_SHELL_PLATFORM_IOS_TOUCH_MAPPER_H_
#define SKY_SHELL_PLATFORM_IOS_TOUCH_MAPPER_H_

#include <UIKit/UIKit.h>

#include "base/macros.h"

#include <map>

namespace sky {
namespace shell {

/// UITouch pointers cannot be used as touch ids (even though they remain
/// constant throughout the multitouch sequence) because internal components
/// assume that ids are < 16. This class maps touch pointers to ids
class TouchMapper {
 public:
  TouchMapper();
  ~TouchMapper();

  int registerTouch(UITouch* touch);

  int unregisterTouch(UITouch* touch);

  int identifierOf(UITouch* touch) const;

 private:
  using BitSet = long long int;
  BitSet free_spots_;
  std::map<UITouch*, int> touch_map_;

  DISALLOW_COPY_AND_ASSIGN(TouchMapper);
};

}  // namespace shell
}  // namespace sky

#endif  // SKY_SHELL_PLATFORM_IOS_TOUCH_MAPPER_H_
