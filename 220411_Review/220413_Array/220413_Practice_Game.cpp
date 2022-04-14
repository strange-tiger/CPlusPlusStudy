#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	/*
		�ǽ�3.
		A ~ Z Ű �߿� �ϳ��� �������� �����Ѵ�.
		������ �� ���� Ű�� �Է��ؼ� ������ ���� �����.
		������ �Է��� Ű�� ������ ���� ������ �¸�, ���α׷� ����
		Ʋ���� ���� ��ȸ�� �����ְ�,
		5�� Ʋ���� ������ �˷��ְ� ���ӿ���

		+ Ʋ�� ������ ���� ���ĺ��� �Էµ� ���ĺ� �տ� �ִ���, �ڿ� �ִ��� ��Ʈ�� �ش�.

		+ �Էµ� ���� ��ҹ��� ���о��� ó���� �� �ֵ��� �����غ���.
	*/

#pragma region �ǽ�3

	char keyMin = 'A'; // ASCII code: 65
	char keyMax = 'Z'; // ASCII code: 90
	int correctAnswer = 0;
	char userAnswer;

	// ���� ����
	srand(time(NULL));
	correctAnswer = rand();
	srand(time(NULL));
	correctAnswer += rand();
	correctAnswer %= (int)keyMax - (int)keyMin + 1;
	correctAnswer += (int)keyMin;

	cout << "���ĺ� Ű�� �����ÿ�" << endl;

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
			cout << "�¸�" << endl;
			break;
		}
		else if (userAnswer > 122 || (userAnswer > 90 && userAnswer < 97) || userAnswer < 65)
		{
			cout << "�Է� ����" << endl;
			i--;
		}
		else if (i < 4)
		{
			cout << "����! ���� ��ȸ : " << 4 - i << endl;
			userAnswer > correctAnswer ? cout << "�� ��" << endl : cout << "�� ��" << endl; // +
		}
		else
		{
			cout << "������ " << (char)correctAnswer << endl << "GAME OVER" << endl;
		}
	}

#pragma endregion

	/*
		10 * 10 ũ���� ���� �����Ѵ�. (2���� �迭)
		�÷��̾�( o , ����(0, 0))�� �����Ѵ�.
		Ż������( e )�� �����Ѵ�.
		wasd Ű�Է��� ���� �÷��̾ �̵���Ų��.
		Ż�������� (0, 0)�� �����ϰ� ���� ����
		o�� e�� �����ϸ� "Ż�⿡ �����߽��ϴ�." ���α׷� ����

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

		ȭ���� ����� ��ɾ� : system("cls");
	*/
#pragma region ���ӽǽ�

	char gamemap[10][10];
	int gameescape[2];
	int gameplayerposition[2] = { 0, 0 };
	char gamekey;

	// ���� ����, gameescape ����
	// x��
	srand(time(null));
	gameescape[0] = rand();
	srand(time(null));
	gameescape[0] += rand();
	gameescape[0] %= 10;

	// y��
	srand(time(null));
	gameescape[1] = rand();
	srand(time(null));
	gameescape[1] += rand();
	gameescape[1] %= 10;

	// gameescape = {0, 0} ����
	while (gameescape[0] == 0 && gameescape[1] == 0)
	{
		gameescape[0] = rand();
		gameescape[0] %= 10;
		gameescape[1] = rand();
		gameescape[1] %= 10;
	}

	// gamemap �ʱ�ȭ
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			gamemap[j][i] = '#';
		}
	}

	// Ż������(gameescape) ǥ��
	gamemap[gameescape[0]][gameescape[1]] = 'e';

	// �÷��̾� ��ġ(gameplayerposition) ǥ��
	gamemap[gameplayerposition[0]][gameplayerposition[1]] = 'o';

	// �ʱ�ȭ�� ǥ��
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			cout << gamemap[i][j];
		}
		cout << endl;
	}

	// �̵� �� ȭ�� ����
	while (gameplayerposition[0] != gameescape[0] || gameplayerposition[1] != gameescape[1])
	{
		gamekey = _getch();

		gamemap[gameplayerposition[0]][gameplayerposition[1]] = '#';
		// ��ҹ��� ������ �ν�
		if (gamekey >= 97 && gamekey <= 122) // ascii code a = 97, z = 122
		{
			gamekey -= 32;
		}
		bool errbool = 0;
		// �÷��̾� ��ġ ���� (if ��)
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
		// �÷��̾� ��ġ ���� (switch��)
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

		// �̵� �Ѱ� (if��)
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

		// �÷��̾� ��ġ ���ε�
		gamemap[gameplayerposition[0]][gameplayerposition[1]] = 'o';

		// ȭ�� ����
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
		// �̵� �Ѱ� ���
		errbool == 1 ? cout << "�̵� �Ұ�" << endl : cout << gamekey << endl;
	}

	cout << "Ż�⿡ �����߽��ϴ�." << endl;

#pragma endregion
}