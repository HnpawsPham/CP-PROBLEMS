#include <bits/stdc++.h>
using namespace std;
#define el '\n'

string s;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    

    int x, y;
    cin>>s>>x>>y;
    n = s.length();

    string fi = "ab", se = "ba";
    if(y > x) {
        swap(fi, se);
        swap(x, y);
    }

    int sum = 0;
    stack<char> st;

    for(int i = 0; i < n; i++){
        if(s[i] == fi[1] && !st.empty() && st.top() == fi[0]){
            sum += x;
            st.pop();
        }
        else st.push(s[i]);
    }

    string tmp = "";
    while(!st.empty()){
        tmp += st.top();
        st.pop();
    }

    for(const char& x : tmp){
        if(x == se[0] && !st.empty() && st.top() == se[1]){
            sum += y;
            st.pop();
        }
        else st.push(x);
    }
    cout<<sum;
    return 0;
}

// cdbcbbaaabab 4 5