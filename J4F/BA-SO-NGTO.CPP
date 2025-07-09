#include <bitset>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
#define el "\n"

struct expo{
    int fi, se, th;
    expo(int f, int s, int t) : fi(f), se(s), th(t) {}
};

ll n;
int k;
const int maxn = 1e6 + 5;
bitset<maxn> nprime;
vector<int> p;
vector<expo> ex;

void sieve(){
    nprime[0] = nprime[1] = 1;

    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j += i)
                nprime[j] = 1;
    
    for(int i = 2; i < maxn; i++)
        if(!nprime[i]) p.push_back(i);
    return;
}

ll safe_mul(ll a, ll b){
  if(a == 0 || b == 0) return 0;
  if(a > n / b) return n + 1;
  return a * b;
}

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b & 1) return safe_mul(half, safe_mul(half, a));
    return safe_mul(half, half);
}

void gen_expo(){
    for(int t1 = 2; t1 <= 59; t1++)
        for(int t2 = 2; t2 <= 37; t2++)
            for(int t3 = 2; t3 <= 26; t3++)
                if(1LL * t1 * t2 * t3 == k)
                    ex.push_back({t1, t2, t3});
    return;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    sieve();
    gen_expo();
    int m = p.size();
    ll res = 0;

    for(int i = 2; i < m; i++){
        for(const expo& t: ex){
            ll x = ppow(p[i - 2], t.fi - 1);
            ll y = ppow(p[i - 1], t.se - 1);
            ll z = ppow(p[i], t.th - 1);

            ll mul = safe_mul(safe_mul(x, y), z);
            if(mul <= n) res = max(res, mul);
        }
    }
    cout<<res;
    return 0;
}