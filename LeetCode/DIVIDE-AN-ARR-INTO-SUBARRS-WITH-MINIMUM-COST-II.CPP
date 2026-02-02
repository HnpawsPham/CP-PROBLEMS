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

int n, k, d;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>d;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 1; i < n; i++){
        sum = 0;
        int l = i + 1, r = min(i + d, n - 1);
        vi b = a;
        sort(b.begin() + l, b.begin() + r + 1);
        if(r - l + 1 < k - 2) continue;

        for(int j = l; j < l + k - 2; j++)
            sum += b[j];
        sum += a[0] + a[i];
        
        res = min(res, sum);
    }
    cout<<res;
    return 0;
}

// 6 3 3
// 1 3 2 6 4 2