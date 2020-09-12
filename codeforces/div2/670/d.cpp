#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
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
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k] / 2, lazy[k*2+1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = node[2*k] + node[2*k+1];
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++];
            if(b & 1) eval(--b), res2 += node[b];
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void _print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

ll f(ll x){
    if(x > 0)return (x + 1) / 2;
    return x / 2;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<ll> vb(n + 1, 0), vc(n + 1, 0);
    segtree<ll> b(vb), c(vc);

    rrep(i, n - 1, 1)a[i] -= a[i - 1];

    zep(i, 0, n){
        if(a[i] > 0)b.range(i, i + 1, a[i]);
        if(a[i] < 0)c.range(i, i + 1, a[i]);
    }
    
    print(f(b.query(0, n) + c.query(0, 1)))
    
    ll q; cin >> q;
    while(q--){
        ll l, r, x; cin >> l >> r >> x;
        l--;
        
        ll y = x + b.query(l, l + 1) + c.query(l, l + 1);
        b.range(l, l + 1, -b.query(l, l + 1));
        c.range(l, l + 1, -c.query(l, l + 1));

        if(y > 0)b.range(l, l + 1, y);
        if(y < 0)c.range(l, l + 1, y);

        x *= -1;
        l = r;

        y = x + b.query(l, l + 1) + c.query(l, l + 1);
        b.range(l, l + 1, -b.query(l, l + 1));
        c.range(l, l + 1, -c.query(l, l + 1));

        if(y > 0)b.range(l, l + 1, y);
        if(y < 0)c.range(l, l + 1, y);

        print(f(b.query(0, n) + c.query(0, 1)))
    }

    return 0;
}