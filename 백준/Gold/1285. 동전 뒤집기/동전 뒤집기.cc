#include<iostream>
using namespace std;

const int INF = 987654321;  // 큰 값으로 초기화해 최소값 갱신에 사용

// n: 문자열 수, a: 각 문자열을 비트로 변환한 배열, ret: 최소값 저장
int n, a[44], ret = INF;

string s;  // 문자열 입력을 받을 변수

// 백트래킹 함수 - 현재 인덱스 'here'의 상태를 변경하며 최소값 계산
void go(int here)
{
    if (here == n + 1) // 모든 문자열을 처리했을 때
    {
        int sum = 0;      // 각 자리 비트에서 최소 변화 수를 계산하는 변수

        // 각 비트 위치별로 T와 H의 개수를 비교
        for (int i = 1; i <= (1 << (n - 1)); i *= 2)
        {
            int cnt = 0;  // 현재 비트에 대해 T의 개수 카운트

            // 각 문자열의 해당 비트 위치가 T인지 확인
            for (int j = 1; j <= n; j++)
                if (a[j] & i) cnt++;

            // T와 H의 개수 중 작은 값을 더함 (최소로 뒤집어야 하는 개수)
            sum += min(cnt, n - cnt);
        }
        ret = min(ret, sum);  // 최소값 갱신
        return;
    }

    go(here + 1);         // 현재 문자열을 유지하고 다음으로 이동
    a[here] = ~a[here];    // 현재 문자열의 모든 비트를 반전
    go(here + 1);         // 반전한 상태로 다음으로 이동
}

// 메인 함수 - 입력 처리 및 결과 출력
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);   // 입출력 속도 향상

    cin >> n;  // 문자열 수 입력
    for (int i = 1; i <= n; i++)
    {
        cin >> s;    // 문자열 입력
        int value = 1;
        for (int j = 0; j < s.size(); j++)
        {
            // 합 연산자를 통해서 value 를 추가하고 있음
            if (s[j] == 'T') a[i] |= value;  // 'T'인 경우 해당 비트를 1로 설정
            value *= 2;                      // 다음 비트 위치로 이동
        }
    }

    go(1);  // 백트래킹 함수 호출
    cout << ret << "\n";   // 최소 뒤집기 횟수 출력
    return 0;
}