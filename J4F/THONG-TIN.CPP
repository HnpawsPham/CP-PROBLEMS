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
ll s;
const int maxn = 1e5 + 5;
int a[maxn], w[maxn];

int main(){
    // freopen("TT.INP", "r", stdin);
    // freopen("TT.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s;
    for(int i= 0; i < n; i++) cin>>a[i];
    for(int i= 0; i < n; i++) cin>>w[i];

    ll suma = 0, sumw = 0, res = 0;
    int l = 0;
    for(int r = 0; r < n; r++){
        suma += a[r];
        sumw += w[r];

        while(sumw > s){
            sumw -= w[l];
            suma -= a[l];
            l++;
        }

        int len = r - l + 1;
        if(len >= k){
            ll tmp = suma;
            for(int i = 0; i < len % k; i++) 
                tmp -= a[l + i];
            res = max(res, tmp);
        }
    }
    cout<<res;
    return 0;
}

// 5 2 6
// 3 -1 2 5 -2
// 2 1 2 2 1

// 3 2 5
// 10 20 5
// 1 1 1