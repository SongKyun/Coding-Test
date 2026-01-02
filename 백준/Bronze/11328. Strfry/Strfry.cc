#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    while (N--)
    {
        // 알파벳 빈도수 체크
        // 크기가 26인 정수형 배열(알파벳 개수 저장용)을 0으로 초기화
        int a[26] = {};
        string s1, s2;
        cin >> s1 >> s2;
        // 첫 번째 문자열을 순회 - 알파벳 개수 배열에 ++
        for (auto c : s1) a[c-'a']++;
        // 두 번째 문자열 순회 알파벳 개수 배열에 --
        for (auto c : s2) a[c-'a']--;
        
        // 0이 아닌 배열 요소 존재 시, 개수가 다른 문자 존재 시 false
        bool isPossible = true;
        for (int i : a)
        {
            if (i != 0) isPossible = false;
        }
        
        if (isPossible) cout << "Possible\n";
        else cout << "Impossible\n";
    }
    
    return 0;
}