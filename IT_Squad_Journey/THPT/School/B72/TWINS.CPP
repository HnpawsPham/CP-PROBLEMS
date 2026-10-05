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
#define taskname "TWINS"

int tc = 1, m;
const int maxn = 3e6 + 6;
bitset<maxn> nprime;
ll p[maxn];
int twin[maxn];
vi prime;


void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;

    for(int i = 2; i < maxn; i++) 
        if(!nprime[i]) prime.push_back(i);
        

    m = prime.size();
    for(int i = 0; i < m; i++){
        int x = prime[i], res = 0;
        while(x > 0){
            res = res * 10 + (x % 10);
            x /= 10;
        }
        twin[i + 1] = twin[i] + (!nprime[res] && (res != prime[i]));
    }
    
    for(int i = 1; i <= m; i++)
        p[i] = p[i - 1] + prime[i - 1];
}

void sol(){
    int a, b;
    cin>>a>>b;
    int posa = lower_bound(prime.begin(), prime.end(), a) - prime.begin();
    int posb = upper_bound(prime.begin(), prime.end(), b) - prime.begin();
    cout<<p[posb] - p[posa]<<" "<<twin[posb] - twin[posa];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    p[0] = twin[0] = 0;
    sieve();
    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}