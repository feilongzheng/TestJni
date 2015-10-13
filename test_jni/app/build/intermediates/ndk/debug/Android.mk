LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := JniTest
LOCAL_LDFLAGS := -Wl,--build-id
LOCAL_LDLIBS := \
	-llog \
	-lz \
	-lm \

LOCAL_SRC_FILES := \
	/Users/xfeng/Documents/untitled_folder/app/src/main/jni/com_example_test_TestJni.c \
	/Users/xfeng/Documents/untitled_folder/app/src/main/jni/empty.c \

LOCAL_C_INCLUDES += /Users/xfeng/Documents/untitled_folder/app/src/main/jni
LOCAL_C_INCLUDES += /Users/xfeng/Documents/untitled_folder/app/src/debug/jni

include $(BUILD_SHARED_LIBRARY)
