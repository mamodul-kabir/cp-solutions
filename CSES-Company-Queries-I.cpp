/*
 
    Note        :         

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
int lvl[si], anc[si][18];

void dfs(int v){
	for(int r: ar[v]){
		lvl[r] = lvl[v] + 1;
		anc[r][0] = v;
		int ps = log2(lvl[r]);
		for(int i = 1; i <= ps; i++){
			anc[r][i] = anc[anc[r][i-1]][i-1];
		}
		dfs(r);
	}
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
    int n,q; cin>>n>>q;
    for(int i = 2; i <= n; i++){
    	int x; cin>>x; 
    	ar[x].pb(i);
    }
    lvl[1] = 0;
    dfs(1);
    while(q--){
    	int x,k; cin>>x>>k;
    	if(lvl[x] < k) cout<<-1 el;
    	else{
    		int i = 0;
    		while(k){
    			if(k&1) x = anc[x][i];
    			i++; 
    			k /= 2;
    		}
    		cout<<x el;
    	}
    }
    return 0;
}
