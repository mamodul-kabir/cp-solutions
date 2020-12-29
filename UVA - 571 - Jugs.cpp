/*
    
    Note        :       


    Link        :       https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=512
    
    
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

const ll mamod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
ll si = 26;
int dum = 1000000007;

int a,b,n;
bool vis[1005][1005],en;

vector<string> str = {"fill A","fill B","empty A", "empty B","pour A B","pour B A"},ans;
pii fun(int x,int y,int op){
    if(op == 0) return {a,y};
    else if(op == 1) return {x,b};
    else if(op == 2) return {0,y};
    else if(op == 3) return {x,0};
    else if(op == 4){
        int mn = min(b - y,x);
        return {x - mn,y + mn};
    }else{
        int mn = min(a - x,y);
        return {x + mn,y - mn};
    }
}

bool valid(pii x){
    if(x.F < 0 || x.F > a || x.S < 0 || x.S > b) return false;
    return 1;
}

void dfs(int x,int y){
    vis[x][y] = 1;
    if(x == n || y == n){
        ans.pb("success");
        for(string r: ans) cout<<r el;
        ans.clear();
        en = 1;
        return;
    }
    for(int i = 0; i < 6; i++){
        pii tr = fun(x,y,i);
        if(valid(tr) && !vis[tr.F][tr.S]){
            ans.pb(str[i]);
            dfs(tr.F,tr.S);
            if(en) return;
            else ans.pop_back();
        }
    }
}

void solve(){
    memset(vis,0,sizeof(vis));
    en = 0;
    dfs(0,0);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/
    while(cin>>a>>b>>n){
        solve();
    }
    return 0;
}
