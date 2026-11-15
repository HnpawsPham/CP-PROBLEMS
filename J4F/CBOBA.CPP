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
#define taskname "CBOBA"

int n;
const int maxn = 1e6 + 5;
int a[maxn];

void sub2(){
    unordered_map<int, bool> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]] = 1;

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(mp.count(a[i] + a[j]))
                cnt++;
    cout<<cnt;
}

void sub3(){
    ll cnt = 0;
    for(int i = 3; i <= n; i++)
        cnt += (i - 1) / 2;
    cout<<cnt;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n <= 3000) sub2();
    else sub3();
    return 0;
}

// 7
// 1 3 2 25 20 45 100