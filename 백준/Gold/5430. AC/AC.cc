#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
    string p, s;
    int n;
    cin >> p >> n >> s;

    deque<int> dq;
    string temp = "";

    // 1. 숫자 파싱: [1,2,3,4]에서 숫자만 추출
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            temp += s[i];
        } else {
            if (!temp.empty()) {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
    }

    bool isReversed = false;
    bool isError = false;

    // 2. 명령어 처리
    for (char cmd : p) {
        if (cmd == 'R') {
            isReversed = !isReversed;
        } else { // 'D' 명령
            if (dq.empty()) {
                isError = true;
                break;
            }
            if (isReversed) {
                dq.pop_back();
            } else {
                dq.pop_front();
            }
        }
    }

    // 3. 출력 처리
    if (isError) {
        cout << "error\n";
    } else {
        cout << "[";
        while (!dq.empty()) {
            if (isReversed) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << dq.front();
                dq.pop_front();
            }
            if (!dq.empty()) cout << ",";
        }
        cout << "]\n";
    }
}

int main() {
    // 입출력 속도 향상 (필수!)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}