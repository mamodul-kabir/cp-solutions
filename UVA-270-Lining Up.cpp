


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
 
const ll mod = 1111111111;
const ll oo = 3372036000000000;
const ll si = 1000005;

struct pnt{
    int x,y; 
}; 

pii ar[702][702];  

pii slope(pnt a,pnt b){
    int y = (a.y - b.y), x = (a.x - b.x), gc = __gcd(x,y); 
    x /= gc; y /= gc; 
    return {x,y}; 
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
//*/ 
    int t; cin>>t; 
    string dm; getline(cin,dm); getline(cin,dm);  
    while(t--){
        string s; 
        vector<pnt> poin; 
        while(getline(cin,s)){
            if(s == "") break; 
            istringstream ss(s); 
            pnt nw; ss>>nw.x>>nw.y; 
            poin.pb(nw); 
        }
        int n = poin.size(); 
        for(int i = 0; i < n; i++) for(int j = i + 1; j < n; j++){
            pii slo = slope(poin[i],poin[j]); 
            ar[i][j] = ar[j][i] = slo; 
        }
        int ans = 0; 
        for(int i = 0; i < n; i++){
            map<pii,int> rec; 
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                rec[ar[i][j]] += 1;  
            }
            for(auto r: rec) ans = max(ans,r.S + 1); 
        }
        cout<<ans el; 
        if(t) cout el; 
    } 
    return 0;
}
