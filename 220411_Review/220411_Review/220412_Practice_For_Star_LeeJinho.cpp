#include <iostream>
#include <string>

using namespace std;

int main()
{
/*
喊嘛扁
1)
*
**
***
****
*****

2)
*
**
***
****
*****

3)
*****
****
***
**
*

4)
*****
****
***
**
*

5)
*
***
*****
*******
*********

6)
*********
*******
*****
***
*

7)
*
***
*****
*******
*********
*******
*****
***
*
*/

#pragma region 槛力1
	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力2
	for (int i = 1; i < 6; i++)
	{
		for (int j = 5; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力3
	for (int i = 0; i < 5; i++)
	{
		for (int j = 5; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力4
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << " ";
		}
		for (int j = 5; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力5
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力6
	for (int i = 0; i < 10; i += 2)
	{
		for (int j = 0; j < i; j += 2)
		{
			cout << " ";
		}
		for (int j = 9; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion

#pragma region 槛力7
	for (int i = 0; i < 5; i++)
	{
		for (int j = 4; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 2; i < 10; i += 2)
	{
		for (int j = 0; j < i; j += 2)
		{
			cout << " ";
		}
		for (int j = 9; j > i; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
#pragma endregion
}