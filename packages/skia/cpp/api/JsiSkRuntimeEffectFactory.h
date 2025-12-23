#pragma once

#include <memory>
#include <string>
#include <utility>

#include <jsi/jsi.h>

#include "JsiSkHostObjects.h"
#include "JsiSkRuntimeEffect.h"

namespace RNSkia {

namespace jsi = facebook::jsi;

class JsiSkRuntimeEffectFactory : public JsiSkHostObject {

  jsi::Value wrap_shader_result(jsi::Runtime &runtime,
                                SkRuntimeEffect::Result result) {
    auto effect = result.effect;
    auto errorText = result.errorText;
    if (!effect) {
      throw jsi::JSError(runtime, std::string("Error in sksl:\n" +
                                              std::string(errorText.c_str()))
                                      .c_str());
      return jsi::Value::null();
    }
    auto runtimeEffect =
        std::make_shared<JsiSkRuntimeEffect>(getContext(), std::move(effect));
    return JSI_CREATE_HOST_OBJECT_WITH_MEMORY_PRESSURE(runtime, runtimeEffect,
                                                       getContext());
  }

public:
  JSI_HOST_FUNCTION(Make) {
    auto sksl = arguments[0].asString(runtime).utf8(runtime);
    auto result = SkRuntimeEffect::MakeForShader(SkString(sksl));
    return wrap_shader_result(runtime, result);
  }

  JSI_HOST_FUNCTION(MakeForBlender) {
    auto sksl = arguments[0].asString(runtime).utf8(runtime);
    auto result = SkRuntimeEffect::MakeForBlender(SkString(sksl));
    return wrap_shader_result(runtime, result);
  }

  size_t getMemoryPressure() const override { return 1024; }

  std::string getObjectType() const override {
    return "JsiSkRuntimeEffectFactory";
  }

  JSI_EXPORT_FUNCTIONS(JSI_EXPORT_FUNC(JsiSkRuntimeEffectFactory, Make),
                       JSI_EXPORT_FUNC(JsiSkRuntimeEffectFactory,
                                       MakeForBlender));

  explicit JsiSkRuntimeEffectFactory(
      std::shared_ptr<RNSkPlatformContext> context)
      : JsiSkHostObject(std::move(context)) {}
};

} // namespace RNSkia
