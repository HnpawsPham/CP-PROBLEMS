#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

ll calc(const vi& v){
    ll sum = 0;
    int n = v.size();

    for(int i = 0; i < n; i++)
        sum += 1LL * v[i] * (2LL * i - n + 1);
    return sum;
}

int main(){
    // freopen("RC.INP", "r", stdin);
    // freopen("RC.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n];
    vi b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];

    vector<vi> d(m + 1);
    for(int i = 0; i < n; i++)
        d[a[i]].push_back(b[i]);

    sort(b.begin(), b.end());
    ll sum = calc(b);

    for(int i = 1; i <= m; i++){
        sort(d[i].begin(), d[i].end());
        sum -= calc(d[i]);
    }
    cout<<sum;
    return 0;
}

// 5 3
// 1 2 3 2 1
// 3 4 5 6 7