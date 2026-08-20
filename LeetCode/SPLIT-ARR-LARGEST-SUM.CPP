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

bool check(int t, int k, const vi& a){
    int sum = 0, cnt = 1;
    for(const int& x : a){
        if(sum + x > t){
            sum = x;
            cnt++;
        }
        else sum += x;
    }
    return cnt <= k;
}

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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    const int oo = 1e9 + 5;
    int l = *max_element(a, a + n), r = oo, mid, res = oo;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(mid, k, a)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}

// 5 2
// 7 2 5 10 8