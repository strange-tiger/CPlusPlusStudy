#include <iostream>
#include <string>
using namespace std;
// 여기에 구조체 정의
struct score
{
    int kor;
    int eng;
    int math;
};

struct student
{
    string name; // 클래스
    int age; // 기본 자료형
    string homeTown;
    int pride;
    int monthlyScore[12]; // 배열
    score myScore; // 구조체
}seoyeon, jaehyuk; // 중괄호의 끝과 세미콜론 사이에 student의 변수를 미리 선언해 줄 수도 있다.

// name, age, korScore, rank라는 하위 변수를 가지고 있는 student라는 구조체를 정의한다.

int main()
{
    /*
    프로그래밍 기초 ( 메모리, CPU, 디스크 )
    getch()
    구조체
    
    프로그래밍의 종류
    1. 절차적
    2. 구조적
    3. 객체지향적

    ### 추상화 ###
    C언어에서 코드를 추상화하는 데 사용되는 삼총사 : 배열, 구조체, 함수

    추상화란 : 실제 세계( 현상 )를 간략화 / 기호화/ 보편화 해서 표현한 것

    코드에서 추상화가 필요한 이유 : 결국 코드는 사람이 짜는 것이기 때문에,
    다른 사람이 코드를 해석하기 편리해야 하고
    다른 사람이 인수인계 받아서 유지보수하기 편리해야 하고
    다른 사람들과 함께 공동으로 코드를 만들기 편리해야 하고

    - 배열 : 속성이 동일한 여러 개의 데이터를 같은 이름과 순서를 지정한 연속된 번호로
    서로 연관되어 있음을 표시함으로써 추상화함
    변수명[숫자]

    - 구조체 : 데이터(자료형)을 실제로 쓰이는 데이터끼리 묶어서 추상화
    - 함수 : 프로세스(코드)를 특정 기능 단위로 묶어서 추상화

    최악의 추상화 -> 추상화 단계를 상승시키는 과정
    
    string a, b, c; // <- 최악의 추상화
    string a[3]; // <- 위의 것보다는 좀 낫다
    string name1, name2, name3; // <- 아니면 이런 식으로든지
    string studentName[3]; // 위의 것보다 의도가 명료하게 드러나기 때문에 좋은 추상화
    */

    /*
    구조체란
    - 변수를 모아 놓은 집합체
    - 특정 변수들이 무언가의 하위 개념으로 묶일 수 있을 때
    - studentName[10], studentAge[10], studentKorScore[10] ...
    - '학생'의 'XXX'
    - 이름, 나이, 국어점수, 석차 등등을 '학생'이라는 구조체로 묶어서 사용
    
    1. 구조체를 정의하는 위치 : 구조체가 사용되는 함수의 앞에 정의한다.
    ( 해당 함수의 바깥쪽 앞(위))

    2. 구조체 정의의 방법
    struct 구조체 변수명
    {
        구조체 안에 들어갈 하위 변수들 (멤버 변수);
        ( 위의 예시에 따르면 이름, 나이, 국어점수, 석차 등등이 하위 변수다)
    };
    구조체는 일종의 우리가 새롭게 만든 데이터형이다.

    구조체 안에 들어갈 수 있는 하위 변수는 무엇이 있을까
    int, bool, float 같은 기본 자료형들은 모두 사용 가능
    string <- 클래스도 사용 가능
    int a[8] 같은 배열이나 다른 구조체도 사용 가능

    * 중괄호의 끝과 세미콜론 사이에 student의 변수를 미리 선언해 줄 수도 있다.
    * ex)
        struct 구조체 변수명
        {
            멤버 변수;
        }선언할 변수명;

    3. 구조체 선언과 초기화
    기본적으로 구조체 변수의 개념은 배열 변수의 개념과 동일
    int a[3] = {50, 70, 80};
    구조체 변수도 다음과 같이 선언과 동시에 초기화할 수 있다.
    score myScore = { 50, 80, 90 };

    player.HP = player.HP - monster[n].dmg;
    <- 주석 없이 코드를 
    */
    student minseop; // 구조체 변수의 선언
    minseop.name = "심민섭"; // minseop의 name은 "심민섭"이다.
    minseop.age = 34; // minseop의 age는 34이다.
    minseop.homeTown = "인천";
    minseop.pride = 100;
    // 실습 : student 구조체를 사용해서 자기 자신의 정보를 입력해보자.
    student jinho; // 구조체 변수의 선언
    jinho.name = "이진호"; // minseop의 name은 "심민섭"이다.
    jinho.age = 25; // minseop의 age는 34이다.
    jinho.homeTown = "서울";
    jinho.pride = 70;
    cout << jinho.name << endl;
    seoyeon.name = "최서연";

    score myScore = { 50, 80, 90 }; // 배열을 초기화하듯 구조체 변수도 초기화할 수 있다.
    cout << myScore.kor << myScore.eng << myScore.math << endl;

    /* 과제 : 미궁탈출 게임의 업데이트
    사용할 수 있는 모든 요소에 구조체를 활용해서 소스 코드를 개선해 보세요.
    tile : 지형 정보를 넣고 ( 숲, 늪, 평지 )
    player : 피로도
    플레이어가 어느 지형에 있는지, 플레이어의 피로도가 얼마인지 ( 숲 -1, 늪 -3, 평지 0)
    표시되도록 수정해 봅시다.
    */
}