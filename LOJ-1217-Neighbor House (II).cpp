/*
 
    Note        :        the ok variable stores whether the 1st element is taken or not. 
 
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
const ll si = (1000);

int ar[si],mamo[si][2],n;

int dp(int i,int ok){
	if(i >= n) return 0;
	if(i == n - 1) return ok ? 0 : ar[n-1];
	if(mamo[i][ok] == -1) mamo[i][ok] = max(ar[i] + dp(i+2,ok),dp(i+1,ok));
	return mamo[i][ok];
}

int do_dp(){
	memset(mamo,-1,sizeof(mamo));
	return max(dp(1,0),ar[0] + dp(2,1));
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
