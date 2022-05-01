#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, y, w, h;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	int xEdgeDistance = 0;
	int yEdgeDistance = 0;
	int minEdgeDistance = 0;

	xEdgeDistance = (w - x) < x ? w - x : x;
	yEdgeDistance = (h - y) < y ? h - y : y;

	minEdgeDistance = xEdgeDistance < yEdgeDistance ? xEdgeDistance : yEdgeDistance;

	printf("%d", minEdgeDistance);

	return 0;
}