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

	  srand(time(NULL)); 시간을 매개변수로 seed값 변화시켜 세팅. 4Byte
*/

/*
	실습1. 3 ~ 7 사이의 랜덤한 숫자를 출력하는 프로그램을 작성하자.
	(3, 7 포함)

	실습2. 가장 작은 값과 큰 값을 입력 받아서 그 사이의 임의의 값을 출력하는 프로그램을 작성하자.

	실습3. 프로그램을 실행하면 내부적으로 1 ~ 9 사이의 숫자가 정답으로 정해진다. 유저가 1 ~ 9 사이의 숫자를 입력하면 맞으면 true, 틀리면 false를 출력한다.
*/

/*
	220412
	과제 해설
	#pragma : #pragma region (영역이름) ~ #pragma endregion
	코드의 구역을 나누어, 주석 없이도 접었다폈다 가능

	제어문
		데이터(타입) / 연산자 / <제어구조>

	1. 조건문 : 특정 조건에 따라서 실행문을 실행할지 안할지 제어 : if / switch
	2. 반복문 : 특정 조건에 따라서 실행문을 일정 횟수만큼 반복 실행 제어 : while / for

	조건문
	1_1. if문

	if (조건식1)
	{
		실행문1;
	}
	else if (조건식2)
	{
		실행문2;
	}
	else
	{
		실행문3;
	}

	조건문 실습1.
	정수를 하나 입력 받아서
	입력 받은 숫자가 10보다 크면 "입력된 숫자가 10보다 큽니다." 출력
	10 이하 9 초과 이면 "9보다 큽니다." 출력
	9 이하 6 초과 이면 "6보다 큽니다." 출력
	그 이외에는 "6보다 작거나 같습니다." 출력

	1_2. switch문

	switch (정수형 변수)
	{
		case 정수1:
			실행문1;
		break;
		case 정수2:
			실행문2;
		break;
		case -3:
			실행문3;
		break;
		default:	// 해당하는 정수값이 없을 때. if문의 else 역할
			실행문4;
		break;
	}

	조건문 실습2. switch문 실습
	당신의 고향은 어디입니까?
	1. 서울	2. 양평	3. 광주	4. 대전	5. 제주도
	_1

	안녕하세요. 당신의 고향은 서울이군요.
	안녕하수꽝. 혼저옵서예.
	그 외 : 5개 중에 선택해주세요.

	반복문
	2_1. while문

	while (조건식)
	{
		실행문;
		조건식을 바꾸는 실행문;	// while문을 중단시키는 첫번째 방법, 증감식

		if (조건식)
		{
			break;				// while문을 중단시키는 두번째 방법
		}
	}

	2_2. do-while문

	do							// 실행을 먼저 한 번 하고,
	{
		실행문;
	}
	while (조건식);				// 다시 실행할 지를 판별

	2_3. for문

	for ((1) 초기식; (2) 조건식; (3) 증감식)
	{
		(4) 실행문;
	}

	(1) -> (2) -> (4) -> (3) -> (2) -> (4) -> (3) -> ... 조건식의 값이 0이 나올 때까지
*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
	//220411 내용
	
	#pragma region 실습과제
		// 실습1
		/*
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
	#pragma endregion

		//srand(time(NULL));
		//cout << rand() << endl;
		//(10 > 5) ? std::cout << "10이 5보다 크다." : std::cout << "10이 5보다 작다.";
		//std::cout << std::endl;
		//std::cout << !-300 << std::endl; // 0
		//std::cout << ((10 < 5) == 0) << std::endl; // 1

		//int input_key = 10;
		//std::cout << input_key << input_key++ << std::endl; // 예상 : 1011 결과값 : 1110
		//std::cout << input_key++ << input_key++ << std::endl; // 예상 : 1112 결과값 : 1211
		//std::cout << input_key++ << input_key << std::endl; // 예상 : 1011 결과값 : 1011
		//cout이 블랙박스 상태 => 수의 순서가 바뀌는 이유가 불명, 증감연산 두 번 이어서는 비추천

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
		
	#pragma region 실습1해설
	
		int rand_num;
		// 입력

		// 처리
		srand(time(NULL));
		//rand(); // 0 ~ 32767 % 5

		rand_num = 3 + rand() % 5;
		// 3 + 0, 3 + 1, 3 + 2, 3 + 3, 3 + 4;

		// 출력 - 숫자 하나 출력
		cout << rand_num << endl;
	#pragma endregion

	#pragma region 실습2해설

		// 입력
		int input_min_number;
		int input_max_number;
		cin >> input_min_number;
		cin >> input_max_number;

		// 처리
		rand_num = input_min_number + rand() % (input_max_number - input_min_number + 1);

		// 출력
		cout << rand_num << endl;
		
	#pragma endregion

	#pragma region 실습3해설

		// 입력
		int input_quiz_number;
		cin >> input_quiz_number;

		// 처리
		int correct_number;
		correct_number = 1 + rand() % 9;

		// 출력 : true, false
		(input_quiz_number == correct_number) ? cout << "true" << endl : cout << "false" << endl;
		*/
	#pragma endregion
	
	// #pragma : #pragma region (영역이름) ~ #pragma endregion
	// 코드의 구역을 나누어, 주석 없이도 접었다폈다 가능

