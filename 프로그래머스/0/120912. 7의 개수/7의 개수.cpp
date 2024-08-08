#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int count = 0;

    for (int num : array) {
        // 숫자를 문자열로 변환
        string num_str = to_string(num);
        
        // 문자열에서 '7'의 개수를 센다
        for (char c : num_str) {
            if (c == '7') {
                count++;
            }
        }
    }

    return count;
}