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

    int n, b, a;
    cin>>n>>b>>a;
    bool s[n];
    for(int i = 0; i < n; i++) cin>>s[i];

    int curb = b, cura = a;
    for(int i= 0; i < n; i++){
        if(cura <= 0 && curb <= 0)
            return cout<<i, 0;

        if(s[i]){
            if(curb > 0 && cura < a){
                cura++;
                curb--;
            }
            else cura--;
        }
        else{
            if(cura > 0) cura--;
            else curb--;
        }
    }
    cout<<n;
    return 0;
}