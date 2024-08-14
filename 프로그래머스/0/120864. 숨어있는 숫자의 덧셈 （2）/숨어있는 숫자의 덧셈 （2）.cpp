#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int sum = 0;  // 자연수들의 합을 저장할 변수
    string num = "";  // 숫자를 임시로 저장할 문자열

    for (char ch : my_string) {
        if (isdigit(ch)) {
            // 문자가 숫자라면 num에 추가
            num += ch;
        } else {
            // 문자가 숫자가 아니라면, 지금까지 쌓은 num을 정수로 변환하여 합산
            if (!num.empty()) {
                sum += stoi(num);
                num = "";  // num 초기화
            }
        }
    }
    
    // 마지막으로 num에 남아있는 숫자를 합산
    if (!num.empty()) {
        sum += stoi(num);
    }

    return sum;
}