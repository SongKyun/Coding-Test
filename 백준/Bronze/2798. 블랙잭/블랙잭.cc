#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> cards(N);
	for (int i = 0; i < N; i++)
	{
		cin >> cards[i];
	}

	int max_sum = 0; // 변수를 선언하고 초기화를 해줘야 쓰레기 값을 가지지 않는다 - 예측 불가능

	for (int i = 0; i < N; ++i)
	{// 중복 방지, 순서 보장, 효율적 조합 생성
		for (int j = i + 1; j < N; ++j) // i + 1 : i와 동일한 카드를 선택하지 않도록 보장
		{
			for (int k = j + 1; k < N; ++k)
			{
				int current_sum = cards[i] + cards[j] + cards[k];
				if (current_sum <= M && current_sum > max_sum)
				{
					max_sum = current_sum;
				}
			}
		}
	}

	cout << max_sum << endl;

	return 0;
}