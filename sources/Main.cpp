#include "extension/init.hpp"
#include <iostream>
#include <thread>

#define end << '\n'

profiler debug;
console window;
style css;

using namespace std;

void newFunction() {
	debug.fragmentStart("newFunction");

	cout << "Hello, World" end;

	debug.fragmentStop();
}

int main() {
	debug.fragmentStart("main");

	window.setTitle("App");
	window.clear();
	window.setCursorPosition(0, 0);

	thread Thread_newFunction(newFunction);
	Thread_newFunction.join();

	theme success = {GREEN, DEFAULT, INTENSIVE_NORMAL, UNDERLINE_FALSE};
	theme warning = {YELLOW, DEFAULT, INTENSIVE_NORMAL, UNDERLINE_FALSE};
	theme error   = {RED, DEFAULT, INTENSIVE_HIGH, UNDERLINE_TRUE};

	css.defaultSet(success);

	cout << css.get() << "status : ok" end;
	cout << css.get(warning) << "status : warning" end;
	cout << css.get(error) << "status : error" end;

	debug.write("status : ok");

	css.clear();

	debug.fragmentStop();
	return EXIT_SUCCESS;
}