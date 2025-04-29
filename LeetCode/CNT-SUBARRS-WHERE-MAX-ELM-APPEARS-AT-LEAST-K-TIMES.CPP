#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, maxx, appear = 0;
    ll cnt = 0;

    for(int x : a) maxx = max(maxx, x);

    for(int r = 0; r < n; r++){
        if(a[r] == maxx) 
            appear++;

        while(l <= r && appear >= k){
            if(a[l] == maxx)
                appear--;
            l++;
        }
        cnt += l;
    }
    cout<<cnt;
    return 0;
}