#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>s;
    vector<string> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<string> res = {a[0]};
    string prev = a[0];
    sort(prev.begin(), prev.end());

    for(int i = 1; i < n; i++){
        string tmp = a[i];
        sort(tmp.begin(), tmp.end());

        if(tmp != prev){
            res.push_back(a[i]);
            prev = tmp;
        }
    }

    for(string x : res) cout<<x<<el; 
    return 0;
}