#include <iostream>
#include <vector>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(9);
    for (int i = 0; i < 9; i++) { cin >> v[i]; }
    
    int maxValue = v[0];
    int maxIndex = 0;
    for (int i = 1; i < 9; i++)
    {
        if (v[i] > maxValue)
        {
            maxValue = v[i];
            maxIndex = i;
        }
    }
    cout << maxValue << endl;
    cout << maxIndex + 1 << endl;
    return 0;
}