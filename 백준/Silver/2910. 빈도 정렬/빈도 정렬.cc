#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

struct Element {
    int value;        // 수열의 값
    int frequency;    // 등장 횟수
    int first_index;  // 처음 등장한 위치
};

// 정렬 기준: 등장 횟수가 많은 순, 등장 횟수가 같다면 먼저 등장한 순
bool compare(const Element& a, const Element& b) {
    if (a.frequency != b.frequency) {
        return a.frequency > b.frequency;  // 등장 횟수가 많은 순으로 정렬
    }
    return a.first_index < b.first_index;  // 등장 횟수가 같으면 먼저 등장한 순서대로
}

int main() {
    int n, c;
    std::cin >> n >> c;

    std::vector<int> sequence(n);
    std::unordered_map<int, int> frequency_map;
    std::unordered_map<int, int> first_index_map;

    // 수열 입력 및 빈도와 첫 등장 인덱스 기록
    for (int i = 0; i < n; ++i) {
        std::cin >> sequence[i];
        frequency_map[sequence[i]]++;
        if (first_index_map.find(sequence[i]) == first_index_map.end()) {
            first_index_map[sequence[i]] = i;  // 처음 등장한 인덱스를 기록
        }
    }

    // 각 원소를 담을 벡터
    std::vector<Element> elements;
    for (const auto& entry : frequency_map) {
        elements.push_back({entry.first, entry.second, first_index_map[entry.first]});
    }

    // 빈도 정렬
    std::sort(elements.begin(), elements.end(), compare);

    // 정렬된 순서대로 출력
    for (const auto& element : elements) {
        for (int i = 0; i < element.frequency; ++i) {
            std::cout << element.value << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
