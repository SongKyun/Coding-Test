#include <string>
#include <sstream>
#include <vector>

using namespace std;

string solution(string p) {
    int x = 0; // x의 계수 합
    int c = 0; // 상수항 합
    
    stringstream ss(p);
    string term;
    
    while (ss >> term) {
        if (term == "+") continue; // '+'는 건너뜀
        if (term.find('x') != string::npos) { // x가 포함된 항인지 확인
            if (term == "x") { x += 1; } // x 앞에 숫자가 없는 경우 (계수 1인 경우)
            else { x += stoi(term.substr(0, term.find('x'))); } //x 앞 숫자가 있는 경우
            } 
        else { c += stoi(term); } // 상수항인 경우
    }
    
    // 결과를 생성
    string result = "";
    if (x != 0) { result += (x == 1) ? "x" : to_string(x) + "x"; }
    if (c != 0) {
    if (!result.empty()) result += " + ";
        result += to_string(c);
    }
    
    return result;
}