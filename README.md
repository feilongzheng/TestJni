# TestJni
总结:  使用javah生成.h文件时,
      如果在D:\Android\project\ndk\bin\classes中,执行javah com.heima.ndk.ndkActivity无法访问,找不到类文件的话
    那就在D:\Android\project\ndk\src中,执行javah com.heima.ndk.ndkActivity,或许能成功
   详情＝http://www.cnblogs.com/shortboy/archive/2013/03/12/2956673.html


生成.so文件
1、生成.h文件 pengsier@localhost:~/Desktop/copy/JNI/app/src/main/java$javah -jni com.cn.jni.MainActivity

借鉴gradle配置 = http://blog.csdn.net/sodino/article/details/41946607
借鉴生成.h的方法 = http://www.android100.org/html/201502/14/118812.html
调用。so文件
http://blog.csdn.net/shamusoft/article/details/7872907
mac上ndk环境配置
http://blog.csdn.net/zf135792468/article/details/11926995
ndk迅雷地址
http://dl.google.com/android/ndk/android-ndk-r10c-darwin-x86_64.bin

步骤：
1、在java文件中加载library声明native方法
static{    System.loadLibrary("JniTest");}
public native String getStringFromNative();
2.用命令生成.h文件 pengsier@localhost:~/Desktop/copy/JNI/app/src/main/java$javah -jni com.cn.jni.MainActivity
3、main文件夹下新建jni类型文件夹，将.h文件复制到文件夹下，再新建与.h同名的.c文件实现.h文件中申明的方法。
4、local.properties文件中配置ndk.dir=ndk文件路径，gradle中配置ndk{}对.so,运行生成各种类型的.so文件
defaultConfig {
    applicationId "com.example.test"
minSdkVersion 14
targetSdkVersion 20

ndk {
        moduleName "JniTest"
ldLibs "log", "z", "m"
abiFilters "armeabi", "armeabi-v7a", "x86"
}
}
Android使用JNI实现Java与C之间传递数据

对jni c 文件有详细提到，还有解释动态注册jni  =http://www.360doc.com/content/13/0530/14/110467_289211699.shtml
