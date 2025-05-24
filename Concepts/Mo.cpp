#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int B; // block size
int currL = 0, currR = -1;
int cnt[N], answer[N];
int distinct = 0;

struct Query {
    int l, r, idx;
    bool operator<(Query q) const {
        if (l / B != q.l / B) return l / B < q.l / B;
        return r < q.r;
    }
};

void add(int x) {
    if (cnt[x] == 0) distinct++;
    cnt[x]++;
}

void remove(int x) {
    cnt[x]--;
    if (cnt[x] == 0) distinct--;
}

void mo_algo(vector<Query>& queries, vector<int>& arr) {
    sort(queries.begin(), queries.end());
    for (auto q : queries) {
        while (currL > q.l) add(arr[--currL]);
        while (currR < q.r) add(arr[++currR]);
        while (currL < q.l) remove(arr[currL++]);
        while (currR > q.r) remove(arr[currR--]);
        answer[q.idx] = distinct;
    }
}

int main() {
    vector<int> arr = {1, 1, 2, 1, 3}; // example array
    int n = arr.size();
    B = sqrt(n);

    vector<Query> queries = {
        {0, 4, 0}, // full range
        {1, 3, 1}, // subrange
        {2, 4, 2}  // another subrange
    };

    mo_algo(queries, arr);

    for (int i = 0; i < queries.size(); ++i) {
        cout << "Query " << i << ": " << answer[i] << " distinct elements\n";
    }

    return 0;
}
