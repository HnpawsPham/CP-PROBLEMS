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

int tc = 1;
const int maxn = 5e5 + 5;
int spf[maxn];

void sieve(){
    memset(spf, -1, sizeof spf);
    spf[1] = 1;

    for(int i = 2; i * i < maxn; i++)
        if(spf[i] == -1)
            for(int j = i; j < maxn; j+=i)
                if(spf[j] == -1) spf[j] = i;
    return;
}

int color[maxn];
void precompute(){
    for(int i = 1; i < maxn; i++){
        int x = i, cnt = 1;
        while(x > 1){
            x /= spf[x];
            cnt++;
        }
        color[i] = cnt;
    }
    return;
}

void sol(){
    int n;
    cin>>n;
    
    int maxx = 1;
    for(int i = 1; i <= n; i++)
        maxx = max(maxx, color[i]);

    cout<<maxx<<el;
    for(int i = 1; i <= n; i++) 
        cout<<color[i]<<" ";
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

    cin>>tc;
    sieve();
    precompute();

    while(tc--){
        sol();
        cout<<el;
    }
    return 0;
}