#pragma region 조건문실습1
/*
	// 입력
	int input_num;
	cin >> input_num;

	// 처리
	// 출력
	cout << "입력된 숫자가 ";
	if (input_num > 10)
	{
		cout << "10보다 큽니다." << endl;
	}
	else if (input_num > 9)
	{
		cout << "9보다 큽니다." << endl;
	}
	else if (input_num > 6)
	{
		cout << "6보다 큽니다." << endl;
	}
	else
	{
		cout << "6보다 작거나 같습니다." << endl;
	}
	*/
#pragma endregion
	// if 문은 사실 중괄호가 없어도 컴파일링이 가능하다. 두 줄 이상의 코드를 묶어 if문의 안에 넣기 위해 중괄호를 넣는다.
	/*
		if (input_num > 10)
			cout << "10보다 큽니다." << endl; // 실행가능

		if (input_num > 10)
			cout << "10보다 큽니다." << endl; // 이것만 if문 안에 들어감
			cout << "9보다 큽니다." << endl;
	*/

#pragma region 조건문실습2
/*
	cout << "당신의 고향은 어디입니까?\n1. 서울	2. 양평	3. 광주	4. 대전	5. 제주도" << endl;
	// 입력
	int hometown_num;
	cin >> hometown_num;
	cout << endl;

	// 처리
	// 출력
	switch (hometown_num)
	{
	case 1:
		cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
		break;
	case 2:
		cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
		break;
	case 3:
		cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
		break;
	case 4:
		cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
		break;
	case 5:
		cout << "안녕하수꽝. 당신의 고향은 제주도이군요. 혼저옵서예." << endl;
		break;
	default:
		cout << "5개 중에 선택해주세요." << endl;
		break;
	}
	*/
#pragma endregion
	// break; 를 빠트리면 종료되지 않고 다음 경우의 실행문까지 실행된다.

#pragma region 조건문실습2_2
/*
	cout << "당신의 고향은 어디입니까?\n1. 서울	2. 양평	3. 광주	4. 대전	5. 제주도" << endl;
	// 입력
	// int hometown_num;
	cin >> hometown_num;
	cout << endl;

	// 처리
	// 출력
	if (hometown_num == 1)
	{
		cout << "안녕하세요. 당신의 고향은 서울이군요." << endl;
	}
	else if (hometown_num == 2)
	{
		cout << "안녕하세요. 당신의 고향은 양평이군요." << endl;
	}
	else if (hometown_num == 3)
	{
		cout << "안녕하세요. 당신의 고향은 광주이군요." << endl;
	}
	else if (hometown_num == 4)
	{
		cout << "안녕하세요. 당신의 고향은 대전이군요." << endl;
	}
	else if (hometown_num == 5)
	{
		cout << "안녕하수꽝. 당신의 고향은 제주도이군요. 혼저옵서예." << endl;
	}
	else
	{
		cout << "5개 중에 선택해주세요." << endl;
	}
	*/
#pragma endregion

