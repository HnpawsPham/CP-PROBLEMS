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
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int cnt = 0, l = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            if(l == -1) l = i;
            cnt += i - l + 1;
        }
        else l = -1;
    }
    cout<<cnt;
    return 0;
}