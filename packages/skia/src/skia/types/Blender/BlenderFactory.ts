import type { SkBlender } from "./Blender";

export interface BlenderFactory {
  /**
   *  Create a blender that implements the following:
   *     k1 * src * dst + k2 * src + k3 * dst + k4
   *  @param k1, k2, k3, k4 The four coefficients.
   *  @param enforcePMColor If true, the RGB channels will be clamped to the calculated alpha.
   */
  MakeArithmetic(
    k1: number,
    k2: number,
    k3: number,
    k4: number,
    enforcePremul: boolean
  ): SkBlender;
}
