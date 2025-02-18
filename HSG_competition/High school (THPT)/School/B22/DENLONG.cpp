#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k, x;
const int maxn = (int)1e5 + 5;
int a[maxn];

bool isOk(int l, int r){
    set<int> s;

    for(int i = l; i <=r; i++) s.insert(a[i]);
    return (s.size() <= k);
}

int main(){
    freopen(".\\txt\\DENLONG.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>x;

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    int l = 0, r = n - 1;
    int res = 0;

    while(l < r){
        int mid = (l + r)/ 2;
        if(isOk(l, r) == k){
            res = max(r - l + 1, res);
            l = mid;
        }
        else r = mid;
    }
    
    cout<<res + x;

    return 0;
}