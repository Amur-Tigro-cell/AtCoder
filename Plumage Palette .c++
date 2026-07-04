#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1), B(N + 1), D(N + 1);
    vector<vector<int>> changes(M + 1);
    vector<int> cnt(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> D[i] >> B[i];

        // Color on day 1
        if (D[i] == 1)
            cnt[B[i]]++;
        else
            cnt[A[i]]++;

        // Change occurs before day D, so apply after printing day D-1
        if (A[i] != B[i] && D[i] >= 2)
            changes[D[i]].push_back(i);
    }

    int distinct = 0;
    for (int c = 1; c <= N; c++)
        if (cnt[c] > 0) distinct++;

    for (int day = 1; day <= M; day++) {
        cout << distinct << '\n';

        // Prepare colors for the next day
        if (day + 1 <= M) {
            for (int id : changes[day + 1]) {
                if (--cnt[A[id]] == 0) distinct--;
                if (cnt[B[id]]++ == 0) distinct++;
            }
        }
    }

    return 0;
}
