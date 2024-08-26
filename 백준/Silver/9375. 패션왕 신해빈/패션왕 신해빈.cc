#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t; // 테스트 케이스 수 입력

    while (t--) {
        int n;
        cin >> n; // 의상의 수 입력

        unordered_map<string, int> clothing_types; // 의상 종류별 개수를 저장할 맵

        for (int i = 0; i < n; i++) {
            string name, type;
            cin >> name >> type;
            clothing_types[type]++; // 의상 종류별로 개수를 센다
        }

        int combinations = 1;

        for (auto& type : clothing_types) {
            combinations *= (type.second + 1); // 각 종류별로 (의상 수 + 1) 만큼 곱한다
        }

        // 알몸이 아닌 상태로 입을 수 있는 경우의 수
        cout << (combinations - 1) << endl;
    }

    return 0;
}

