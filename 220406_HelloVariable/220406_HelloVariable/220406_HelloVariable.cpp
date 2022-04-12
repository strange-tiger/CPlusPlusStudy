#include <iostream>
#include <string>

using namespace std; // 네임스페이스 std 선언

int main()
{
	/*
		변수
		1) 이름 : testNum 2) 값 : 2.8 3) 크기 : 4Byte 4) 메모리 주소 : 000000413C50FCC4
	*/
	//float testNum = 2.8f; // float - 소수점 아래 7자리까지. 선언 시 숫자 뒤 f
	//double testNum1 = 2.8; // double - 소수점 아래 15자리까지. default

	//cout << testNum << endl;
	//cout << testNum1 << endl;
	//cout << sizeof(testNum) << endl; // sizeof - 변수 크기
	//cout << &testNum << endl;   // &변수명 - 변수 메모리 주소 - 16진수 16자리, 네 개씩 끊어서
	//cout << sizeof(testNum1) << endl;

	// 실습 1. 상대방 이름과 내 이름, 상대방 나이를 입력 받아서 생일 축하메시지를 출력하는 프로그램을 만들어보자.

	/*
		예시)
			상대방 이름을 입력하세요.
			_김균지

			본인의 이름을 입력하세요.
			입력
			_이진호

			상대방 나이를 입력하세요.
			_29

			이진호 : 김균지님 29살 생일을 축하합니다.
	*/

	/*
		변수명 이름 규칙
		1. C++에서 사용하는 키워드들은 변수명으로 사용할 수 없다.
		2. 알파벳, 숫자, _(언더바)로만 구성할 수 있다.
			예외 1) 숫자로 변수명을 시작할 수는 없다.
		3. 대/소문자 구분을 한다.
		4. 변수명 사이에 띄어쓰기를 넣을 수 없다.
		5. 전부 소문자로 작성한다.
		6. 축약어를 쓰지 않는다.
		- 누가 보더라도 어떤 변수인지 알 수 있도록.
		- 구글에서 제시한 표기법

		헝가리안 표기법
		카멜 표기법
	*/
	/*
	string YourName;
	string MyName;
	int YourAge;

	cout << "상대방 이름을 입력하세요." << endl;
	cin >> YourName;
	cout << "본인의 이름을 입력하세요." << endl;
	cin >> MyName;
	cout << "상대방 나이를 입력하세요." << endl;
	cin >> YourAge;
	
	cout << MyName << " : " << YourName << "님 " << YourAge << "살 생일을 축하합니다." << endl;
	*/
	//C++ 출력 시 주의사항 : 한글, 문자열 등 1바이트를 넘는 내용은 작은 따옴표 안에서 수로 변함.
	//변수명 한 번에 바꾸기 : Ctrl + R + R, OR 우클릭 > 이름바꾸기
	//주석 처리 : Ctrl + K + C, 주석 해제 : Ctrl + K + U
	//자동완성 : Ctrl + Space, 자동정렬 : Ctrl + K + F, 현재 줄 잘라내기 : Ctrl + L
	//대소문자 변환 : 소문자 Ctrl + U, 대문자 Ctrl + Shift + U
	//파일 맨 처음, 맨 끝으로 커서 이동 : 맨 처음 Ctrl + Home, 맨 끝 Ctrl + End

	/*
		연산자
		데이터를 가공(연산)하는 모든 명령에 필요한 것들
		1) 어떤 종류의 연산자들이 있는지?
		2) 우선 순위 : 어떤 순서로 연산이 진행되는지?
		3) 결합 순서 : 좌측부터 연산하는 연산자, 우측부터 연산하는 연산자

		1. 사칙연산 : 산술연산자 (좌측부터 연산)
		+ : 더하기
		- : 빼기
		* : 곱하기
		/ : 나누기		11 / 3 => 3
		% : 나머지		11 % 3 => 2

		*, /, % > +, -
		
		2. 대입연산자 (우측부터 연산)
		= : 왼쪽 항에 오른쪽 항의 값을 대입한다. 복사한다.

		3. 복합대입연산자 
		+= : a += b;	=> a = a + b;
		-= : a -= b;	=> a = a - b;
		*= : a *= b;	=> a = a * b;
		/= : a /= b;	=> a = a / b;
		%= : a %= b;	=> a = a % b; (a와 b는 정수형 타입이어야 한다)

		* 2, 3과 같은 대입연산자를 사용하면 변수의 값을 바꿀 수 있다.
		
		4. 증감연산자
		특정 변수의 값을 1씩 증가시키거나 감소시킬 때 사용한다.
		변수의 앞이나 뒤에 ++ / -- 를 붙여서 사용한다.

		5. 관계연산자
		두 값을 비교한 결과가 참(1, 0 이외의 모든 수, true)인지 거짓(0, false)인지 반환하는 연산자

		< : 왼쪽 항의 값이 오른쪽 항의 값보다 작으면 참을 반환한다.
		> : 왼쪽 항의 값이 오른쪽 항의 값보다 크면 참을 반환한다.
		<= : 왼쪽 항의 값이 오른쪽 항의 값보다 작거나 같으면 참을 반환한다.
		>= : 왼쪽 항의 값이 오른쪽 항의 값보다 크거나 같으면 참을 반환한다.
		== : 왼쪽 항의 값과 오른쪽 항의 값이 같을 때 참을 반환한다.
		!= : 왼쪽 항의 값과 오른쪽 항의 값이 다를 때 참을 반환한다.

	*/

	int left_value = 11 + 3;
	int right_value = 3;

	cout << "+ : " << left_value + right_value << endl;	// 17
	cout << "- : " << left_value - right_value << endl;	// 11
	cout << "* : " << left_value * right_value << endl;	// 42
	cout << "/ : " << left_value / right_value << endl;	// 4	// right_value = 0 -> Runtime Error
	cout << "% : " << left_value % right_value << endl;	// 2

	cout << left_value << " += " << right_value << ", left_value => ";
	left_value += right_value;	
	cout << left_value << endl;	// 17
	//left_value = 14;

	cout << left_value << " -= " << right_value << ", left_value => ";
	left_value -= right_value;
	cout << left_value << endl;	// 14
	//left_value = 14;

	cout << left_value << " *= " << right_value << ", left_value => ";
	left_value *= right_value;
	cout << left_value << endl;	// 42
	//left_value = 14;

	cout << left_value << " /= " << right_value << ", left_value => ";
	left_value /= right_value;
	cout << left_value << endl;	// 14
	//left_value = 14;

	cout << left_value << " %= " << right_value << ", left_value => ";
	left_value %= right_value;
	cout << left_value << endl;	// 2
	//left_value = 14;

	// 특수 : 아래처럼 계산식이어도 괄호로 묶어주면 괄호 안에서 연산이 종료되기에, 출력이 가능하다. 출력은 left_value(계산 결과)
	cout << (left_value += right_value) << endl;	// 5

	left_value++; // 6
	++left_value; // 7

	left_value--; // 6
	--left_value; // 5

	cout << left_value++ << endl;	// 출력 : 5, 메모리 : 6	// 증감연산은 cout 다음으로 수행된다.
	cout << ++left_value << endl;	// 출력 : 7, 메모리 : 7

	cout << left_value-- << endl;	// 출력 : 7, 메모리 : 6
	cout << --left_value << endl;	// 출력 : 5, 메모리 : 5

	/*
		실습.
		고객의 나이를 입력 받아서 미성년자(19세 이하)이면 false를 출력
		성인이면 true를 출력.

		아까 입력 받은 나이를 기준으로, 주민등록증 발급대상(20살만)이면 true를 아니면 false를 출력.

		+아홉수(1의 자리가 9인 수)인지 확인해서 true, false를 출력.
	*/

	int age;

	cout << "나이를 입력하시오." << endl;
	cin >> age;

	cout << "성인 : " << boolalpha << (age > 19) << endl;
	cout << "주민등록증 발급 대상 : " << boolalpha << (age == 20) << endl;
	cout << "아홉수 : " << boolalpha << (age % 10 == 9) << endl;

	// c++에서의 true/false 직접 출력하기 위해서는, cout에서 출력할 변수의 앞에 [ boolalpha << ]를 적어 출력한다.
}