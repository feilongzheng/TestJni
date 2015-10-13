#include <jni.h>
#define LOG_TAG "HelloWorld"
//#include <utils/Log.h>
/**
 * native interface
 */
JNIEXPORT jstring JNICALL Java_com_example_test_TestJni_printJNI
  (JNIEnv *env, jobject obj, jstring inputStr){
//	LOGI("hello world from libhelloworld.so");
	const char *str = (const char *)(*env)->GetStringUTFChars(env,inputStr,JNI_FALSE);
//	LOGI("%s",(const char *));

	(*env)->ReleaseStringUTFChars(env, inputStr, (const char *)str);
	return (*env)->NewStringUTF(env, "hello world i am native interface");
}

jint JNI_OnLoad(JavaVM* vm , void * reserved){
	void *venv;
//	LOGI("log--JNI_OnLoad");
	if((*vm)->GetEnv(vm, (void**)&venv, JNI_VERSION_1_4) != JNI_OK ){
//		LOGE("LOG-ERROR: GETenv fiailed");
		return -1;
	}
	return JNI_VERSION_1_4;
}
