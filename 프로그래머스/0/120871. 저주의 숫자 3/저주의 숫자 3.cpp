#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int count = 0;
    
    for(int i = 1; count < n ; i++)
    {
        if(i % 3 == 0 || to_string(i).find('3') != string::npos)
        {
            continue;
        }
        count++;
        answer = i;
    }
    
    return answer;
}