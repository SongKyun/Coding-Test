#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string name;
    cin >> name;

    map<char, int> char_count;
    for (char c : name) { // 문자가 몇 번 등장하는지 카운팅
        char_count[c]++;
    }

    int odd_count = 0;
    char odd_char = 0;
    string first_half = "", second_half = "";

    // 홀수 개수의 문자가 있는지 확인
    for (auto& entry : char_count) {
        if (entry.second % 2 != 0) {
            odd_count++;
            odd_char = entry.first;
        }
        // 홀수 개 문자가 2개 이상이면 팰린드롬 불가능
        if (odd_count > 1) {
            cout << "I'm Sorry Hansoo" << endl;
            return 0;
        }
    }

    // 팰린드롬의 절반 만들기
    for (auto& entry : char_count) {
        string temp(entry.second / 2, entry.first);
        first_half += temp;
    }

    second_half = first_half;
    reverse(second_half.begin(), second_half.end());

    // 팰린드롬 완성
    if (odd_count == 1) { // 홀수 개수 중앙 배치
        cout << first_half + odd_char + second_half << endl;
    }
    else {
        cout << first_half + second_half << endl;
    }

    return 0;
}
