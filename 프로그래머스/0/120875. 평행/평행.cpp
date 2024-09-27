#include <vector>

using namespace std;

// 두 점을 잇는 직선의 기울기를 구하는 함수
double getSlope(vector<int> p1, vector<int> p2) {
    return static_cast<double>(p2[1] - p1[1]) / (p2[0] - p1[0]);
}

int solution(vector<vector<int>> dots) {
    // 네 점 중 두 점씩 이어서 직선이 평행한지 확인
    // 두 직선이 평행하려면 기울기가 같아야 함
    // 기울기: (y2 - y1) / (x2 - x1)

    if (getSlope(dots[0], dots[1]) == getSlope(dots[2], dots[3])) return 1;
    if (getSlope(dots[0], dots[2]) == getSlope(dots[1], dots[3])) return 1;
    if (getSlope(dots[0], dots[3]) == getSlope(dots[1], dots[2])) return 1;

    return 0;
}
