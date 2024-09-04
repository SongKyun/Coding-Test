#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers(5);  // 5개의 자연수를 저장할 벡터

    // 5개의 자연수를 입력받습니다.
    for (int i = 0; i < 5; ++i) {
        std::cin >> numbers[i];
    }

    int result = 1;  // 최소 배수를 찾기 위한 초기값 설정

    while (true) {
        int count = 0;  // 현재 숫자가 몇 개의 입력 수로 나누어지는지 세기 위한 변수

        // 입력받은 숫자들로 나누어지는지 확인합니다.
        for (int num : numbers) {
            if (result % num == 0) {  // result가 num으로 나누어 떨어지면
                count++;
            }
        }

        // 적어도 3개의 숫자로 나누어지면 출력하고 종료합니다.
        if (count >= 3) {
            std::cout << result << std::endl;
            break;
        }

        result++;  // 다음 숫자를 확인합니다.
    }

    return 0;
}
