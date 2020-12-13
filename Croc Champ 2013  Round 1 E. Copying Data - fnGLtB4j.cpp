/*
    
Note        :       Amazing problem. 
    My solution is, 
    for each update, save the update number in a segment tree for the range of the b array. 
    and also save the update data(starting index for array A & B) in a vector.
    For each point query, check in the segment tree for latest update number for that index, if it is
    not updated, then output the element in B. else if a update is found then, find the distance between 
    the query index and the starting index in B. then output the starting index of A + the distance.

    See the solution for better understanding.  


    Link        :       	https://codeforces.com/contest/292/problem/E
    
    
    Boka hoye gelum...
*/
#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100006;
int dum = 1000000007;

int a[si],b[si],str[si * 4],oi = 0,n;
vector<pii> opn;

void update(int a,int b,int i,int j,int node,int on){
    if(i > b || j < a) return;
    if(i <= a && j >= b){
        //cout<<a sp<<b sp<<on sp;
        str[node] = on;
        //cout<<node el;
        return;
    }
    int mid = a + (b - a)/2;
    update(a,mid,i,j,(node * 2),on);
    update(mid + 1,b,i,j,(node * 2) + 1,on);
    return;
}

int que(int a,int b,int i,int node,int cval){
    //cout<<a sp<<b sp<<node el;
    cval = max(str[node],cval);
    if(a == b) return cval;
    int mid = a + (b - a)/2;
    if(i <= mid) return que(a,mid,i,node * 2,cval);
    else return que(mid + 1,b,i,(node * 2) + 1,cval);
}

void qtt(int i){
    int qn = que(0,n-1,i,1,-1);
    //cout<<qn sp;
    if(qn == -1) cout<<b[i] el;
    else{
        int x = opn[qn].F, y = opn[qn].S;
        int ind = i - y;
        cout<<a[x + ind] el;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    int q; cin>>n>>q;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    memset(str,-1,sizeof(str));
    for(int i = 0; i < q; i++){
        int ty; cin>>ty;
        if(ty == 1){
            int x,y,k; cin>>x>>y>>k;
            x -= 1; y -= 1;
            opn.pb({x,y});
            update(0,n-1,y,y+k-1,1,oi);
            oi++;
        }else{
            int a; cin>>a;
            a -= 1;
            qtt(a);
        }
    }
    return 0;
}