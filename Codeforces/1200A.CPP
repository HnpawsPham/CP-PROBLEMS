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
    string s;
    cin>>n>>s;

    bitset<10> res;
    for(const char& x : s){
        if(x == 'L'){
            int j = 0;
            while(res[j]) j++;
            res[j] = 1;
        }
        else if(x == 'R'){
            int j = 9;
            while(res[j]) j--;
            res[j] = 1;
        }
        else res[x - '0'] = 0;
    }
    
    for(int i = 0; i < 10; i++)
        cout<<res[i];
    return 0;
}