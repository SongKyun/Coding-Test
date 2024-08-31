#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int num = 1; // '1'로 이루어진 첫 번째 수
        int length = 1; // 자릿수

        // '1'로 이루어진 수가 n으로 나누어떨어질 때까지 반복
        while (num % n != 0) {
            num = (num * 10 + 1) % n;
            length++;
        }

        // 자릿수를 출력
        cout << length << endl;
    }
    return 0;
}
