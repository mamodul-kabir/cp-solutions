/*
    
    Note        :           
 
    Link        :       https://toph.co/p/path-intersection-extended
 
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
 
const ll mod = 1000000007;
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 100005;

int n,q; 
vector<int> g[si]; 
int sz[si],anc[si][17],lvl[si],tin[si],tout[si],timer = 0,bc[si],label = 0,id[si],ch[si],rid[si];
int hol[si * 4],cnt[si];  
pii str[si * 4]; 

void pdfs(int v,int p){
    sz[v] = 1; 
    tin[v] = timer++; 
    int bz = 0; 
    for(int r: g[v]){
        if(r == p) continue;
        lvl[r] = lvl[v] + 1; 
        anc[r][0] = v; 
        int pos = log2(lvl[r]); 
        for(int i = 1; i <= pos; i++){
            anc[r][i] = anc[anc[r][i-1]][i-1]; 
        }
        pdfs(r,v); 
        sz[v] += sz[r]; 
        if(bz < sz[r]){
            bc[v] = r; 
            bz = sz[r]; 
        } 
    }
    tout[v] = timer++; 
    return; 
}

bool is_an(int a,int b){
    return tin[a] < tin[b] && tout[a] > tout[b]; 
}

pii max(pii a,pii b){
    if(a.F > b.F) return a; 
    else if(a.F < b.F) return b; 
    else return {a.F,a.S + b.S}; 
}

int lca(int a,int b){
    if(is_an(a,b)) return a; 
    else if(is_an(b,a)) return b; 
    int pos = log2(lvl[a]); 
    for(int i = pos; i >= 0; i--){
        if(!is_an(anc[a][i],b)) return lca(anc[a][i],b); 
    }
    return anc[a][0]; 
}

void make(int a,int b,int node){
    if(a == b){
        str[node] = {0,1}; 
        return; 
    }
    int mid = a + (b - a)/2; 
    make(a,mid,node * 2); make(mid + 1,b,(node * 2) + 1);  
    str[node] = max(str[node * 2],str[(node * 2) + 1]); 
    return; 
}

void push(int node,int l,int r){
    str[node].F += hol[node]; 
    if(l != r){
        hol[node * 2] += hol[node]; 
        hol[(node * 2) + 1] += hol[node]; 
    }
    hol[node] = 0; 
}

void updt(int l,int r,int a,int b,int node,int val){
    if(hol[node]) push(node,a,b); 
    if(r < a || l > b) return; 
    if(l <= a && r >= b){
        //cout<<a sp<<b sp<<val el;
        hol[node] += val;
        push(node,a,b); 
        return;
    }
    int mid = a + (b - a)/2; 
    updt(l,r,a,mid,2 * node,val); 
    updt(l,r,mid+1,b,(2 * node) + 1,val); 
    str[node] = max(str[node * 2],str[(node * 2) + 1]); 
    return; 
}

void sdfs(int v,int p){
    id[v] = label; 
    rid[label++] = v; 
    if(ch[v] == -1) ch[v] = id[v]; 
    if(bc[v] != -1){
        ch[bc[v]] = ch[v]; 
        sdfs(bc[v],v); 
    }
    for(int r: g[v]){
        if(r != p && r != bc[v]) sdfs(r,v); 
    }
    return; 
}

void adv(int lc,int a,int val){
    int il = id[lc]; 
    while(ch[lc] != ch[a]){
        int fr = ch[a], to = id[a];
        updt(fr,to,0,label-1,1,val); 
        a = anc[rid[fr]][0]; 
    }
    updt(il,id[a],0,label-1,1,val);
    return;  
}

void hupdt(int a,int b,int val){
    int lc = lca(a,b); 
    //cout<<a sp<<b sp<<lc el;
    adv(lc,a,val); 
    adv(lc,b,val); 
    updt(id[lc],id[lc],0,label-1,1,-val); 
    return; 
}

void prprcss(){
    memset(bc,-1,sizeof(bc)); memset(ch,-1,sizeof(ch)); 
    memset(hol,0,sizeof(hol)); cnt[0] = n; 
    lvl[1] = 0; 
    pdfs(1,0); 
    sdfs(1,0); 
    make(0,label-1,1); 
    //for(int i = 1; i <= n; i++) cout<<id[i] sp; cout el;
    //for(int i = 1; i <= n; i++) cout<<ch[i] sp; cout el;
    return; 
}

void que(int a,int b,int x,int node){
    if(a == b){
        cout<<str[node].F sp<<str[node].S el;
        return; 
    }
    int mid = a + (b - a)/2; 
    if(x <= mid) que(a,mid,x,node * 2); 
    else que(mid+1,b,x,(node * 2) + 1); 
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
    cin>>n>>q; 
    for(int i = 1; i < n; i++){
        int a,b; cin>>a>>b; 
        g[a].pb(b); g[b].pb(a); 
    }
    prprcss(); 
    while(q--){
        string s; cin>>s; 
        if(s == "Add"){
            int a,b; cin>>a>>b; 
            hupdt(a,b,1);
        } 
        else if(s == "Remove"){
            int a,b; cin>>a>>b; 
            hupdt(a,b,-1);
        } 
        else{
            int ans = str[1].F; 
            if(!ans) cout<<0 sp<<0 el;
            else cout<<str[1].S sp<<ans el;
        }
    }
    return 0;
}
