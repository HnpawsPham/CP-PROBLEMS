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
#define taskname "SMM"

const int maxn = 1005;
bitset<maxn> nprime;
int n;

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
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
    sieve();
    vi res;
    for(int i = 1; i < 5235000; i++){
        int sum = 0, x = i;
        while(x > 0){
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        if(!nprime[sum]) res.push_back(i);
    }
    for(int i = 0; i < n; i++)
        cout<<res[i]<<" ";
    return 0;
}