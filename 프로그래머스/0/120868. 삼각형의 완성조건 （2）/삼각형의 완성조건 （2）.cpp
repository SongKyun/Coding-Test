#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    sort(sides.begin(), sides.end()); // 두 변을 오름차순으로 정렬

    int min_side = sides[0];
    int max_side = sides[1];

    // 1. x가 max_side보다 작은 경우
    int count1 = max_side - (max_side - min_side); // max_side보다 작은 경우의 수

    // 2. x가 max_side보다 큰 경우
    int count2 = (min_side + max_side) - max_side - 1;

    // 두 경우의 수를 더하여 반환
    return count1 + count2;
}
