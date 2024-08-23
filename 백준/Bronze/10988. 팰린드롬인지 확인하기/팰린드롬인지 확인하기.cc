#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string input;
    cin >> input;  // 단어 입력받기

    bool isPalindrome = true;
    int length = input.length();

    // 단일 for문으로 팰린드롬 확인
    for (int i = 0; i < length / 2; ++i) {
        if (input[i] != input[length - 1 - i]) {
            isPalindrome = false;  // 팰린드롬이 아님
            break;  // 반복 종료
        }
    }

    // 팰린드롬 여부 출력
    cout << (isPalindrome ? 1 : 0) << endl;

    return 0;
}