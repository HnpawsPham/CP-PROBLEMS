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

string sol(){
    int n;
    string s;
    cin>>n>>s;
    
    int minn = n;
    int cnt = 0;
    
    for(int i= 0; i < n; i++){
        if(s[i] == '1') cnt++;
        else {
            if(0 < cnt && cnt < 3) return "No";
            cnt = 0;
        }
    }
    if(0 < cnt && cnt < 3) return "No";
    return "Yes";
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
