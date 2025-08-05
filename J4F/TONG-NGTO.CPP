#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int maxn = 1e7 + 2;
bitset<maxn> nprime;

void sieve(){
    for(int i = 2; i < sqrt(maxn); i++)
        if(!nprime[i])
            for(int j = i * i; j < maxn; j+=i)
                nprime[j] = 1;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    sieve();
    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    while(q--){
        int l, r;
        cin>>l>>r;
        
        int sum = p[r] - p[l - 1];
        if(sum < 2) cout<<0<<el;
        else cout<<!nprime[sum]<<el;
    }

    return 0;
}