#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 2e6 + 15;
int cnt[maxn];

int main(){
    freopen("ABC02.INP", "r", stdin);
    freopen("ABC02.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    memset(cnt, 0, sizeof cnt);
    vi special;

    for(int i = 1; i <= 9; i++){
        int x = 0;
        while(1){
            x = x * 10 + i;
            if(x > maxn) break;
            special.push_back(x);
        }
    }

    ll res = 0;
    for(int i = 0; i < n; i++){
        for(int x : special){
            if(x < a[i]) continue;
            res += cnt[x - a[i]];
        } 
        cnt[a[i]]++;
    }
    cout<<res;
    return 0;
}

// 3
// 13 9 2