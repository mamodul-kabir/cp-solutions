/*
    
    Note        :       New thing learnt: MO's ordering and algo. 
    					          I had to also get the hint to indentify the unique element in an array from rez1 bhai's 
    					          blog. 

    					          Moreover, not an OC solution but I learnt a lot from this problem. 


    Link        :       https://cses.fi/problemset/task/1734/
    
    
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

const ll mod = 100000000;
const ll oo = 3372036000000000;
const ll si = 250000;
const ll k = 448;

#define psi pair<pii,int> 

int ar[si],mr[si],qan[si],fr[si],ans = 0;
unordered_set<int> rc;
unordered_map<int,int> ind;
vector<int> v;
vector<psi> qq;

bool cmp(psi a,psi b){                                            //compare by MO's ordering. 
	if((a.F.F/k) == (b.F.F/k)) return a.F.S < b.F.S;                //if they are in the same block, then sort them by their right value.
	return (a.F.F/k) < (b.F.F/k);                                   //if not, then sort them by block index.
}

void add(int x){
	fr[mr[x]] += 1;
	if(fr[mr[x]] == 1) ans++;                       //// if frequency is 1 then an unique element has been added.
	return;
}

void rmv(int x){
	fr[mr[x]] -= 1;
	if(fr[mr[x]] == 0) ans--;                       // if frequency is 0 then an unique element has been removed.
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
    rc.reserve(1<<18);
    rc.max_load_factor(0.25);
    int n,q; cin>>n>>q;
    for(int i = 0; i < n; i++){
    	cin>>ar[i];
    	rc.insert(ar[i]);
    }
    for(int r: rc) v.pb(r);
    sort(all(v));
	ind.reserve(1<<18);
	ind.max_load_factor(0.25);
	for(int i = 0, t = v.size(); i < t; i++) ind[v[i]] = i;
	for(int i = 0; i < n; i++){
		mr[i] = ind[ar[i]];
	} 
	memset(fr,0,sizeof(fr));
	for(int i = 0; i < q; i++){
		int a,b; cin>>a>>b;
		a -= 1; b -= 1;
		qq.pb({{a,b},i});
	}
	sort(all(qq),cmp);
	int cl = 0, cr = -1;
	for(auto d: qq){
		int l = d.F.F, r = d.F.S;
		while(cl > l) add(--cl);                            //--cl because cl is included. --cl is to include (cl-1)
		while(cr < r) add(++cr);
		while(cl < l) rmv(cl++);                            //cl++ because cl is included but cl + 1 is not, then cl++ is to increment cl then add/remove it
		while(cr > r) rmv(cr--);
		//cout<<l sp<<r sp<<cl sp<<cr el;
		qan[d.S] = ans;
		//cout<<ans el;
	}
	for(int i = 0; i < q; i++) cout<<qan[i] el;
    return 0;
}
