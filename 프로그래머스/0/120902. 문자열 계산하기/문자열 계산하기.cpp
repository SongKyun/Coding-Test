#include <string>
#include <vector>
#include <sstream>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    // 공백을 기준으로 입력받기 위해 sstream의 stringstream 사용
    stringstream s;
    s.str(my_string);
    
    // 연산자 저장
    string opt;
    
    // 첫 입력은 무조건 숫자 이므로 먼저 입력 받는다
    s >> answer;
    string temp;
    
    // temp에 저장하며 계속 확인
    while(s >> temp)
    {
        // 입력 받은게 연산자라면, opt에 저장하고 넘어간다.
        if(temp == "+")
        {
            opt = "+";
            continue;
        }
        if(temp == "-")
        {
            opt = "-";
            continue;
        }
        
        // 입력 받은게 숫자라면 opt에 따라 계속해서 answer에 답을 누적
        if(opt == "+")
        {
            answer += stoi(temp);
        }
        else if(opt == "-")
        {
            answer -= stoi(temp);
        }
    }
    return answer;
}