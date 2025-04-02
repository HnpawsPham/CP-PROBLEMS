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

    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
            st.push(s[i]);
        
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (st.empty()) return cout<<0, 0; 

            char top = st.top();
            st.pop();

            if ((s[i] == ')' && top != '(') ||
                (s[i] == ']' && top != '[') ||
                (s[i] == '}' && top != '{')) {
                return cout<<0, 0;
            }
        }
    }
    cout<<st.empty();

    return 0;
}