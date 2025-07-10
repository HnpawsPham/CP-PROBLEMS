#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    sort(a.begin(), a.end());
    int cnt = 0;
    for(const int& x : a){
        if(x > k) break;
        cnt++
        k -= x;
    }
    cout<<cnt;
    return 0;
}
