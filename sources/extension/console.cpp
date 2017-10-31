#include "console.hpp"

console::console() {
}

console::~console() {
}

void console::setCursorPosition(int x, int y) {
	std::cout << "\033[" << y << ";" << x << "H";
}

void console::setTitle(std::string title) {
	std::cout << "\033]2;" << title << "\007";
}

bool console::clear() {
	return system(CONSOLE_CLEAR);
}