/*
 
    Note        :        I am really happy that I have been able to solve this problems by myself. UwU (lul)
 
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
const ll si = 100;

int n, mamo[si][si][2],ar[si],prf[si];

int get(int i,int j){
	return i == 0 ? prf[j] : prf[j] - prf[i-1];
}

int dp(int i,int j,int d){
	//cout<<i sp<<j sp<<d el;
	if(i > j) return 0;
	if(i == j) return max(ar[i],0);
	if(mamo[i][j][d] == -1){
		int ans,ni = d == 0 ? i + 1 : i, nj = d == 1 ? j - 1 : j,cr = d == 0 ? i : j;
		ans = max(ar[cr] + dp(ni,nj,d),get(i,j) - max(ar[i] + dp(i+1,j,0),ar[j] + dp(i,j-1,1)));
		mamo[i][j][d] = ans; 
		//cout<<i sp<< j sp<< d sp<< ans el;
	}
	return mamo[i][j][d];
}

int do_dp(){
	memset(mamo,-1,sizeof(mamo)); memset(prf,0,sizeof(prf));
	prf[0] = ar[0];
	for(int i = 1; i < n; i++) prf[i] = ar[i], prf[i] += prf[i-1];
	int al = max(ar[0] + dp(1,n-1,0),ar[n-1] + dp(0,n-2,1)),bob = prf[n-1] - al;
	//cout<<al sp<<bob el;
	return al - bob;
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
    	cin>>n; 
    	for(int i = 0; i < n; i++) cin>>ar[i];
    	int ans = do_dp();
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
