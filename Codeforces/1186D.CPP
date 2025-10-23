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
    db a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    int sumz = 0;
    for(db x : a){
        int z = floor(x);
        sumz += z;
    }

    sumz *= -1;
    for(int i = 0; i < n; i++){
        int z = floor(a[i]);
        if(sumz > 0 && a[i] != z){
            cout<<z + 1<<el;
            sumz--;
        }
        else if(sumz < 0 && a[i] != z){
            cout<<z - 1<<el;
            sumz++;
        }
        else cout<<z<<el;
    }
    return 0;
}