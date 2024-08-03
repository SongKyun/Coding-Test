#include <string>

using namespace std;

int solution(int num, int k) {
    // num을 문자열로 변환
    string numStr = to_string(num);
    // k를 문자로 변환
    char kChar = '0' + k;

    // 문자열에서 kChar를 찾기
    size_t pos = numStr.find(kChar);
    
    if (pos != string::npos) {
        // 위치를 1부터 시작하도록 조정
        return pos + 1;
    } else {
        // k가 문자열에 없을 때
        return -1;
    }
}
