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

    string s;
    cin>>s;
    stack<int> st;

    int cnt = 0;
    for(char x : s){
        if(!st.empty() && st.top() == x) {
            cnt++;
            st.pop();
        }
        else st.push(x);
    }
    cout<<(cnt % 2 ? "Yes" : "No");
    return 0;
}