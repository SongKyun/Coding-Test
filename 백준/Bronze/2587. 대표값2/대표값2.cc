#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;
int A, B, C, D, E;
int result, sum = 0, average, middle;
int main()
{
    cin >> A >> B >> C >> D >> E;
    vector<int> v{A,B,C,D,E};
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    average = sum / v.size();
    sort(v.begin(), v.end());
    middle = v[v.size() / 2];
    cout << average << "\n" << middle;
    return 0;
}