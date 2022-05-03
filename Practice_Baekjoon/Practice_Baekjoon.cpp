#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ResidentNums(int K, int N)
{
	if (N == 0)
	{
		return 0;
	}
}

int main(void)
{
	int T, k, n;

	scanf("%d", &T);

	for (int j = 0; j < T; j++)
	{
		int residentNum = 0;
		int floorResidentNum[14] = { 0 };

		scanf("%d %d", &k, &n);

		for (int i = 0; i < n; i++)
		{
			floorResidentNum[i] += i + 1;
		}

		for (int floor = 1; floor <= k; floor++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				for (int i = 0; i < j; i++)
				{
					floorResidentNum[j] += floorResidentNum[i];
				}
			}
		}
		residentNum = floorResidentNum[n - 1];

		printf("%d\n", residentNum);
	}
}