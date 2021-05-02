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
    vector<bool> lazyFlag;
    void eval(int k) {
        if(lazyFlag[k]){
            node[k] = lazy[k];
            if(k < n) {
                lazy[k*2] = lazy[k*2+1] = lazy[k] / 2;
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
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = (r-l)*x; lazyFlag[k] = true, eval(k);
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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, T; cin >> n >> T;
    ll a[n]; zep(i, 0, n)cin >> a[i];

    vector<ll> u(n, 1), v(n);
    zep(i, 0, n)v[i] = a[i];
    segtree<ll> sg(v), cnt(u);

    ll ans = 0, s = 0;
    zep(i, 0, n){
        ll sm = sg.query(0, n);
        ans += (T / sm) * (n - i);
        T -= sm * (T / sm);

        ll ok = 0, ng = n, okx = 0;
        while(ng - ok > 1){
            ll mid = (ok + ng) / 2;

            ll x = 0;
            x += sg.query(s, min(s + mid, n));
            if(s + mid > n)x += sg.query(0, (s + mid) % n);

            if(x <= T){
                ok = mid;
                okx = x;
            }else{
                ng = mid;
            }
        }

        ans += cnt.query(s, min(s + ok, n));
        if(s + ok > n)ans += cnt.query(0, (s + ok) % n);

        T -= sg.query(s, min(s + ok, n));
        if(s + ok > n)T -= sg.query(0, (s + ok) % n);

        s += ok; s %= n;
        sg.range(s, s + 1, 0);
        cnt.range(s, s + 1, 0);
    }

    print(ans)
    
    return 0;
}