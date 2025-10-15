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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int sz = 1, prevsz = 0;
    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]) sz++;
        else{
            prevsz = sz;
            sz = 1;
        }
        if(sz / 2 >= k || min(sz, prevsz) >= k) return cout<<1, 0;
    }
    cout<<0;
    return 0;
}