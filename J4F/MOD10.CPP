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
int fact[10];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(n == 1) return cout<<0, 0;

    fact[0] = 1;
    for(int i = 1; i <= 9; i++)
        fact[i] = fact[i - 1] * i;

    string res = "";
    for(int i = 9; i > 0; i--)
        while(n >= fact[i]){
            n -= fact[i];
            res.push_back(i + '0');
        }

    sort(res.begin(), res.end());
    cout<<res;
    return 0;
}