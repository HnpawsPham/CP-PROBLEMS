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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    
    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++){
            int z = i ^ j;
            if(z < i || z < j || z > n) continue;
            if(i + j > z && i + z > j && j + z > i)
                cnt++;
        }
    cout<<cnt;
    return 0;
}