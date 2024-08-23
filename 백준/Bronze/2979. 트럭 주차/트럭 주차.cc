#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	// 첫 째 줄에 주차 요금 A B C 를 입력 받음
	int A, B, C;
	cin >> A >> B >> C;

	vector<int> parkingTime(101, 0); // 시간 1 ~ 100

	// 3대의 트럭에 대한 도착 및 떠난 시간 입력
	for (int i = 0; i < 3; ++i) {
		int arrive, depart;
		cin >> arrive >> depart;

		// 각 시간대에 주차된 트럭 수 기록
		for (int t = arrive; t < depart; ++t) {
			parkingTime[t]++;
		}
	}

	int totalCost = 0;
	// 1분 단위로 주차 요금 계산
	for (int t = 1; t <= 100; ++t) {
		if (parkingTime[t] == 1) totalCost += A * 1;
		else if (parkingTime[t] == 2) totalCost += B * 2;
		else if (parkingTime[t] == 3) totalCost += C * 3;
	}

	cout << totalCost << endl;
	
	return 0;
}