/*
 
    Note        :         My first Heavy-Light Decomposition solution. 
                                          =^.^=			      
			  To be noted: lvl[1] = 0; 

 
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
const ll si = 200006;
 
vector<int> ar[si];
int val[si], sz[si], anc[si][18], tin[si], tout[si], lbl[si], lvl[si], bc[si];
int  vch[si],label = 1, str[si * 4], flt[si],tim = 1,rbl[si];
bool is(int a,int b){
	return tin[a] <= tin[b] && tout[b] <= tout[a];
}
 
int lca(int a,int b){
	if(is(a,b)) return a;
	if(is(b,a)) return b;
	int p = log2(lvl[a]);
	for(int i = p; i >= 0; i--){
		if(!is(anc[a][i],b)) return lca(anc[a][i],b);
	}
	return anc[a][0];
}
 
void pdfs(int v,int p){
	tin[v] = tim++;
	sz[v] = 1;
	int bigz = 0; 
	for(int r: ar[v]){
		if(r == p) continue;
		lvl[r] = lvl[v] + 1;
		int p = log2(lvl[r]);
		anc[r][0] = v;
		for(int i = 1; i <= p; i++){
			anc[r][i] = anc[anc[r][i-1]][i-1];
		}
		pdfs(r,v);
		sz[v] += sz[r];
		if(sz[r] > bigz){
			bigz = sz[r];
			bc[v] = r;
		}
	}
	tout[v] = tim++;
	return;
}
 
void sdfs(int v,int p){
	lbl[v] = label++;
	rbl[lbl[v]] = v;
	if(vch[v] == -1) vch[v] = lbl[v];
	flt[lbl[v]] = val[v];
	if(bc[v] != -1){
		vch[bc[v]] = vch[v];
		sdfs(bc[v],v);
	}
	for(int r: ar[v]){
		if(r == p || r == bc[v]) continue;
		sdfs(r,v);
	}
	return;
}
 
void make(int a,int b,int node){
	if(a == b){
		str[node] = flt[a];
		return;
	}
	int mid = a + (b - a)/2;
	make(a,mid,node * 2); 
	make(mid + 1,b,(node * 2) + 1);
	str[node] = max(str[node * 2],str[(node * 2) + 1]);
	return;
}
 
void update(int a,int b,int i, int v,int node){
	if(a == b){
		str[node] = v;
		return;
	}
	int mid = a + (b-a)/2;
	if(i <= mid) update(a,mid,i,v,2 * node);
	else update(mid+1,b,i,v,(2 * node) + 1);
	str[node] = max(str[node * 2],str[(node * 2) + 1]);
	return;
}
 
int query(int a,int b,int l,int r,int node){
	if(b < l || a > r) return -2000000000;
	if(l <= a && b <= r) return str[node];
	int mid = a + (b - a)/2;
	return max(query(a,mid,l,r,node * 2),query(mid+1,b,l,r,(node * 2) + 1));
}
 
void upd(int s,int x){
	int in = lbl[s];
	flt[in] = x;
	update(1,label-1,in,x,1);
	return;
}
 
int dir(int l,int ot){
	int ans = 0;
	while(vch[l] != vch[ot]){
		int lto = vch[ot], lfr = lbl[ot];
		//cout<<ot sp<<lto sp<<lfr el;
		if(lto == lfr) ans = max(ans,flt[lto]);                                 // this caused a TLE. when the query is for a point look it up on the array, not on the segment tree. 
		else ans = max(ans,query(1,label-1,lto,lfr,1));
		ot = anc[rbl[vch[ot]]][0];
	}
	int lto = lbl[l], lfr = lbl[ot];
	ans = max(ans,query(1,label-1,lto,lfr,1));
	return ans;
}
 
int que(int a,int b){
	int l = lca(a,b),ans = 0;
	ans = max(dir(l,a),dir(l,b));
	return ans;
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
    memset(bc,-1,sizeof(bc));
    memset(vch,-1,sizeof(vch));
    for(int i = 1; i <= n; i++) cin>>val[i];
    for(int i = 1; i < n; i++){
    	int a,b; cin>>a>>b; 
    	ar[a].pb(b); ar[b].pb(a);
    }
    pdfs(1,0);
    sdfs(1,0);
    make(1,label-1,1);
    for(int i = 0; i < q; i++){
    	int t,a,b; cin>>t>>a>>b; 
    	if(t == 1) upd(a,b);
    	else if(t == 2) cout<<que(a,b) sp;
    }
    return 0;
}
