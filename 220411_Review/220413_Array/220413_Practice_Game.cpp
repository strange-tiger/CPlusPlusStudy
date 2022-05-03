#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
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

#pragma endregion

	/*
		10 * 10 크기의 맵을 구성한다. (2차원 배열)
		플레이어( o , 시작(0, 0))가 존재한다.
		탈출지점( e )이 존재한다.
		wasd 키입력을 통해 플레이어를 이동시킨다.
		탈출지점은 (0, 0)을 제외하고 랜덤 설정
		o가 e에 도달하면 "탈출에 성공했습니다." 프로그램 종료

		#o########
		##########
		##########
		##########
		##########
		##########
		##########
		##########
		########e#
		##########

		화면을 지우는 명령어 : system("cls");
	*/
#pragma region 게임실습

	char gamemap[10][10];
	int gameescape[2];
	int gameplayerposition[2] = { 0, 0 };
	char gamekey;

	// 난수 생성, gameescape 설정
	// x축
	srand(time(null));
	gameescape[0] = rand();
	srand(time(null));
	gameescape[0] += rand();
	gameescape[0] %= 10;

	// y축
	srand(time(null));
	gameescape[1] = rand();
	srand(time(null));
	gameescape[1] += rand();
	gameescape[1] %= 10;

	// gameescape = {0, 0} 제외
	while (gameescape[0] == 0 && gameescape[1] == 0)
	{
		gameescape[0] = rand();
		gameescape[0] %= 10;
		gameescape[1] = rand();
		gameescape[1] %= 10;
	}

	// gamemap 초기화
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			gamemap[j][i] = '#';
		}
	}

	// 탈출지점(gameescape) 표시
	gamemap[gameescape[0]][gameescape[1]] = 'e';

	// 플레이어 위치(gameplayerposition) 표시
	gamemap[gameplayerposition[0]][gameplayerposition[1]] = 'o';

	// 초기화면 표시
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << gamemap[i][j];
		}
		cout << endl;
	}

	// 이동 및 화면 갱신
	while (gameplayerposition[0] != gameescape[0] || gameplayerposition[1] != gameescape[1])
	{
		gamekey = _getch();

		gamemap[gameplayerposition[0]][gameplayerposition[1]] = '#';
		// 대소문자 무관계 인식
		if (gamekey >= 97 && gamekey <= 122) // ascii code a = 97, z = 122
		{
			gamekey -= 32;
		}
		bool errbool = 0;
		// 플레이어 위치 변경 (if 문)
		/*if (gamekey == 'w')
		{
			gameplayerposition[1] -= 1;
		}
		else if (gamekey == 'a')
		{
			gameplayerposition[0] -= 1;
		}
		else if (gamekey == 's')
		{
			gameplayerposition[1] += 1;
		}
		else if (gamekey == 'd')
		{
			gameplayerposition[0] += 1;
		}
		else
		{
			errbool = 1;
		}*/
		// 플레이어 위치 변경 (switch문)
		switch (gamekey)
		{
		case 'W':
			gameplayerposition[1] -= 1;
			break;
		case 'A':
			gameplayerposition[0] -= 1;
			break;
		case 'S':
			gameplayerposition[1] += 1;
			break;
		case 'D':
			gameplayerposition[0] += 1;
			break;
		default:
			errbool = 1;
			break;
		}

		// 이동 한계 (if문)
		if (gameplayerposition[0] > 9)
		{
			gameplayerposition[0] -= 1;
			errbool = 1;
		}
		else if (gameplayerposition[0] < 0)
		{
			gameplayerposition[0] += 1;
			errbool = 1;
		}
		else if (gameplayerposition[1] > 9)
		{
			gameplayerposition[1] -= 1;
			errbool = 1;
		}
		else if (gameplayerposition[1] < 0)
		{
			gameplayerposition[1] += 1;
			errbool = 1;
		}

		// 플레이어 위치 업로드
		gamemap[gameplayerposition[0]][gameplayerposition[1]] = 'o';

		// 화면 갱신
		system("cls");

		// cout << gameplayerposition[0] << gameplayerposition[1] << endl;

		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				cout << gamemap[i][j];
			}
			cout << endl;
		}
		// 이동 한계 출력
		errbool == 1 ? cout << "이동 불가" << endl : cout << gamekey << endl;
	}

	cout << "탈출에 성공했습니다." << endl;

#pragma endregion
}