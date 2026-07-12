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
//#define taskname ""

const int maxp = 1e7 + 10;
bitset<maxp> nprime;

void sieve(){
    nprime[1] = nprime[0] = 1;

    for(int i = 2; i * i < maxp; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1;
}

namespace sub2{
    bool isprime(int x){
        if(x < 2) return 0;

        for(int i = 2; i * i <= x; i++)
            if(x % i == 0) return 0;
        return 1;
    }

    bool check(int x){
        if(!isprime(x)) return 0;
        
        bool ok = 0;
        for(int i = 0; i < 10 && !ok; i++)
            if(isprime(x * 10 + i))
                ok = 1;
        if(!ok) return 0;

        while(x / 10 > 0){
            x /= 10;
            if(!isprime(x)) return 0;
        }
        return 1;
    }
};

namespace sub3{
    bool checksub = 1;

    void prep(){
        if(checksub) sieve();
    }

    bool check(int x){
        if(nprime[x]) return 0;

        bool ok = 0;
        for(int i = 0; i < 10 && !ok; i++)
            if(!nprime[x * 10 + i])
                ok = 1;
        if(!ok) return 0;

        while(x / 10 > 0){
            x /= 10;
            if(nprime[x]) return 0;
        }
        return 1;
    }   
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 5];
    for(int i = 0; i < n; i++){
        cin>>a[i];
        if(a[i] > 1e6) sub3::checksub = 0;
    }
    sub3::prep();

    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (sub3::checksub ? sub3::check(a[i - 1]) : sub2::check(a[i - 1]));

    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<p[r] - p[l - 1]<<el;
    }
    return 0;
}