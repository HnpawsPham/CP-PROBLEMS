#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;
const int maxn = 1e6 + 5;
int cnt[maxn] = {0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int x : a) cnt[x]++;
    sort(a.begin(), a.end());

    int res = 1;
    for(int i = 0; i < a[n - 1] + k; i++){
        int l = lower_bound(a.begin(), a.end(), i - k) - a.begin();
        int r = upper_bound(a.begin(), a.end(), i + k) - a.begin();
        int d = r - l - cnt[i];

        res = max(res, min(d, m) + cnt[i]);
    }
    cout<<res;
    return 0;
}

// 3 1 2
// 1 4 5

// 4 5 1
// 5 11 20 20