//Write a program that outputs the string representation of numbers from 1 to n.
//
//But for multiples of three it should output “Fizz” instead of the numberand for the multiples of five output “Buzz”.For numbers which are multiples of both threeand five output “FizzBuzz”.
//
//Example:
//
//n = 15,
//
//Return :
//    [
//        "1",
//        "2",
//        "Fizz",
//        "4",
//        "Buzz",
//        "Fizz",
//        "7",
//        "8",
//        "Fizz",
//        "Buzz",
//        "11",
//        "Fizz",
//        "13",
//        "14",
//        "FizzBuzz"
//    ]

#include "Header.h";
vector<string> fizzBuzz(int n) {
	vector<string> ret(n, "");
	int fizz = 3;
	int buzz = 5;
	for (int i = 0; i < n; i++) {
		fizz--;
		buzz--;
		if (fizz == 0 && buzz == 0)
		{
			ret[i] = "FizzBuzz";
			fizz = 3;
			buzz = 5;
		}
		else if (fizz == 0)
		{
			ret[i] = "Fizz";
			fizz = 3;
		}
		else if (buzz == 0)
		{
			ret[i] = "Buzz";
			buzz = 5;
		}
		else {
			ret[i] = to_string(i + 1);
		}
	}

	return ret;
}