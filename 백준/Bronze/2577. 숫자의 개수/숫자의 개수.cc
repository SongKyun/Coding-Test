#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int A, B, C;
    cin >> A >> B >> C;
    int mul = A * B * C;
    int count[10] = {0}; // 0부터 9까지의 숫자의 개수를 저장할 배열
    
    // 첫째 줄 : 계산 결과에 0이 몇 번 쓰였는지 출력한다.
    // 둘째 줄 부터 : 1~9까지 숫자가 각각 몇 번 쓰였는지 출력한다.
    
    // 자릿수 분리 로직 : mul의 각 자릿수를 하나씩 떼서 확인해야함
    while (mul > 0)
    {
        int digit = mul % 10;   // 마지막 자릿수 추출
        count[digit]++;         // 해당 숫자 방 번호 +1
        mul /= 10;              // 추출한 자릿수 제거
    }
    // 결과 출력
    for (int i = 0; i < 10; i++)
    {
        cout << count[i] << endl;
    }
    return 0;
}