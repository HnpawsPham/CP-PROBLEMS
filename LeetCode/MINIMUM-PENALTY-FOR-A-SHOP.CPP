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

string s;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    
    vi p(n + 1, 0);
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (s[i - 1] == 'Y');

    int minn = n + 1, res = 0;
    for(int i = 1; i <= n + 1; i++){
        int tmp = i + p[n] - 2 * p[i - 1];
        if(tmp < minn){
            minn = tmp;
            res = i;
        }
    }
    cout<<res - 1;
    return 0;
}