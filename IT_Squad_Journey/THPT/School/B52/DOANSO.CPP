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
#define taskname "DOANSO"

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

    int l = 1, r = 10000 - 1, mid, cnt = 0;
    while(l <= r){
        mid = (l + r) / 2;
        cnt++;
 
        if(mid == n) break;
        if(mid < n)
            l = mid + 1;
        else r = mid - 1;
    } 
    cout<<cnt + (mid != n);
    return 0;
}