/*
 
    Note        :                   Not OC, but really fun problem and I learnt a lot from this. 
                                    I also had a 4^n inefficient solution which got TLE. 
                                    
                                    Things learnt: 
                                    *you can use inter-dependent data-structure, eg. array of pairs in this case, because when a lesser step is needed for a mask, it is updated and the
                                    last added value does not matter. But when the updatable step is equal, we consider the least last lift value. 
 
    Link        :      		    https://cses.fi/problemset/task/1653/
 
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
const ll si = (1<<20);
 
ll ar[20],n,k,lim;
pii mamo[si];               // here, First is the least steps needed for the subset of people to get into the top floor, and Second is the least total weight of the people in the last
                           // in the last batch. 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/    
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>ar[i];
    lim = (1<<n);
	for(int m = 1; m < lim; m++) mamo[m] = {n+1,0};
	mamo[0] = {1,0};
	for(int m = 0; m < lim; m++){
		for(int i = 0; i < n; i++) if(!(m & (1<<i))){
			pii opt;
			if(mamo[m].S + ar[i] > k) opt = {mamo[m].F + 1,ar[i]};
			else opt = {mamo[m].F,ar[i] + mamo[m].S};
			mamo[m | (1<<i)] = min(mamo[m | (1<<i)],opt);
		}
	}
	cout<<mamo[lim - 1].F el;
    return 0;
}
