#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;  // 무한대를 나타내는 큰 값으로 초기 최소 비용을 설정하기 위한 상수
int n, mp, mf, ms, mv;      // n: 식재료 개수, mp: 목표 단백질, mf: 목표 지방, ms: 목표 탄수화물, mv: 목표 비타민
int b, c, d, e, ret = INF, sum;  // b, c, d, e: 각각 단백질, 지방, 탄수화물, 비타민 합산 값, ret: 최소 비용, sum: 현재 조합의 비용

// 5 가지의 값을 담는 구조체
struct A
{
    int mp, mf, ms, mv, cost;  // 각각 단백질, 지방, 탄수화물, 비타민, 비용을 나타냄
}a[16]; // 문제의 범위를 보고 최대 16개의 식재료를 받을 수 있도록 배열 설정

map<int, vector<vector<int>>> ret_v;  // 최소 비용이 같은 여러 조합을 저장하는 맵. 키는 비용, 값은 그 비용에 해당하는 조합의 벡터들.

int main()
{
    cin >> n;            // 식재료의 개수 입력
    cin >> mp >> mf >> ms >> mv;  // 목표로 해야 할 각 영양소의 최소값 입력

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].mp >> a[i].mf >> a[i].ms >> a[i].mv >> a[i].cost;  // 각 식재료의 영양소 값 및 비용 입력
    }

    // 모든 가능한 조합을 순회하기 위한 부분 (부분 집합 순회)
    for (int i = 1; i < (1 << n); i++)  // 1부터 (2^n - 1)까지 즉, 각 식재료를 사용하는 경우의 수를 순회
    {
        b = c = d = e = sum = 0;  // 각 영양소와 비용 합을 초기화
        vector<int> v;  // 현재 조합에 포함된 식재료들의 번호를 저장할 벡터

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))  // i의 j번째 비트가 1이면 해당 식재료를 선택한 것
            {
                v.push_back(j + 1);  // 식재료 번호는 1부터 시작하므로 j + 1을 벡터에 추가
                b += a[j].mp;        // 단백질 합산
                c += a[j].mf;        // 지방 합산
                d += a[j].ms;        // 탄수화물 합산
                e += a[j].mv;        // 비타민 합산
                sum += a[j].cost;    // 비용 합산
            }
        }

        // 목표치 이상으로 영양소를 충족시키는지 확인
        if (b >= mp && c >= mf && d >= ms && e >= mv)
        {
            // 현재까지의 최소 비용보다 작거나 같으면 업데이트
            if (ret >= sum)
            {
                ret = sum;  // 최소 비용 갱신
                ret_v[ret].push_back(v);  // 해당 비용에 대한 조합을 맵에 저장
            }
        }
    }

    // 가능한 조합이 없는 경우
    if (ret == INF)
        cout << -1 << '\n';  // 어떤 조합도 목표치를 충족시키지 못하면 -1 출력
    else
    {
        // 가능한 비용이 여러 개인 경우 사전순으로 가장 앞서는 것을 출력하기 위해 정렬
        sort(ret_v[ret].begin(), ret_v[ret].end());
        cout << ret << "\n";  // 최소 비용 출력
        for (int a : ret_v[ret][0])  // 가장 사전순으로 앞서는 조합 출력
        {
            cout << a << " ";  // 식재료 번호 출력
        }
    }

    return 0;
}
