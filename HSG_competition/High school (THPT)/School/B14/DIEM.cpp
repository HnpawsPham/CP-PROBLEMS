#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    freopen(".\\txt\\DIEM.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n], b[n];
    for(int i =0;i<n;i++) cin>>a[i];
    for(int i = 0;i<n;i++) cin>>b[i];

    sort(a, a + n);
    sort(b, b + n);
    
    int res = 0;
    ll last = -LLONG_MAX;
    for(int i = 0;i<n;i++){
        if(a[i] > last && b[i] > last){
            res++;
            last = max(a[i], b[i]);   
        }
    }
    cout<<res<<el;
    return 0;
}