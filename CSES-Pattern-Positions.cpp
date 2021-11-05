/*
    
    Note        :       suffix array + segtree
 
    Link        :       https://cses.fi/problemset/task/2104/
 
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
 
const ll mo = 1000000007,mt = 1000008259;
const ll oo = 3372036000000000;
const ll si = 100010;
const ll po = 31, pt = 29; 
 
struct tenstr{
    vector<ll> str,&id;
    ll def = 1000000000;
    ll fun(ll a,ll b){
        return min(a,b);
    }
    ll fun(ll a,ll b,ll c){
        return fun(a,fun(b,c));
    }
    void make(ll a,ll b,ll node){
        if(a == b){
            str[node] = id[a];
            return;
        }
        ll lef = node * 2, mid = a + (b - a)/2;
        make(a,mid,lef);
        make(mid+1,b,lef+1);
        str[node] = fun(str[lef],str[lef + 1]);
        return;
    }
    void updp(ll a,ll b,ll x,ll node,ll val){
        if(a == b){
            str[node] = val;
            return;
        }
        ll lef = node * 2, mid = a + (b - a)/2;
        if(x <= mid) updp(a,mid,x,lef,val); 
        else updp(mid+1,b,x,lef+1,val);
        str[node] = fun(str[lef],str[lef+1]); 
        return;
    }
    ll que(ll a,ll b,ll l,ll r,ll node){
        if(b < l || a > r) return def;
        if(a >= l && b <= r) return str[node];
        ll lef = node * 2, mid = a + (b - a)/2;
        return fun(que(a,mid,l,r,lef),que(mid+1,b,l,r,lef+1));
    }
    tenstr(ll x,vector<ll > &v) : id(v){
        str.assign(x * 4,def);
        make(0,x-1,1);
        return;
    }
};
 
vector<ll> sort_cyclic_shifts(string const& s) {
    ll n = s.size();
    const ll alphabet = 256;
    vector<ll> p(n), c(n), cnt(max(alphabet, n), 0);
    for (ll i = 0; i < n; i++)
        cnt[s[i]]++;
    for (ll i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (ll i = n-1; i >= 0; i--)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    ll classes = 1;
    for (ll i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
        vector<ll> pn(n), cn(n);
    for (ll h = 0; (1 << h) < n; ++h) {
        for (ll i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (ll i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (ll i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (ll i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        vector<int> div; 
        for (ll i = 1; i < n; i++) {
            pair<ll, ll> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<ll, ll> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev){
                ++classes;
                div.pb(i); 
            }
            cn[p[i]] = classes - 1;
        } 
        int sz = div.size(); 
        for(int i = 0; i < sz; i++){
            if(i == 0) sort(p.begin(),p.begin() + div[i]);
            else sort(p.begin() + div[i-1],p.begin() + div[i]);  
            if(i == sz - 1) sort(p.begin() + div[i],p.end()); 
 
        }
        c.swap(cn);
    }
    return p;
}
 
vector<ll> suffix_array_construction(string s) {
    s += "$";
    vector<ll> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}
 
vector<ll> sua; 
string s,x; 
ll n,xs; 
 
ll comp(ll a){
    ll i,j; 
    for(i = a,j = 0; i < n && j < xs; i++,j++){
        if(s[i] < x[j]) return -1; 
        if(s[i] > x[j]) return 1; 
    }
    if(j < xs && i == n) return -1; 
    return 0; 
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
    cin>>s; 
    n = s.size(); 
    sua = suffix_array_construction(s); 
    tenstr fmn(n,sua); 
    ll q; cin>>q; 
    while(q--){
        cin>>x;
        xs = x.size();  
        ll l = 0, r = n - 1, b = n + 1,a = n + 1;
        while(l <= r){
            ll mid = l + (r - l)/2; 
            ll res = comp(sua[mid]); 
            if(res >= 0){
                if(res == 0) b = mid;
                r = mid - 1; 
            }
            else l = mid + 1; 
        } 
        l = 0; r = n - 1; 
        while(l <= r){
            ll mid = l + (r - l)/2; 
            ll res = comp(sua[mid]); 
            if(res <= 0){
                if(res == 0) a = mid;
                l = mid + 1;
            }
            else r = mid - 1;  
        } 
        //cout<<a sp<< b sp; 
        b == n + 1 ? cout<<-1 el : cout<<fmn.que(0,n-1,b,a,1) + 1 el; 
    }
    return 0; 
}
/*
    check for: 
        *is mod minus? 
        *missed a break,continue ? 
        *corner cases, n = 1?
        *overflow.
        *unnecessary logics.
        *impreciseness caused by double or long double. 
 
*/
