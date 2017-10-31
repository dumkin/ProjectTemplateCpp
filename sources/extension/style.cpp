#include "style.hpp"

style::style() {
}

style::style(theme newTheme) : defaultTheme(newTheme) {
}

style::~style() {
}

void style::defaultSet(theme newTheme) {
	defaultTheme = newTheme;
}

void style::defaultReset() {
	theme newDefaultTheme;
	defaultTheme = newDefaultTheme;
}

char style::clear() {
	std::cout << "\033[m";

	return '\0';
}

char style::get() {
	std::cout << "\033[3" << defaultTheme.foreground << "m";
	std::cout << "\033[4" << defaultTheme.background << "m";
	std::cout << "\033[" << defaultTheme.intensive << "m";
	std::cout << "\033[" << defaultTheme.underline << "m";

	return '\0';
}

char style::get(theme selectTheme) {
	std::cout << "\033[3" << selectTheme.foreground << "m";
	std::cout << "\033[4" << selectTheme.background << "m";
	std::cout << "\033[" << selectTheme.intensive << "m";
	std::cout << "\033[" << selectTheme.underline << "m";

	return '\0';
}