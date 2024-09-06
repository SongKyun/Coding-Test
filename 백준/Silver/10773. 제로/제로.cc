#include <iostream>
#include <stack>

int main() {
    int K; // 입력 개수
    std::cin >> K;

    std::stack<int> numbers; // 스택 자료구조를 사용하여 입력 수를 저장

    for (int i = 0; i < K; ++i) {
        int num;
        std::cin >> num; // 입력 숫자를 받음

        if (num == 0) {
            if (!numbers.empty()) {
                numbers.pop(); // 0이 입력되면 가장 최근 수 제거
            }
        } else {
            numbers.push(num); // 0이 아닌 경우 수를 스택에 추가
        }
    }

    int sum = 0; // 결과 합
    while (!numbers.empty()) {
        sum += numbers.top(); // 스택의 맨 위 요소를 더함
        numbers.pop(); // 스택에서 요소 제거
    }

    std::cout << sum << std::endl; // 결과 출력
    return 0;
}
