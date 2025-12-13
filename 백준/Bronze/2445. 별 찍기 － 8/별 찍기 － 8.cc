#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    // 2 * N - 1 번째 줄까지 별 출력 / N = 5
    
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= i; j++) cout << "*";
        for (int j = 1; j <= 2 * (N - i); j++) cout << " ";
        for (int j = 1; j <= i; j++) cout << "*";
        cout << '\n';
    }

    for (int j = 1; j <= 2 * N; j++) cout << '*';
    cout << '\n';
    
    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - i; j++) cout << "*";
        for (int j = 1; j <= 2 * i; j++) cout << " ";
        for (int j = 1; j <= N - i; j++) cout << "*";
        cout << '\n';
    }
}