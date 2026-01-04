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

int n;
const int maxn = 5e3 + 5;
bitset<maxn> nprime;
vi prime;

void sieve(int n){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i <= n + 15; i++)
        if(!nprime[i])
            for(int j = i * i; j <= n + 15; j+=i)
                nprime[j] = 1;
    
    for(int i = 2; i <= n; i++)
        if(!nprime[i]) prime.push_back(i);
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sieve(n);

    int cnt = 0;
    vi res;
    for(int x : prime){
        if(x > n) break;
        int tmp = x;
        for(int i = 1; tmp <= n; i++){
            cnt++;
            res.push_back(tmp);
            tmp *= x;
        }
    }
    cout<<cnt<<el;
    for(int x : res) cout<<x<<" ";
    return 0; 
}