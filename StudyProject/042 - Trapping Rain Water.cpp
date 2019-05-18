#include "pch.h";

int trap(vector<int>& height) {
	int i = 0;
	stack<int> st;
	int water = 0;
	while (i < height.size()) {
		if (st.empty() || height[i] < height[st.top()]) {
			st.push(i);
			i++; // only increment here
		}
		else {
			int t = height[st.top()];
			st.pop();
			water += st.empty() ? 0 : (i - st.top() - 1)*(min(height[st.top()], height[i]) - t);
		}
	}
	return water;
}