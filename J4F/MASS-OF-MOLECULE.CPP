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
    int n = s.length();
    unordered_map<char, int> mp;
    mp['C'] = 12;
    mp['H'] = 1;
    mp['O'] = 16;

    stack<int> st;
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '(') st.push(0);
        else if(s[i] == ')'){
            int tmp = 0;
            while(!st.empty() && st.top()){
                tmp += st.top();
                st.pop();
            }

            if(!st.empty() && !st.top()) {
                st.pop();
                st.push(tmp);
            }
        } 
        else if('2' <= s[i] && s[i] <= '9'){
            if(!st.empty()){ 
                int x = st.top() * int(s[i] - '0');
                st.pop();
                st.push(x);
            }
        }
        else st.push(mp[s[i]]);
    }

    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    cout<<sum;
    return 0;
}