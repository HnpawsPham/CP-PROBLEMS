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

int tc;

int sol(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[i] = x % 2;
    }
    int res = 1;
    for(int i = 1; i < n; i++){
        int tmp = 1;
        for(int j = i; j < n; j++)
            if(a[j] != a[j - 1]) tmp++;
        res = max(res, tmp);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin>>tc;
	while(tc--){
        cout<<sol()<<el;
	}
    return 0;
}
