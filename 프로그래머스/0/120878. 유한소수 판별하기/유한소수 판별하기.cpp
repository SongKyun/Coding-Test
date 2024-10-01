#include <string>
#include <vector>

// 최대공약수를 구하는 함수 (유클리드 호제법 사용)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(int a, int b) {
    // a와 b의 최대공약수를 구하여 기약분수로 만들기
    int gcd_ab = gcd(a, b);
    b /= gcd_ab;  // 기약분수로 만들기 위해 분모를 최대공약수로 나눈다.
    
    // 분모에서 2로 나눌 수 있을 때까지 나눈다.
    while (b % 2 == 0) {
        b /= 2;
    }
    
    // 분모에서 5로 나눌 수 있을 때까지 나눈다.
    while (b % 5 == 0) {
        b /= 5;
    }
    
    // 남은 값이 1이면 유한소수, 아니면 무한소수
    if (b == 1) {
        return 1;  // 유한소수
    } else {
        return 2;  // 무한소수
    }
}
