#include <iostream>
#include <vector>

using namespace std;

int n, r, root;
vector<int> tree[50];

int countLeafNodes(int node) {
    int leafCount = 0, childCount = 0;

    for (int child : tree[node]) {
        if (child == r) continue; // 삭제된 노드는 탐색 안 함
        leafCount += countLeafNodes(child);
        childCount++;
    }

    return (childCount == 0) ? 1 : leafCount; // 자식이 없으면 리프 노드
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) root = i;
        else tree[parent].push_back(i);
    }

    cin >> r;

    if (r == root) {
        cout << "0\n";
        return 0;
    }

    cout << countLeafNodes(root) << "\n";
    return 0;
}
