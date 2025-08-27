#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vi res;
    res.push_back(0);
    
    for(int i = 1; i < n; i++){
        int pos, m;
        pos = m = res.size();

        for(int j = 0; j < m; j++)
            if(a[i][res[j]] == '1'){
                pos = j;
                break;
            }

        res.insert(res.begin() + pos, i);
    }
    for(int x : res) cout<<x + 1<<" ";
    return 0;
}