#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    pii a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i].se;
        a[i].fi = 10 - (a[i].se % 10);
    }
    sort(a, a + n);

    int res = 0;
    for(int i = 0; i < n; i++){
        if(k >= a[i].fi){
            k -= a[i].fi;
            res += (a[i].se + a[i].fi) / 10;
        }
        else if(k > 0 && k < a[i].fi){
            res += (a[i].se + k) / 10;
            k = 0;
        }
        else res += a[i].se / 10;
    }
    cout<<res;
    return 0;
}