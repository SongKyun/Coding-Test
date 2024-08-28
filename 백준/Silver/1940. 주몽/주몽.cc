#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

	int main()
	{
		int N, M;
		cin >> N >> M;

		vector<int> materials(N); // 재료의 고유 번호를 저장할 벡터 생성

		for (int i = 0; i < N; ++i) {
			cin >> materials[i]; // 재료의 고유 번호 입력
		}

		// 재료 배열 정렬 - 양 끝에서 투 포인터 알고리즘
		sort(materials.begin(), materials.end());

		int count = 0; // 갑옷을 만들 수 있는 개수
		int left = 0; // 왼쪽 포인터
		int right = N - 1; // 오른쪽 포인터

		while (left < right)
		{
			int sum = materials[left] + materials[right]; // 현재 두 포인터가 가리키는 재료의 합
			if (sum == M) {
				// 두 재료의 합이 M과 같다면
				count++; // 갑옷을 만들 수 있으므로 개수 증가
				left++; // 왼쪽 포인터 이동
				right--; // 오른쪽 포인터 이동
			}
			else if (sum < M) {
				// 두 재료의 합이 M보다 작으면
				left++; // 더 큰 값을 만들기 위해 왼쪽 포인터를 오른쪽으로 이동
			}
			else {
				// 두 재료의 합이 M보다 크면
				right--; // 더 작은 값을 만들기 위해 오른쪽 포인터를 왼쪽으로 이동
			}
		}

		cout << count << endl; // 갑옷을 만들 수 있는 개수 출력

		return 0;
	}