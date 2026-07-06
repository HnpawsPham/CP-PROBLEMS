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
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0;
    int cnt[500005] = {0};
    ll res = 0;

    for(int r = 0; r < n; r++){
        cnt[a[r]]++;

        while(l <= r && cnt[a[r]] > 2)
            cnt[a[l++]]--;
        
        res += (r - l + 1);
    }
    cout<<res;
    return 0;
}