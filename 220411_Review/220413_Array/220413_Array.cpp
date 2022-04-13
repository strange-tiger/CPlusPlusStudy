/*
	
	boolean타입
	boolean타입에는 true / false 두 가지만 들어갈 수 있다.
	bool is_alive = 5 > 3;

	배열 (자료구조)
	같은 데이터타입의 여러 변수를 하나의 묶음으로 나타낸 것.

	배열의 데이터타입에 대한 동일한 크기로 메모리 상에 연속된 공간이 할당된다.
	배열명이 메모리 시작 주소이다.
	배열의 수 = 시작 주소로부터의 거리

	2차원배열 및 다차원배열
	배열이 개념적으로 2중으로, 다중으로 구성되어 있는 것. 실제로는 일직선 상의 연속된 메모리 공간.

	1차원 배열 : int student_nums[5];	// 5개의 int
		-> 5명의 학생이 있다.
	2차원 배열 : int student_nums[3][5];	// 15개의 int
		-> 3개의 반에 각각 5명의 학생이 있다.
	3차원 배열 : int student_nums[4][3][5];	// 60개의 int
		-> 4개의 학년에 각각 3개 반이 존재, 각 반에 5명의 학생이 있다.

	(엔터 없이) 문자 하나를 입력 받는 방법
	#include <conio.h>
	_getch();
	ASCII 코드값으로 읽는다.
*/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	/*int input_key = _getch();
	char input_key_char = _getch();
	cout << (int)input_key_char << endl;
	float test_float = 5.4f;*/

	/*int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 12 };

	cout << nums << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << &(nums[i]) << endl;
	}*/

	/*
		실습1. string형 배열변수 5개짜리를 선언하고
		반복문을 통해 학생의 이름을 입력받는다.

		입력을 다 받고나서 1 ~ 5 사이의 값을 입력하면 해당학생의 이름이 출력된다.

		예시)
			1번째 학생의 이름을 입력하세요 : _
			2번째 학생의 이름을 입력하세요 : _
			3번째 학생의 이름을 입력하세요 : _
			4번째 학생의 이름을 입력하세요 : _
			5번째 학생의 이름을 입력하세요 : _

			1 ~ 5 사이의 번호를 입력하세요 : _3
			3번째 학생의 이름은 ... 입니다.
	*/

#pragma region 실습1
	/*
	string studentName[5];
	int selectNum;

	for (int i = 0; i < 5; i++)
	{
		cout << i + 1 << "번째 학생의 이름을 입력하세요 : ";
		cin >> studentName[i];
		cout << endl;
	}

	cout << "1 ~ 5 사이의 번호를 입력하세요 : ";
	cin >> selectNum;
	cout << selectNum << "번째 학생의 이름은 " << studentName[selectNum - 1] << "입니다." << endl;
	*/
#pragma endregion

	//int student_nums[3][5] = { {1, 2, 3, 4, 5},
	//						   {6, 7, 8, 9, 10},
	//						   {11, 12, 13, 14, 15} };
	//cout << student_nums[0][6] << endl; // 7, [1][1] : 개념적으로 2중, 연속된 메모리
	//// 순서대로 출력하는 코드
	//for (int j = 0; j < 3; j++)
	//{
	//	for (int i = 0; i < 5; i++)
	//	{
	//		cout << student_nums[j][i] << endl;
	//	}
	//}

	/*
		실습2.
		구구단의 결과를 저장하는 2차원 배열을 하나 선언하고,
		2 * 1 = 2

		이중 for문을 이용해서 배열 변수에 구구단의 결과값을 저장하고,
		두 수를 입력받아서 적합한 결과값을 출력해보자.

		예시)
			몇 단을 볼까요? : _4
			몇을 곱할까요? : _7

			4 * 7 = 28
	*/

#pragma region 실습2
	/*
	int gugu_db[8][9];
	int beNum, afNum;

	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i < 9; i++)
		{
			gugu_db[j][i] = (j + 2) * (i + 1);
		}
	}

	cout << "몇 단을 볼까요?\t: ";
	cin >> beNum;
	cout << "몇을 곱할까요?\t: ";
	cin >> afNum;
	(beNum >= 2 && beNum <= 9 && afNum >= 1 && afNum <= 9) ? 
		cout << beNum << " * " << afNum << " = " << gugu_db[beNum - 2][afNum - 1] << endl : cout << "범위 외" << endl;
	*/
#pragma endregion
	
	/*
		실습3.
		A ~ Z 키 중에 하나를 정답으로 설정한다.
		유저는 한 개의 키를 입력해서 설정된 값을 맞춘다.
		유저가 입력한 키와 설정된 값이 맞으면 승리, 프로그램 종료
		틀리면 남은 기회를 보여주고,
		5번 틀리면 정답을 알려주고 게임오버

		+ 틀릴 때마다 정답 알파벳이 입력된 알파벳 앞에 있는지, 뒤에 있는지 힌트를 준다.

		+ 입력된 값이 대소문자 구분없이 처리될 수 있도록 수정해보자.
	*/

