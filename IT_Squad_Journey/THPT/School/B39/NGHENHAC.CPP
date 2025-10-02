#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    // freopen("NGHENHAC.INP", "r", stdin);
    // freopen("NGHENHAC.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
  
    int l = 0, sum = 0, res = 0;
    for(int r = 0; r < n; r++){
        sum += a[r];

        while(l <= r && sum > k){
            sum -= a[l];
            l++;
        }
        if(l <= r)
            res = max(res, r - l + 1);
    }
    cout<<res;
    return 0;
}

// 5 20
// 9 3 5 4 7