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
#define taskname "DAYCON"

const int maxp = 2e6 + 5;
bitset<maxp> nprime;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxp; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1;
}

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
    sieve();
    int x, prev = -1, res = n + 5;
    for(int i = 0; i < n; i++){
        cin>>x;
        if(!nprime[x]){
            if(prev != -1)
                res = min(res, i - prev + 1);
            prev = i;
        } 
    }
    cout<<(res == n + 5 ? -1 : res);
    return 0;
}