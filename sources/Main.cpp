#include "extension/init.hpp"
#include <iostream>
#include <thread>

profiler debug;
console window;
style css;

void newFunction() {
	debug.fragmentStart("newFunction");

	std::cout << "Hello, World\n";

	debug.fragmentStop();
}

int main() {
	debug.fragmentStart("main");

	window.setTitle("App");
	window.clear();
	window.setCursorPosition(0, 0);

	std::thread Thread_newFunction(newFunction);
	Thread_newFunction.join();

	theme success = {GREEN, DEFAULT, INTENSIVE_NORMAL, UNDERLINE_FALSE};
	theme warning = {YELLOW, DEFAULT, INTENSIVE_NORMAL, UNDERLINE_FALSE};
	theme error   = {RED, DEFAULT, INTENSIVE_HIGH, UNDERLINE_TRUE};

	css.defaultSet(success);

	std::cout << css.get() << "status : ok\n";
	std::cout << css.get(warning) << "status : warning\n";
	std::cout << css.get(error) << "status : error\n";

	debug.write("status : ok");

	css.clear();

	debug.fragmentStop();
	return EXIT_SUCCESS;
}