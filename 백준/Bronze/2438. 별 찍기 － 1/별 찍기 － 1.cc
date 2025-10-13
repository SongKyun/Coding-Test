#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << '*';
        }
        cout << '\n';
    }
}