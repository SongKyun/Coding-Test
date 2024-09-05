#include <iostream>
#include <vector>

// d(n) 함수를 정의: n과 n의 각 자리수를 더하는 함수
int d(int n) {
    int sum = n;
    while (n > 0) {
        sum += n % 10; // 마지막 자리수만 구해서 더함
        n /= 10; // 마지막 자리수를 제거 -> 반복하면 모든 자리수의 숫자가 나옴
    }
    return sum;
}

int main() {
    const int MAX = 10000;
    std::vector<bool> isSelfNumber(MAX + 1, true); // 1부터 10000까지 셀프 넘버 여부를 저장하는 배열
    // 1부터 MAX 까지의 숫자를 인덱스로 그대로 사용하기 위해서는 MAX + 1을 해줘야 한다.
    // 

    // 1부터 10000까지의 모든 수에 대해 생성자를 기록
    for (int i = 1; i <= MAX; ++i) {
        int generatedNumber = d(i);

        if (generatedNumber <= MAX) {
            isSelfNumber[generatedNumber] = false; // 생성된 숫자는 셀프 넘버가 아님
        }
    }

    // 셀프 넘버를 출력
    for (int i = 1; i <= MAX; ++i) {
        if (isSelfNumber[i]) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}