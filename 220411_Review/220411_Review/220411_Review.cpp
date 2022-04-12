// C++ 문법

// 주석 : 실행 (컴파일) 되지 않고 설명만을 위해서 사용되는 문법
/*

*/


// 220411_Review.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


/*
	C++ 문법을 사용할 때 주의해야 할 점
	1. 대/소문자를 구분해야 한다.

	main / Main / mAIN / maIN

	2. 띄어쓰기를 통해 요소를 구분한다.
	3. 실행문의 마무리는 세미콜론(;)으로 한다.

	[변수] : 변하는 수, 변화를 주고 싶을 때 사용한다. 데이터를 저장할 메모리공간을 할당받는다.
	문법 : 데이터타입 변수명;
	초기화 : 변수를 선언하면서, 동시에 값을 대입.
	데이터타입 변수명 = 10;
	데이터타입 변수명 = 'a';
	데이터타입 변수명 = "Hello";

	데이터타입
	1. 정수형 ( 0, 1, 2, 3, ... , -1, -2, -3, ...)
	 int
	 short
	 long
	 long long
	 __int8, __int16, __int32, __int64
	2. 실수형
	 float
	 double
	 long double
	3. 문자형
	 char
	4. 문자열
	 string

	 변수명 이름짓기 규칙 (표기법)
	 1. 헝가리안 표기법
	  - 데이터타입 약자를 접두어로 붙인다.
	  int nTokenMaxCount = 10;
	 2. 카멜 표기법
	  int tokenMaxCount = 10;
	 3. 파스칼 표기법
	  int TokenMaxCount = 10;

	  구글 가이드라인
	  int token_max_count = 10;

	  안 좋은 예)
	  int nn = 10;
	  int cmprs = 20;

	  문법적 표기법
	  1. 대소문자를 구분한다.
	  2. 알파벳, 숫자, _(언더바)만 사용한다.
		2-1. 숫자는 가장 앞에 올 수 없다.

	  변수의 4가지 속성
	  1) 이름 : input_key    2) 크기 : 4byte   3) 값 : 10    4) 메모리주소 : &input_key = 000000D6BB17FA54 (16진수 총 16자리)

	  연산자
	  데이터를 가공(연산)하는 모든 명령에 필요한 것들
	  1) 어떤 종류의 연산자인가
	  2) 우선순위 : 어떤 순서로 연산이 되는가
	  3) 결합순서 : 좌측부터 연산하는가, 우측부터 연산하는가

	  1. 사칙연산 : 산술연산자 (좌측부터 연산된다)
	  + : 더하기
	  - : 빼기
	  * : 곱하기
	  / : 나누기 11 / 3 -> 3 (몫)
	  % : 나머지 11 % 3 -> 2 (나머지)

	  *, /, % > +, -

	  2. 대입연산자 (우측부터 연산된다)
	  = : 왼쪽 항에 오른쪽 항의 값을 대입(복사)한다.

	  3. 복합대입연산자
	  += : a += b;	-> a = a + b;
	  -= : a -= b;	-> a = a - b;
	  *= : a *= b;	-> a = a * b;
	  /= : a /= b;	-> a = a / b;	(b == 0, 런타임에러 발생)
	  %= : a %= b;	-> a = a % b;	(데이터타입이 정수형이 아닐 때)

	  4. 증감연산자
	  특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용하는 연산자.
	  변수명 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

	  5. 관계연산자
	  두 항의 값을 비교한 결과가 참(1, 0 이외, true) 또는 거짓(0, false)으로 반환되는 연산자

	  a < b
	  a > b
	  a <= b
	  a >= b
	  a == b
	  a != b

	  6. 논리연산자
	  왼쪽 항과 오른쪽 항의 값을 각각 참과 거짓으로 연산해서 두 값을 비교하여 참과 거짓을 반환하는 연산자

	  && : 논리곱(AND)
	  a && b : a의 결과값이 참이고 b의 결과값이 참이면 1을 반환

	  || : 논리합(OR)
	  a || b : a의 결과값이 참이거나 b의 결과값이 참이면 1을 반환

	  ! : 논리부정(NOT)
	  !a : a의 결과값이 참이면 거짓을 반환, 거짓이면 참을 반환

	  7. 삼항연산자
	  a ? b : c;
	  a의 결과값이 참이면 b실행문이 동작, 거짓이면 c실행문이 동작.

	  난수 (랜덤값)
	  rand();	// 0 ~ 32767 사이의 랜덤한 정수값이 반환된다. 32768 = 2^15, 2Byte
	  함수 내부에 seed값이 있어서 이 값에 의해서 리턴값이 정해진다.
	  기본적으로 seed : 1로 세팅되어 있다.

	  srand(time(NULL)); 시간을 매개변수로 seed값 변화시켜 세팅.
*/

/*
	실습1. 3 ~ 7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자.
	(3, 7 포함)

	실습2. 가장 작은 값과 큰 값을 입력 받아서 그 사이의 임의의 값을 출력하는 프로그램을 작성하자.

	실습3. 프로그램을 실행하면 내부적으로 1 ~ 9 사이의 숫자가 정답으로 정해진다. 유저가 1 ~ 9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false를 출력한다.
*/

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
	numRandom1 = rand();
	srand(time(NULL));
	numRandom1 += rand();
	numRandom1 %= 5;
	numRandom1 += 3;
	
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
	numRandom2 = rand();
	srand(time(NULL));
	numRandom2 += rand();
	numRandom2 %= inputMax2 - inputMin2 + 1;
	numRandom2 += inputMin2;

	// 출력
	cout << numRandom2 << endl;

	// 실습3

	int numMin = 1;
	int numMax = 9;
	int numRandom3;
	int playerAnswer = 0;

	// 난수 생성
	srand(time(NULL));
	numRandom3 = rand();
	srand(time(NULL));
	numRandom3 += rand();
	numRandom3 %= numMax - numMin + 1;
	numRandom3 += numMin;

	// 문제 제시
	cout << "1부터 9까지의 수 중 어느 것일지 맞추시오." << endl;
	cin >> playerAnswer;

	// 정답 비교
	cout << boolalpha << (playerAnswer == numRandom3) << endl;

	//srand(time(NULL));
	//cout << rand() << endl;
	//(10 > 5) ? std::cout << "10이 5보다 크다." : std::cout << "10이 5보다 작다.";
	//std::cout << std::endl;

	//std::cout << !-300 << std::endl; // 0

	//std::cout << ((10 < 5) == 0) << std::endl; // 1

	//int input_key = 10;
	//
	///*
	//std::cout << input_key << input_key++ << std::endl; // 예상 : 1011 결과값 : 1110
	//std::cout << input_key++ << input_key++ << std::endl; // 예상 : 1112 결과값 : 1211
	//std::cout << input_key++ << input_key << std::endl; // 예상 : 1011 결과값 : 1011
	//cout이 블랙박스 상태 => 수의 순서가 바뀌는 이유가 불명, 증감연산 두 번 이어서는 비추천
	//*/

	//std::cout << &input_key << std::endl;	// 메모리주소
	//std::cout << input_key++ << std::endl;	// 10	증감연산은 cout 다음으로 수행된다. 
	//std::cout << ++input_key << std::endl;	// 12
	//std::cout << input_key-- << std::endl;	// 12
	//std::cout << --input_key << std::endl;	// 10

	//float testFloat = 5.3f;
	//float testFloat2 = 5.3;
	//char testCharacter = 'a';
	//std::string testString = "Hello";


	//std::cout << "Hello World!\n";
	//std::cin >> input_key;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
