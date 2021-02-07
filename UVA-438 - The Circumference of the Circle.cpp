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
#define pii pair<ld,ld>
 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 1000000007;
const ll mxr = 1e6 + 10;
const ll oo = 3372036000000000;
const ll si = 100005;

struct eq
{
    ld a,b,c; 
};

ld sq(ld a){
    return a * a;
}

eq fq(ld x1,ld y1, ld x2, ld y2){
    ld x,y,z = -sq(x1) - sq(y1) + sq(x2) + sq(y2);
    x = 2 * (x2 - x1); y = 2 * (y2 - y1);

    return {x,y,z};
}

pii solve(eq n,eq m){
    ld x,y; 
    x = ((ld) (n.c * m.b) - (n.b * m.c))/((n.a * m.b) - (n.b * m.a));
    y = ((ld) (n.a * m.c) - (m.a * n.c))/((n.a * m.b) - (n.b * m.a));
    return {x,y};
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
    ld x1,x2,x3,y1,y2,y3; 
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3){
        eq n = fq(x1,y1,x2,y2), m = fq(x1,y1,x3,y3);
        pii cn = solve(n,m);
        ld rd = sqrt(sq(cn.F - x1) + sq(cn.S - y1));
        ld ans = 2 * rd *  3.141592653589793;
        cout<<showpoint<<setprecision(2)<<fixed<<ans el;
    }
    return 0;
}
