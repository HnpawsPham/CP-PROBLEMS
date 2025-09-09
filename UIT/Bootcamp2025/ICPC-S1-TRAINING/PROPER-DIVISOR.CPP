#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int maxn = 1e7 + 2;
const int maxd = 450;
int cntd[maxn] = {0}, f[maxd] = {0};
int l, r, k, tc;

void sieve(){
    for(int i = 1; i < maxn; i++)
        for(int j = i; j < maxn; j+=i)
            cntd[j]++;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    sieve();

    while(tc--){
        memset(f, 0, sizeof f);
        cin>>l>>r>>k;

        for(int i = l; i <= r; i++)
            f[cntd[i] - 1]++;

        int sum = 0, d;
        for(int i = maxd - 1; i >= 0; i--){
            sum += f[i];
            if(sum >= k){
                d = i;
                break;
            }
        }
        
        int x;
        for(int i = l; i <= r; i++)
            if(cntd[i] - 1 == d){
                x = i;
                break;
            }
        cout<<x<<" "<<d<<el;
    }

    return 0;
}