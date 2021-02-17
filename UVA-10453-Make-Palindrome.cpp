/*
 
    Note        :        had a little trouble building the solution. 
 
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
#define pui pair<ll,pii> 
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = (100);

string s,rec; 
int mamo[1005][1005],n;

int dp(int i,int j){
	if(i >= j) return 0;
	if(mamo[i][j] == -1){
		int ans;
		if(s[i] == s[j]) ans = dp(i+1,j-1);
		else ans = min(dp(i,j-1),dp(i+1,j)) + 1;
		mamo[i][j] = ans;
	}
	return mamo[i][j];
}

void reb(int i,int j){
	if(i >= j){
		if(i == j) rec = s[i];
		return;
	}
	if(s[i] == s[j]){
		reb(i+1,j-1);
		rec = s[i] + rec + s[i];
	}
	else if(mamo[i][j-1] <= mamo[i+1][j]){
		reb(i,j-1);
		rec = s[j] + rec + s[j];
	}
	else{
		reb(i+1,j);
		rec = s[i] + rec + s[i];
	}
	return;
}

void do_dp(){
	memset(mamo,-1,sizeof(mamo));
	rec = "";
	n = s.size();
	int ans = dp(0,n-1);
	reb(0,n-1);
	cout<<ans sp<<rec el;
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
    while(cin>>s){
    	do_dp();
    }
    return 0;
}
