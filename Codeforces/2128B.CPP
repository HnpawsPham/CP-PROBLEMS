#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

string sol(){
    int a[n];
    string res = "";
    for(int i = 0; i < n; i++) cin>>a[i];

    int l = 0, r = n - 1;
    for(int i = 0; i < n; i++){
        bool addL = 0;
        if(i % 2) addL = (a[l] < a[r]);
        else addL = (a[l] > a[r]);

        if(addL){
            res += 'L';
            l++;
        }
        else{
            res += 'R';
            r--;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        cout<<sol()<<el;
    }

    return 0;
}