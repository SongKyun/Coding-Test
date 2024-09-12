#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

// 이동 방향을 정의 (상, 하, 좌, 우)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> maze(N, vector<int>(M));
    vector<vector<int>> distance(N, vector<int>(M, 0)); // 각 칸까지의 거리를 저장할 배열

    // 미로 입력 받기
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            maze[i][j] = row[j] - '0'; // 문자형을 정수형으로 변환
        }
    }

    // BFS를 위한 큐 정의
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    distance[0][0] = 1; // 시작 위치의 거리

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 네 방향으로 이동 시도
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 미로 범위를 벗어나지 않고, 이동할 수 있는 칸일 때
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == 1) {
                // 아직 방문하지 않은 칸일 때
                if (distance[nx][ny] == 0) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
    }
    // 도착 지점 (N, M)까지의 최소 칸 수 출력
    cout << distance[N - 1][M - 1] << endl;
    return 0;
}