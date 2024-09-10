#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Soldier {
    int strength, agility, intelligence;
};

bool canDefeatK(const vector<Soldier>& soldiers, int K, int max_strength, int max_agility, int max_intelligence) {
    int count = 0;
    for (const auto& soldier : soldiers) {
        if (soldier.strength <= max_strength && soldier.agility <= max_agility && soldier.intelligence <= max_intelligence) {
            count++;
        }
    }
    return count >= K;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Soldier> soldiers(N);
    for (int i = 0; i < N; ++i) {
        cin >> soldiers[i].strength >> soldiers[i].agility >> soldiers[i].intelligence;
    }

    int min_stat_points = INT32_MAX;

    // 세 가지 능력에 대해 각각 모든 가능한 경우를 탐색
    for (const auto& soldier1 : soldiers) {
        for (const auto& soldier2 : soldiers) {
            for (const auto& soldier3 : soldiers) {
                // soldier1.strength 이상의 힘, soldier2.agility 이상의 민첩, soldier3.intelligence 이상의 지능을 가진 진수가 K명을 이길 수 있는가?
                int max_strength = soldier1.strength;
                int max_agility = soldier2.agility;
                int max_intelligence = soldier3.intelligence;

                if (canDefeatK(soldiers, K, max_strength, max_agility, max_intelligence)) {
                    min_stat_points = min(min_stat_points, max_strength + max_agility + max_intelligence);
                }
            }
        }
    }

    cout << min_stat_points << endl;
    return 0;
}
