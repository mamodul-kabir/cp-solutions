/*
 
    Note        :        
 
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
 
const ll mod = 100000000;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = (100);

int n; 
vector<vector<int>> ar;

bool sem(vector<int> &a,vector<int> &b){
	for(int i = 0; i < 6; i++){
		if(a[i] != b[i]) return false;
	}
	return 1;
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
    cin>>n;
    bool p = false;
    for(int i = 0; i < n; i++){
    	vector<int> h(6);
    	for(int i = 0; i < 6; i++) cin>>h[i];
    	sort(all(h));
    	ar.pb(h);
    }
    sort(all(ar));
    for(int i = 1; i < n; i++){
    	if(sem(ar[i],ar[i-1])) p = 1;
    }
    if(p) cout<<"Twin snowflakes found." el;
    else cout<<"No two snowflakes are alike." el;
    return 0;
}
