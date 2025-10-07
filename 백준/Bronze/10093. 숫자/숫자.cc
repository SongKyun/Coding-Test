#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 1. 2개 양의 정수 A B
    long long A, B;
    cin >> A >> B;
    // 2. A와 B 둘 중 누가 더 큰지 판별
    int big = max(A, B);
    int small = min(A, B);
    // 3. 예외 처리
    if (A == B) {   cout << 0 << "\n"; return 0;}
    // 4. 두 수 사이의 개수
    int diff = big - small - 1;
    // 5. 사이의 수를 벡터에 저장
    vector<long long> v;
    for (long long i = small + 1; i < big; i++) { v.push_back(i); }
    // 6. 수의 개수 출력
    cout << diff << "\n";
    // 7. 오름차순 출력
    sort(v.begin(), v.end());
    for (long long num : v) cout << num << " ";
    return 0;
}