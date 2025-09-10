#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;
const int maxn = 1e5 + 5;
int suf[maxn], id[maxn], tmp[maxn];
int pos[maxn], lcp[maxn];

bool comp(int i, int j, int k) {
    if (id[i] < id[j]) return 1;
    if (id[i] > id[j]) return 0;

    int x = (i + k < n) ? id[i + k] : -1;
    int y = (j + k < n) ? id[j + k] : -1;

    return x < y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    n = s.size();

    for (int i = 0; i < n; i++) {
        suf[i] = i;
        id[i] = s[i];
    }

    int k = 1;
    while (k < n) {
        sort(suf, suf + n, [k](int a, int b) {return comp(a, b, k);});

        tmp[suf[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (comp(suf[i - 1], suf[i], k)) 
                tmp[suf[i]] = tmp[suf[i - 1]] + 1;
                
            else tmp[suf[i]] = tmp[suf[i - 1]];
        }

        for (int i = 0; i < n; i++) id[i] = tmp[i];
        k *= 2;
    }

    for (int i = 0; i < n; i++) pos[suf[i]] = i;

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (pos[i] == 0) {
            lcp[0] = 0;
            continue;
        }

        int j = suf[pos[i] - 1];
        while (i + len < n && j + len < n && s[i + len] == s[j + len]) len++;
        lcp[pos[i]] = len;
        if (len > 0) len--;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) 
        res += n - suf[i] - lcp[i];

    cout << res;
    return 0;
}
