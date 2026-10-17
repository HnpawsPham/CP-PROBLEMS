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

int n, m;
const int maxn = 1e5 + 5;
bitset<maxn> check;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    check.reset();

    int x = n % m;
    for(int i = n;;i++){
        if(x == 0)
            return cout<<"Yes", 0;
        
        if(check[x]) break;
        check[x] = 1;
        x = 2 * (x % m);
    }
    cout<<"No";
    return 0;
}