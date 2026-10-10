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

int n;
const int maxn = 1e5 + 5;
int a[maxn];

bool check(int t){
    ll sum = 0, maxx = -1e9 -15;
    for(int i = 0; i < n; i++){
        sum = max(sum + a[i] - t, 1LL * a[i] - t);
        maxx = max(maxx, sum);
    }
    return maxx >= 0;
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
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = 1e9 + 5, mid, res;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}