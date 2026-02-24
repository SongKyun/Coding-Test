#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; ++i)
    {
        dq.push_back(i);
    }

    int total_moves = 0;

    while (M--)
    {
        int target;
        cin >> target;

        int idx = 0;
        for (int i = 0; i < dq.size(); ++i)
        {
            if (dq[i] == target)
            {
                idx = i;
                break;
            }
        }

        if (idx <= dq.size() / 2)
        {
            for (int i = 0; i < idx; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                total_moves++;
            }
        }
        else
        {
            for (int i = 0; i < dq.size() - idx; ++i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
                total_moves++;
            }
        }
        dq.pop_front();
    }
    cout << total_moves << '\n';
    return 0;
}