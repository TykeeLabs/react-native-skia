package com.shopify.reactnative.skia;

import android.content.Context;

import com.facebook.jni.HybridData;
import com.facebook.jni.annotations.DoNotStrip;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.uimanager.ThemedReactContext;

public class SkiaDomView extends SkiaBaseView {
    @DoNotStrip
    private HybridData mHybridData;

    public SkiaDomView(ThemedReactContext context) {
        super(context);
        RNSkiaModule skiaModule = context.getReactApplicationContext().getNativeModule(RNSkiaModule.class);
        mHybridData = initHybrid(skiaModule.getSkiaManager());
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        mHybridData.resetNative();
    }

    private native HybridData initHybrid(SkiaManager skiaManager);

    protected native void surfaceAvailable(Object surface, int width, int height);

    protected native void surfaceSizeChanged(Object surface, int width, int height);

    protected native void surfaceDestroyed();

    protected native void setBgColor(int color);

    protected native void setMode(String mode);

    protected native void setDebugMode(boolean show);

    protected native void registerView(int nativeId);

    protected native void unregisterView();
}
