#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    int good_word_count = 0;  // 좋은 단어의 개수 카운트
    
    while (N--) {
        string word;
        cin >> word;
        
        stack<char> s;  // 스택 선언
        
        for (char ch : word) {  // 단어의 각 글자 순회
            if (!s.empty() && s.top() == ch) {
                s.pop();  // 스택의 최상단 글자와 같은 경우 제거
            } else {
                s.push(ch);  // 스택에 현재 글자 추가
            }
        }
        
        // 스택이 비어 있다면 좋은 단어
        if (s.empty()) {
            good_word_count++;
        }
    }
    
    cout << good_word_count << endl;  // 좋은 단어의 개수 출력
    return 0;
}