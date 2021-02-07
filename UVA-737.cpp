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
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005;

struct cub{
    int x,y,z,xc,yc,zc;
};

cub comb(cub a, cub b){
    cub ans;
    ans.x = max(a.x,b.x);
    ans.xc = max(ans.x,min(a.xc,b.xc));
    ans.y = max(a.y,b.y);
    ans.yc = max(ans.y,min(a.yc,b.yc));
    ans.z = max(a.z,b.z);
    ans.zc = max(ans.z,min(a.zc,b.zc));
    return ans;
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
    int n;  
    while(cin>>n){
        if(n == 0) break;
        cub a; int d; cin>>a.x>>a.y>>a.z>>d; a.xc = a.x + d; a.yc = a.y + d; a.zc = a.z + d;
        for(int i = 1; i < n; i++){
            cub t; cin>>t.x>>t.y>>t.z>>d; t.xc = t.x + d; t.yc = t.y + d; t.zc = t.z + d;
            a = comb(a,t);
        }
        //cout<<a.x sp<<a.y sp<<a.z sp<<a.xc sp<<a.yc sp<<a.zc el;
        cout<<(a.xc - a.x) * (a.yc - a.y) * (a.zc - a.z) el;
    }
    return 0;
}
