/*
 
    Note        :         Fruteborce is da sweetest fruit. 
 
    Link        :      
 
 
*/
 
 
#include "bits/stdc++.h"
 
#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define pb push_back
#define all(ar) ar.begin(),ar.end()
#define pii pair<int,int>
#define vec vector<ll> 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 100000007;
const ll si = 10006;

ld ar[200][200];
vector<pii> crd; 

int sq(int a){
	return a * a;
}

ld dis(pii a,pii b){
	//cout<<a.F sp<<b.F sp<<a.S sp<<b.S el;
	return sqrt(sq(a.F - b.F) + sq(a.S - b.S));
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
    int n,t = 0; 
    while(cin>>n){
    	if(!n) break;
    	crd.clear();
    	for(int i = 0; i < n; i++){
    		int x,y; cin>>x>>y; 
    		crd.pb({x,y});
    	}
    	for(int i = 0; i < n; i++) for(int j = i; j < n; j++){
    		if(i == j) ar[i][j] = 0;
    		else ar[i][j] = dis(crd[i],crd[j]);
    		ar[j][i] = ar[i][j];
    		//cout<<i sp<<j sp<<ar[i][j] el;
    	}
    	for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    		if(i != j){
    			ar[i][j] = min(ar[i][j],max(ar[i][k],ar[k][j]));
    		}
    	}
    	cout<<"Scenario #"<<++t el<<"Frog Distance = "<<showpoint<<setprecision(3)<<fixed<<ar[0][1] el el;
    }
    return 0;
}
