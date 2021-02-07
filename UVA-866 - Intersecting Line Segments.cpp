/*
 
    Note        :        implementation problem._.
 
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
#define pii pair<ld,ld>
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005;

struct eq{
    int a,b,c; 
};

struct enp
{
    int x1,y1,x2,y2;
};

bool par(eq n,eq m){
    if(n.a == m.a && n.b == m.b) return true;
    return false;
}

bool in(pii p,enp n,enp m){
    if(min(n.x1,n.x2) > p.F || max(n.x1,n.x2) < p.F) return false;
    if(min(n.y1,n.y2) > p.S || max(n.y1,n.y2) < p.S) return false;
    if(min(m.x1,m.x2) > p.F || max(m.x1,m.x2) < p.F) return false;
    if(min(m.y1,m.y2) > p.S || max(m.y1,m.y2) < p.S) return false;
    return true;
}

pii solve(eq n,eq m){
    ld x,y; 
    x = ((ld) (n.c * m.b) - (n.b * m.c))/((n.a * m.b) - (n.b * m.a));
    y = ((ld) (n.a * m.c) - (m.a * n.c))/((n.a * m.b) - (n.b * m.a));
    return {x,y};
}

eq fq(enp a){
    int dx = a.x1 - a.x2, dy = a.y1 - a.y2,x,y,z; 
    x = dy; y = -dx; z = -((dx * a.y1) - (dy * a.x1));
    if(!(x == 0 && y == 0)){
        int gc = __gcd(x,__gcd(y,z));
        x /= gc; y /= gc; z /= gc;
    }
    return {x,y,z};
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
        int n; cin>>n; 
        vector<int> cut(n,1);
        vector<pair<enp,eq>> ar(n);
        for(int i = 0; i < n; i++){
            cin>>ar[i].F.x1>>ar[i].F.y1>>ar[i].F.x2>>ar[i].F.y2; 
            ar[i].S = fq(ar[i].F);
            //cout<<i sp<<ar[i].S.a sp<<ar[i].S.b sp<<ar[i].S.c el;
        }
        //cout el;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(par(ar[i].S,ar[j].S)) continue;
                pii sl = solve(ar[i].S,ar[j].S);
                //cout<<i sp<<j sp<<sl.F sp<<sl.S el;
                if(in(sl,ar[i].F,ar[j].F)){
                    cut[i] += 1;
                    cut[j] += 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) ans += cut[i];
        cout<<ans el;
        if(t) cout el;
    }
    return 0;
}
