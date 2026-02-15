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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int cntp = 0, cntn = 0;
    for(int x : a){
        if(x > 0) cntp++;
        else if(x < 0) cntn++;
    }

    if((cntn < (n + 1) / 2) && (cntp < (n + 1) / 2)) 
        return cout<<0, 0;

    if(cntn < cntp) cout<<1;
    else cout<<-1;
    return 0;
}