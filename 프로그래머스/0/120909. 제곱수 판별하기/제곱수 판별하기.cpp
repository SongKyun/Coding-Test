#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 제곱근을 계산
    double sqrt_n = sqrt(n);
    
    // floor 주어진 숫자를 내림하여 가장 가까운 정수로 만듬
    // 제곱근이 정수인지 확인한다
    if(sqrt_n == floor(sqrt_n))
    {
        return 1;
    } else {
        return 2;
    }
    
    return answer;
}