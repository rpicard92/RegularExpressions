#include <iostream>
#include "RegularExpressions.h"

int main() {
	RegularExpressions * reg = new RegularExpressions();
	bool answer = reg->isMatch("test", "*tes");
	std::cout << answer << std::endl;
};