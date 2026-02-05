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
#define taskname "COMPUTER"

int a1, a2, a3, b1, b2, b3;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a1>>a2>>a3>>b1>>b2>>b3;
    int res = 0;
    while(1){
        if(a1 > 0 && b1 > 0){
            a1--;
            b1--;
            res++;
        }
        else if(a2 > 0 && b2 > 0){
            a2--;
            b2--;
            res++;
        }
        else if(a1 > 0 && b3 > 0){
            a1--;
            b3--;
            res++;
        }
        else if(a2 > 0 && b3 > 0){
            a2--;
            b3--;
            res++;
        }
        else if(a3 > 0 && b2 > 0){
            a3--;
            b2--;
            res++;
        }
        else if(a3 > 0 && b1 > 0){
            a3--;
            b1--;
            res++;
        }
        else if(a3 > 0 && b3 > 0){
            a3--;
            b3--;
            res++;
        }
        else break;
    }
    cout<<res;
    return 0;
}

// 3 4 6
// 2 11 0