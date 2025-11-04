#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k, t;

bool comp(const pii& a, const pii& b){
    if(a.fi != b.fi) return a.fi > b.fi;
    return a.se > b.se;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>t;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[55][n + 1];
    for(int i = 1; i <= 50; i++){
        cnt[i][0] = 0;
        for(int j = 1; j <= n; j++)
            cnt[i][j] = cnt[i][j - 1] + (a[j - 1] == i);
    }

    vi res;
    vector<pii> tmp;
    bool check[55] = {0};

    for(int i = 0; i <= n - k; i++){
        for(int j = i; j < i + k; j++){
            if(check[a[j]]) continue;
            check[a[j]] = 1;

            tmp.push_back({cnt[a[j]][i + k] - cnt[a[j]][i], a[j]});
        }
        sort(tmp.begin(), tmp.end(), comp);

        int sum = 0;
        for(int i = 0; i < t && tmp.size() > i; i++) 
            sum += tmp[i].fi * tmp[i].se;

        res.push_back(sum);
        tmp.clear();
        memset(check, 0, sizeof check);
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 8 6 2
// 1 1 2 2 3 4 2 3