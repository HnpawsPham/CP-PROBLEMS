#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second;
int n;

const ll oo = 1e14;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1][n + 1];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];

    bool del[n + 1] = {0};

    for(int k = 0; k < n; k++){
        int x;
        cin>>x;

        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                

        ll sum = 0;

        for(int i = 0; i < n; i++){
            ll mindis = oo;

            for(int j = i; j < n; j++){
                if(del[j] || del[i]) continue;
                mindis = min(mindis, (ll)a[i][j]);
            }
            sum += mindis;
        }
        cout<<sum<<" ";
        del[x] = 1;
    }

    return 0;
}