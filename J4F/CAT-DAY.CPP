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

int n, k;
const int maxn = 2e5 + 5;
int a[maxn];

bool check(int t){
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += a[i] / t;
        if(a[i] % t == 0) cnt--; 
    }
    return cnt <= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 1, r = 1e9 + 2;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}