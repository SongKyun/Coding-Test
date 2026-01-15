#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

int ans, K;
stack<int> S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> K;
    while (K--)
    {
        int num;
        cin >> num;
        // 정수가 "0" 일 경우에는 가장 최근에 쓴 수를 지우고, 아닐 경우 해당 수를 쓴다.
        if (num == 0) S.pop();
        else S.push(num);
    }
    // 모든 수를 받아 적은 후 그 수의 합
    while (!S.empty())
    {
        ans += S.top();
        S.pop();
    }
    cout << ans;
}