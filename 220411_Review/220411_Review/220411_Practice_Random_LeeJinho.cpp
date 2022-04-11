#include <iostream>
#include <string>

using namespace std;

int main()
{
	// 실습1

	int inputMin1;
	int inputMax1;
	int numRandom1;

	// 변수 초기화
	inputMin1 = 3;
	inputMax1 = 7;
	
	// 난수 생성
	srand(time(NULL));
	numRandom1 = (rand() * rand() - rand() % inputMax1) % 5 + 3;
	
	// 출력
	cout << numRandom1 << endl;

	// 실습2

	int inputMin2;
	int inputMax2;
	int numRandom2;

	// 입력
	cout << "난수 범위 최솟값 입력" << endl;
	cin >> inputMin2;
	cout << "난수 범위 최댓값 입력" << endl;
	cin >> inputMax2;

	// 난수 생성
	srand(time(NULL));
	numRandom2 = (rand() * rand() - rand() % inputMax2) % (inputMax2 - inputMin2 + 1) + inputMin2;
	
	// 출력
	cout << numRandom2 << endl;

	// 실습3

	int numMin = 1;
	int numMax = 9;
	int numRandom3;
	int playerAnswer = 0;

	// 난수 생성
	srand(time(NULL));
	numRandom3 = (rand() * rand() - rand() % numMax) % 9 + 1;
	
	// 문제 제시
	cout << "1부터 9까지의 수 중 어느 것일지 맞추시오." << endl;
	cin >> playerAnswer;

	// 정답 비교
	cout << boolalpha << (playerAnswer == numRandom3) << endl;
}
