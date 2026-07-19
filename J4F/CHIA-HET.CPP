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

const int maxn = 1e6 + 5;
int spf[maxn], mp[maxn] = {0};

void sieve(){
    memset(spf, -1, sizeof spf);
    
    for(int i = 2; i * i < maxn; i++)
        if(spf[i] == -1)
            for(int j = i; j < maxn; j+=i)
                if(spf[j] == -1) spf[j] = i;

    for(int i = 2; i < maxn; i++)
        if(spf[i] == -1) spf[i] = i;
}

void pfact(int x){
    while(x > 1){
        int p = spf[x];
        while(x % p == 0){
            x /= p;
            mp[p]++;
        }
    }
}

bool check(int a, int b){
    if(a == 1) return 1;

    while(a > 1){
        int p = spf[a], cnt = 0;
        while(a % p == 0){
            cnt++;
            a /= p;
        }
        
        if(1LL * cnt * 1LL * b > mp[p])
            return 0;
    }
    return 1;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin>>n;
    sieve();
    for(int i = 0; i < n; i++){
        cin>>x; 
        pfact(x);
    }

    int tc;
    cin>>tc;
    while(tc--){
        int x, p;
        cin>>x>>p;
        cout<<check(x, p);
    }
    return 0;
}