#include <iostream>
using namespace std;
int A, B;

int main()
{
    cin >> A >> B;
    if(A < 0 && B <0 && B <= 10000)
    { return 0; }
    
    cout << A + B << endl;
    cout << A - B << endl;
    cout << A * B << endl;
    cout << A / B << endl;
    cout << A % B << endl;
}