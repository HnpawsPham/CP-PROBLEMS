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

    int a, b;
    cin>>a>>b;

    int k = 1;
    while(1){
        ll x = a - 1LL * b * k;
        if(x < k) return -1;

        if(__builtin_popcountll(x) <= k) return k;
        k++;
    }

    return 0;
}