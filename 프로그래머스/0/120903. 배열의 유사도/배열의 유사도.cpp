#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    unordered_set<string> set_s1(s1.begin(), s1.end());
// s1을 set으로 변환하여 빠른 조회 가능하게 함
    
    for (const auto& item : s2) {
        if (set_s1.find(item) != set_s1.end()) {
            ++answer;
        }
    }

    return answer;
}