#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    
/*반복적 비교
sort()는 배열의 모든 요소를 정렬하기 위해 a와 b를 반복적으로 비교합니다.
첫 번째 요소와 두 번째 요소를 비교한 후, 정렬 기준에 따라 위치를 교환합니다. 그 다음, 첫 번째 요소와 세 번째 요소를 비교하고, 이런 방식으로 전체 배열을 정렬합니다.
그러므로 sort() 함수는 비교하는 두 요소 a와 b만으로 전체 배열을 정리할 수 있습니다.*/
    
    sort(numlist.begin(), numlist.end(), [n](int a, int b) {
        int distA = abs(a - n);
        int distB = abs(b - n);
        if(distA == distB) {
            // a가 b보다 클 경우 true
            return a > b; // 거리가 같으면 더 큰 수가 앞에 옴
        }
        // true인 경우
        return distA < distB; // 거리가 작을수록 앞에 옴
    });
    
    return numlist;
}