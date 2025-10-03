#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;
int A, B, C, D, E, F, G;
int result = 0;
int minOdd = INT_MAX;
int main()
{
    // 7개 자연수
    // 홀수인 자연수 : 합
    cin >> A >> B >> C >> D >> E >> F >> G;
    vector<int> v{A, B, C, D, E, F, G};
    for (int i = 0; i < 7; i++)
    {
        if (v[i] % 2 == 1)
        {
            result += v[i];
            if (v[i] < minOdd)
            {
                minOdd = v[i];
            }
        }
    }
    // 홀수가 없을 시 첫줄에 -1 출력
    if (minOdd == INT_MAX) { cout << -1; }
    else { cout << result << "\n" << minOdd; }
    return 0;
}