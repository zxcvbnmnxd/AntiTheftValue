#ifndef ACE_H
#define ACE_H

#include <string>

namespace ace {
	void pardon(bool pattern); // 宽恕模式 true 后不会强制退出
	void gamedetect(std::string package = ""); // 可以传入游戏包名开启游戏是否被注入的检测
	void ace(); // 启用检测
}

#endif
