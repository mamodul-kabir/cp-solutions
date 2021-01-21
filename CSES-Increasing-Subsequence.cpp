/*
 
    Note        :             Had to take a hint to become sure that an O(NlogN) solution exists. Didn't see the solution. Can say that it's full OC. Hashing + Segment Tree + DP.

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
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 200005;

int str[si * 4],ar[si],dp[si],mr[si],n,ans = 0;
unordered_set<int> st;
unordered_map<int,int> rec;

int que(int a,int b,int l,int r,int node){
	if(b < l || r < a) return -1;
	if(a >= l && b <= r) return str[node];
	int mid = a + (b - a)/2;
	return max(que(a,mid,l,r,node * 2),que(mid+1,b,l,r,(2 * node) + 1));
}

void upd(int a,int b,int p,int val,int node){
	if(a == b){
		str[node] = val;
		return;
	}
	int mid = a + (b - a)/2;
	if(p <= mid) upd(a,mid,p,val,2 *node);
	else upd(mid+1,b,p,val,(2 * node) + 1);
	str[node] = max(str[node * 2],str[(node * 2) + 1]);
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
    rec.reserve(1<<18);
    cin>>n;
    for(int i = 0; i < n; i++) cin>>ar[i], st.insert(ar[i]);
    vector<int> tem;
	for(int r: st) tem.pb(r);
	sort(all(tem));
	int q = 1;
	for(int r: tem) rec[r] = q++;
	for(int i = 0; i < n; i++) mr[i] = rec[ar[i]];
	//for(int i = 0; i < n; i++) cout<<mr[i] sp;
	memset(str,0,sizeof(str));
	for(int i = 0; i < n; i++){
		int val = que(0,q - 1,0,mr[i]-1,1) + 1;
		dp[i] = val;
		ans = max(ans,val);
		upd(0,q-1,mr[i],val,1);
	}
	cout<<ans el;
    return 0;
}
