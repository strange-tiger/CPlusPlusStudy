// 220414_Study.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
int main()
{
    /*
    콘솔용 탈출게임 10 * 10 크기의 맵을 구성한다.
    (2차원 배열) 플레이어가 존재한다.(0, 0)
    탈출구가 존재한다.(0, 0)을 제외한 랜덤 설정
    WASD 키입력을 통해 플레이어를 이동시킨다.
    플레이어가 탈출구에 도달하면 "탈출 성공" 출력 후 종료
    SYSTEM("cls"); 를 이용해 콘솔 초기화를 사용한다.
    */

    string map[20][20];
    int ex, ey;
    int px, py;
    int wx, wy;
    int mx, my;
    int mx1, my1;
    int mx2, my2;
    int mx3, my3;
    int mmx[4];
    int key[4] = { 0,0,0,0 };
    int chance;
    px = 0; py = 0;
    srand((unsigned int)time(NULL));


    for (int i = 0; i < 20; i++)// 지형 배치
    {
        for (int j = 0; j < 20; j++)
        {
            map[i][j] = "□";
        }
    }
    /*
    for (int i = 0; i < 1000; i++)//벽 배치
    {
        do
        {
            wx = rand() % 20;
            wy = rand() % 20;
        } while (wx == 0 && wy == 0);
        map[wx][wy] = "■";
    }
    */
    do//몬스터 배치1
    {
        mx = rand() % 20;
        my = rand() % 20;
    } while (mx == 0 && my == 0);
    do//몬스터 배치2
    {
        mx1 = rand() % 20;
        my1 = rand() % 20;
    } while (mx1 == 0 && my1 == 0);
    do//몬스터 배치3
    {
        mx2 = rand() % 20;
        my2 = rand() % 20;
    } while (mx2 == 0 && my2 == 0);
    do//몬스터 배치4
    {
        mx3 = rand() % 20;
        my3 = rand() % 20;
    } while (mx3 == 0 && my3 == 0);
    do// 플레이어, 출구 배치
    {
        ex = rand() % 20;
        ey = rand() % 20;
    } while (ex == 0 && ey == 0);

    while (true)
    {
        map[px][py] = "♣";//플레이어 위치를 #에서 ♣로 바꿈
        if (key[0] == 1 || key[0] == 0)
        {
            map[mx][my] = "11";//적 위치를 #에서 ★로 바꿈
        }
        if (key[1] == 1 || key[1] == 0)
        {
            map[mx1][my1] = "22";//적 위치를 #에서 ★로 바꿈
        }
        if (key[2] == 1 || key[2] == 0)
        {
            map[mx2][my2] = "33";//적 위치를 #에서 ★로 바꿈
        }
        if (key[3] == 1 || key[3] == 0)
        {
            map[mx3][my3] = "44";//적 위치를 #에서 ★로 바꿈
        }
        map[ex][ey] = "●";
        system("cls");

        for (int i = 0; i < 20; i++)// 이동마다 초기화 후 맵 다시 깔기
        {
            for (int j = 0; j < 20; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }

        if (px == ex && py == ey && key[0] == 2 && key[1] == 2 && key[2] == 2 && key[3] == 2)// 플레이어와 탈출구의 값이 같으면...
        {
            cout << "탈출 성공!";
            break;
        }

        if ((px == mx && py == my) || (px - 1 == mx && py == my) || (px + 1 == mx && py == my) || (px == mx && py - 1 == my) || (px == mx && py + 1 == my))// 플레이어와 몬스터 값이 같으면...
        {
            cout << "몬스터를 마주쳤다!";
            key[0] = 1;
            for (chance = 1; chance <= 3; chance++) // chance : 미니게임 도전 횟수
            {
                int m_rps = 1 + (rand() % 3); // m_rps : 몬스터가 내는 가위바위보 값 (1 = 바위, 2 = 보, 3 = 가위)

                int u_rps; // u_rps : 유저가 내는 가위바위보 값 (1. 바위 / 2. 보 / 3. 가위)

                cout << "결전의 시간이다! 무엇을 낼지 번호를 입력해보자!" << endl << endl;
                cout << "1. 바위   2. 보   3. 가위" << endl << endl;

                cin >> u_rps;

                if (m_rps != u_rps) // 승, 패가 결정되는 경우 
                {
                    system("cls");

                    for (int i = 0; i < 20; i++)// 이동마다 초기화 후 맵 다시 깔기
                    {
                        for (int j = 0; j < 20; j++)
                        {
                            cout << map[i][j];
                        }
                        cout << endl;
                    }

                    if (u_rps == 1) // 유저가 바위를 낸 경우
                    {
                        if (m_rps == 3) // 몬스터가 가위를 낸 경우
                        {
                            cout << "이겼다! 몬스터를 물리쳤다!" << endl;
                            key[0] = 2;
                            break;
                        }
                        else // 몬스터가 보를 낸 경우
                        {
                            cout << "졌다... 하지만 아직 기회는 " << (3 - chance) << "번 있어!" << endl;
                        }
                    }
                    else if (u_rps == 2) // 유저가 보를 낸 경우
                    {
                        if (m_rps == 1) // 몬스터가 바위를 낸 경우
                        {
                            cout << "이겼다! 몬스터를 물리쳤다!" << endl;
                            key[0] = 2;
                            break;
                        }
                        else // 몬스터가 가위를 낸 경우
                        {
                            cout << "졌다... 하지만 아직 기회는 " << (3 - chance) << "번 있어!" << endl;
                        }
                    }
                    else // 유저가 가위를 낸 경우
                    {
                        if (m_rps == 2) // 몬스터가 보를 낸 경우
                        {
                            cout << "이겼다! 몬스터를 물리쳤다!" << endl;
                            key[0] = 2;
                            break;
                        }
                        else // 몬스터가 바위를 낸 경우
                        {
                            cout << "졌다... 하지만 아직 기회는 " << (3 - chance) << "번 있어!" << endl;
                        }
                    }
                }
                else // 무승부일 경우
                {
                    system("cls");
                    for (int i = 0; i < 20; i++)// 이동마다 초기화 후 맵 다시 깔기
                    {
                        for (int j = 0; j < 20; j++)
                        {
                            cout << map[i][j];
                        }
                        cout << endl;
                    }
                    cout << "무승부다! 다시 승부를 보자!" << endl;

                    chance -= 1;
                }
            }
            map[mx][my] = "□";
            mx = 0; my = 0;
            if (key[0] != 2)
            {
                cout << "game over";
                break;
            }
        }
        if ((px == mx1 && py == my1) || (px - 1 == mx1 && py == my1) || (px + 1 == mx1 && py == my1) || (px == mx1 && py - 1 == my1) || (px == mx1 && py + 1 == my1))// 플레이어와 몬스터1 값이 같으면...
        {
            key[1] = 1;
            cout << "몬스터를 마주쳤다!";
            map[mx1][my1] = "□";
            mx1 = 0; my1 = 0;


            int beskin_p = 0;
            int beskin_m;
            int beskin_num = 0;

            while (1)
            {
                if (beskin_num < 31)
                {
                    if (beskin_num <= 15)
                    {
                        beskin_m = rand() % 3;
                    }
                    /*
                    switch (beskin_num)
                    {
                    case 15: beskin_m = 2;
                        break;
                    case 16: beskin_m = 1;
                        break;
                    case 17: beskin_m = 0;
                        break;
                    case 19: beskin_m = 2;
                        break;
                    case 20: beskin_m = 1;
                        break;
                    case 21: beskin_m = 0;
                        break;
                    case 23: beskin_m = 2;
                        break;
                    case 24: beskin_m = 1;
                        break;
                    case 25: beskin_m = 0;
                        break;
                    case 27: beskin_m = 2;
                        break;
                    case 28: beskin_m = 1;
                        break;
                    case 29: beskin_m = 0;
                        break;
                    }
                   */
                    cout << "컴퓨터 : " << "\t";
                    switch (beskin_m)
                    {
                    case 0: cout << (beskin_num += 1) << endl;
                        break;
                    case 1: cout << (beskin_num += 1) << ", ";
                        cout << (beskin_num += 1) << endl;
                        break;
                    case 2: cout << (beskin_num += 1) << ", ";
                        cout << (beskin_num += 1) << ", ";
                        cout << (beskin_num += 1) << endl;
                        break;
                    }
                }
                else
                {
                    cout << "플레이어 패배\n" << "game over";
                    break;
                }
                if (beskin_num < 31)
                {
                    while (1)
                    {
                        cout << "1 ~ 3 숫자 입력" << endl;
                        cin >> beskin_p;
                        system("cls");
                        for (int i = 0; i < 20; i++)// 이동마다 초기화 후 맵 다시 깔기
                        {
                            for (int j = 0; j < 20; j++)
                            {
                                cout << map[i][j];
                            }
                            cout << endl;
                        }
                        cout << "플레이어 : " << "\t";
                        switch (beskin_p)
                        {
                        case 1: cout << (beskin_num += 1) << endl;
                            break;
                        case 2: cout << (beskin_num += 1) << ", ";
                            cout << (beskin_num += 1) << endl;
                            break;
                        case 3: cout << (beskin_num += 1) << ", ";
                            cout << (beskin_num += 1) << ", ";
                            cout << (beskin_num += 1) << endl;
                            break;
                        }
                        if (beskin_p >= 1 && beskin_p <= 3)
                        {
                            break;
                        }
                    }
                }
                else
                {
                    cout << "컴퓨터 패배";
                    key[1] = 2;
                    break;
                }

            }

        }
        if (key[1] == 1)
        {
            break;
        }
        if ((px == mx2 && py == my2) || (px - 1 == mx2 && py == my2) || (px + 1 == mx2 && py == my2) || (px == mx2 && py - 1 == my2) || (px == mx2 && py + 1 == my2))// 플레이어와 몬스터2 값이 같으면...
        {
            cout << "몬스터를 마주쳤다!";
            key[2] = 1;
            map[mx2][my2] = "□";
            mx2 = 0;
            my2 = 0;
            string u_answer;
            int wrong_answer = 0;
            string quiz[2][10] = {
                                    {
                                        "항상 말다툼이 일어나는 곳은?", "중학생 고등학생만 탈 수 있는 차는?",
                                        "밤낮을 가리지 않고 일하는 것은?", "몸에 해로운 바지는?",
                                        "먹을수록 덜덜 떨게되는 음식은?", "세상에서 가장 빠른 떡은?",
                                        "크면 클수록 가벼워지는 것은?", "왕이 궁에 가기 싫으면 하는 말은?",
                                        "인천앞바다의 반대말은?", "도둑이 훔친 돈을 뭐라고 할까?",
                                    },
                                    {
                                        "경마장", "중고차",
                                        "시계", "유해진",
                                        "추어탕", "헐레벌떡",
                                        "풍선", "궁시렁",
                                        "인천엄마다", "슬그머니",
                                    }
            };

            for (int problem = 0; problem < 10; problem++)
            {
                cout << quiz[0][problem] << endl;
                cin >> u_answer;

                if (u_answer == quiz[1][problem])
                    cout << "흠... 정답을 맞췄군. 제법인데?" << endl;
                else
                {
                    cout << "바보같은 녀석 ㅋㅋㅋ 정답은 " << quiz[1][problem] << "이다." << endl;
                    wrong_answer++;
                }

                if (wrong_answer == 3)
                {
                    cout << "4번이나 틀리다니!!! 너는 탈출할 자격이 없구나!!! 죽어라!!!" << endl;
                    break;
                }
            }
            if (wrong_answer <= 4)
            {
                key[2] = 2;
            }
            else
            {
                break;
            }
        }
        if (key[2] == 1)
        {
            break;
        }
        if ((px == mx3 && py == my3) || (px - 1 == mx3 && py == my3) || (px + 1 == mx3 && py == my3) || (px == mx3 && py - 1 == my3) || (px == mx3 && py + 1 == my3))// 플레이어와 몬스터2 값이 같으면...
        {
            cout << "몬스터를 마주쳤다!\n";
            map[mx3][my3] = "□";
            mx3 = 0; my3 = 0;
            key[3] = 1;
            srand((unsigned int)time(NULL));

            int player_num;
            int monster_num;

            bool p_win = false;
            bool m_win = false;

            int empty = 0;

            int p_row = 0;
            int p_col = 0;
            int m_row = 0;
            int m_col = 0;

            char bingo[3][3];

            for (int i = 0; i < 3; i++) // 필드 넣기
                for (int j = 0; j < 3; j++)
                    bingo[i][j] = 'c';



            for (int i = 0; i < 3; i++) // 필드에 찍기
            {
                for (int j = 0; j < 3; j++)
                    cout << bingo[i][j];
                cout << endl;
            }


            while (1)
            {
                cout << "a : 사용자의 말 | b : 몬스터의 말 | c : 빈칸 " << endl << endl;
                cout << "왼쪽 위부터 0 1 2 이다. 숫자를 넣으시오" << endl;

                cin >> player_num;

                p_row = player_num / 3; // 가로
                p_col = player_num % 3; // 세로

               // cout << p_row << endl;
              //  cout << p_col << endl;

                Sleep(1000);


                if ((bingo[p_row][p_col] == 'c')) // 플레이어 말이 놓을 수 있는가?
                {
                    bingo[p_row][p_col] = 'a'; // 플레이어 말

                    system("cls");

                    for (int i = 0; i < 3; i++) // 플레이어 차례 후 필드 찍기
                    {
                        for (int j = 0; j < 3; j++)
                            cout << bingo[i][j];
                        cout << endl;
                    }

                    cout << "몬스터 차례 " << endl;

                    Sleep(1000);


                    while (1) // 몬스터 말 두기
                    {
                        //srand(time(NULL));
                        monster_num = rand() % 9;

                        m_row = monster_num / 3; // 가로
                        m_col = monster_num % 3; // 세로


                        if (bingo[m_col][m_row] == 'c') // 몬스터가 말을 두려는 곳이 c로 비어있으면
                        {
                            bingo[m_col][m_row] = 'b'; // 말을 둔다
                            break;
                        }
                        else // 안비어있다.
                        {
                            for (int i = 0; i < 3; i++) // 안 비어 있는데 놓을 수 있는 곳도 없어서 나와야 할때
                                for (int j = 0; j < 3; j++)
                                    if (bingo[i][j] == 'c')
                                        empty++;

                            if (empty == 9)
                                break;

                            empty = 0;
                        }


                    }

                    Sleep(1000);

                    system("cls");

                    for (int i = 0; i < 3; i++) // 몬스터 말 놓고 필드 찍기
                    {
                        for (int j = 0; j < 3; j++)
                            cout << bingo[i][j];
                        cout << endl;
                    }

                    // 탐색 후 빙고 됬는 지 출력

                    for (int i = 0; i < 3; i++) // 012 345 789
                        if ((bingo[i][0] == bingo[i][1]) && (bingo[i][1] == bingo[i][2]))
                            if (bingo[i][0] == 'a')
                            {
                                p_win = true;
                            }
                            else if (bingo[i][0] == 'b')
                            {

                                m_win = true;
                            }
                            else // 이경우는 '_'가 되었을 때 즉 _ _ _ 인 경우는 아무것도 안하기
                                ;


                    for (int i = 0; i < 3; i++) // 036 147 258
                        if ((bingo[0][i] == bingo[1][i]) && (bingo[1][i] == bingo[2][i]))
                            if (bingo[0][i] == 'a')
                            {
                                //cout << "빙고! 사용자가 이겼습니다." << endl;
                                p_win = true;
                            }
                            else if (bingo[0][i] == 'b')
                            {
                                //cout << "빙고! 몬스터가 이겼습니다." << endl;
                                m_win = true;
                            }
                            else // 이경우는 '_'가 되었을 때 즉 _ _ _ 인 경우는 아무것도 안하기
                                ;

                    if ((bingo[0][0] == bingo[1][1]) && (bingo[1][1] == bingo[2][2])) // 대각선(\) 로 승리 0 4 8
                        if (bingo[0][0] == 'a')
                            p_win = true;
                        else if (bingo[0][0] == 'b')
                            m_win = true;
                        else
                            ;

                    if ((bingo[0][2] == bingo[1][1]) && (bingo[1][1] == bingo[2][0])) // 대각선(/) 로 승리 246
                        if (bingo[0][2] == 'a')
                            p_win = true;
                        else if (bingo[0][2] == 'b')
                            m_win = true;
                        else
                            ;

                    for (int i = 0; i < 3; i++)
                        for (int j = 0; j < 3; j++)
                            if (bingo[i][j] == 'c')
                                empty++;

                    if (empty == 9) // 무승부 종료
                    {
                        cout << "둘 수 있는 자리가 없습니다. 무승부" << endl;
                        break;
                    }

                    if (p_win)
                    {
                        cout << "빙고! 사용자가 이겼습니다." << endl;
                        key[3] = 2;
                        break;
                    }
                    if (m_win)
                    {
                        cout << "빙고! 몬스터가 이겼습니다." << endl;
                        break;
                    }

                    empty = 0;
                    p_row = 0;
                    p_col = 0;
                    m_row = 0;
                    m_col = 0;
                    // 전체 탐색 후 빈칸 (_) 이 없을 때 무승부로 끝나기.

                }

                else // 플레이어 말을 둘 수 없음 C가 아닌 a나 b가 자리하고 있음
                {
                    empty = 0;
                    p_row = 0;
                    p_col = 0;
                    m_row = 0;
                    m_col = 0;
                    cout << "그곳엔 둘 수 없습니다.";
                }

            }

        }
        if (key[3] == 1)
        {
            cout << "game over";
            break;
        }
        if (key[0] == 0)
        {
            mmx[0] = rand() % 4;

            map[mx][my] = "□";
            switch (mmx[0])//입력받은 키를 토대로 적의 위치값을 변환함
            {
            case 1:
                if (my != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
                {
                    my -= 1;
                }
                break;
            case 2:
                if (mx != 19)
                {
                    mx += 1;
                }
                break;
            case 3:
                if (my != 19)
                {
                    my += 1;
                }
                break;
            case 0:
                if (mx != 0)
                {
                    mx -= 1;
                }
                break;
            }
        }
        if (key[1] == 0)
        {
            mmx[1] = rand() % 4;

            map[mx1][my1] = "□";
            switch (mmx[1])//입력받은 키를 토대로 적의 위치값을 변환함
            {
            case 1:
                if (my1 != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
                {
                    my1 -= 1;
                }
                break;
            case 2:
                if (mx1 != 19)
                {
                    mx1 += 1;
                }
                break;
            case 3:
                if (my1 != 19)
                {
                    my1 += 1;
                }
                break;
            case 0:
                if (mx1 != 0)
                {
                    mx1 -= 1;
                }
                break;
            }
        }
        if (key[2] == 0)
        {
            mmx[2] = rand() % 4;

            map[mx2][my2] = "□";
            switch (mmx[2])//입력받은 키를 토대로 적의 위치값을 변환함
            {
            case 1:
                if (my2 != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
                {
                    my2 -= 1;
                }
                break;
            case 2:
                if (mx2 != 19)
                {
                    mx2 += 1;
                }
                break;
            case 3:
                if (my2 != 19)
                {
                    my2 += 1;
                }
                break;
            case 0:
                if (mx2 != 0)
                {
                    mx2 -= 1;
                }
                break;
            }
        }
        if (key[3] == 0)
        {
            mmx[3] = rand() % 4;

            map[mx3][my3] = "□";
            switch (mmx[3])//입력받은 키를 토대로 적의 위치값을 변환함
            {
            case 1:
                if (my3 != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
                {
                    my3 -= 1;
                }
                break;
            case 2:
                if (mx3 != 19)
                {
                    mx3 += 1;
                }
                break;
            case 3:
                if (my3 != 19)
                {
                    my3 += 1;
                }
                break;
            case 0:
                if (mx3 != 0)
                {
                    mx3 -= 1;
                }
                break;
            }
        }
        int key = _getch();//키를 입력받음 플레이어의 위치값을 #으로 미리 바꿔둠

        map[px][py] = "□";

        if (key < 96)//입력받은 키가 대문자 일때 소문자로 통일시킴
        {
            key += 32;
        }
        switch (key)//입력받은 키를 토대로 플레이어의 위치값을 변환함
        {
        case 97: //a
            if (py != 0)//IF조건을 걸고 맵을 넘어갈 수 없도록 제한
            {
                py -= 1;
            }
            break;
        case 115: //s
            if (px != 19)
            {
                px += 1;
            }
            break;
        case 100: //d
            if (py != 19)
            {
                py += 1;
            }
            break;
        case 119: //w
            if (px != 0)
            {
                px -= 1;
            }
            break;
        default://방향키 이외에 입력은 넘김
            break;
        }

    }
}