#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end());
    
    // 가능한 세 번째 변의 개수 계산
    int answer = (sides[0] + sides[1] - 1) - (sides[1] - sides[0]);

    return answer;
}