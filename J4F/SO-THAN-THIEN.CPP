#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int l, r;
const int maxn = 3e4 + 5;
bitset<maxn> nprime;

void sieve(){
    for(int i = 2; i * i <= maxn; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j +=i)
                nprime[j] = 1;
    return;
}

bool check(int x){
    int tmp = x, rx = 0;
    while(tmp > 0){
        rx = rx * 10 + tmp % 10;
        tmp /= 10;
    }
    return (__gcd(x, rx) == 1);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r;
    sieve();
    int cnt = 0;
    for(int i = l; i <= r; i++){
        if(!nprime[i] && i != 11) cnt++;
        else if(check(i)) cnt++;
    }
    cout<<cnt;
    return 0;
}