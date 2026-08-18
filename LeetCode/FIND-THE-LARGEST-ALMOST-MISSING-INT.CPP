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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = -1;
    int cnt[55];
    memset(cnt, 0, sizeof cnt);

    bool check[55];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i + k - 1 < n; i++){
        memset(check, 0, sizeof check);
        for(int j = i; j < min(n, i + k); j++)
            if(!check[a[j]]){
                cnt[a[j]]++;
                check[a[j]] = 1;
            }
    }
    
    for(int i = 0; i < 55; i++)
        if(cnt[i] == 1) res = i;
    cout<<res;
    return 0;
}

// 5 3
// 3 9 2 1 7