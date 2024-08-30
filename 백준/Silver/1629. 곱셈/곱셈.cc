#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

// 거듭제곱을 모듈러 연산을 적용하여 구하는 함수
long long modular_pow(long long a, long long b, long long c) {
    if (b == 0) return 1;  // A^0 = 1 (모든 수의 0제곱은 1)
    long long half = modular_pow(a, b / 2, c);  // A^(B/2) 구하기
    half = (half * half) % c;  // (A^(B/2))^2 % C 계산

    if (b % 2 == 1) {  // 만약 B가 홀수라면
        half = (half * a) % c;  // A * A^(B-1) % C 계산
    }

    return half;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << modular_pow(A, B, C) << endl;  // 결과 출력
    return 0;
}