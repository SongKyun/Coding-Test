#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true)
    {
        // 입력
        string a;
        getline(cin, a);
        // 종료 조건
        if (a == ".") break;
        // 스택
        stack<char> s;
        // bool 변수 초기화
        bool isValid = true;
        // 조건 : 반복 순회
        for (auto c : a)
        {
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    isValid = false;
                    break;
                } s.pop();
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    isValid = false;
                    break;
                } s.pop();
            }
        }
        if (!s.empty()) isValid = false;
        // 출력
        if (isValid) cout << "yes\n";
        else cout << "no\n";
    }
}