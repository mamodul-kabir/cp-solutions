/*
   YOU CAN'T TAKE HELP FROM EDITORIAL               .m.
    
    Note        :       There is problem in the sample case. The input format is Y X instead of X Y. 

    Link        :	https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=691	

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
#define pii pair<int,int> 


using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;

vector<vector<int>> ans;
map<int,bool> d1,d2; bool c[8];
int ix,iy,tem[8];

void ini(){
	ans.clear();
	for(int i = -7; i < 8; i++) d1[i] = 1;
	for(int i = 0; i < 15; i++) d2[i] = 1;
	memset(c,1,8); memset(tem,-1,sizeof(tem));
	return;
}

void bktrk(int i){
	if(i == 8){
		vector<int> rel(8);
		for(int a = 0; a < 8; a++) rel[a] = tem[a] + 1;
		ans.pb(rel);
		return;
	}
	if(i == ix){
		bktrk(i + 1);
		return;
	}
	for(int a = 0; a < 8; a++){
		if(!c[a]) continue;
		bool ob = d1[i - a], tb = d2[i + a];
		if(ob && tb){
			d1[i - a] = 0; d2[i + a] = 0; c[a] = 0;
			tem[i] = a;
			bktrk(i + 1);
			d1[i - a] = 1; d2[i + a] = 1; c[a] = 1;
			tem[i] = -1;
		}
	}
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
    int t; cin>>t;
    while(t--){
    	ini();
    	cin>>iy>>ix; ix--, iy--;
    	tem[ix] = iy;
    	c[iy] = 0;
    	d1[ix - iy] = 0; d2[ix + iy] = 0;
    	bktrk(0);
    	sort(all(ans));
    	int cnt = 0;
    	for(auto r: ans){
    		if(cnt == 0) cout<<"SOLN       COLUMN" el<<" #      1 2 3 4 5 6 7 8" el el;
    		if(cnt < 9) cout<<" ";
    		cout<<++cnt<<"      ";
    		for(int i = 0; i < 8; i++) cout<<r[i],i == 7 ? cout el : cout sp;
    	}
    	if(t != 0) cout el;
    }
    return 0;
}