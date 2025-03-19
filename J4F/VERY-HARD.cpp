#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = (ll)1e7 + 5;
ll a[105];
vector<int> ngto(maxn, 0);

void sieve(){
    ngto[1] = -1;

    for(int i = 2; i<=sqrt(maxn); i++){
        if(!ngto[i])
        for(int j = i + i; j <= maxn; j += i) ngto[j]++;
    }
    return;
}

int count(ll x){
    int cnt = 0;
    for(int i = 2; i<=sqrt(x); i++){
        if(x % i == 0){
            cnt+= 2;
            if(i == x / i) cnt--;
        }
    }
    return cnt % 2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sieve();

    for(int i = 0; i<n;i++) {
        cin>>a[i];
        if(a[i] < (ll)1e7) cout<<ngto[a[i]] % 2<<" ";
        else cout<<count(a[i])<<" ";
    }

    return 0;
}