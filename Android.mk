LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := ace
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libace.so
include $(PREBUILT_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := Tellthetime.rc

LOCAL_CFLAGS += -Wno-asm-operand-widths
LOCAL_CFLAGS += -fvisibility=hidden

LOCAL_CPPFLAGS += -std=c++17
LOCAL_CPPFLAGS += -fexceptions

LOCAL_C_INCLUDES += $(LOCAL_PATH)/include
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include/ace

LOCAL_SRC_FILES := \
	src/main.cpp

LOCAL_LDLIBS := -llog -landroid -lEGL -lGLESv3 -ldl

LOCAL_SHARED_LIBRARIES := ace

LOCAL_LDFLAGS := -Wl,-rpath,.

include $(BUILD_EXECUTABLE)
