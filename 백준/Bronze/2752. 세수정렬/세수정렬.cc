#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A, B, C ;
int main()
{
    // 정수 3개 입력
    cin >> A >> B >> C;
    // 정수 3개를 담을 벡터
    vector<int> numbers = {A, B, C};
    // 정렬 실행
    sort(numbers.begin(),numbers.end());
    // numbers 요소 출력
    for (int num : numbers)
    { cout << num << " "; }
    return 0;
}