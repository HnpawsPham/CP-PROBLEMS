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

    int n;
    string s;
    cin>>n>>s;
    vll a;

    string t;
    for(const char& x : s){
        if(x == ','){
            a.push_back(stoi(t));
            t.clear();
        }
        else t.push_back(x);
    }
    a.push_back(stoi(t));


    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(abs(a[i]) > abs(a[j]) && (a[i] % a[j]))
                return cout<<"NOT FRIENDS", 0;
    cout<<"FRIENDS";
    return 0;
}