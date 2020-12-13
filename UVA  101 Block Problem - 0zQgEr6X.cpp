/*
    
    Note        :    	Totally implementation and Nasty implementation.    

    Link        :	https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37

    Boka hoye gelum...
*/
#include "bits/stdc++.h"
#include "bitset"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end() 
#define showp(x) <<showpoint<<setprecision(x)<<fixed<<
#define pii pair<ll,ll> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;

int at[24];
vector<int> ar[24];

int par(int i){
	while(at[i] != i){
		at[i] = at[at[i]];
		i = at[i];
	}
	return i;
}

void show(int n){
	for(int i = 0; i < n; i++, cout el){
		cout<<i<<":";
		if(at[i] == i){
			cout sp<<i;
			int s = ar[i].size();
			for(int x = 0; x < s; x++){
				if(x == 0) cout sp;
				cout<<ar[i][x];
				if(x != s - 1) cout sp;
			}
		}
	}
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
    int n; cin>>n;
    for(int i = 0; i < n; i++) at[i] = i;
    string st;
	while(1){
		int a,b,dd,pa; string tp;
		cin>>st;
		if(st == "quit"){
			//cout<<"done" el;
			show(n);
			break;
		}
		cin>>a>>tp>>b;
		dd = par(b); pa = par(a);
		if(dd == pa || a == b) continue;
		if(st == "move"){
			if(pa == a){
				for(int r: ar[a]) at[r] = r;
				ar[a].clear();
			}
			else{
				bool f = 0;
				int i = 0; 
				for(int r: ar[pa]){
					if(r == a) f = 1;
					if(f) at[r] = r;
					else i++;
				}
				ar[pa].erase(ar[pa].begin() + i, ar[pa].end());
			}
			if(tp == "onto"){
				bool fnd = false;
				int i = 0;
				for(int r: ar[dd]){
					if(!fnd) i++;
					if(r == b || b == dd) fnd = 1;
					if(fnd && r != b) at[r] = r;
				}
				if(dd != b) ar[dd].erase(ar[dd].begin() + i, ar[dd].end());
				else ar[b].clear();
			}
			ar[dd].pb(a);
		}else if(st == "pile"){
			vector<int> pl; 
			if(pa == a){
				pl.pb(a); for(int r: ar[a]) pl.pb(r);
				ar[a].clear();
			}else{
				bool f = 0;
				int i = 0; 
				for(int r: ar[pa]){
					if(r == a) f = 1;
					if(f) pl.pb(r);
					else i++;
				}
				ar[pa].erase(ar[pa].begin() + i, ar[pa].end());
			}
			if(tp == "onto"){
				bool fnd = false;
				int i = 0;
				for(int r: ar[dd]){
					if(!fnd) i++;
					if(r == b || b == dd) fnd = 1;
					if(fnd && r != b) at[r] = r;
				}
				if(dd != b) ar[dd].erase(ar[dd].begin() + i, ar[dd].end());
				else ar[b].clear();
			}
			for(int r: pl) ar[dd].pb(r),at[r] = dd; 
		}
		at[a] = dd;
	}
    return 0;
}