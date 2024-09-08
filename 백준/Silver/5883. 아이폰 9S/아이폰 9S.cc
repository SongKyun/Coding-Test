#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;  // 입력받을 정수의 개수
bool check[1000010];  // 각 수의 존재 여부를 확인하기 위한 배열
vector<int> vec;  // 입력된 정수를 저장하는 벡터

// 사람들이 원하는 용량이 0 ~ 1,000,000 이고,
// n의 최댓값이 1000이므로 
// 모든 경우의 수를 확인하더라도
// 최대 1,000,000,000(10억)번의 연산이 필요하다.
// 따라서 이 문제는 일일이 모두 확인하더라도 시간초과가 나지 않는다.

int main()
{
    ios_base::sync_with_stdio(false);  // C++의 입출력 속도를 향상시키기 위한 코드
    cin.tie(0); cout.tie(0);  // 입출력의 묶음을 풀어주는 코드

    cin >> n;  // 정수의 개수 입력
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;  // 입력된 정수를 temp에 저장
        vec.push_back(temp);  // vec 벡터에 입력된 정수 추가
        check[temp] = 1;  // 해당 정수의 존재 여부를 true로 설정
    }

    int ans = 0;  // 최대 연속 부분 수열 길이를 저장하는 변수

    // 사람들이 요구했던 모든 용량 중 하나를 골라
    // 제외한 후 최대 길이를 측정한다.
    for (int i = 0; i < 1000001; i++)  // 0부터 1,000,000까지 모든 가능한 수에 대해 검사
    {
        // 특정 용량(i)을 원하는 사람을 제외한다.
        if (check[i])  // check[i]가 true인 경우, 즉 해당 용량을 원하는 사람이 있을 때만 실행
        {
            int m = vec[0];  // 비교할 기준 정수(m)를 vec의 첫 번째 값으로 초기화
            int m_cnt = 0;  // 연속된 m의 개수를 세는 변수

            for (int j = 0; j < n; j++)  // 입력된 모든 정수에 대해 반복
            {
                if (vec[j] == i) continue;  // 현재 검사 중인 용량(i)와 같은 값은 건너뜀
                if (m == vec[j]) m_cnt++;  // 연속된 같은 값이 나오면 카운트 증가
                else if (m != vec[j])  // 다른 값이 나오면
                {
                    m = vec[j];  // 기준 값을 현재 값으로 변경
                    m_cnt = 1;  // 카운트를 1로 초기화
                }

                ans = max(ans, m_cnt);  // 최대 연속 길이 업데이트
            }
        }
    }

    cout << ans;  // 최대 연속 부분 수열 길이 출력

    return 0;
}
