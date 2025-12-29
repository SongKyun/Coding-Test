#include <iostream>
using namespace std;

// 수의 범위 최대 1,000,000
// x 범위 2,000,000
bool exist[2000001];
int a[100001]{};
int n, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++){ cin >> a[i]; }
    cin >> x;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int target = x - a[i];
        // 타겟이 양수 , 타겟이 이전에 등장했는지 확인
        if (target > 0 && target <= 2000000 && exist[target]) { count++; }
        // 현재 숫자를 기록 (다음 올 숫자의 짝궁이 될 수 있게)
        exist[a[i]] = true;
    }
    cout << count;
    return 0;
}