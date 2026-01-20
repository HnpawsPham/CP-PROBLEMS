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

int s, n;
const int maxn = 1e5 + 5;
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>s;
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n, mid, cnt = 0;
    ll res = 0;
    
    while(l <= r){
        mid = (l + r) / 2;

        vll cost;
        for(int i = 0; i < n; i++)
            cost.push_back(a[i] + 1LL * (i + 1) * mid);
        sort(cost.begin(), cost.end());

        ll sum = accumulate(cost.begin(), cost.begin() + mid, 0LL);

        if(sum <= s){
            cnt = mid;
            res = sum;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<cnt<<" "<<res;
    return 0;
}