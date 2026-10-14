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

    int n, sum;
    cin>>n>>sum;
    if(9 * n < sum) 
        return cout<<"", 0;

    string res = "";
    int sz = 0;
    for(int i = 0; i < sum / 9; i++){
        res.push_back('9');
        sz++;
    }
    res.push_back((sum % 9) + '0');
    sz++;

    while(sz < n){
        sz++;
        res.push_back('0');
    }
    cout<<res;
    return 0;
}