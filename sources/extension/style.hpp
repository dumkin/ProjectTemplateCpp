#pragma once

#include <iostream>

#ifdef WIN32

#else

#define BLACK "0"
#define RED "1"
#define GREEN "2"
#define YELLOW "3"
#define BLUE "4"
#define MAGENTA "5"
#define CYAN "6"
#define GRAY "7"
#define DEFAULT "9"

#define INTENSIVE_NORMAL "22"
#define INTENSIVE_HIGH "1"
#define INTENSIVE_LOW "2"

#define UNDERLINE_FALSE "24"
#define UNDERLINE_TRUE "4"

#endif

struct theme {
	std::string foreground = DEFAULT;
	std::string background = DEFAULT;
	std::string intensive  = INTENSIVE_NORMAL;
	std::string underline  = UNDERLINE_FALSE;
};

class style {
	public:
	style();
	style(theme newTheme);
	~style();

	void defaultSet(theme newTheme);
	void defaultReset();

	char clear();

	char get();
	char get(theme selectTheme);

	private:
	theme defaultTheme;
#ifdef WIN32
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
};