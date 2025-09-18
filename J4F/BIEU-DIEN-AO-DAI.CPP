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
    // freopen("AODAI.INP", "r", stdin);
    // freopen("AODAI.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n, greater<int>());

    vi b;
    int cnt = 0;

    for(int i = 0; i < n; i++){
        bool ok = 0;
        for(int j = 0; j < b.size(); j++){
            if(a[i] + b[j] <= 4){
                ok = 1;
                b[j] += a[i];
                break;
            }
        }
        if(!ok) b.push_back(a[i]);
    }
    cout<<b.size();
    return 0;
}