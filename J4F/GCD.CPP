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
const int maxp = 5e6 + 5;
int spf[maxp] = {0}, cnt[maxp] = {0};

void sieve(){
    spf[0] = spf[1] = -1;
    for(int i = 2; i * i < maxp; i++)
        if(!spf[i])
            for(int j = i * i; j < maxp; j+=i)
                if(!spf[j]) spf[j] = i;

    for(int i = 2; i < maxp; i++)
        if(!spf[i]) spf[i] = i;
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
    int a[n];
    int x = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        x = __gcd(a[i], x);
    }

    sieve();
    for(int i = 0; i < n; i++){
        if(a[i] / x == 1 || spf[a[i]] == -1) continue;
        
        int num = a[i] / x;
        while(num > 1){
            int p = spf[num];
            cnt[p]++;
            
            while(num % p == 0)
                num /= p;
        }
    }

    int maxx = *max_element(cnt, cnt + maxp);
    cout<<(maxx > 0 ? n - maxx : -1);
    return 0;
}