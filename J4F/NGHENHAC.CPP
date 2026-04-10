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
    int a[n] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, sum = 0, res = 0;
    for(int r = 0; r < n; r++){
        sum += a[r];

        while(l <= r && sum > k){
            sum -= a[l];
            l++;
        }
        if(sum <= k) res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}