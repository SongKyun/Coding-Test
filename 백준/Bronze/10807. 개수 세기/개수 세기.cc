#include <iostream>
using namespace std;

int N, v;
int a[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 첫째 줄에 정수 개수 N(1<=N<=100)이 주어짐
    cin >> N;
    // 둘째 줄에 정수가 공백으로 구분되어 있음
    for (int i = 0; i < N; i++) { cin >> a[i]; }
    // 셋째 줄엔 찾으려고 하는 정수 v가 주어짐
    cin >> v;
    // 입력으로 주어지는 정수와 v는 -100보다 크거나 같으며, 100보다 작거나 같다.
    if (-100 > v && v > 100) { return 0; }
    // 첫째 줄에 입력으로 주어진 N개의 정수 중에 v 가 몇 개인지 출력한다.
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] == v)
            count++;
    }
    cout << count << endl;
    return 0;
}