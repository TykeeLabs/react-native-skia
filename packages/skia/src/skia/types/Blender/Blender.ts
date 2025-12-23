import type { SkJSIInstance } from "../JsiInstance";

export const isBlender = (
  obj: SkJSIInstance<string> | null
): obj is SkBlender => obj !== null && obj.__typename__ === "Blender";

export type SkBlender = SkJSIInstance<"Blender">;
