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
    int n, m;
    cin>>n>>m;
    string a[n];
    int cnt1 = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(char x : a[i]) 
            if(x == '1') cnt1++;
    }

    cout<<3 * cnt1<<el;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '1'){
                int x1 = i + 1, y1 = j + 1;

                int x2 = (x1 < n ? x1 + 1 : x1 - 1);
                int y2 = (y1 < m ? y1 + 1 : y1 - 1);

                cout<<x2<<" "<<y1<<" "<<x1<<" "<<y2<<" "<<x1<<" "<<y1<<el;
                cout<<x2<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<el;
                cout<<x1<<" "<<y2<<" "<<x2<<" "<<y2<<" "<<x1<<" "<<y1<<el;
            }
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
    }
    return 0;
}