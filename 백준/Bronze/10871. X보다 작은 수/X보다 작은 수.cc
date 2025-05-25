#include <iostream>
#include <vector>
using namespace std;

int N, X, tempA;
vector<int> A;

int main()
{
	// 1. N과 X 입력 받기
	cin >> N >> X;

	// 2. N은 1이상이다
	if (N <= 0) {
		return 1;
	}
	
	// 3. 수열 A를 만들기 위한 반복문
	for (int i = 0; i < N; i++) {
	// 4. 수열 A를 입력 받아야함 // * cin의 기본 입력 구분자는 공백
		cin >> tempA;
		A.push_back(tempA);
	}

	// 5. N X 와 수열 A 를 입력 받았음

	// 6. A에서 X보다 작은 수를 모두 출력
	for (int i = 0; i < N; i++) {
		
	// 7. X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력
		if (A[i] < X) {
			cout << A[i] << " ";
		}
	}

	return 0;
}