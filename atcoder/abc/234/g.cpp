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
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            node[k] %= MOD;
            if(k < n) {
                lazy[k*2] += lazy[k] * ((MOD + 1) / 2) % MOD, lazy[k*2+1] += lazy[k] * ((MOD + 1) / 2) % MOD;
                lazy[k*2] %= MOD;
                lazy[k*2+1] %= MOD;
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
            lazy[k] += (r-l)*x % MOD;
            lazy[k] %= MOD;
            eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = node[2*k] + node[2*k+1];
            node[k] %= MOD;
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

ll n, a[300030], l[2][300030], r[2][300030], p[300030], ans;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i, 1, n)cin >> a[i];

    vector<P> v; rep(i, 1, n)v.push_back(P(a[i], i));

    sort(v.begin(), v.end(), greater<>());
    set<ll> ls, rs;
    ls.insert(0);
    rs.insert(n + 1);
    zep(i, 0, n){
        ll x = v[i].second;
        l[0][x] = -(*ls.lower_bound(-x));
        r[0][x] = *rs.lower_bound(x);
        ls.insert(-x);
        rs.insert(x);
    }

    sort(v.begin(), v.end());
    ls.clear(), rs.clear();
    ls.insert(0);
    rs.insert(n + 1);
    zep(i, 0, n){
        ll x = v[i].second;
        l[1][x] = -(*ls.lower_bound(-x));
        r[1][x] = *rs.lower_bound(x);
        ls.insert(-x);
        rs.insert(x);
    }

    vector<ll> u(n + 1, 0);
    u[0] = 1;
    segtree<ll> sg(u);

    rep(i, 1, n){
        // cout << l[0][i] << " " << r[0][i] << " " << l[1][i] << " " << r[1][i] << endl;
        // cout << sg.query(l[0][i], i) << " " << sg.query(l[1][i], i) << " " << a[i] << endl;
        sg.range(i, r[0][i], sg.query(l[0][i], i) * a[i] % MOD);
        sg.range(i, r[1][i], MOD - sg.query(l[1][i], i) * a[i] % MOD);
        // sg._print();
    }

    print(sg.query(n, n + 1) % MOD)
    
    return 0;
}