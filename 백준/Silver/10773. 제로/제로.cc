#include <iostream>
#include <stack>

using namespace std;

int main() {
	int K;
	cin >> K;

	stack<int> numbers; // 스택 자료구조 사용 , 입력 수 저장

	for (int i = 0; i < K; ++i)
	{
		int num;
		cin >> num; // 입력 숫자 받음

		if (num == 0) {
			if (!numbers.empty()) {
				numbers.pop();
			}
        }
		else
		{
			// 0이 아닌 경우 수 추가
			numbers.push(num);
		}
	}

	int sum = 0;
	while (!numbers.empty())
	{
		sum += numbers.top(); // 맨 위를 더하고
		numbers.pop(); // 빼버림
		// 반복하면서 모든 수를 더함
	}

	cout << sum << "\n";
	return 0;
}