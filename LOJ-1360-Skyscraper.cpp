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
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll ms = 200; 
const ll oo = 3372036000000000;
const ll si = 200005;

vector<pii> vec[si]; 

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
    for(int z = 1; z <= t; z++){
        int n; cin>>n; 
        for(int i = 0; i <= 200000; i++) vec[i].clear();  
        for(int i = 0; i < n; i++){
            int a,b,c; cin>>a>>b>>c; 
            vec[a].pb({b,c});  
        } 
        ll ar[si]; memset(ar,0,sizeof(ar)); 
        ll cur = 0; 
        for(int i = 0; i <= 200000; i++){
            for(pii r: vec[i]){
                int nin = i + r.F - 1; 
                ar[nin] = max(ar[nin],r.S + cur); 
                //cout<<i sp<<nin el;
            }
            cur = max(cur,ar[i]); 
        }
        cout<<"Case "<<z<<": "<<cur el;
    }
    return 0;
}
