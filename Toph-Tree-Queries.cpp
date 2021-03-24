/*
 
    Note        :                 hash the values within 10^6, use dsu on tree with BIT. 
                                  n * log(n)^ 2 offline. 
 
    Link        :                 https://toph.co/p/tree-queries?fbclid=IwAR1PARQ596k4lxTj0gDvu5y-Iw_f-I9QoB9uAuRDmwBzW7zl7qCj3Klk6B8
 
    Boka hoye gelum...
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
 
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
 
const ll mod = 1000000007;
const ll oo = 3372036000000000;
const ll si = 500005;

set<int> con;
unordered_map<int,int> rec;  
vector<int> g[si]; 
vector<pii> ofl[si]; 
int ar[si],que[si],ftr[si * 2],sz[si]; 
vector<bool> big(si); 
pii oq[si]; 

void upd(int x,int v){
    while(x <= 1000000){
        ftr[x] += v; 
        x += x & (-x); 
    }
    return; 
}

int get(int x){
    int ans = 0; 
    while(x){
        ans += ftr[x]; 
        x -= x & (-x); 
    }
    return ans;
}

int vof(int x){
    return get(1000000) - get(x-1); 
}

void dfs(int v){
    sz[v] = 1; 
    for(int r: g[v]){
        dfs(r); 
        sz[v] += sz[r]; 
    }
    return; 
}

void add(int v,int x){
    upd(ar[v],x); 
    for(int r: g[v]){
        if(!big[r]) add(r,x); 
    }
}

void dfs(int v,bool clear){
    int bc = -1, bz = 0; 
    for(int r: g[v]){
        if(sz[r] > bz){
            bz = sz[r]; 
            bc = r; 
        }
    }
    for(int r: g[v]){
        if(r != bc) dfs(r,1); 
    }
    if(bc != -1){
        dfs(bc,0); big[bc] = 1; 
    }
    add(v,1); 
    for(pii r: ofl[v]){
        int ans = vof(r.S); 
        que[r.F] = ans;
    }
    if(bc != -1) big[bc] = 0; 
    if(clear) add(v,-1); 
    return; 
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
    rec.max_load_factor(0.25);
    rec.reserve(1<<20); 
    memset(ftr,0,sizeof(ftr));    
    int n,m; cin>>n>>m; 
    for(int i = 2; i <= n; i++){
        int x; cin>>x; 
        g[x].pb(i); 
    }
    for(int i = 1; i <= n; i++){
        cin>>ar[i]; 
        con.insert(ar[i]); 
    }
    for(int i = 0; i < m; i++){
        int v,x; cin>>v>>x; 
        con.insert(x); 
        oq[i] = {v,x}; 
    }
    int cr = 1; 
    for(int r: con) rec[r] = cr++; 
    for(int i = 1; i <= n; i++) ar[i] = rec[ar[i]]; 
    for(int i = 0; i <  m; i++){
        int v = oq[i].F,nx = rec[oq[i].S]; 
        ofl[v].pb({i,nx}); 
    }
    dfs(1); 
    dfs(1,1); 
    for(int i = 0; i < m; i++) cout<<que[i] el;
    return 0; 
}
