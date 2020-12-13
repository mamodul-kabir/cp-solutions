/*
    
    Note        :   		Find if the graph is connected or not. If not, then no way. If connected but edge == vertex - 1, then No second way. Find the mst and save its edges. Then remove each edge in the mst and see whether it is a bridge or not.(ie. check all vertex is visited or not). If the edge is not a bridge, then store the spanning tree value in a vector. Sort the vector after doing the process with all valid edges. Print the second minimum cost. 

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
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;

#define psi pair<pii,ll>

vector<psi> ed;
vector<pii> ar[101];
vector<ll> ans;
ll v,e;
bool f = 1;

void fun(psi x){
	vector<bool> vis(101);
	priority_queue<pair<int,pii>> pq;
	pq.push({0,{1,1}});
	ll tot = 0,rs = 0;
	bool nw = x.F.F == 169;
	while(!pq.empty()){
		pair<int,pii> cr = pq.top(); pq.pop();
		if(vis[cr.S.F]) continue;
		vis[cr.S.F] = 1;
		tot += (-cr.F);
		if(nw) ed.pb({{cr.S.F,cr.S.S},-cr.F});
		for(auto r: ar[cr.S.F]){
			if(!vis[r.F]){
				if((r.F == x.F.F || r.F == x.F.S) && (cr.S.F == x.F.S || cr.S.F == x.F.F) && r.S == x.S && rs == 0){
					//cout<<x.F.F sp<<x.F.S sp<<x.S el;
					rs++;
					continue;
				}else pq.push({-r.S,{r.F,cr.S.F}});
			}
		}
	}
	bool al = 1;
	for(int i = 1; i <= v; i++) al &= vis[i];
	if(al && x.F.F == 169) f = 1;
	else if(al) ans.pb(tot);
	return;
}

void ini(){
	ed.clear();
	for(int i = 0; i < 101; i++) ar[i].clear();	
	ans.clear();
	f = 0;
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
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
    	cin>>v>>e;
    	ini();
    	for(int i = 0; i < e; i++){
    		ll a,b,c; cin>>a>>b>>c;
    		if(a == b) continue;
    		ar[a].pb({b,c}); ar[b].pb({a,c});
    	}
    	fun({{169,169},69});
    	for(auto r: ed){
    		fun(r);
    	}
    	sort(all(ans));
    	//for(int r: ans) cout<<r sp;
    	//cout el;
    	cout<<"Case #"<<t<<" : ";
    	if(!f) cout<<"No way" el;
    	else{
    		if(e == v - 1) cout<<"No second way" el;
    		else cout<<ans[1] el;
    	}
    }
    return 0;
}