#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int A, B, C, res=0;
    cin >> A >> B >> C;
    vector<int> nums = {A, B, C};
    sort(nums.begin(), nums.end());
    int smallest    = nums[0];
    int middle      = nums[1];
    int largest     = nums[2];
    if (smallest == largest) { res = 10000+smallest*1000; }
    else if (smallest == middle || middle == largest) { res = 1000+middle*100; }
    else { res = largest * 100; }
    cout << res;
    return 0;
}