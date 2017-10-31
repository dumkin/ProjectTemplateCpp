#pragma once

#include "dLog.hpp"
#include "style.hpp"
#include <fstream>
#include <string>
#include <vector>

#define FRAGMENT_START 0
#define FRAGMENT_STATUS 1
#define FRAGMENT_STOP 2

class profiler {
	public:
	profiler();
	~profiler();

	void fragmentStart(std::string fragment);
	void fragmentStop();

	void write(std::string text, int status = FRAGMENT_STATUS);

	unsigned long long clockGet();

	private:
	style css;

	dLog log;

	std::vector<unsigned long long> stack;
};