#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();
    stack<char> st;
    string res = "";
    vector<char> minn(n);

    minn[n - 1] = s[n - 1];
    for(int i = n - 2; i >= 0; i--)
        minn[i] = min(minn[i + 1], s[i]);

    for(int i = 0; i < n; i++){
        st.push(s[i]);

        while(!st.empty() && ( i == n - 1 || st.top() <= minn[i + 1])){
            res += st.top();
            st.pop();
        }
    }

    cout<<res;
    return 0;
}