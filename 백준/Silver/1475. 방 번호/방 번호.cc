#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;
    
    int count[10] = {0}; // 0-9까지 담을 10개의 바구니 준비

    // 1. 각 숫자가 몇 번 쓰이는지 카운팅
    for (char c : N)
    {
        count[c - '0']++; // 문자를 숫자로 변환하여 해당 인덱스의 값을 1 증가
    }

    // 2. 6과 9는 서로 호환되므로 합쳐서 계산
    // 6이 3번, 9가 0번 나오면 총 3번 -> (3+1) / 2 = 2세트 필요
    int six_nine = count[6] + count[9];
    count[6] = (six_nine + 1) / 2;
    count[9] = 0; // 6에 합산했으므로 9는 0으로 초기화

    // 3. 필요한 세트의 최댓값 찾기
    int max_sets = 0;
    for (int i = 0; i < 9; i++)
    {
        if (count[i] > max_sets)
            max_sets = count[i];
    }
    cout << max_sets << endl;
    return 0;
}