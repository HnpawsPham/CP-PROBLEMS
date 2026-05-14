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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt[205] = {0};
    memset(cnt, 0, sizeof cnt);
    for(const int& x : a)
        cnt[x]++;

    int n = *max_element(a.begin(), a.end());
    for(int i = 1; i < n; i++)
        if(cnt[i] != 1) return cout<<0, 0;
    cout<<(cnt[n] == 2);
    return 0;
}