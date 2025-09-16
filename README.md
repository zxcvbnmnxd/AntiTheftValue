
#项目名 ：AntiTheftValue

`介绍`
Android C++ 项目使用的防偷值 可以检测到大部分偷值行为

1. 已特征所有 [GG] 并防止模糊
2. [elf] 二进制模糊
3. 检测游戏是否被注入进行偷值
4. 也可检测自身项目是否被注入

🔒. [kill](如果有以上行为会进行杀进程)

[目前项目版本为 1.0]

[1.0](版本)

#该项目使用共享库的方式进行连接 [libace.so]

[提供三个函数]

#你可以在main开头中使用 #include "ace.h" 加载定义

1. 宽恕模式 true 后不会强制退出
	void pardon(bool pattern);

2. 可以传入游戏包名开启游戏是否被注入的检测
	void gamedetect(std::string package = "");

3. 启用检测 (必要调用)
	void ace();

#你可以参考下方代码
	
	int main() {
	
	// 检测游戏是否被注入
	//ace::gamedetect("com.tencent.tmgp.cfalpha");
	
	// 打开宽恕模式
	ace::pardon(true);
	
	// 启用检测
	ace::ace();
	
	while (1) {
	usleep(1 * 1000000); // 一秒检测一次
	}
	
	return 0;
	
	}
	

[](在android c++ 中你可以使用aide-ndk进行编译链接)

1. 在 [Android.mk] 中的 `LOCAL_PATH := $(call my-dir)` 下一行添加ace库链接

	include $(CLEAR_VARS)
	LOCAL_MODULE := ace
	LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libace.so
	include $(PREBUILT_SHARED_LIBRARY)

2. 在文件末尾添加

	LOCAL_SHARED_LIBRARIES := ace
	LOCAL_LDFLAGS := -Wl,-rpath,.
