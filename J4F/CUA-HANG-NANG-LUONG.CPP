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

int n, q;
const int maxn = 5e5 + 5;
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];

    vi gud;
    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            gud.push_back(a[i]);
            continue;
        }

        ll x2 = 1, x3 = 1, x5 = 1;
        for(int j = 0; j < 31; j++){
            x2 *= 2;
            x3 *= 3;
            x5 *= 5;
            if(a[i] == x2 || a[i] == x3 || a[i] == x5)
                gud.push_back(a[i]);
            else if(min(x2, min(x3, x5)) > a[i])
                break;
        }
    }
    sort(gud.begin(), gud.end());

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<upper_bound(gud.begin(), gud.end(), r) - lower_bound(gud.begin(), gud.end(), l)<<el;
    }
    return 0;
}