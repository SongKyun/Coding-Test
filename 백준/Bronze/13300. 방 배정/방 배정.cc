#include <iostream>
using namespace std;

int N, K, ans=0;
int s[2][7]{}; // 성별/반별 학생 수 저장 배열

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 학생 수 저장
    cin >> N >> K;
    for (int i =0; i<N; i++)
    {
        int a, b;
        cin >> a >> b;
        s[a][b]++;
    }
    // 필요한 방 개수 계산
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j < 7; j++)
        {
            // 배정에 필요한 만큼 방의 개수 추가
            ans += s[i][j] / K;
            // 학생이 남을 경우, 하나의 방이 더 필요하므로 방의 개수 추가
            if (s[i][j] % K) ++ans;
        }
    }
    cout << ans;
    return 0;
}