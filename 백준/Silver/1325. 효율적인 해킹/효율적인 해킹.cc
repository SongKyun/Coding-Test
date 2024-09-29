#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// 10001 크기의 vector 배열 v 선언 (각 노드의 인접 리스트를 저장하기 위한 용도)
vector<int> v[10001];

// dp: 각 노드에서 DFS를 통해 도달할 수 있는 노드 수를 저장하는 배열
// mx: DFS를 통해 얻은 최대 도달 노드 수를 저장하는 변수
// visited: 방문 여부를 기록하는 배열 (DFS에 사용)
// n: 노드의 개수 (정점의 수), m: 간선의 개수
// a, b: 입력으로 주어지는 두 정점 (간선 연결)
int dp[10001], mx, visited[10001], n, m, a, b;

// DFS 함수: 현재 노드(here)에서 시작하여 연결된 노드를 탐색하고, 연결된 노드의 개수를 반환
int dfs(int here) {
    visited[here] = 1; // 현재 노드를 방문 처리
    int ret = 1; // 현재 노드 자체도 개수에 포함하므로 1로 시작
    for (int there : v[here]) { // 현재 노드에 연결된 다른 노드를 탐색
        if (visited[there]) continue; // 이미 방문한 노드는 건너뜀
        ret += dfs(there); // 방문하지 않은 노드를 DFS로 재귀 호출
    }
    return ret; // 연결된 노드 수 반환
}

int main() {
    cin >> n >> m; // 노드(n)와 간선(m) 입력 받음
    while (m--) {
        cin >> a >> b;
        v[b].push_back(a); // b에서 a로 연결되는 간선을 저장 (a가 b로부터 신뢰됨)
    }

    // 각 노드에 대해 DFS 수행
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited)); // 매번 새로운 DFS 탐색을 위해 방문 기록 초기화
        dp[i] = dfs(i); // i에서 출발하는 DFS의 결과(연결된 노드의 수)를 dp[i]에 저장
        mx = max(dp[i], mx); // 최대 도달 노드 수 갱신
    }

    // 최대 도달 가능한 노드 수를 갖는 모든 노드를 출력
    for (int i = 1; i <= n; i++)
        if (mx == dp[i])
            cout << i << " "; // dp[i]가 최대 도달 노드 수와 같다면 해당 노드 출력

    return 0;
}
