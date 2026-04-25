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

int n;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<string> st;
    st.push_back("");

    while(n--){
        string s;
        cin>>s;
        if(s == "pwd"){
            for(const string& x : st)
                cout<<x<<"/";
            cout<<el;
        }
        else{
            string dir, tmp = "";
            cin>>dir;   
            
            if(dir[0] == '/'){
                st.clear();
                st.push_back("");
            }

            for(const char& x : dir){
                if(x != '/') tmp.push_back(x);
                else if(!tmp.empty()){
                    if(tmp != "..") st.push_back(tmp);
                    else st.pop_back();
                    tmp.clear();
                }     
            }

            if(!tmp.empty()){
                if(tmp != "..") st.push_back(tmp);
                else st.pop_back();
                tmp.clear();
            }
        }
    }

    return 0;
}