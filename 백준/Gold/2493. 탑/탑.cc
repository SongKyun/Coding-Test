#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 일직선에 N개의 높이가 서로 다른 탑 수평 진선 왼쪽부터 오른쪽 방향 채우기
     * 레이저 신호는 가장 먼저 만나는 단 하나의 탑에서만 수신 가능
     * 6 9 5 7 4
     * 4 -> 7 -> 9
     * 5 -> 9 -> X
     * 6 -> X
     * 탑들의 개수 N
     * 스택으로 69574 입력 시 Top에서부터 -1 위치와 비교해서 이전보다 크면 해당 위치 출력
    */

    int N;
    cin >> N;
    
    stack<pair<int, int>> s; // 탑의 높이, 탑의 번호

    for (int i = 1; i <= N; i++)
    {
        int height;
        cin >> height;

        // 현재 탑보다 낮은 앞선 탑들을 스택에서 제거
        while (!s.empty() && s.top().first < height)
        {
            s.pop();
        }
        // 결과 출력
        if (s.empty())
        {
            cout << 0 << '\n';
        }
        else
        {
            cout << s.top().second << " ";
        }
        s.push({height, i});
    }
    return 0;
}