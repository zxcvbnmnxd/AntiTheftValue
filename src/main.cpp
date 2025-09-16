#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/mman.h>
#include <cstdint>
#include <cstdlib>
#include <sys/mman.h>
#include <linux/filter.h>
#include <linux/seccomp.h>
#include <linux/ptrace.h>
#include <sys/syscall.h>
#include <sys/ucontext.h>
#include <unistd.h>
#include <new>
#include <iostream>
#include <functional>
#include <thread>
#include <dlfcn.h>

#include "ace.h"

int main() {
	
	std::cout << "当前pid > " << getpid() << std::endl;
	
	// 检测游戏是否被注入
	//ace::gamedetect("com.tencent.tmgp.cfalpha");
	
	// 打开宽恕模式
	ace::pardon(true);
	
	// 启用检测
	ace::ace();
	
	while (1) {
		usleep(1 * 1000000);
	}
	
	return 0;
}
