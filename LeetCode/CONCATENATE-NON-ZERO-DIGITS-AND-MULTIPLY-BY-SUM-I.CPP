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
    if(n == 0) return cout<<0, 0;
    
    int sum = 0;
    string res;
    while(n > 0){
        if(n % 10){
            sum += (n % 10);
            res.push_back((n % 10) + '0');
        }
        n /= 10;
    }
    reverse(res.begin(), res.end());
    cout<<1LL * stoi(res) * sum;
    return 0;
}