#pragma region 반복문예제while
	// Hello World를 5번 출력하는 프로그램
	/*
	int repeat_count = 0;
	while (repeat_count < 5)
	{
		cout << "Hello World" << endl;
		repeat_count++;
	}

	repeat_count = 0;
	while (1)
	{
		cout << "Hello World" << endl;
		repeat_count++;

		if (repeat_count >= 5)
		{
			break;
		}
	}

	repeat_count = 0;
	do
	{
		cout << "Hello World" << endl;
		repeat_count++;
	}
	while (repeat_count < 5);
	*/
#pragma endregion

#pragma region 실습3
	// while문을 써서 정답을 맞출 때까지 반복되는 프로그램으로 수정해보자.
	/*
	int numMin = 1;
	int numMax = 9;
	int randNum;
	int userAnswer = 0;

	// 난수 생성
	srand(time(NULL));
	randNum = rand();
	srand(time(NULL));
	randNum += rand();
	randNum %= numMax - numMin + 1;
	randNum += numMin;

	// 문제 제시
	cout << "1부터 9까지의 수 중 어느 것일지 맞추시오." << endl;
	cout << "미리보는 정답 : " << randNum << endl;
	cin >> userAnswer;

	// 정답 제시
	while (1)
	{
		cout << boolalpha << "답 : " << userAnswer << " => " << (userAnswer == randNum) << endl;
		
		//(userAnswer != randNum) ? cin >> userAnswer : break;

		if (userAnswer == randNum)
		{
			cout << "정답" << endl;
			break;
		}

		cin >> userAnswer;
	}
	*/
#pragma endregion

#pragma region 반복문예제for
/*
	for (int i = 0; i < 5; i++)
	{
		cout << "Hello World" << endl;
	}
	*/
#pragma endregion

	/*
		for문 실습1.
		10부터 1까지 차례대로 출력되는 코드를 작성해보자.
		10
		9
		...
		1

		실습2.
		100 미만의 3의 배수를 차례대로 출력하는 코드를 작성해보자.
		3
		6
		9
		...
		99

		실습3.
		1000 미만의 2의 승수를 차례대로 출력하는 코드를 작성해보자.
		1
		2
		4
		8
		16
		32
		64
		128
		256
		512

		실습4.
		구구단을 출력해보자.
		4_1. 구구단 2단을 차례대로 출력해보자.
		2 * 1 = 2
		2 * 2 = 4
		2 * 3 = 6
		2 * 4 = 8
		2 * 5 = 10
		2 * 6 = 12
		2 * 7 = 14
		2 * 8 = 16
		2 * 9 = 18
		4_2. 구구단 2 ~ 9단을 차례대로 출력해보자.
		2단

		3단

		4단
		...
		9단
		4_3. 구구단 2단 ~ 9단을 다음과 같은 형태로 출력해보자.
		2단	3단	4단

		5단	6단	7단
		
		8단	9단

		별찍기
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
#pragma region for문실습1
	/*
	for (int i = 10; i > 0; i--)
	{
		cout << i << endl;
	}
	cout << endl;
	*/
#pragma endregion

#pragma region for문실습2
	/*
	for (int i = 3; i < 100; i += 3)
	{
		cout << i << endl;
	}
	cout << endl;
	*/
#pragma endregion

#pragma region for문실습3
	/*
	for (int i = 1; i < 1000; i *= 2)
	{
		cout << i << endl;
	}
	cout << endl;
	*/
#pragma endregion

#pragma region for문실습4
	/*
	// 4_1
	cout << "실습 4_1" << endl << endl;

	for (int i = 1; i < 10; i++)
	{
		cout << 2 << " * " << i << " = " << 2 * i << endl;
	}
	cout << endl;

	// 4_2
	cout << "실습 4_2" << endl << endl;

	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
		cout << endl;
	}
	cout << endl ;

	//4_3
	cout << "실습 4_3" << endl << endl;

	for (int i = 2; i < 9; i += 3)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = i; k < i + 3; k++) {
				if (k > 9) 
				{
					break;
				}
				cout << k << " * " << j << " = " << k * j << "\t"; // 탭(tab) - "\t"
			}
			cout << endl << endl;
		}
		cout << endl;
	}
	*/
#pragma endregion

#pragma region 숙제1
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

#pragma region 숙제2
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

#pragma region 숙제3
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

#pragma region 숙제4
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

#pragma region 숙제5
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

#pragma region 숙제6
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

#pragma region 숙제7
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