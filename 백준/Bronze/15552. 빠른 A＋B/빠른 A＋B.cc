#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int A, B, T;
    vector<int> v;
    
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> A >> B;
        v.push_back(A + B);
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';
}