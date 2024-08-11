#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> position = {0,0}; // 초기 위치
    
    int x_min = -(board[0] / 2), x_max = board[0] / 2;
    int y_min = -(board[1] / 2), y_max = board[1] / 2;
    
    for(const string& key : keyinput) {
        if(key == "up") { position[1]++; }
        else if (key == "down") { position[1]--; }
        else if (key == "left") { position[0]--; }
        else if (key == "right") { position[0]++; }
        
        if (position[0] < x_min) position[0] = x_min;
        if (position[0] > x_max) position[0] = x_max;
        if (position[1] < y_min) position[1] = y_min;
        if (position[1] > y_max) position[1] = y_max;
    }
    
    return position;
}