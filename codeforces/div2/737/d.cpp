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
        for(int i = n - 1; i >= 1; i--) node[i] = max(node[i*2], node[i*2+1]);
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
            node[k] = max(node[2*k], node[2*k+1]);
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::max(), res2 = numeric_limits<T>::max();
        while(a < b) {
            if(a & 1) eval(a), res1 = max(res1, node[a++]);
            if(b & 1) eval(--b), res2 = max(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return max(res1, res2);
    }
    // void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    ll a[m], l[m], r[m]; zep(i, 0, m){cin >> a[i] >> l[i] >> r[i]; a[i]--;}
    
    map<ll, ll> mp;
    zep(i, 0, m){
        mp[l[i]] = -1;
        mp[r[i]] = -1;
    }
    
    ll cnt = 0;
    for(auto it = mp.begin(); it != mp.end(); it++){
        mp[(*it).first] = cnt++;
    }
    
    vector<vector<P>> sp(n);
    zep(i, 0, m){
        sp[a[i]].push_back(P(mp[l[i]], mp[r[i]]));
    }

    ll N = mp.size();
    vector<P> v(N, P(0, -1));
    segtree<P> sg(v);

    ll mxi[n];
    zep(i, 0, n){
        ll mx = -1, from = -1;

        zep(j, 0, sp[i].size()){
            auto p = sp[i][j];
            auto q = sg.query(p.first, p.second + 1);
            // print(q.second)
            if(q.first > mx){
                mx = q.first;
                from = q.second;
            }
        }

        zep(j, 0, sp[i].size()){
            auto p = sp[i][j];
            sg.range(p.first, p.second + 1, P(mx + 1, i));
        }
        mxi[i] = from;
    }
    // printa(mxi, 0, n - 1)
    
    auto q = sg.query(0, N);

    print(n - q.first)
    
    bool use[n]; memset(use, 0, sizeof(use));
    ll at = q.second;
    zep(i, 0, q.first){
        use[at] = true;
        at = mxi[at];
    }
    
    zep(i, 0, n){
        if(!use[i])cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}