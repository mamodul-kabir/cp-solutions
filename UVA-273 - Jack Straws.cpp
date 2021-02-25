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
#define pii pair<ld,ld>
#define vec vector<ll> 
 
using namespace std;
using ll = long long;
using ld = long double;
 
const ll mod = 100000007;
const ll si = 10006;

struct str{
    int x1,y1,x2,y2; 
};

struct eqn{
    int x,y,z; 
};

vector<str> tbl;
bool ar[14][14];

eqn gete(str a){
    int dx = a.x1 - a.x2, dy = a.y1 - a.y2; 
    eqn ans; 
    ans.x = dy; ans.y = -dx; ans.z = ((dy * a.x1) - (dx * a.y1));
    int gc = __gcd(ans.x,__gcd(ans.y,ans.z));
    ans.x /= gc; ans.y /= gc; ans.z /= gc; 
    return ans;
}

pii slv(eqn a,eqn b){
    int d = (a.x * b.y) - (a.y * b.x), dx = (a.z * b.y) - (b.z * a.y), dy = (a.x * b.z) - (b.x * a.z);
    ld xx = ((ld) dx/d), yy = ((ld) dy/d);
    return {xx,yy};    
}

bool in(str a,pii q){
    return min(a.x1,a.x2) <= q.F && q.F <= max(a.x2,a.x1) && min(a.y1,a.y2) <= q.S && q.S <= max(a.y2,a.y1);
}

bool corner(str a,str b){
    bool one = (min(a.x1,a.x2) <= b.x1 && b.x1 <= max(a.x2,a.x1)), two = (min(a.x1,a.x2) <= b.x2 && b.x2 <= max(a.x2,a.x1));
    bool three = (min(b.x1,b.x2) <= a.x1 && a.x1 <= max(b.x1,b.x2)), four = (min(b.x1,b.x2) <= a.x2 && a.x2 <= max(b.x1,b.x2));
    return one || two || three || four;
}

bool check(str a,str b){
    eqn p = gete(a), q = gete(b);
    if(p.x == q.x && p.y == q.y && p.z != q.z) return false;
    else if(p.x == q.x && p.y == q.y) return corner(a,b);
    pii sol = slv(p,q);
    //cout<<sol.F sp<<sol.S sp;
    //in(a,sol) && in(b,sol) ? cout<<"yes" el: cout<<"no" el;
    return in(a,sol) && in(b,sol);

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
        tbl.clear();
        memset(ar,0,sizeof(ar));
        for(int i = 0; i < n; i++){
            int q,w,e,r; cin>>q>>w>>e>>r; 
            str a = {q,w,e,r}; 
            //eqn tem = gete(a);
            //cout<<i sp<<tem.x sp<<tem.y sp<<tem.z el;
            tbl.pb(a);
        }
        for(int i = 0; i < n; i++) for(int j = i; j < n; j++){
            if(i == j){
                ar[i][i] = 1; continue;
            }
            //cout<<i sp<<j <<" : ";
            bool con = check(tbl[i],tbl[j]);
            ar[i][j] = ar[j][i] = con; 
        }
        //for(int i = 0; i < n; i++, cout el) for(int j = 0; j < n; j++,cout sp) cout<<ar[i][j];
        for(int k = 0; k < n; k++) for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
            ar[i][j] |= (ar[i][k] && ar[k][j]);
        }
        int a,b;
        while(cin>>a>>b){
            if(a == b && a == 0) break;
            a -= 1; b -= 1; 
            ar[a][b] ? cout<<"CONNECTED" el : cout<<"NOT CONNECTED" el;
        }
        if(t) cout el;
    }
    return 0;
}
