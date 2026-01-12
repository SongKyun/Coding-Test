#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 개수 입력 받기
    int n;
    cin >> n;
    // 문자열을 조건에 맞게 순회하면서 키로거를 기록
    for (int i = 0; i < n; i++)
    {
        // 리스트 L에 n만큼 기록
        list<char> L {};
        // 입력받을 문자열
        string s;
        cin >> s;
        // 키로거 초기값은 L의 맨 처음부터 읽어야함
        auto p = L.begin();
        /// 백스페이스 '-'
        /// 커서 앞에 글자 존재 - 글자 삭제
        for (auto c : s)
        {
            if (c == '<')
            {
                if (p != L.begin()) p--;
            }
            else if (c == '>')
            {
                if (p != L.end()) p++;
            }
            else if (c == '-')
            {
                if (p != L.begin())
                {
                    p--;
                    p = L.erase(p);
                }
            }
            else
            {
                L.insert(p,c); // p 앞에 c를 삽입
            }
        }
        for (auto c : L) cout << c;
        cout << endl;
    }
    return 0;
}