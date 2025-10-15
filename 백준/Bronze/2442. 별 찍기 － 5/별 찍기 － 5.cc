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
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N - i; j++) cout << ' ';
        for (int j = 1; j <= 2 * i -1; j++) cout << '*';
        cout << '\n';
    }
    return 0;
}