#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    sort(numbers.begin(), numbers.end());
    
    // 가장 큰 두 수의 곱과 가장 작은 두 수의 곱 중 큰 값을 선택
    answer = max(numbers[numbers.size()-1] * numbers[numbers.size()-2], 
                         numbers[0] * numbers[1]);
    
    return answer;
}