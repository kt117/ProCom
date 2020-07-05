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

const long long MAX = 2e5+100;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    COMinit();

    ll n; cin >> n;
    ll p[n]; zep(i, 0, n){
        cin >> p[i];
        if(p[i] != -1)p[i]--;
    }

    bool use[n]; memset(use, 0, sizeof(use));
    ll m = 0;
    zep(i, 0, n){
        if(p[i] == -1){
            m++;
        }else{
            use[p[i]] = true;
        }
    }

    ll ans = 0;
    vector<ll> v1(n, 0);
    segtree<ll> sg1(v1);
    zep(i, 0, n){
        if(p[i] != -1){
            ans += sg1.query(p[i], p[i] + 1); ans %= MOD;
            sg1.range(0, p[i], 1);
        }
    }
    
    vector<ll> v(n, 0);
    segtree<ll> sg(v);
    zep(i, 0, n){
        if(!use[i])sg.range(0, i, 1);
    }

    ll cnt = 0;
    zep(i, 0, n){
        if(p[i] == -1){
            cnt++;
        }else{
            ll x = sg.query(p[i], p[i] + 1) % MOD;
            ans += (m - cnt) * (m - x) % MOD * inv[m] % MOD; ans %= MOD;
            ans += cnt * x % MOD * inv[m] % MOD; ans %= MOD;
        }
    }
    //print(ans)
    ans += (m * (m - 1) / 2) % MOD * inv[2] % MOD; ans %= MOD;
    print(ans)

    return 0;
}