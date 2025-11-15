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

int tc = 1;
const int maxn = 2e5 + 5;
int n;
int a[maxn], b[maxn];

bool check(int t){
    ll sum = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > t) sum += b[i];
    return sum <= t;
}

int sol(){
    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0; j < n; j++) cin>>b[j];

    int l = 0, r = 1e9 + 5;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}