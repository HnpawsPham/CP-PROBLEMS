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
#define taskname "BEAUTY"

const int maxp = 1005;
bitset<maxp> nprime;
vi prime;

void sieve(){
    nprime[1] = nprime[0] = 1;

    for(int i = 2; i * i < maxp; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1;

    for(int i = 2; i < maxp; i++)
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

    sieve();
    int n;

    vi a;
    for(int i = 11; i <= 1000000; i++){
        int x = i, sum = 0;
        while(x > 0){
            sum += (x % 10) * (x % 10);
            x /= 10;
        }
        if(!nprime[sum]) a.push_back(i);
    }

    while(cin>>n)
        cout<<a[n - 1]<<el;
    return 0;
}