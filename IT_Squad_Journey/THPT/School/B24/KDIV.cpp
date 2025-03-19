#include <iostream>
#include <cstring>
using namespace std;
#define el "\n"

int q, n, m , k;
const int maxn = (int)1e5 + 5;
bool nprime[maxn];
int cntp[maxn], pre[18][maxn];

void sieve(){
    for(int i = 2; i * i < maxn; i++){
        if(!nprime[i]){
            cntp[i]++;

            for(int j = i + i; j < maxn; j+=i){
                nprime[j] = 1;
                int x = j;
                while(x % i == 0){
                    x /= i;
                    cntp[j]++;
                }
            }
        }
    }

    for(int i = 1; i <= 16; i++){
        pre[i][0] = 0;
        for(int j = 1; j < maxn - 4;j++) 
            pre[i][j] = pre[i][j - 1] + (cntp[j] == i); 
    }
    return;
}

int main(){
    freopen(".\\txt\\KDIV.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(cntp, 0, sizeof(cntp));
    sieve();

    cin>>q;
    while(q--){
        cin>>n>>m>>k;
        cout<<pre[k][m] - pre[k][n - 1]<<el;
    }

    return 0;
}