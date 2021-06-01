/*
    
    Note        :           spoj has some problems with the time limits. The limits in the statement is misleading. Plus, this kinda time limit stops potential solutions. 
 
    Link        :       
 
    Boka hoye gelum...
*/


#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define pii pair<int,int> 

 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll oo = 3372036000000000;
const ll si = 100005;

int n; 
vector<vector<int>> g; 
vector<vector<pii>> pdi; 
vector<set<pii>> rec(si); 
vector<int> sz(si),par(si,-1); 
bitset<si> ded,on; 

void dfs(int v,int p){
    for(int r: g[v]){
        if(r == p) continue; 
        par[r] = v; 
        dfs(r,v); 
        sz[v] += sz[r] + 1; 
    }
    return; 
}

void count(int v,int p,int dep,int cen){
    pdi[v].pb({cen,dep}); 
    for(int r: g[v]){
        if(r == p || ded[r]) continue; 
        count(r,v,dep+1,cen); 
    }
    return; 
}

void decompose(int v,int w){
    int cen = v; 
    while(1){
        int nc = -1; 
        for(int r: g[cen]){
            if(par[cen] == r || ded[r]) continue; 
            if((sz[r] + 1) * 2 > w) nc = r; 
        }
        if(((w - sz[cen] - 1) * 2 > w) && par[cen] != -1 && !ded[par[cen]]) nc = par[cen]; 
        if(nc == -1) break; 
        else cen = nc; 
    }
    for(int u = par[cen]; u != -1 && !ded[u]; u = par[u]) sz[u] -= sz[cen] + 1; 
    ded[cen] = 1; 
    count(cen,0,0,cen); 
    for(int r: g[cen]){
        if(ded[r]) continue; 
        int nw = sz[r] + 1; 
        if(r == par[cen]) nw = w - sz[cen] - 1; 
        decompose(r,nw); 
    }
    return; 
}

void chang(int v){
    on[v] = !on[v]; 
    for(pii r: pdi[v]){
        pii xd = {r.S,v}; 
        if(on[v]) rec[r.F].insert(xd); 
        else rec[r.F].erase(xd); 
    }
}

int query(int v){
    int ans = mod; 
    for(pii r: pdi[v]){
        if(rec[r.F].empty()) continue; 
        pii f = *(rec[r.F].begin()); 
        ans = min(ans,f.F + r.S); 
    }
    return ans; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    cin>>n; 
    g.assign(n+1,{}); 
    pdi.assign(n+1,{});  
    for(int i = 1; i < n; i++){
        int a,b; cin>>a>>b;
        g[a].pb(b); 
        g[b].pb(a); 
    }
    dfs(1,0); 
    decompose(1,n); 
    int q; cin>>q; 
    while(q--){
        int t,v; cin>>t>>v; 
        if(t){
            int ans = query(v); 
            ans == mod ? cout<<-1 el : cout<<ans el; 
        }else chang(v); 
    }
    return 0;
}
