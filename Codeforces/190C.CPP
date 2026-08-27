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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    cin.ignore();

    string s, x;
    getline(cin, s);
    stringstream ss(s);

    vector<string> a;
    while(ss >> x)
        a.push_back(x);

    int m = a.size();
    if(m == 1){
        if(a[0] == "pair")
            return cout<<"Error occurred", 0;
        return cout<<"int", 0;
    }

    string res = "";
    stack<int> st;
    bool ok = 1;

    for(int i = 0; i < m && ok; i++){
        if(i > 0 && st.empty())
            ok = 0;

        if(a[i] == "pair"){
            if(!st.empty()){
                if(st.top() == 1 && res.back() != ',') 
                    res.push_back(',');
                st.top()++;
            }
            st.push(0);
            res += "pair<";
        }
        else{
            if(!st.empty()){
                if(st.top() == 1 && res.back() != ',') 
                    res.push_back(',');
                st.top()++;
            }
            res += "int";
        }

        while(!st.empty() && st.top() == 2){
            res.push_back('>');
            st.pop();

            if(!st.empty() && st.top() == 1)
                res.push_back(',');
        }
    }
    cout<<(ok && st.empty() ? res : "Error occurred");
    return 0;
}