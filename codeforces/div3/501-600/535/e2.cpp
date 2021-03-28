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
                lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, numeric_limits<T>::max());
        lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = min(node[2*i], node[2*i+1]);
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k);
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

const ll N = 1e5;
ll n, m, a[N], l[300], r[300];
vector<vector<ll>> lv(N), rv(N);

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> m;
    zep(i, 0, n)cin >> a[i];

    vector<ll> v(n, 0);
    zep(i, 0, n)v[i] += a[i];
    segtree<ll> sg(v);
    
    zep(j, 0, m){
        cin >> l[j] >> r[j]; l[j]--;
        rv[l[j]].push_back(r[j]);
        sg.range(l[j], r[j], -1);
    }

    ll ans = 0, ai = -1;
    zep(i, 0, n){
        zep(j, 0, rv[i].size()){
            sg.range(i, rv[i][j], 1);
            lv[rv[i][j]].push_back(i);
        }

        zep(j, 0, lv[i].size()){
            sg.range(lv[i][j], i, -1);
        }

        ll mx = a[i] - sg.query(0, n);
        if(mx > ans){
            ans = mx;
            ai = i;
        }
    }

    
    vector<ll> av;
    zep(j, 0, m){
        if(ai < l[j] || r[j] <= ai){
            av.push_back(j);
        }
    }

    print(ans)
    print(av.size())
    zep(j, 0, av.size())cout << av[j] + 1 << " "; cout << endl;

    return 0;
}