#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // 1. 2개 양의 정수 A B
    long long A, B;
    cin >> A >> B;

    // 2. 예외 처리 ( 두 수 같을 경우 )
    if (A == B) {   cout << 0 << "\n"; return 0;}

    // 3. A와 B 둘 중 누가 더 큰지 판별
    long long big = max(A, B);
    long long small = min(A, B);

    // 4. 두 수 사이의 개수
    long long diff = big - small - 1;

    // 5. 수의 개수 출력
    cout << diff << "\n";
    
    // 5. 사이의 수를 벡터에 저장
    for (long long i = small + 1; i < big; i++) { cout << i << " "; }
    return 0;
}