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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        ll b[n]; zep(i, 0, n)b[i] = a[i];
        sort(b, b + n);
        map<ll, ll> mp;
        zep(i, 0, n)mp[b[i]] = i;
        zep(i, 0, n)a[i] = mp[a[i]];

        ll l[n], r[n];
        ll mx = a[0];
        zep(i, 0, n){
            mx = max(mx, a[i]);
            l[i] = mx;
        }

        mx = a[n - 1];
        rrep(i, n - 1, 0){
            mx = max(mx, a[i]);
            r[i] = mx;
        }
        //printa(l, 0, n - 1)
        //printa(r, 0, n - 1)

        ll li[n]; memset(li, -1, sizeof(li));
        zep(i, 0, n)li[l[i]] = i;

        ll ri[n]; memset(ri, -1, sizeof(ri));
        rrep(i, n - 1, 0)ri[r[i]] = i;

        //printa(li, 0, n - 1)
        //printa(ri, 0, n - 1)

        vector<int> u(n); zep(i, 0, n)u[i] = a[i];
        segtree<int> sg(u);
        
        bool ok = false;
        vector<ll> ans;
        zep(i, 0, n){
            if(li[i] != -1 && ri[i] != -1){
                if(li[i] >= ri[i]){
                    vector<ll> v;
                    zep(j, 0, n)if(a[j] == i)v.push_back(j);
                    
                    if(v.size() >= 3){
                        ok = true;
                        ans = {v[1], 1, n - (v[1] + 1)};
                    }
                }else{
                    if(li[i] + 1 < ri[i] && sg.query(li[i] + 1, ri[i]) == i){
                        ok = true;
                        ans = {li[i] + 1, ri[i] - li[i] - 1, n - ri[i]};
                    }else if(li[i] + 1 == ri[i] || sg.query(li[i] + 1, ri[i]) > i){
                        if(a[li[i]] == i && li[i] > 0 && l[li[i] - 1] == i){
                            ok = true;
                            ans = {li[i], ri[i] - li[i], n - ri[i]};
                        }else if(a[ri[i]] == i && ri[i] < n - 1 && r[ri[i] + 1] == i){
                            ok = true;
                            ans = {li[i] + 1, ri[i] - li[i], n - ri[i] - 1};
                        }
                    }
                }

                if(ok)break;
            }
        }

        if(ok){
            print("YES")
            zep(i, 0, 3)cout << ans[i] << " "; cout << endl;
        }else{
            print("NO")
        }
    }
    
    return 0;
}