#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// 모음인지 확인하는 함수
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

// 패스워드가 규칙을 따르는지 확인하는 함수
bool isAcceptable(const string& password) {
    bool hasVowel = false;
    int vowelCount = 0, consonantCount = 0;
    char lastChar = '\0';

    for (size_t i = 0; i < password.length(); i++) {
        char currentChar = password[i];

        // 모음 여부에 따라 처리
        if (isVowel(currentChar)) {
            hasVowel = true;
            vowelCount++;
            consonantCount = 0;
        } else {
            vowelCount = 0;
            consonantCount++;
        }

        // 모음이 3개 연속 또는 자음이 3개 연속인 경우
        if (vowelCount >= 3 || consonantCount >= 3) {
            return false;
        }

        // 같은 글자가 두 번 연속 오는지 확인 (ee와 oo는 허용)
        if (lastChar == currentChar && currentChar != 'e' && currentChar != 'o') {
            return false;
        }

        lastChar = currentChar;
    }

    // 모음을 포함하지 않으면 false
    return hasVowel;
}

int main() {
    string password;

    while (true) {
        cin >> password;
        if (password == "end") break;

        if (isAcceptable(password)) {
            cout << "<" << password << "> is acceptable." << endl;
        } else {
            cout << "<" << password << "> is not acceptable." << endl;
        }
    }

    return 0;
}
