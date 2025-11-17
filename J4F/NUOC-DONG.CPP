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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n - 1, lmax = 0, rmax = 0;
    ll sum = 0;
    while(l <= r){
        if(a[l] <= a[r]){
            lmax = max(lmax, a[l]);
            sum += lmax - a[l];
            l++;
        }
        else{
            rmax = max(rmax, a[r]);
            sum += rmax - a[r];
            r--;
        }
    }
    cout<<sum;
    return 0;
}