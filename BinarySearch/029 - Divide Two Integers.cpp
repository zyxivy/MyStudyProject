#include "pch.h";
int divide(int dividend, int divisor) {
	if (divisor == 0) {
		return dividend < 0 ? INT_MIN : INT_MAX;
	}
	if (abs(divisor) == 1) {
		if (dividend == INT_MIN && divisor == -1) {
			return INT_MAX;
		}
		return divisor == -1 ? -dividend : dividend;
	}

}