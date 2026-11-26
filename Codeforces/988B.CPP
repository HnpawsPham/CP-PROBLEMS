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

bool comp(const string& a, const string& b){
    if(a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i];
    sort(a, a + n, comp);

    for(int i = 1; i < n; i++)
        if(a[i].find(a[i - 1]) == string::npos)
            return cout<<"NO", 0;

    cout<<"YES"<<el;
    for(const string& x : a)
        cout<<x<<el;
    return 0;
}