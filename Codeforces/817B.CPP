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
    int a[n];
    for(int i= 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int cnt[3] = {0, 0, 0};
    for(const int& x : a){
        if(x == a[0]) cnt[0]++;
        else if(x == a[1]) cnt[1]++;
        else if(x == a[2]) cnt[2]++;
    }
    
    if(a[0] == a[2]) cout<<1LL * cnt[0] * (cnt[0] - 1) * (cnt[0] - 2) / 6;
    else if(a[1] == a[2]) cout<<1LL * cnt[1] * (cnt[1] - 1) / 2;
    else cout<<cnt[2]; 
    return 0;
}