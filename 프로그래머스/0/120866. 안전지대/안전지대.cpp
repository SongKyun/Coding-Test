#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board) {
    int n = board.size();
    vector<vector<int>> danger_zone(n, vector<int>(n, 0));  // 위험지역을 표시할 배열
    
    // 8방향 탐색을 위한 델타 배열
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
    
    // 지뢰가 있는 위치를 기준으로 위험지역을 설정
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 1) {
                danger_zone[i][j] = 1;  // 지뢰가 있는 칸
                for (int d = 0; d < 8; ++d) { // 인접 8방향 추가
                    // 현재 지뢰가 위치한 칸 (i, j)에서 d번째 방향으로 이동한 칸 (ni, nj)의 좌표를 계산
                    int ni = i + dx[d];
                    int nj = j + dy[d];
                    // 새로운 좌표가 유효한지 확인 (보드 범위 내에 있는지)
                    // 배열의 경계를 벗어나는 경우를 방지하기 위한 조건
                    if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                        danger_zone[ni][nj] = 1; // 해당 칸을 위험지역으로 표시
                    }
                }
            }
        }
    }
    
    // 안전한 칸을 계산
    int safe_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (danger_zone[i][j] == 0) {
                ++safe_count;
            }
        }
    }
    
    return safe_count;
}