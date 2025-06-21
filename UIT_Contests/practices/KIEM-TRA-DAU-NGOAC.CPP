#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    cin >> s;
    stack<char> st;

    for(const char& x : s){
        if(x == '(' || x == '[' || x == '{')
            st.push(x);
        else{
            if(st.empty()) return cout<<0, 0;

            char cur = st.top();
            st.pop();

            if ((x == ')' && cur != '(') || 
                (x == ']' && cur != '[') || 
                (x == '}' && cur != '{')) {
                return cout<<0, 0;
            }
        }
    }
    cout<<(st.empty());
    return 0;
}