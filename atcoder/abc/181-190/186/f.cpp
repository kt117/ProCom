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

template<typename T> class BIT {
private:
    int n,sz;
    vector<T> node;

public:
    BIT(int sz) : n(1), sz(sz){
        while(n < sz) n *= 2;
        node.resize(n, 0);
    }
    
    void add(int i, T x){
        i++;
        while(i <= n){
            node[i] += x;
            i += i & -i;
        }
    }
    
    T sum(int i){
        if(i < 0)return 0;

        T s = 0;
        i++;
        while(i){
            s += node[i];
            i -= i & -i; 
        }
        return s;
    }
};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll h, w, m; cin >> h >> w >> m;
    ll x[m], y[m];
    zep(i, 0, m){cin >> x[i] >> y[i]; x[i]--; y[i]--;}
    
    vector<ll> xs(w, h - 1), ys(h, w - 1);
    zep(i, 0, m)xs[y[i]] = min(xs[y[i]], x[i] - 1);
    zep(i, 0, m)ys[x[i]] = min(ys[x[i]], y[i] - 1);
    
    vector<P> yx; rep(i, 0, xs[0])yx.push_back(P(ys[i], i));
    sort(yx.begin(), yx.end(), greater<>());
    
    BIT<ll> bt(h);
    rep(i, 0, xs[0])bt.add(i, 1);

    ll db = 0;
    rep(i, 0, ys[0]){
        db += bt.sum(xs[i]);

        while(!yx.empty() && yx.back().first == i){
            bt.add(yx.back().second, -1);
            yx.pop_back();
        }
    }

    ll ans = 0;
    rep(i, 0, ys[0])ans += xs[i] + 1;
    rep(i, 0, xs[0])ans += ys[i] + 1;
    ans -= db;
    print(ans)

    return 0;
}