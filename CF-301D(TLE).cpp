/*
    
    Note        :       Tried to solve with MO's algo with hilbert's curve. Got TLE.   
                        Edit: I missed a key point. the array will be permutation of numbers from 1...n 
 
    Link        :       https://codeforces.com/contest/301/problem/D
 
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
const ll oo = 3372036000000000;
const ll si = 200005;
const ll block = 450; 


constexpr int logn = 18;
constexpr int maxn = 1 << logn;

long long hilbertorder(int x, int y)
{
    long long d = 0;
    for (int s = 1 << (logn - 1); s; s >>= 1)
    {
        bool rx = x & s, ry = y & s;
        d = d << 2 | rx * 3 ^ static_cast<int>(ry);
        if (!ry)
        {
            if (rx)
            {
                x = maxn - x;
                y = maxn - y;
            }
            swap(x, y);
        }
    }
    return d;
}

 
int oc[si],n,q, mul[si]; 
vector<int> ar,di[si];  
ll heu = 0,res = 0; 



struct qq
{
    int l,r,i,ord; 
    void cal(){
        ord = hilbertorder(l,r); 
    }
};

bool comp(qq a,qq b){
    return a.ord < b.ord; 
    //ll x = a.l/block, y = b.l/block; 
    //if(x == y) return a.r < b.r; 
    //return x < y; 
}

void add(int x){
    //cout<<"add" sp<<x sp; 
    oc[x] += 1; 
    mul[x] -= 1; 
    for(int r: di[x]){
        res += oc[r]; 
        mul[r] += 1; 
    }
    res += mul[x]; 
    //cout<<res el;
}

void remove(int x){ 
    //cout<<"rem" sp<<x sp;
    mul[x] += 1; 
    for(int r: di[x]){
        res -= oc[r]; 
        mul[r] -= 1; 
    }
    oc[x] -= 1;
    res -= mul[x]; 
    //cout<<res el;
}

void do_di(){
    for(int r = 1; r <= n; r++){
        for(int i = 1; i * i <= r; i++){
            if(r % i == 0){ 
                di[r].pb(i); 
                int ot = r/i; 
                if(ot != i ) di[r].pb(ot); 
            }
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
    memset(mul,0,sizeof(mul)); memset(oc,0,sizeof(oc)); 
    cin>>n>>q; 
    for(int i = 0; i < n; i++){
        int x; cin>>x;  
        ar.pb(x); 
    }
    do_di();  
    int ans[q]; 
    //cout<<"done" el; 
    vector<qq> que(q);
    for(int i = 0; i < q; i++){
        int l,r; cin>>l>>r; 
        l -= 1; r -= 1; 
        que[i].l = l; que[i].r = r; que[i].i = i; 
        que[i].cal(); 
    }
    sort(all(que),comp);
    int a = 0, b = -1; 
    for(qq r: que){ 
        //cout<<r.l sp<<r.r el;
        while(a > r.l) add(ar[--a]); 
        while(b < r.r) add(ar[++b]);
        while(a < r.l) remove(ar[a++]); 
        while(b > r.r) remove(ar[b--]); 
        ans[r.i] = res; 
    }
    for(int r: ans) cout<<r el;
    return 0;
}