#pragma region 실습3
	/*
	char keyMin = 'A'; // ASCII code: 65
	char keyMax = 'Z'; // ASCII code: 90
	int correctAnswer = 0;
	char userAnswer;

	// 난수 생성
	srand(time(NULL));
	correctAnswer = rand();
	srand(time(NULL));
	correctAnswer += rand();
	correctAnswer %= (int)keyMax - (int)keyMin + 1;
	correctAnswer += (int)keyMin;

	cout << "알파벳 키를 누르시오" << endl;

	// cout << (char)correctAnswer << endl;

	for (int i = 0; i < 5; i++)
	{	
		userAnswer = _getch();
		
		cout << userAnswer << endl;

		// ++
		if (userAnswer >= 97 && userAnswer <= 122) // ASCII code a = 97, z = 122
		{
			userAnswer -= 32;
		}
		
		if (userAnswer == correctAnswer)
		{
			cout << "승리" << endl;
			break;
		}
		else if (userAnswer > 122 || (userAnswer > 90 && userAnswer < 97) || userAnswer < 65)
		{
			cout << "입력 오류" << endl;
			i--;
		}
		else if (i < 4)
		{
			cout << "오답! 남은 기회 : " << 4 - i << endl;
			userAnswer > correctAnswer ? cout << "더 앞" << endl : cout << "더 뒤" << endl; // +
		}
		else
		{
			cout << "정답은 " << (char)correctAnswer << endl << "GAME OVER" << endl;
		}
	}
	*/
#pragma endregion

	/*
		10 * 10 크기의 맵을 구성한다. (2차원 배열)
		플레이어( O , 시작(0, 0))가 존재한다.
		탈출지점( E )이 존재한다.
		WASD 키입력을 통해 플레이어를 이동시킨다.
		탈출지점은 (0, 0)을 제외하고 랜덤 설정
		O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료

		#O########
		##########
		##########
		##########
		##########
		##########
		##########
		##########
		########E#
		##########

		화면을 지우는 명령어 : system("cls");
	*/
#pragma region 게임실습
	
	char gameMap[10][10];
	int gameEscape[2];
	int gamePlayerPosition[2] = {0, 0};
	char gameKey;

	// 난수 생성, gameEscape 설정
	// x축
	srand(time(NULL));
	gameEscape[0] = rand();
	srand(time(NULL));
	gameEscape[0] += rand();
	gameEscape[0] %= 10;
	
	// y축
	srand(time(NULL));
	gameEscape[1] = rand();
	srand(time(NULL));
	gameEscape[1] += rand();
	gameEscape[1] %= 10;
	
	// gameEscape = {0, 0} 제외
	while (gameEscape[0] == 0 && gameEscape[1] == 0)
	{
		gameEscape[0] = rand();
		gameEscape[0] %= 10; 
		gameEscape[1] = rand();
		gameEscape[1] %= 10;
	}

	// gameMap 초기화
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			gameMap[j][i] = '#';
		}
	}

	// 탈출지점(gameEscape) 표시
	gameMap[gameEscape[0]][gameEscape[1]] = 'E';

	// 플레이어 위치(gamePlayerPosition) 표시
	gameMap[gamePlayerPosition[0]][gamePlayerPosition[1]] = 'O';

	// 초기화면 표시
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << gameMap[i][j];
		}
		cout << endl;
	}

	// 이동 및 화면 갱신
	while (gamePlayerPosition[0] != gameEscape[0] || gamePlayerPosition[1] != gameEscape[1])
	{
		gameKey = _getch();

		gameMap[gamePlayerPosition[0]][gamePlayerPosition[1]] = '#';
		// 대소문자 무관계 인식
		if (gameKey >= 97 && gameKey <= 122) // ASCII code a = 97, z = 122
		{
			gameKey -= 32;
		}
		bool errBool = 0;
		// 플레이어 위치 변경 (if 문)
		/*if (gameKey == 'W') 
		{
			gamePlayerPosition[1] -= 1;
		}
		else if (gameKey == 'A')
		{
			gamePlayerPosition[0] -= 1;
		}
		else if (gameKey == 'S')
		{
			gamePlayerPosition[1] += 1;
		}
		else if (gameKey == 'D')
		{
			gamePlayerPosition[0] += 1;
		}
		else
		{
			errBool = 1;
		}*/
		// 플레이어 위치 변경 (switch문)
		switch (gameKey)
		{
		case 'W':
			gamePlayerPosition[1] -= 1;
			break;
		case 'A':
			gamePlayerPosition[0] -= 1;
			break;
		case 'S':
			gamePlayerPosition[1] += 1;
			break;
		case 'D':
			gamePlayerPosition[0] += 1;
			break;
		default:
			errBool = 1;
			break;
		}
		
		// 이동 한계 (if문)
		if (gamePlayerPosition[0] > 9)
		{
			gamePlayerPosition[0] -= 1;
			errBool = 1;
		}
		else if (gamePlayerPosition[0] < 0)
		{
			gamePlayerPosition[0] += 1;
			errBool = 1;
		}
		else if (gamePlayerPosition[1] > 9)
		{
			gamePlayerPosition[1] -= 1;
			errBool = 1;
		}
		else if (gamePlayerPosition[1] < 0)
		{
			gamePlayerPosition[1] += 1;
			errBool = 1;
		}

		// 플레이어 위치 업로드
		gameMap[gamePlayerPosition[0]][gamePlayerPosition[1]] = 'O';

		// 화면 갱신
		system("cls");

		// cout << gamePlayerPosition[0] << gamePlayerPosition[1] << endl;

		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				cout << gameMap[i][j];
			}
			cout << endl;
		}
		// 이동 한계 출력
		errBool == 1 ? cout << "이동 불가" << endl : cout << gameKey << endl;
	}

	cout << "탈출에 성공했습니다." << endl;
		
#pragma endregion
}