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
    // freopen("KHUYENMAI.INP", "r", stdin);
    // freopen("KHUYENMAI.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    n *= n;
    int a[n];
    for(int i = 0; i < n;i++) cin>>a[i];
    sort(a, a + n, greater<int>());

    int l = 0, r = n - 1, sum, res = 0;
    while(l < r){
        sum = a[l] + a[r];
        if(sum > k) l++;
        else{
            res = max(res, a[l] + a[r]);
            r--;
        }
    }
    cout<<res;
    return 0;
}

// 5 14
// 8 1 8 3 3
// 1 2 1 1 3
// 1 9 9 3 3 
// 9 7 9 3 8
// 8 9 8 9 14

// 5 14
// 9 1 6 3 3
// 1 2 1 1 3
// 1 9 9 3 3 
// 9 7 9 3 8
// 8 9 8 9 14