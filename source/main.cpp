#include <include/sarda.h>

int main(int argc, char** argv) {
	SARDA_CONSOLE_CYAN("Hello, world!");
	SARDA_CONSOLE_LOG("This is just a log.");
	SARDA_TRACE("Let's trace something.");
	SARDA_ERROR("Error! Or a false alarm.");
	SARDA_WARN("Stay sharp, soldier!");
	SARDA_INFO("This is just a drill.");
	
	return 0;
}
