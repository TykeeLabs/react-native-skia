import type { Blender, CanvasKit } from "canvaskit-wasm";

import type { SkBlender } from "../types";

import { HostObject } from "./Host";

export class JsiSkBlender
  extends HostObject<Blender, "Blender">
  implements SkBlender
{
  constructor(CanvasKit: CanvasKit, ref: Blender) {
    super(CanvasKit, ref, "Blender");
  }
}
