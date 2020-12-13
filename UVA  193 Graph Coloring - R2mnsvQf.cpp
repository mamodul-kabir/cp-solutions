/*
   YOU CAN'T TAKE HELP FROM EDITORIAL               .m.
    
    Note        :       We know that in backtrack, it's a common pattern: remove-do-add || add- do - remove; 
			While terminating the recursion, don't forget the last (add for 1st and remove for second) part. (more at the
			*** part)

    Link        :	https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=129

    Boka hoye gelum...
*/
#include "bits/stdc++.h"
#include "bitset"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;

vector<int> ar[101],wae,fin;
bool vis[101];
ll ans = 0;
set<int> st,blc;
vector<pii> dgr;

void dfs(int i, bool * tv){
	tv[i] = 1;
	dgr.pb({ar[i].size(),i});
	for(int r: ar[i]){
		if(!tv[r]) dfs(r,tv);
	}
	return;
}

void bktrk(ll &an, ll tn,ll nd){
	tn += 1;
	vector<int> tbd;
	wae.pb(nd);
	blc.insert(nd);
	for(int r: ar[nd]){
		if(!blc.count(r)) tbd.pb(r);
	}
	for(int r: tbd) blc.insert(r);
	if(st == blc){
		//  ***
		for(int r: tbd) blc.erase(r);
		blc.erase(nd);
		//  ***
		//for(int r: wae) cout<<r<<"-> ";
		//cout<<tn el;
		if(tn > an){
			an = tn;
			fin.clear();
			for(int r: wae) fin.pb(r);
		}
		wae.pop_back(); 
		return;
	}
	for(int r: st) if(!blc.count(r)) bktrk(an,tn,r);
	for(int r: tbd) blc.erase(r);
	blc.erase(nd); wae.pop_back();
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
    int t; cin>>t;
    while(t--){
    	int n,m; cin>>n>>m;
    	vector<int> anv;
    	for(int i = 1; i <= n; i++) ar[i].clear();
    	memset(vis,0,sizeof(vis)); ans = 0;
    	while(m--){
    		int a,b; cin>>a>>b;
    		ar[a].pb(b); ar[b].pb(a);
    	}
    	for(int i = 1; i <= n; i++){
    		if(!vis[i]){
    			bool tv[101]; memset(tv,0,sizeof(tv));
    			dgr.clear(); dfs(i,tv); sort(all(dgr));
    			st.clear();  fin.clear(); wae.clear();
    			ll tn = 0,node = dgr[0].S;
    			//cout<<node el;
    			for(auto r: dgr) st.insert(r.S);
    			//for(int r: st) cout<<r sp;
    			bktrk(tn,0LL,node);
    			for(int r: ar[node]){
    				bktrk(tn,0LL,r);
    			}
    			for(int r: fin) anv.pb(r);
    			ans += tn;
    			for(auto r: dgr) vis[r.S] = 1;
    		}
    	}
    	cout<<ans el;
    	sort(all(anv));
    	for(int i = 0; i < ans; i++) cout<<anv[i], i == ans - 1 ? cout el : cout sp;
    }
    return 0;
}