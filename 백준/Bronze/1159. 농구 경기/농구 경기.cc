#include <iostream>
#include <string>

using namespace std;

int n, cnt[26];
string s, ret;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s[0] - 'a']++; // 문자열의 첫 번째 문자의 인덱스를 계산하여 cnt 배열의 해당 위치를 증가
    }
    
    for(int i = 0; i < 26; i++)
    if(cnt[i] >= 5) ret += (i + 'a'); // 해당 알파벳의 개수가 5개 이상이면 ret 문자열에 그 알파벳을 추가
    
    if(ret.size()) cout << ret << "\n"; // 문자열이 비어 있지 않으면 그 문자열을 출력
    else cout << "PREDAJA" << "\n";
}