#include <iostream>
#include <list>
#include <stack>
#include <vector>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos;

void push(int val)
{
    dat[pos++] = val;
}

void pop()
{
    pos--;
}

int top()
{
    return dat[pos-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string c;
        cin >> c;
        if (c == "push")
        {
            int t;
            cin >> t;
            push(t);
        }
        else if (c == "pop")
        {
            if (pos == 0)
                cout << -1 << endl;
            else
            {
                cout <<top() << endl;
                pop();
            }
        }
        else if (c == "size")
            cout << pos << endl;
        else if (c == "empty")
            cout << (int)(pos == 0) << endl;
        else
        {
            if (pos == 0)
                cout << -1 << endl;
            else cout << top() << endl;
        }
    }
}