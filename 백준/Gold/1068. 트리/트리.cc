#include <iostream>  // 입출력 사용을 위한 라이브러리
#include <vector>    // 트리 구조를 표현할 벡터 사용을 위한 라이브러리

using namespace std;

int n, r, temp, root;         // n: 노드 개수, r: 삭제할 노드 번호, temp: 입력값 저장용, root: 루트 노드 번호
vector<int> adj[54];          // 트리를 표현할 인접 리스트 (노드 번호가 0~53까지 가능)

int dfs(int here) {           // 깊이 우선 탐색(DFS) 함수, here는 현재 탐색 중인 노드를 의미
    int ret = 0;              // 리프 노드 개수를 반환할 변수
    int child = 0;            // 자식 노드의 개수를 세기 위한 변수

    for (int there : adj[here]) {  // 현재 노드 here의 자식 노드를 순회
        if (there == r) continue;  // 만약 현재 순회 중인 노드가 삭제된 노드라면 패스
        ret += dfs(there);         // 자식 노드가 있을 경우, 해당 자식에서 리프 노드 개수를 더해줌
        child++;                   // 자식 노드가 존재함을 기록
    }

    if (child == 0) return 1;      // 자식이 없는 노드라면 리프 노드이므로 1을 반환
    return ret;                    // 자식이 있으면 리프 노드의 개수를 반환
}

int main() {
    cin >> n;                      // 노드의 개수 입력

    for (int i = 0; i < n; i++) {
        cin >> temp;               // 각 노드의 부모 정보 입력

        if (temp == -1) root = i;  // 부모가 -1인 경우는 루트 노드
        else adj[temp].push_back(i);  // 부모가 있으면 그 부모 노드의 자식 리스트에 추가
    }

    cin >> r;                      // 삭제할 노드의 번호 입력

    if (r == root) {               // 만약 삭제할 노드가 루트 노드라면
        cout << 0 << "\n";         // 모든 트리가 삭제되므로 리프 노드는 0개
        return 0;                  // 프로그램 종료
    }

    cout << dfs(root) << "\n";     // 루트 노드부터 DFS 탐색 시작, 리프 노드 개수를 출력

    return 0;                      // 프로그램 종료
}
