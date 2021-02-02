/*
 
    Note        :        idea: hash the element according to their size and make them come into range 1-100, then do dp with 3 states.
                               i means index, a means the last taken left book, b means last taken right book.
                               we can skip the book,
                               if a book can be taken, ie. is >= left and <= right, then we can add it to left side or right side.
                               take the  max and print. 
 
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
const ll si = 1<<15;

int ar[100],mr[100],n,mamo[100][101][102];
unordered_map<int,int> rec;
set<int> con;

int dp(int i,int a,int b){
	if(i == n) return 0;
	if(mamo[i][a][b] == -1){
		int ans = dp(i+1,a,b);
		if(mr[i] >= a && b >= mr[i]) ans = max(ans,max(dp(i+1,mr[i],b),dp(i+1,a,mr[i])) + 1);
		mamo[i][a][b] = ans;
	}
	return mamo[i][a][b];
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
    int T,s; cin>>T;
    rec.max_load_factor(0.25);
    rec.reserve(1<<7);
    for(int t = 1; t <= T; t++){
    	cin>>n;
    	s = 0;
    	rec.clear(); con.clear();
    	for(int i = 0; i < n; i++){
    		cin>>ar[i];
    		con.insert(ar[i]);
    	}
    	for(int r: con) if(!rec.count(r)) rec[r] = ++s;
    	for(int i = 0; i < n; i++) mr[i] = rec[ar[i]];
    	memset(mamo,-1,sizeof(mamo));
    	ll ans = dp(0,0,101);
    	cout<<"Case "<<t<<": "<<ans el;
    }
    return 0;
}
