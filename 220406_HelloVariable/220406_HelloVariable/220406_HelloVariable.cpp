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
	//C++ 출력 시 주의사항 : 한글, 문자열 등 1바이트를 넘는 내용은 작은 따옴표 안에서 수로 변함.
	//변수명 한 번에 바꾸기 : Ctrl + R + R, OR 우클릭 > 이름바꾸기
	//주석 처리 : Ctrl + K + C, 주석 해제 : Ctrl + K + U
	//자동완성 : Ctrl + Space, 자동정렬 : Ctrl + K + F, 현재 줄 잘라내기 : Ctrl + L
	//대소문자 변환 : 소문자 Ctrl + U, 대문자 Ctrl + Shift + U
	//파일 맨 처음, 맨 끝으로 커서 이동 : 맨 처음 Ctrl + Home, 맨 끝 Ctrl + End
}