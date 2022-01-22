#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    vector<bool> lazyFlag;
    void eval(int k) {
        if(lazyFlag[k]){
            node[k] = lazy[k];
            if(k < n) {
                lazy[k*2] = lazy[k*2+1] = lazy[k] * ((MOD + 1) / 2) % MOD;
                lazyFlag[k*2] = lazyFlag[k*2+1] = true;
            }
            lazyFlag[k] = false;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0), lazyFlag.resize(2*n, false);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = (node[2*i] + node[2*i+1]) % MOD;
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = (r-l)*x % MOD; lazyFlag[k] = true, eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = (node[2*k] + node[2*k+1]) % MOD;
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++], res1 %= MOD;
            if(b & 1) eval(--b), res2 += node[b], res2 %= MOD;
            a >>= 1, b >>= 1;
        }
        return (res1 + res2) % MOD;
    }
    void _print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n + 1]; rep(i, 1, n)cin >> a[i];
    a[0] = 0;
    rep(i, 1, n){a[i] += a[i - 1]; a[i] %= MOD;}

    vector<ll> v(n + 1, 0);
    // v[0] = 1;
    segtree<ll> sg(v);
    map<ll, ll> mp;
    // mp[0] = 1;

    rep(i, 1, n - 1){
        ll x = (sg.query(1, i) + 1) % MOD;

        if(mp.find(a[i]) == mp.end()){
            mp[a[i]] = 0;
        }
        x = (x + MOD - mp[a[i]]) % MOD;
        mp[a[i]] = (mp[a[i]] + x) % MOD;
        
        sg.range(i, i + 1, x);
    }

    print((sg.query(0, n) + 1) % MOD)

    return 0;
}