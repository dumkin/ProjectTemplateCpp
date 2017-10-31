#pragma once

#include <iostream>
#include <string>

#ifdef WIN32

#define CONSOLE_CLEAR "cls"

#else

#define CONSOLE_CLEAR "clear"

#endif

class console {
	public:
	console();
	~console();

	void setCursorPosition(int x, int y);
	void setTitle(std::string title);
	bool clear();

	private:
#ifdef WIN32
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
};