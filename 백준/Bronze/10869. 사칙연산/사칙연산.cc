#include <iostream>
using namespace std;
int A, B;

int main()
{
    cin >> A >> B;
    if(B == 0) { return 1; }
    
    cout << A + B << endl;
    cout << A - B << endl;
    cout << A * B << endl;
    cout << A / B << endl;
    cout << A % B << endl;
}