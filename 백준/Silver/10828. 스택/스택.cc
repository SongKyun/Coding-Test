#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> S;
    while (n--)
    {
        string c;
        cin >> c;
        if (c == "push")
        {
            int t;
            cin >> t;
            S.push(t);
        }
        else if (c == "pop")
        {
            if (S.empty()) cout << -1 << endl;
            else
            {
                cout << S.top() << endl;
                S.pop();
            }
        }
        else if (c == "size")
            cout << S.size() << endl;
        else if (c == "empty")
            cout << (int)S.empty() << endl;
        else
        {
            if (S.empty())
                cout << -1 << endl;
            else cout << S.top() << endl;
        }
    }
}