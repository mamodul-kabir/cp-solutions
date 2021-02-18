/*
 
    Note        :        cpu-time: 1.48 s
 
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

string s,ans,hue[1000][1000]; 
int mamo[1000][1000],n;

string mn(string a,string b,int y){
	for(int i = 0; i < y; i++){
		if(a[i] < b[i]) return a;
		else if(a[i] > b[i]) return b;
	}
	return a;
}

int dp(int i,int j){
	if(i == j){
		hue[i][j] = string(1,s[i]);
		return 1;
	}
	if(i > j) return 0;
	if(mamo[i][j] == -1){
		int ans;
		if(s[i] == s[j]){
			ans = 2 + dp(i+1,j-1);
			hue[i][j] = s[i] + hue[i+1][j-1] + s[i];
		}
		else{
			int p1 = dp(i+1,j), p2 = dp(i,j-1);
			if(p1 > p2){
				ans = p1;
				hue[i][j] = hue[i+1][j];
			}else if(p1 < p2){
				ans = p2;
				hue[i][j] = hue[i][j-1];
			}else{
				ans = p1;
				hue[i][j] = mn(hue[i][j-1],hue[i+1][j],p1);
			}
		}
		mamo[i][j] = ans;
		//cout<<i sp<<j sp<<ans el;
	}
	return mamo[i][j];
}

void do_dp(){
	memset(mamo,-1,sizeof(mamo));
	n = s.size();
	int pln = dp(0,n-1);
	ans = hue[0][n-1];
	cout<<ans el;
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
