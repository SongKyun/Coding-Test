#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N, K; // N 전체날짜 , K 합하는 연속 날짜 수
	cin >> N >> K;

	vector<int> temperatures(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temperatures[i];
	}

	// 첫 번째 K일의 합
	int current_sum = 0;
	for (int i = 0; i < K; i++)
	{
		current_sum += temperatures[i];
	}

	// 첫 번째 최대 합으로 초기화
	int max_sum = current_sum;

	// 슬라이딩 윈도우를 사용해 나머지 구간의 합을 구함
	for (int i = K; i < N; i++)
	{
		current_sum = current_sum - temperatures[i - K] + temperatures[i];
		if (current_sum > max_sum)
		{
			max_sum = current_sum;
		}
	}

	cout << max_sum << endl;

	return 0;
}