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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];   
    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    int len = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(p[j] - p[i - 1] > 100 * (j - i + 1))
                len = max(len, j - i + 1);
    cout<<len;
    return 0;
}