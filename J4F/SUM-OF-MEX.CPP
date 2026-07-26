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

int tc = 1;

ll sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool check[n + 2] = {0};
    ll sum = 0;
    for(int l = 0; l < n; l++){
        memset(check, 0, sizeof check);
        int cnt = 0, mex = 0, blank = 0;

        for(int r = l; r < n; r++){
            if(a[r] == -1) cnt++;
            else if(a[r] <= n && !check[a[r]]){
                check[a[r]] = 1;
                if(a[r] < mex) blank--;
            }

            while(check[mex] || blank < cnt){
                if(!check[mex]) blank++;
                mex++;
            }   
            sum += mex;
        }
    }
    return sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}