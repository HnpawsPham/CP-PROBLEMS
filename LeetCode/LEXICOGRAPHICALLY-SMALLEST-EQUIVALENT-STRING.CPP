#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
string s1, s2, s;
int parent[26];

void make_set(){
    for(int i = 0; i < 26; i++)
        parent[i] = i;
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(a > b) swap(a, b);

    parent[b] = a;

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s1>>s2>>s;
    n = s1.length();

    make_set();

    for(int i = 0; i < n; i++){
        union_set(s1[i] - 'a', s2[i] - 'a');
    }

    int m = s.length();
    for(int i = 0; i < m; i++)
        s[i] = find(s[i] - 'a') + 'a'; 

    cout<<s;
    return 0;
}