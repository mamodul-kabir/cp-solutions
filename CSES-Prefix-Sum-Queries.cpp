/*
 
    Note        :      

    Link        :      https://cses.fi/problemset/task/2166/
 
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
 
const ll mod = 100000007;
const ll mxr = 1e6 + 10;
const ll oo = -2000000000;
const ll si = 200006;

struct info
{
	ll sum,prf;
};

ll ar[si],n,q;
info str[si * 4];

info comb(info a,info b){
	info ans;
	ans.sum = a.sum + b.sum;
	ans.prf = max(a.prf,a.sum + b.prf);
	return ans;
}

void make(int a,int b,int node){
	if(a == b){
		str[node].sum = ar[a];
		str[node].prf = max(0LL,ar[a]);
		return;
	}
	int mid = a + (b - a)/2;
	make(a,mid,2 * node); make(mid + 1,b,(2 * node) + 1);
	str[node] = comb(str[node * 2],str[(node * 2) + 1]);
	return;
}

void upd(int a,int b,int c,int node){
	if(a == b){
		str[node].sum = ar[a];
		str[node].prf = max(ar[a],0LL);
		return;
	}
	int mid = a + (b - a)/2;
	if(c <= mid) upd(a,mid,c,2 * node);
	else upd(mid+1,b,c,(2 * node) + 1);
	str[node] = comb(str[node * 2],str[(node * 2) + 1]);
	return;
}

info que(int a,int b,int l,int r,int node){
	if(a >= l && b <= r) return str[node];
	if(b < l || a > r) return {0,0};
	int mid = a + (b - a)/2;
	return comb(que(a,mid,l,r,2 * node),que(mid+1,b,l,r,(2 * node) + 1));
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
    for(int i = 0; i < n; i++) cin>>ar[i];
    make(0,n-1,1);
	for(int i = 0; i < q; i++){
		int t,a,b; cin>>t>>a>>b;
		if(t == 1){
			a -= 1;
			ar[a] = b;
			upd(0,n-1,a,1);
		}else{
			a -= 1; b -= 1;
			info ans = que(0,n-1,a,b,1);
			cout<<ans.prf el;
		}
	}
	return 0;
}
