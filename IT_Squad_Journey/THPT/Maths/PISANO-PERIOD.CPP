#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

// nếu đề bài yêu cầu f(i) % MOD thì dùng (k phải số fibo thông thường, fibo này là kq của mod) 
const int MOD = 1e3 + 7;
int period = 0;
vector<ll> fibo;

void calc_period(){
    ll f1 = 0, f2 = 1, tmp;

    do{ 
        tmp = (f1 + f2) % MOD;
        f1 = f2;
        f2 = tmp;
        period++;
    } while(!(f1 == 0 && f2 == 1));
    return;
}

void precompute(){
    fibo.resize(period);
    fibo[0] = 0;
    if(period >= 2) fibo[1] = 1;

    for(int i = 2; i < period; i++)
        fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
    return;
}

ll calc_fibo(ll x){
    return fibo[x % period];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    calc_period();
    precompute();

    cout<<calc_fibo(5);
    return 0;
}