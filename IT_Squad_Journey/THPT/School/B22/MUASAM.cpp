#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, l, r;
const int maxn = (int)1e6 + 5;
ll a[maxn];

int main(){
    freopen(".\\txt\\MUASAM.INP", "r", stdin);
    freopen("MUASAM.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    for(int i = 0; i < n; i++) cin>>a[i];

    sort(a, a + n);

    ll res = LLONG_MAX;
    int i = 0, j = n - 1;

    while(i < j){
        ll sum = a[i] + a[j];
        if(sum >= l && sum <= r) {
            res = min(res, sum);
            j--;
        }
        else if(sum < l) i++;
        else if(sum > r) j--;
    }
    cout<<res<<el;

    return 0;
}