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

const int oo = 1e9 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    string a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];

    int pos[k];
    for(int i = 0; i < k; i++)
        pos[i] = i;

    int res = oo;
    do{
        int minn = oo, maxx = 0;

        for(int i = 0; i < n; i++){
            int x = 0;
            for(int j = 0; j < k; j++) 
                x = x * 10 + (a[i][pos[j]] - '0');

            minn = min(minn, x);
            maxx = max(maxx, x);
        }

        res = min(res, maxx - minn);
    } while(next_permutation(pos, pos + k));

    cout<<res;
    return 0;
}