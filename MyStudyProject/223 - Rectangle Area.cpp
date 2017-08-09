//Find the total area covered by two rectilinear rectangles in a 2D plane.
//
//Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
//
//Rectangle Area
//Assume that the total area is never beyond the maximum possible value of int.

#include "Header.h";

int overlap(int A, int B, int C, int D, int E, int F, int G, int H) {

	int h1 = max(A, E);
	int h2 = min(C, G);
	int h = h2 - h1;

	int v1 = max(B, F);
	int v2 = min(D, H);
	int v = v2 - v1;

	if (h2 < h1 || v2 < v1) return 0;
	else return h*v;
}
int Solution::computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	int area1 = (C - A) * (D - B);
	int area2 = (G - E) * (H - F);

	int overlapRegion = overlap(A, B, C, D, E, F, G, H);
	return area1  - overlapRegion + area2;
}
