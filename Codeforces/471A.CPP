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

    int cnt[10];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < 6; i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    bool leg = 0, elep = 0, bear = 0;
    for(int i = 0; i < 10; i++){
        if(cnt[i] == 6) elep = 1;
        if(cnt[i] >= 4) leg = 1;
        else if(cnt[i] >= 2) elep = 1;  
        else if(cnt[i]) bear = 1;
    }
    if(leg && elep) cout<<"Elephant";
    else if(leg && bear) cout<<"Bear";
    else cout<<"Alien";
    return 0;
}