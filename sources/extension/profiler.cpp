#include "profiler.hpp"

profiler::profiler() {
	log.write("[" + log.getDate() + "] App started.");
}

profiler::~profiler() {
	log.write("[" + log.getDate() + "] App closed.");
}

void profiler::fragmentStart(std::string fragment) {
	unsigned long long segmentTimeStart = clockGet();

	write(fragment + "()", FRAGMENT_START);

	stack.push_back(segmentTimeStart);
}

void profiler::fragmentStop() {
	unsigned long long segmentTimeStop = clockGet();

	unsigned long long segmentTimeResult = segmentTimeStop - stack.back();

	stack.pop_back();

	write("returned in " + std::to_string(segmentTimeResult) + " ns. / " +
	          std::to_string(segmentTimeResult / 1000000000.0) + " s.",
	      FRAGMENT_STOP);
}

void profiler::write(std::string text, int type) {
	log.write("[" + log.getDate() + "] ", false);

	if (type == FRAGMENT_START) {
		if (stack.size() == 0) {
			log.write("┏ ", false);
		} else {
			for (unsigned long long i = 0; i < stack.size() - 1; ++i) {
				log.write("┃    ", false);
			}
			log.write("┣━━━━┳ ", false);
		}
	} else if (type == FRAGMENT_STATUS) {
		for (unsigned long long i = 0; i < stack.size() - 1; ++i) {
			log.write("┃    ", false);
		}
		log.write("┃ ", false);

	} else if (type == FRAGMENT_STOP) {
		for (unsigned long long i = 0; i < stack.size(); ++i) {
			log.write("┃    ", false);
		}
		log.write("┗ ", false);
	}

	log.write(text);
}

unsigned long long profiler::clockGet() {
	unsigned long long x;
	__asm__ volatile("rdtsc\n\tshl $32, %%rdx\n\tor %%rdx, %%rax"
	                 : "=a"(x)
	                 :
	                 : "rdx");
	return x;
}