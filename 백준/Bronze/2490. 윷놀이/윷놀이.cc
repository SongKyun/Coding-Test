#include <iostream>
using namespace std;

int result, input;
string res = "DCBAE"; // 윷4 걸3 개2 도1 모0 : 배(0)의 개수:내림차순

int main()
{
    // 총 3번의 윷놀이 결과 입력을 반복 처리
    for (int r = 0; r < 3; r++)
    {
        result = 0; // 각 횟수마다 결과를 0으로 초기화
        
        // 윷가락 4개의 값을 입력받고 합산
        for (int c = 0; c < 4; c++)
        {
            cin >> input; // 윷가락 하나의 값 (0 또는 1)을 입력받음
            result += input; // 결과를 누적 합산
        }
        cout << res[result] << '\n'; // 해당 문자를 출력하고 줄바꿈
    }
}