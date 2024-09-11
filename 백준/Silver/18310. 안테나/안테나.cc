#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> houses(N);

    for (int i = 0; i < N; i++) {
        cin >> houses[i];
    }

    // 집의 위치를 정렬합니다.
    sort(houses.begin(), houses.end());

    // 중앙값에 해당하는 위치에 안테나를 설치합니다.
    int antenna_position = houses[(N - 1) / 2];

    cout << antenna_position << endl;

    return 0;
}
