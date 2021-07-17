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
    //void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

const ll MAX = 2 * 101 * 1001;
ll n, p[MAX], a[MAX], b[MAX], c[MAX], pos[MAX], dp[MAX];

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n;
    rep(i, 1, n)cin >> p[i];
    rep(i, 1, n)cin >> a[i] >> b[i] >> c[i];
    rep(i, 1, n)pos[p[i]] = i;

    rep(i, 1, n){
        b[i] = min(a[i], b[i]);
        c[i] = min(a[i], c[i]);
        a[i] += a[i - 1];
        b[i] += b[i - 1];
        c[i] += c[i - 1];
    }
    
    vector<ll> v(MAX, INF);
    segtree<ll> sg(v);
    
    ll ans = INF;
    rep(i, 1, n){
        dp[i] = min(b[i - 1], sg.query(0, pos[i]) + a[i - 1]);
        ans = min(ans, dp[i] + c[n] - c[i]);
        sg.range(pos[i], pos[i] + 1, dp[i] - a[i]);
    }

    print(ans)
    
    return 0;
}