#include <iostream>
#include <conio.h>
using namespace std;

struct Position // { x, y }좌표
{
	int x;
	int y;
}setPosition[50];
// 출구, 플레이어, 종유석, 보석, 아이템, 우물, 랜덤 좌표

struct TypeManual
{
	char player = { 'O' };
	char dark = { '=' };
	char boundary = { '*' };
	char escape = { 'E' };
	char well = { '#' };
	char flat = { ' ' };
	char forest = { '^' };
	char swamp = { '~' };
	char stalactite = { 'T' };
	char jewelry = { 'J' };
	char item = { 'F' };
}typeManual;

struct Player // 플레이어 관련 데이터 구조체
{
	Position position;	// 위치
	int stamina;	// 이동 기회
	int score;	// 획득 점수
	int walk;	// 이동 횟수
	int sight;	// 시야 범위
}player;

struct Tile	// 배치할 오브젝트 구조체
{
	Position position[10];	// 위치
	int count;	// 갯수
	int score[10];	// 점수
	int staminaDecrease; // 피로도
};

struct TileInfo
{
	char show;
}; // gameMap[49][49];

int main()
{
	// 구조체 선언 및 초기화
	Tile sTalactite = { 0 }; // 종유석
	Tile jewelry = { 0 }; // 보석
	Tile item = { 0 }; // 아이템
	Tile forest = { 0 }; // 숲
	forest.staminaDecrease = -2;
	Tile swamp = { 0 }; // 늪
	swamp.staminaDecrease = -3;
	Tile flat = { 0 }; // 평지
	flat.staminaDecrease = -1;
	Tile well = { 0 }; // 우물
	Tile escape = { 0 }; // 출구
	Tile dark = { 0 }; // 암흑

	// 초기설정
	player.position.x = 1;
	player.position.y = 1;
	player.sight = 10; //시야 크기

	char gameMap[49][49] = { typeManual.dark }; //맵 // 맵 최대 사이즈 +2 (경계선) +7 (level3에서의 배열 오버플로우 방지용)
	char gameKey; //입력키
	int inputGameLevel; //난이도 입력
	int gameMapSize = 20; //맵 크기

	int gameJewelryBasicSocre[3] = { 100,200,300 };//보석 기본 점수(여기서 랜덤으로 배정)
	bool gameClear = 1;

	// int plusStamina = 0; // 스테미너 난이도 조절
	forest.count = 10;
	swamp.count = 10;

	// 게임 난이도 설정 // map // sight
	cout << "=================" << endl;
	cout << ">> MINE ESCAPE <<" << endl;
	cout << "=================" << endl;
	do {
		cout << "난이도 입력(1~3): ";
		cin >> inputGameLevel;

		switch (inputGameLevel)
		{
		case 1:
			gameMapSize = 20;
			sTalactite.count = 4;
			jewelry.count = 5;
			//player.sight = 5; // sight
			item.count = 1;
			// plusStamina = 7;
			break;
		case 2:
			gameMapSize = 30;
			sTalactite.count = 7;
			jewelry.count = 7;
			//player.sight = 4; // sight
			item.count = 2;
			// plusStamina = 12;
			break;
		case 3:
			gameMapSize = 40;
			sTalactite.count = 10;
			jewelry.count = 10;
			//player.sight = 3; // sight
			item.count = 6;
			// plusStamina = 22;
			break;
		default:
			cout << "잘못된 입력" << endl;
			break;
		}
	} while (inputGameLevel > 3 || inputGameLevel < 1);

	cout << "로딩중..." << endl;
	srand(time(NULL));
	// 랜덤 좌표 50개 저장
	for (int j = 0; j < 50; j++)
	{
		for (int i = 0; i < 50; i++)
		{
			do {
				setPosition[j].x = rand() % gameMapSize + 1;
				setPosition[j].y = rand() % gameMapSize + 1;
			} while (j != i && (setPosition[j].x == setPosition[i].x && setPosition[j].y == setPosition[i].y));
		}
	}

	for (int i = 0; i < 50; i++)	// 우물을 가운데 영역(3*3등분 기준)에 가능한 한 배치
	{
		if (setPosition[i].x > gameMapSize / 3 && setPosition[i].x < 2 * gameMapSize / 3 &&
			setPosition[i].y > gameMapSize / 3 && setPosition[i].y < 2 * gameMapSize / 3)
		{
			well.position[0].x = setPosition[i].x;
			well.position[0].y = setPosition[i].y;
			for (int j = i; j < 49; j++)
			{
				setPosition[j].x = setPosition[j + 1].x;
				setPosition[j].y = setPosition[j + 1].y;
			}
			setPosition[49].x = 0;
			setPosition[49].y = 0;
			break;
		}
		else if (i == 49)
		{
			well.position[0].x = setPosition[i].x;
			well.position[0].y = setPosition[i].y;
		}
	}

	for (int i = 0; i < 1 + sTalactite.count + jewelry.count + item.count + forest.count + swamp.count; i++)	// 랜덤좌표를 각 요소에 대입 (gameEscapePosition, sTalactite.position, jewelry.position, item.position)
	{
		if (i == 0)
		{
			escape.position[0].x = setPosition[0].x;
			escape.position[0].y = setPosition[0].y;
			// gameMap[escape.position[0].x][escape.position[0].y] = typeManual.escape;
		}
		else if (i >= 1 && i <= sTalactite.count)
		{
			sTalactite.position[i - 1].x = setPosition[i].x;
			sTalactite.position[i - 1].y = setPosition[i].y;
		}
		else if (i > sTalactite.count && i <= sTalactite.count + jewelry.count)
		{
			jewelry.position[i - (sTalactite.count + 1)].x = setPosition[i].x;
			jewelry.position[i - (sTalactite.count + 1)].y = setPosition[i].y;
			//보석 점수 설정
			jewelry.score[i - (sTalactite.count + 1)] = gameJewelryBasicSocre[rand() % 3];
		}
		else if (i > sTalactite.count + jewelry.count && i <= sTalactite.count + jewelry.count + item.count)
		{
			item.position[i - (sTalactite.count + jewelry.count + 1)].x = setPosition[i].x;
			item.position[i - (sTalactite.count + jewelry.count + 1)].y = setPosition[i].y;
		}
		else if (i > sTalactite.count + jewelry.count + item.count && i <= sTalactite.count + jewelry.count + item.count + forest.count)
		{
			forest.position[i - (sTalactite.count + jewelry.count + item.count + 1)].x = setPosition[i].x;
			forest.position[i - (sTalactite.count + jewelry.count + item.count + 1)].y = setPosition[i].y;
		}
		else if (i > sTalactite.count + jewelry.count + item.count + forest.count && i <= sTalactite.count + jewelry.count + item.count + forest.count + swamp.count)
		{
			swamp.position[i - (sTalactite.count + jewelry.count + item.count + forest.count + 1)].x = setPosition[i].x;
			swamp.position[i - (sTalactite.count + jewelry.count + item.count + forest.count + 1)].y = setPosition[i].y;
		}
	}

	// 최소 이동거리
	// player.stamina = (well.x + well.y) + plusStamina;
	player.stamina = 2 * gameMapSize;

	//초기 화면

	// gameMap 초기화
	for (int j = 0; j < gameMapSize + 2; j++) // map
	{
		for (int i = 0; i < gameMapSize + 2; i++) // map
		{
			(i == 0 || j == 0 || i == gameMapSize + 1 || j == gameMapSize + 1) ? gameMap[j][i] = typeManual.boundary : gameMap[j][i] = typeManual.dark; // map
		}
	}

	// 플레이어 위치 업로드
	gameMap[player.position.x][player.position.y] = typeManual.player;

	// 플레이어 시야 지정 // sight
	for (int i = -1 * player.sight; i < player.sight + 1; i++) {
		for (int j = -1 * player.sight; j < player.sight + 1; j++) {
			if (gameMap[player.position.x + i][player.position.y + j] == typeManual.dark)
				gameMap[player.position.x + i][player.position.y + j] = typeManual.flat;
		}
	}

	//우물 위치 지정
	if (gameMap[well.position[0].x][well.position[0].y] == typeManual.flat)
		gameMap[well.position[0].x][well.position[0].y] = typeManual.well;

	// 탈출지점(gameEscape) 지정
	if (gameMap[escape.position[0].x][escape.position[0].y] == typeManual.flat)
		gameMap[escape.position[0].x][escape.position[0].y] = typeManual.escape;

	//종유석 지정
	for (int i = 0; i < sTalactite.count; i++) {
		if (gameMap[sTalactite.position[i].x][sTalactite.position[i].y] == typeManual.flat)
			gameMap[sTalactite.position[i].x][sTalactite.position[i].y] = typeManual.stalactite;
	}

	//보석 지정
	for (int i = 0; i < jewelry.count; i++) {
		if (gameMap[jewelry.position[i].x][jewelry.position[i].y] == typeManual.flat)
			gameMap[jewelry.position[i].x][jewelry.position[i].y] = typeManual.jewelry;
	}

	//아이템 지정
	for (int i = 0; i < item.count; i++) {
		if (gameMap[item.position[i].x][item.position[i].y] == typeManual.flat)
			gameMap[item.position[i].x][item.position[i].y] = typeManual.item;
	}

	//숲 지정
	for (int i = 0; i < forest.count; i++) {
		if (gameMap[forest.position[i].x][forest.position[i].y] == typeManual.flat)
			gameMap[forest.position[i].x][forest.position[i].y] = typeManual.forest;
	}

	//늪 지정
	for (int i = 0; i < swamp.count; i++) {
		if (gameMap[swamp.position[i].x][swamp.position[i].y] == typeManual.flat)
			gameMap[swamp.position[i].x][swamp.position[i].y] = typeManual.swamp;
	}

	// 이동 및 화면 갱신 
	system("cls");
	do
	{
		// 화면 표시
		for (int j = 0; j < gameMapSize + 2; j++) // map
		{
			for (int i = 0; i < gameMapSize + 2; i++) // map
			{
				cout << gameMap[i][j];
			}
			cout << endl;
		}

		//하단 스코어, 스테미나 표시
		cout << "stamina: " << player.stamina << endl;
		cout << "score: " << player.score << endl;
		cout << "walk: " << player.walk << endl;

		gameKey = _getch();

		bool errPosition = 0; // 이동불가 에러 표시용

		// 플레이어 위치 변경 (switch문)
		switch (gameKey)
		{
		case 'W':
		case 'w':
			//끝
			errPosition = player.position.y <= 1;

			if (!errPosition) {
				//종유석 연산
				for (int j = 0; j < sTalactite.count; j++) {
					if ((player.position.y - 1) == sTalactite.position[j].y &&
						player.position.x == sTalactite.position[j].x) {
						//만약 종유석 위치와 겹친다면
						errPosition = true;
						break;
					}
				}
			}

			if (!errPosition) {
				player.position.y -= 1;
				player.stamina--; // 플레이어 스테미너 감산 : 평지
				// 숲, 늪
				for (int i = 0; i < 10; i++) {
					if (player.position.x == forest.position[i].x && player.position.y == forest.position[i].y)
					{
						player.stamina++;
						player.stamina += forest.staminaDecrease;
					}
					else if (player.position.x == swamp.position[i].x && player.position.y == swamp.position[i].y)
					{
						player.stamina++;
						player.stamina += swamp.staminaDecrease;
					}
				}
			player.walk++;
			}
			break;
		case 'A':
		case 'a':
			//끝
			errPosition = player.position.x <= 1;

			if (!errPosition) {
				//종유석 연산
				for (int j = 0; j < sTalactite.count; j++) {
					if (player.position.y == sTalactite.position[j].y &&
						(player.position.x - 1) == sTalactite.position[j].x) {
						//만약 종유석 위치와 겹친다면
						errPosition = true;
						break;
					}
				}
			}

			if (!errPosition) {
				player.position.x -= 1;
				player.stamina--; // 플레이어 스테미너 감산 : 평지
				// 숲, 늪
				for (int i = 0; i < 10; i++) {
					if (player.position.x == forest.position[i].x && player.position.y == forest.position[i].y)
					{
						player.stamina++;
						player.stamina += forest.staminaDecrease;
					}
					else if (player.position.x == swamp.position[i].x && player.position.y == swamp.position[i].y)
					{
						player.stamina++;
						player.stamina += swamp.staminaDecrease;
					}
				}		
				player.walk++;
			}
			break;
		case 'S':
		case 's':
			//끝
			errPosition = player.position.y >= gameMapSize;

			if (!errPosition) {
				//종유석 연산
				for (int j = 0; j < sTalactite.count; j++) {
					if ((player.position.y + 1) == sTalactite.position[j].y &&
						player.position.x == sTalactite.position[j].x) {
						//만약 종유석 위치와 겹친다면
						errPosition = true;
						break;
					}
				}
			}
			if (!errPosition) {
				player.position.y += 1;
				player.stamina--; // 플레이어 스테미너 감산 : 평지
				// 숲, 늪
				for (int i = 0; i < 10; i++) {
					if (player.position.x == forest.position[i].x && player.position.y == forest.position[i].y)
					{
						player.stamina++;
						player.stamina += forest.staminaDecrease;
					}
					else if (player.position.x == swamp.position[i].x && player.position.y == swamp.position[i].y)
					{
						player.stamina++;
						player.stamina += swamp.staminaDecrease;
					}
				}
				player.walk++;
			}
			break;
		case 'D':
		case 'd':
			//끝
			errPosition = player.position.x >= gameMapSize;

			if (!errPosition) {
				//종유석 연산
				for (int j = 0; j < sTalactite.count; j++) {
					if (player.position.y == sTalactite.position[j].y &&
						(player.position.x + 1) == sTalactite.position[j].x) {
						//만약 종유석 위치와 겹친다면
						errPosition = true;
						break;
					}
				}
			}

			if (!errPosition) {
				player.position.x += 1;
				player.stamina--; // 플레이어 스테미너 감산 : 평지
				// 숲, 늪
				for (int i = 0; i < 10; i++) {
					if (player.position.x == forest.position[i].x && player.position.y == forest.position[i].y)
					{
						player.stamina++;
						player.stamina += forest.staminaDecrease;
					}
					else if (player.position.x == swamp.position[i].x && player.position.y == swamp.position[i].y)
					{
						player.stamina++;
						player.stamina += swamp.staminaDecrease;
					}
				}
				player.walk++;
			}
			break;
		default:
			errPosition = 1;
			break;
		}

		//보석 점수 수정
		for (int j = 0; j < jewelry.count; j++) {
			if (player.position.y == jewelry.position[j].y &&
				player.position.x == jewelry.position[j].x) {
				//만약 보석 위치와 겹친다면 보석의 점수 획득
				player.score += jewelry.score[j];
				jewelry.position[j].y = 0;
				jewelry.position[j].x = 0;
				break;
			}
		}

		//아이템 획득(시아 확장)
		for (int i = 0; i < item.count; i++) {
			if (player.position.x == item.position[i].x && player.position.y == item.position[i].y) {
				player.sight++;
				item.position[i].x = NULL;
				item.position[i].y = NULL;
			}
		}

		//우물 접촉(스테미너 회복)
		if (player.position.y == well.position[0].y && player.position.x == well.position[0].x) {
			player.stamina = 2 * gameMapSize; // 초기 스테미너로 회복
		}

		// gameMap 초기화
		for (int j = 0; j < gameMapSize + 2; j++) // map
		{
			for (int i = 0; i < gameMapSize + 2; i++) // map
			{
				(i == 0 || j == 0 || i == gameMapSize + 1 || j == gameMapSize + 1) ? gameMap[j][i] = typeManual.boundary : gameMap[j][i] = typeManual.dark; // map
			}
		}

		// 플레이어 위치 업로드
		gameMap[player.position.x][player.position.y] = typeManual.player;

		// 플레이어 시야 지정 // sight
		for (int i = -1 * player.sight; i < player.sight + 1; i++) {
			for (int j = -1 * player.sight; j < player.sight + 1; j++) {
				if (gameMap[player.position.x + i][player.position.y + j] == typeManual.dark)
					gameMap[player.position.x + i][player.position.y + j] = typeManual.flat;
			}
		}

		//우물 위치 지정
		if (gameMap[well.position[0].x][well.position[0].y] == typeManual.flat)
			gameMap[well.position[0].x][well.position[0].y] = typeManual.well;

		// 탈출지점(gameEscape) 지정
		if (gameMap[escape.position[0].x][escape.position[0].y] == typeManual.flat)
			gameMap[escape.position[0].x][escape.position[0].y] = typeManual.escape;

		//종유석 지정
		for (int i = 0; i < sTalactite.count; i++) {
			if (gameMap[sTalactite.position[i].x][sTalactite.position[i].y] == typeManual.flat)
				gameMap[sTalactite.position[i].x][sTalactite.position[i].y] = typeManual.stalactite;
		}

		//보석 지정
		for (int i = 0; i < jewelry.count; i++) {
			if (gameMap[jewelry.position[i].x][jewelry.position[i].y] == typeManual.flat)
				gameMap[jewelry.position[i].x][jewelry.position[i].y] = typeManual.jewelry;
		}

		//아이템 지정
		for (int i = 0; i < item.count; i++) {
			if (gameMap[item.position[i].x][item.position[i].y] == typeManual.flat)
				gameMap[item.position[i].x][item.position[i].y] = typeManual.item;
		}

		//숲 지정
		for (int i = 0; i < forest.count; i++) {
			if (gameMap[forest.position[i].x][forest.position[i].y] == typeManual.flat)
				gameMap[forest.position[i].x][forest.position[i].y] = typeManual.forest;
		}

		//늪 지정
		for (int i = 0; i < swamp.count; i++) {
			if (gameMap[swamp.position[i].x][swamp.position[i].y] == typeManual.flat)
				gameMap[swamp.position[i].x][swamp.position[i].y] = typeManual.swamp;
		}

		// 이동 한계 출력
		errPosition == 1 ? cout << "이동 불가" << endl : cout << gameKey << "\t" << player.stamina << endl;

		if (player.stamina == 0) // 스테미나 0 되면 게임 오버
		{
			gameClear = 0;
			break;
		}

		// 화면 갱신
		system("cls");

	} while (player.position.x != escape.position[0].x || player.position.y != escape.position[0].y);

	system("cls");
	cout << "====================" << endl;
	gameClear ? cout << "탈출에 성공했습니다." << endl : cout << "탈출에 실패했습니다." << endl;
	cout << "score: " << player.score << endl;
	cout << "walk: " << player.walk << endl;
	cout << "====================" << endl;
}