#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    while(n > 0) {
        answer += n % 10; // 현재 자릿수를 더함
        n /= 10; // 다음 자릿수로 이동하게함
    }
    
    return answer;
}