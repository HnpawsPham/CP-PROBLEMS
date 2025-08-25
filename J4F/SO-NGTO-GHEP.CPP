#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e6 + 5;
bitset<maxn> nprime;
vector<int> p;

void sieve(){
    for(int i = 2; i <= sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i) 
                nprime[j] = 1;
    
    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) p.push_back(i);
    return;
}

bool check(ll x){
    if(x % 2 == 0 || x % 3 == 0) return 0;

    for(ll i = 5; i * i <= x; i+= 6)
        if(x % i == 0 || x % (i + 2) == 0) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    sieve();
    
    vector<ll> a;
    for(int i = 1; a.size() < n; i+=2){
        ll x = stoll(to_string(p[i - 1]) + to_string(p[i]));
        if(x < maxn && !nprime[x]) a.push_back(x); 
        else if(check(x)) a.push_back(x);
    }
    cout<<a[n - 1];
    return 0;
}