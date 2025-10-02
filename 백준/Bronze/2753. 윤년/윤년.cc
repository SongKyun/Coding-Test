#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int A;
int main()
{
    // 연도가 주어짐
    cin >> A;
    // 윤년 조건
    if (A % 4 == 0 && A % 100 != 0 || A % 400 == 0)
        { cout << 1; }
        else { cout << 0; }
    return 0;
}