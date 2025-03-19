#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

int n;
const int maxn = 100;
int a[maxn];

bool check(){
    ll num = 0;
    for(int i = 0; i < n; i++)
        num = num * 10 + a[i];
    return (num % 11 == 0);
}

int main(){
    freopen("HOANVIDEP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++) a[i] = i + 1;
    int cnt = 0;
    do{
        if(check()) cnt = (cnt + 1) % MOD;
    }while(next_permutation(a, a + n));

    cout<<cnt;
    return 0;
}