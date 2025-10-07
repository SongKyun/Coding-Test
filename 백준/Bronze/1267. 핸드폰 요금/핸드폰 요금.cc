#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int T[20];

    for (int i = 0; i < N; i++) { cin >> T[i]; } // 각 통화 시간 입력
    
    int M = 0, Y = 0;
    
    for (int i = 0; i < N; i++)
    {
        Y += (T[i] / 30 + 1) * 10;

        M += (T[i] / 60 + 1) * 15;
    }

    if (Y < M) cout << "Y " << Y;
    else if (M < Y) cout << "M " << M;
    else cout <<"Y M "<< Y;
    
    // 더 저렴한 요금제 이름, 요금 출력
    // 같을 경우 영식, 민식, 영식 요금 출력
}