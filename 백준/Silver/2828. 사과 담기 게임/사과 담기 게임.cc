#include<string>
#include<iostream>

using namespace std;
int n, m, j, l, r, temp, ret;
int main() {
	cin >> n >> m >> j;
	l = 1;
	for (int i = 0; i < j; i++) { // 사과가 떨어질 때 마다
		r = l + m - 1; // L과 M 값에 따른 R을 구하는 점화식
		cin >> temp; //
		if (temp >= l && temp <= r) continue; // 바구니 범위안에 사과가 있다면
		else {
			if (temp < l) {
				ret += (l - temp); // 5 - 3
				l = temp;
			}
			else {
				l += (temp - r);
				ret += (temp - r);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}