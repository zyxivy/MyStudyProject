#include "pch.h";

int main() {
	bool ret = detectCapitalUse("USA");
	ret = detectCapitalUse("letter");
	ret = detectCapitalUse("FlaG");
	return ret;
}