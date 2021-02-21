/*
 
    Note        :         Finding LCA with binary lifting. 
                          The implementation in cp-algorithm has some bugs in equivalent line of line-57. 

    Link        :      
 
 
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
 
const ll mod = 100000007;
const ll si = 2000006;

vector<int> ar[si];
int tin[si],tout[si], anc[si][20],tim = 0,lvl[si];

bool is(int a,int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void dfs(int v){
	tin[v] = tim++;
	for(int r: ar[v]){
		lvl[r] = lvl[v] + 1;
		anc[r][0] = v;
		int ps = log2(lvl[r]);
		for(int i = 1; i <= ps; i++){
			anc[r][i] = anc[anc[r][i-1]][i-1];
		}
		dfs(r);
	}
	tout[v] = tim++;
	return;
}

int lca(int a,int b){
	int p = log2(lvl[a]);
	//cout<<a sp<<b sp<<p sp<<anc[a][p] el;
	for(int i = p; i >= 0; --i){
		if(!is(anc[a][i],b)){
			return lca(anc[a][i],b);
		}
	}
	return anc[a][0];
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
    int n,q; cin>>n>>q;
    for(int i = 2; i <= n; i++){
    	int x; cin>>x; 
    	ar[x].pb(i);
    }
    dfs(1);
    lvl[1] = 0;
    while(q--){
    	int a,b; cin>>a>>b;
    	if(is(a,b)) cout<<a el;
    	else if(is(b,a)) cout<<b el;
    	else{
    		cout<<lca(a,b) el;
    	}
    }
    return 0;
}
