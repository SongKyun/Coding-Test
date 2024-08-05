#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> quiz) {
    vector<string> answer;
    
    for (const string& q : quiz) {
        stringstream ss(q);
        int X, Y, Z;
        char op, eq;
        
        // 수식을 파싱합니다.
        ss >> X >> op >> Y >> eq >> Z;

        // 수식을 평가하고 결과를 저장합니다.
        if (op == '+') {
            if (X + Y == Z) {
                answer.push_back("O");
            } else {
                answer.push_back("X");
            }
        } else if (op == '-') {
            if (X - Y == Z) {
                answer.push_back("O");
            } else {
                answer.push_back("X");
            }
        }
    }
    
    return answer;
}