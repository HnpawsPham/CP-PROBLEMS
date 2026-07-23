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
    int cur = 1;
    cout<<1<<" ";
    
    bool check[n + 1] = {0};
    check[1] = 1;
    for(int i = n - 1; i > 0; i--){
        if(i >= cur || (cur - i > 0 && check[cur - i])) 
            cur += i;
        else cur -= i;

        cout<<cur<<" ";
        check[cur] = 1;
    }
    return 0;
}