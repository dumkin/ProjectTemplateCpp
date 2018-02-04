#include "extension/init.hpp"
#include "libraries/selene.h"
#include <cassert>
#include <ctime>
#include <iostream>
#include <lua5.3/lua.hpp>
#include <string>
#include <thread>

profiler debug;
console window;
style css;

sel::State state{true};

void newFunction() {
	debug.fragmentStart("newFunction");

	std::cout << "Hello, World\n";

	debug.fragmentStop();
}

int mod(const int &fisrt, const int &second) {
	debug.fragmentStart("newFunction");

	int result = fisrt % second;

	debug.fragmentStop();
	return result;
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

	state.Load("Main.lua");

	state["mod"] = &mod;

	state["main"]();

	std::cout << css.get() << "status : ok\n";
	std::cout << css.get(warning) << "status : warning\n";
	std::cout << css.get(error) << "status : error\n";

	debug.write("status : ok");

	css.clear();

	debug.fragmentStop();
	return EXIT_SUCCESS;
}