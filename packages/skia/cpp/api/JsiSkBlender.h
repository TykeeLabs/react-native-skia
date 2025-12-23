#pragma once

#include <memory>
#include <utility>

#include <jsi/jsi.h>

#include "JsiSkHostObjects.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#include "include/core/SkBlender.h"

#pragma clang diagnostic pop

namespace RNSkia {
namespace jsi = facebook::jsi;

class JsiSkBlender : public JsiSkWrappingSharedPtrHostObject<SkBlender> {
public:
  EXPORT_JSI_API_TYPENAME(JsiSkBlender, Blender)

  JsiSkBlender(std::shared_ptr<RNSkPlatformContext> context,
               sk_sp<SkBlender> blender)
      : JsiSkWrappingSharedPtrHostObject<SkBlender>(std::move(context),
                                                    std::move(blender)) {}

  size_t getMemoryPressure() const override { return 1024 * 1024; }

  std::string getObjectType() const override { return "JsiSkBlender"; }
};
} // namespace RNSkia
