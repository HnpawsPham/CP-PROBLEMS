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

void sol(){
    string s;
    cin>>s;
    int n = s.length();

    char minn = s[1];
    string smax;
    smax.push_back(s[1]);
    int posmin = 1;

    for(int i = 2; i < n - 1; i++){
        if(minn > s[i]){
            minn = s[i];
            posmin = i;
        }
        smax.push_back(s[i]);
    }
 
    string smin = string(1, minn);
    string lmin, rmin;
    for(int i = 0; i < posmin; i++)
        lmin.push_back(s[i]);
    for(int i = posmin + 1; i < n; i++)
        rmin.push_back(s[i]);

    if(lmin >= smin && rmin >= smin){
        cout<<lmin<<" "<<minn<<" "<<rmin;
        return;
    }

    if(smax >= string(1, s[0]) && smax >= string(1, s[n - 1])){
        cout<<s[0]<<" "<<smax<<" "<<s[n - 1];
        return;
    }

    cout<<":(";
    return;
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
        sol();
        cout<<el;
    }
    return 0;
}