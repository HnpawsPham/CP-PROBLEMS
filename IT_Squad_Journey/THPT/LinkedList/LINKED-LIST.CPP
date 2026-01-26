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
#define node Node*
//#define taskname ""

struct Node{
    int val;
    Node *next;
};

node newNode(int x){
    node tmp = new Node();
    tmp->val = x;
    tmp->next = nullptr;
    return tmp;
}

bool empty(node x){
    return x == nullptr;
}

int lsize(node x){
    int sz = 0;
    while(x != nullptr){
        x = x->next;
        sz++;
    }
    return sz;
}

void addback(node &a, int x){
    node tmp = newNode(x);

    if(empty(a)) a = tmp;
    else{
        node cur = a;
        while(cur->next != nullptr)
            cur = cur->next;
        cur->next = tmp;
    }
    return;
}

void addfront(node &a, int x){
    node tmp = newNode(x);
    node cur = a;
    tmp->next = cur;
    a = tmp;
    return;
}

void printlist(node a){
    while(a != nullptr){
        cout<<a->val<<" ";
        a = a->next;
    }
    return;
}

void addmid(node& a, int x, int i){
    node tmp = newNode(x);

    if(i < 0 || i >= lsize(a)) 
        throw runtime_error("invalid insert index");

    node cur = a;
    for(int j = 0; j < i - 1; j++)
        cur = cur->next;

    node back = cur->next;
    cur->next = tmp;
    tmp->next = back;
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin>>n>>x;
    node head = newNode(x);
    for(int i = 1; i < n; i++){
        cin>>x;
        addback(head, x);
    }
    addmid(head, 5, 1);
    printlist(head);
    return 0;
}

// 5
// 3 7 2 1 7