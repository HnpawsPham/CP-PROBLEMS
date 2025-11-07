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

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n == 0) return cout<<1, 0;

    ll res = 1;

    while(n % 2 == 0) n /= 2;
    for(int i = 3; i * i <= n; i += 2){
        int cnt = 0;

        while(n % i == 0){
            n /= i;
            cnt++;
        }
        
        if(i % 4 == 1)
            res *= (2LL * 1LL * cnt + 1);
    }

    if(n > 1 && n % 4 == 1) res *= 3;
    cout<<4 * res;
    return 0;
}