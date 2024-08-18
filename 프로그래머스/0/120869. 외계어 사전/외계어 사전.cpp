#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    // spell을 정렬한 후 하나의 문자열로 결합
    sort(spell.begin(), spell.end());
    string target = "";
    for (string s : spell) {
        target += s;
    }

    // dic의 각 단어를 정렬한 후 비교
    for (string word : dic) {
        sort(word.begin(), word.end());
        if (word == target) {
            return 1;  // 일치하는 단어가 있으면 1 반환
        }
    }

    return 2;  // 일치하는 단어가 없으면 2 반환
}
