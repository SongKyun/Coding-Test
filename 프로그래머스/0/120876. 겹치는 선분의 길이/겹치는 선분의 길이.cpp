#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> lines) {
    // 좌표를 -100에서 100까지 표현하기 위해 201 크기의 배열을 사용합니다.
    vector<int> lineMap(201, 0); // 인덱스 0은 -100에 해당
    
    // 각 선분에 대해 시작점과 끝점을 기록합니다.
    for (auto line : lines) {
        int start = line[0] + 100; // 좌표를 0 이상으로 변환
        int end = line[1] + 100;   // 좌표를 0 이상으로 변환
        for (int i = start; i < end; i++) {
            lineMap[i]++;  // 선분이 포함된 구간에 겹침을 표시
        }
    }
    
    int overlapLength = 0;
    
    // 겹친 구간이 두 개 이상의 선분이 있는 구간의 길이를 구합니다.
    for (int i = 0; i < 201; i++) {
        if (lineMap[i] > 1) {
            overlapLength++;
        }
    }
    
    return overlapLength;
}
