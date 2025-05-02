#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, pills, strength;

bool check(int k, vector<int>& a, vector<int>& b){
    multiset<int> ms(b.begin() + (m - k), b.end());

    for(int i = k - 1; i >= 0; i--){
        auto it = prev(ms.end());

        if(it >= a[i]) ms.erase(it);
        else{
            if(!pills) return 0;

            auto pos = ms.lower_bound(a[i] - strength);
            if(pos == ms.end()) return 0;
            
            pills--;
            ms.erase(pos);
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>pills>>strength;
    vector<int> a(n), b(m);
    // a = task, b = worker
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int l = 0, r = min(n, m), mid, res;
    while(l <= r){
        mid = (l + r) / 2;

        if(check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}