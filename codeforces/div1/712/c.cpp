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
    ll a[n], c[n]; zep(i, 0, n)cin >> a[i] >> c[i];

    vector<P> v(n); zep(i, 0, n)v[i] = P(a[i], i);
    sort(v.begin(), v.end());

    vector<ll> ans;
    ans.push_back(v[0].second);
    ll cost = 0, r = a[v[0].second] + c[v[0].second];
    bool use[n]; memset(use, 0, sizeof(use));
    zep(i, 1, n){
        if(a[v[i].second] + c[v[i].second] > r){
            cost += max(c[ans.back()], a[v[i].second] - a[ans.back()]);
            r = a[v[i].second] + c[v[i].second];
            ans.push_back(v[i].second);
            use[v[i].second] = true;
        }
    }

    rrep(i, n - 1, 1){
        if(!use[v[i].second]){
            cost += c[ans.back()];
            ans.push_back(v[i].second);
        }
    }
    cost += c[ans.back()];
    //printa(ans, 0, ans.size() - 1)
    print(cost);

    return 0;
}