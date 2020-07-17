//Imagine you have a special keyboard with the following keys :
//
//Key 1 : (A) : Print one 'A' on screen.
//
//Key 2 : (Ctrl - A) : Select the whole screen.
//
//Key 3 : (Ctrl - C) : Copy selection to buffer.
//
//Key 4 : (Ctrl - V) : Print buffer on screen appending it after what has already been printed.
//
//Now, you can only press the keyboard for N times(with the above four keys), find out the maximum numbers of 'A' you can print on screen.
//
//Example 1 :
//	Input : N = 3
//	Output : 3
//	Explanation :
//	We can at most get 3 A's on screen by pressing following key sequence:
//	A, A, A
//	Example 2 :
//	Input : N = 7
//	Output : 9
//	Explanation :
//	We can at most get 9 A's on screen by pressing following key sequence:
//	A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
//	Note :
//1 <= N <= 50
//Answers will be in the range of 32 - bit signed integer.

#include "pch.h";
int maxA(int N) {
	// select, copy takes 2 steps, so max step to actually print/paste is i-2;
	// assume dp[x] is the max A for x steps, and paste dp[x] y times, it means x+y=i-2 => y=i-x-2
	// find max(i, dp[x]+dp[x]*y), => max(i, dp[x]*(1+y)) => max(i, dp[x]*(i-x-1))
	vector<int> dp(N + 1, INT_MIN);
	dp[0] = 0;
	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int x = 1; x < i-2; x++) {
			dp[i] = max(dp[i], dp[x] * (i - x - 1));
		}
	}
	return dp[N];
}