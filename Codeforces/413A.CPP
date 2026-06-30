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

    int n, m, minn, maxx;
    cin>>n>>m>>minn>>maxx;
    int a[m];
    bool checkmin = 0, checkmax = 0;
    for(int i = 0; i < m; i++){
        cin>>a[i];
        
        if(a[i] > maxx || a[i] < minn) 
            return cout<<"Incorrect", 0;

        if(a[i] == minn) checkmin = 1;
        else if(a[i] == maxx) checkmax = 1;
    }

    if(checkmax && checkmin) return cout<<"Correct", 0;

    if(checkmax || checkmin){
        if(n - m >= 1) 
            return cout<<"Correct", 0;
    }
    else if(n - m >= 2) return cout<<"Correct", 0;

    cout<<"Incorrect";
    return 0;
}