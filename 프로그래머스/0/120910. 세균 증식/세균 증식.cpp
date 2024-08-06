#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, int t) {
    // answer = n * n * t;
    // pow(2, t)는 2를 t 제곱한 값을 반환합니다.
    return n * pow(2, t);
}