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

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[n]; zep(i, 0, n)cin >> b[i];
    ll p[n]; zep(i, 0, n){cin >> p[i]; p[i]--;}

    zep(i, 0, n){
        if(i != p[i] && a[i] <= b[p[i]]){
            print(-1) return 0;
        }
    }

    vector<P> v;
    zep(i, 0, n){
        if(i != p[i]){
            v.push_back(P(a[i], i));
        }
    }
    if(v.size() == 0){
        print(0) return 0;
    }
    sort(v.begin(), v.end());

    ll rp[n]; zep(i, 0, n)rp[p[i]] = i;

    vector<P> ans;
    zep(i, 0, v.size()){
        ll a = v[i].second;
        if(p[a] != a){
            ll b = rp[a];
            ans.push_back(P(a, b));
            ll tmp = p[a];
            p[a] = p[b];
            p[b] = tmp;

            rp[a] = a;
            rp[p[b]] = b;
        }
    }

    print(ans.size())
    zep(i, 0, ans.size()){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    
    return 0;
}