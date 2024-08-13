#include <string>
#include <sstream>
#include <vector>

using namespace std;

string solution(string polynomial) {
    int coefficient = 0; // x의 계수 합
    int constant = 0;    // 상수항 합
    
    stringstream ss(polynomial);
    string term;
    
    while (ss >> term) {
        if (term == "+") continue; // '+'는 건너뜀
        
        // x가 포함된 항인지 확인
        if (term.find('x') != string::npos) {
            // x 앞에 숫자가 없는 경우 (계수 1인 경우)
            if (term == "x") {
                coefficient += 1;
            } else {
                // x 앞에 숫자가 있는 경우
                coefficient += stoi(term.substr(0, term.find('x')));
            }
        } else {
            // 상수항인 경우
            constant += stoi(term);
        }
    }
    
    // 결과를 생성
    string result = "";
    
    if (coefficient != 0) {
        result += (coefficient == 1) ? "x" : to_string(coefficient) + "x";
    }
    
    if (constant != 0) {
        if (!result.empty()) result += " + ";
        result += to_string(constant);
    }
    
    return result;
}