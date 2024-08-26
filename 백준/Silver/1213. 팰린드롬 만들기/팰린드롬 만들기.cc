#include <iostream>
#include <string>

using namespace std;

string s, ret;
int cnt[200], flag;
char mid;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;

	for (char a : s)cnt[a]++; // 카운팅 배열 - 몇개 인가?

	for (int i = 'Z'; i >= 'A'; i--) { // 오름 차순을 위해 z 부터
		if (cnt[i]) {
			if (cnt[i] & 1) // 비트연산 &(AND) : 마지막 비트가 1인 경우 홀수 , 0이면 짝수
			{
				mid = char(i); flag++; // 홀수인 경우 mid에 초기화 및 카운팅
				cnt[i]--; // 홀수에서 -1 해서 짝수로 만든다 양 끝에 대칭으로 배치해야 하기 때문에
			}

			if (flag == 2)break; // 홀수 2개인 경우 종료

			for (int j = 0; j < cnt[i]; j += 2) { // 2번 붙이므로 +2
				ret = char(i) + ret; // 앞에 붙이고
				ret += char(i); // 뒤에 붙이고
			}
		}
	}

	if (mid)ret.insert(ret.begin() + ret.size() / 2, mid); // 중앙에 mid 삽입

	if (flag == 2)cout << "I'm Sorry Hansoo\n";

	else cout << ret << "\n";
}