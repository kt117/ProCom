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
    int n,sz,h; vector<T> node, lazy;
    vector<bool> lazyFlag;
    void eval(int k) {
        if(lazyFlag[k]){
            node[k] = lazy[k];
            if(k < n) {
                lazy[k*2] = lazy[k*2+1] = lazy[k];
                lazyFlag[k*2] = lazyFlag[k*2+1] = true;
            }
            lazyFlag[k] = false;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0){
        while(n < sz) n *= 2, h++;
        node.resize(2*n, numeric_limits<T>::max());
        lazy.resize(2*n); lazyFlag.resize(2*n, false);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n - 1; i >= 1; i--) node[i] = min(node[i*2], node[i*2+1]);
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b){
            lazy[k] = x, lazyFlag[k] = true; eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = min(node[2*k], node[2*k+1]);
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::max(), res2 = numeric_limits<T>::max();
        while(a < b) {
            if(a & 1) eval(a), res1 = min(res1, node[a++]);
            if(b & 1) eval(--b), res2 = min(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return min(res1, res2);
    }
    void _print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<segtree<int>> mx(32, segtree<int>(vector<int>(n, 0)));
    vector<segtree<int>> mn(32, segtree<int>(vector<int>(n, 0)));

    zep(i, 0, n){
        ll a[k]; zep(j, 0, k)cin >> a[j];

        zep(bit, 0, (1 << k) / 2){
            ll res = 0;
            zep(j, 0, k){
                if(bit & (1 << j)){
                    res += a[j];
                }else{
                    res -= a[j];
                }
            }
            mx[bit].range(i, i + 1, -res);
            mn[bit].range(i, i + 1, res);
        }
    }

    ll q; cin >> q;
    zep(i, 0, q){
        ll f; cin >> f;
        if(f == 1){
            ll at; cin >> at; at--;
            ll b[k]; zep(j, 0, k)cin >> b[j];

            zep(bit, 0, (1 << k) / 2){
                ll res = 0;
                zep(j, 0, k){
                    if(bit & (1 << j)){
                        res += b[j];
                    }else{
                        res -= b[j];
                    }
                }
                mx[bit].range(at, at + 1, -res);
                mn[bit].range(at, at + 1, res);
            }
        }else{
            ll l, r; cin >> l >> r; l--;

            int res = 0;
            zep(bit, 0, (1 << k) / 2){
                res = max(res, abs(mx[bit].query(l, r) + mn[bit].query(l, r)));
            }
            print(res)
        }
    }
    
    return 0;
}