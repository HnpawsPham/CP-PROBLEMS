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
    int a[n], b[n];
    for(int i = 0; i < n; i++) 
        cin>>a[i]>>b[i];

    int markA, markB;
    markA = markB = n / 2;

    int i = 0, j = 0;
    while(i < n && j < n && i + j < n){
        if(a[i] < b[j]) 
            markA = max(markA, ++i);
        else markB = max(markB, ++j);
    }

    for(i = 0; i < n; i++){
        if(i < markA) cout<<'1';
        else cout<<'0';
    }
    cout<<el;
    for(i = 0; i < n; i++){
        if(i < markB) cout<<'1';
        else cout<<'0';
    }
    return 0;
}