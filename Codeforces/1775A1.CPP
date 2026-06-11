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
 
    for(int i = 0; i < n - 2; i++)
        for(int j = i + 1; j < n - 1; j++){
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, j - i);
            string c = s.substr(j + 1);
            if((b <= a && b <= c) || (b >= a && b >= c)){
                cout<<a<<" "<<b<<" "<<c<<" ";
                return;
            }
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