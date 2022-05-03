#include <iostream>
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10
//using namespace std;

int main()
{

#pragma region 과제2

	/*
	콘솔형 탈출게임
	10 * 10 크기의 맵을 구상한다. (2차원 배열)
	플레이어(0,0)가 존재한다.
	탈출지점이 존재한다.
	wasd 키입력을 통해 플레이어를 이동시킨다.
	탈출지점은 (0,0)을 제외하고 랜덤 설정
	O가 E에 도달하면 "탈출에 성공했습니다." 프로그램 종료


	#O########
	##########
	##########
	##########
	##########
	##########
	##########
	######E###
	##########
	##########		#:벽 O:플레이어 E: 탈출지점

	system("cls"); -콘솔창 갱신
*/

	srand(time(NULL));

	char map[MAP_SIZE][MAP_SIZE];
	int stageCount = 0;
	int monsterCount = 0;
	int monsterX[50]; int monsterY[50]; int monsterHp = 50;
	int playerX; int playerY;  int playerHP = 10; int dice = 0;
	int potionCount = 0; int dropPotionCount; int dropPotionX = -1; int dropPotionY = -1;
	int exitX; int exitY;
	int inputKey;
	bool checkLoop;
	int dummy = 0;




#pragma region LoadingScreen
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■□□□□□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■□□□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■□□□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G" << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■□□□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■□□□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■□□□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■□□□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  " << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■□□□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■□□□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■■■□□□" << "\n\n" << std::endl;
	Sleep(500);
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\t\tN  O  W     L  O  A  D  I  N  G  .  .  ." << "\n\n" << std::endl;
	std::cout << "\t■■■■■■■■■■■■■■■■■■■■■■■" << "\n\n" << std::endl;
	system("cls");
	Sleep(500);
#pragma endregion


#pragma region Maintitle
	std::cout << "                                ■■■      ■" << std::endl;
	std::cout << "                                ■    ■    ■" << std::endl;
	std::cout << "                                ■    ■    ■" << std::endl;
	std::cout << "                                ■■■      ■" << std::endl;
	std::cout << "  ■■■■■      ■■■■■          ■          ■■■■■      ■      ■" << std::endl;
	std::cout << "  ■                  ■            ■  ■        ■              ■    ■" << std::endl;
	std::cout << "  ■■■■■          ■            ■■■        ■              ■■■" << std::endl;
	std::cout << "          ■          ■          ■      ■      ■              ■    ■" << std::endl;
	std::cout << "  ■■■■■          ■          ■      ■      ■■■■■      ■      ■" << std::endl;
	std::cout << "\n\n\n\n\n\n\n\t\t\t\t -   Press  Any  Key   -" << std::endl;
	dummy = _getch();
#pragma endregion



	while (playerHP > 0) {

		system("cls");
		//맵 생성
		for (int i = 0; i < MAP_SIZE; i++) {
			for (int j = 0; j < MAP_SIZE; j++) {
				map[i][j] = ' ';
			}
		}
		//변수 초기화
		checkLoop = 1;
		playerX = 0; playerY = 0;
		stageCount++;
		monsterCount = stageCount;
		exitX = rand() % (MAP_SIZE - 1) + 1; exitY = rand() % (MAP_SIZE - 1) + 1;
		playerHP += stageCount / 2;

		map[playerY][playerX] = 'O';
		map[exitY][exitX] = 'E';
		// 몬스터 생성
		for (int i = stageCount; i > 0; i--) {
			monsterX[i] = rand() % (MAP_SIZE - 1) + 1; monsterY[i] = rand() % (MAP_SIZE - 1) + 1;
			if (map[monsterY[i]][monsterX[i]] != ' ')
				i++;
			else
				map[monsterY[i]][monsterX[i]] = 'M';
		}
		//포션 생성
		dropPotionCount = rand() % 2;
		if (dropPotionCount > 0)
		{
			for (int i = dropPotionCount; i > 0; i--) {
				dropPotionX = rand() % (MAP_SIZE - 1) + 1; dropPotionY = rand() % (MAP_SIZE - 1) + 1;
				if (map[dropPotionY][dropPotionX] != ' ')
					i++;
				else
					map[dropPotionY][dropPotionX] = 'P';
			}
		}

		//stage 시작





		std::cout << "\n\n\n\n\n\n\n\n\tS  T  A  G  E\n\n\n\t      " << stageCount << std::endl;
		Sleep(2000);

		while (checkLoop == 1)
		{
			//화면 초기화후 맵표시
			system("cls");

			std::cout << "조작키 : wasd	O : 플레이어	P : 포션\n포션   : 2	E : 탈출지점	M : 몬스터\n" << std::endl;

			map[exitY][exitX] = 'E';				//화면에 탈출구 표시
			for (int i = stageCount; i > 0; i--)	//화면에 몬스터 표시
				map[monsterY[i]][monsterX[i]] = 'M';

			//화면에 맵 표시
			std::cout << "▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒" << std::endl;
			for (int i = 0; i < MAP_SIZE; i++) {
				std::cout << "▒ ";
				for (int j = 0; j < MAP_SIZE; j++) {
					std::cout << map[i][j] << " ";
				}
				std::cout << "▒" << std::endl;
			}
			std::cout << "▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒ ▒" << std::endl;
			//상태 표시
			std::cout << "\n현재 " << stageCount << "층 입니다." << std::endl;
			std::cout << "남은 몬스터 수 : " << monsterCount << std::endl;
			std::cout << "HP : " << playerHP << std::endl;
			std::cout << "남은 포션 : " << potionCount << std::endl;

			//플레이어 이전 위치 값 초기화
			map[playerY][playerX] = ' ';
			//플레이어 행동
			switch (inputKey = _getch())
			{
			case 'w':
				if ((map[playerY - 1][playerX] == '#') || (playerY - 1 < 0))
					playerY = playerY;

				else
					playerY -= 1;

				break;

			case 'a':

				if ((map[playerY][playerX - 1] == '#') || (playerX - 1 < 0))
					playerX = playerX;

				else
					playerX -= 1;

				break;

			case 's':

				if ((map[playerY + 1][playerX] == '#') || (playerY + 1 > MAP_SIZE - 1))
					playerY = playerY;

				else
					playerY += 1;

				break;


			case 'd':

				if ((map[playerY][playerX + 1] == '#') || (playerX + 1 > MAP_SIZE - 1))
					playerX = playerX;

				else
					playerX += 1;

				break;
			case '2': //포션 사용
				if (potionCount > 0) {
					playerHP += 5;
					potionCount--;
				}
				else {
					std::cout << "남은 포션이 없습니다." << std::endl;
					continue;
				}
				break;
			default:
				continue;
			}

			for (int i = monsterCount; i > 0; i--) {
				map[monsterY[i]][monsterX[i]] = ' ';
			}

			//몬스터 조우 확인
			for (int i = stageCount; i > 0; i--) {
				if ((playerX == monsterX[i]) && (playerY == monsterY[i])) {

					//전투
					for (int text = 1; text <= 2; text++)
					{
						system("cls");
						for (int time = 0; time <= 1005000000; time++)
						{
							int demo = 1;
						}
						std::cout << "  ■■■                                   ■          " << std::endl;
						std::cout << "  ■   ■                                  ■          " << std::endl;
						std::cout << "  ■   ■                 ■        ■     ■   ■■■■   " << std::endl;
						std::cout << "  ■■■    ■■       ■■■■  ■■■■  ■ ■       ■  " << std::endl;
						std::cout << "  ■   ■ ■   ■■       ■        ■     ■ ■■■■■■  " << std::endl;
						std::cout << "  ■   ■ ■   ■■       ■        ■     ■ ■       " << std::endl;
						std::cout << "  ■■■    ■■■ ■■    ■■      ■■  ■  ■■■■■  " << std::endl;
						for (int time = 0; time <= 1005000000; time++)
						{
							int demo = 1;
						}

					}
					while (monsterHp > 0 && playerHP > 0)
					{


						system("cls");
						std::cout << "공격 : 1	포션 : 2\n\n" << std::endl;
						std::cout << "몬스터" << "\t\t\t플레이어" << "\n" << std::endl;
						std::cout << "체력 : " << monsterHp << "\t\t체력 : " << playerHP << std::endl;
						std::cout << "\t\tVS\t주사위 : " << dice + 1 << std::endl;
						std::cout << "\t\t\t남은 포션 : " << potionCount << std::endl;
						if (dice == 0)
						{
							std::cout << "\n\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
						}
						else if (dice == 1)
						{
							std::cout << "\n\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
						}
						else if (dice == 2)
						{
							std::cout << "\n\t\t\t □□■ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t ■□□ " << std::endl;
						}
						else if (dice == 3)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t □□□ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}
						else if (dice == 4)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t □■□ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}
						else if (dice == 5)
						{
							std::cout << "\n\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
							std::cout << "\t\t\t ■□■ " << std::endl;
						}


						switch (inputKey = _getch())
						{
						case '1': //공격
							dice = rand() % 6;
							monsterHp -= dice * 10;
							break;
						case '2': //포션 사용
							if (potionCount > 0) {
								playerHP += 5;
								potionCount--;
							}
							else {
								std::cout << "남은 포션이 없습니다." << std::endl;
								continue;
							}
							break;

						default:
							continue;
						}

						if (monsterHp > 0) {
							playerHP -= rand() % 2 + 1;
						}
					}
					monsterCount--;
					monsterHp = 50;
					monsterX[i] = -1;
					monsterY[i] = -1;
				}
			}
			//포션 획득
			if (playerX == dropPotionX && playerY == dropPotionY) {
				potionCount++;
				dropPotionCount--;
				map[dropPotionY][dropPotionX] = ' ';
				dropPotionX = -1;
				dropPotionY = -1;
			}

			//탈출구 도착 행동종료 종료
			if (((playerX == exitX) && (playerY == exitY)) && monsterCount == 0)
				checkLoop = 0;
			//플레이어 사망 while문 종료
			if (playerHP <= 0) {
				system("cls");
				std::cout << "      ■■■■■■■           ■■         ■                ■ ■■■■■■■■■■" << std::endl;
				std::cout << "  ■■              ■       ■    ■       ■■            ■■ ■                  " << std::endl;
				std::cout << "  ■■■■■■■■         ■■■■■■     ■  ■        ■  ■ ■■■■■■■■■■" << std::endl;
				std::cout << "  ■■    ■■    ■     ■            ■   ■    ■    ■    ■ ■                  " << std::endl;
				std::cout << "      ■■          ■ ■                ■ ■      ■■      ■ ■■■■■■■■■■" << std::endl;
				std::cout << "\n\n" << std::endl;
				std::cout << "\n\n" << std::endl;
				std::cout << "      ■■■■■■     ■                ■ ■■■■■■■■■■ ■■■■■■■■■    " << std::endl;
				std::cout << "    ■            ■     ■            ■   ■                   ■                ■  " << std::endl;
				std::cout << "  ■                ■     ■        ■     ■■■■■■■■■■ ■■■■■■■■■    " << std::endl;
				std::cout << "    ■            ■         ■    ■       ■                   ■  ■■■■          " << std::endl;
				std::cout << "      ■■■■■■             ■■         ■■■■■■■■■■ ■          ■■■■  " << std::endl;
				dummy = _getch();
				checkLoop = 0;
			}
			//현재 플레이어 위치 표시
			map[playerY][playerX] = 'O';

		}

	}
	//프로그램 종료
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\t\t\t\t" << stageCount << "스테이지까지 클리어 하셨습니다.\n\n\n\n\n" << std::endl;
}
