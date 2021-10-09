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
    ll a[n], b[n]; zep(i, 0, n)cin >> a[i] >> b[i];

    vector<P> v;
    zep(i, 0, n)v.push_back(P(a[i], 1));
    zep(i, 0, n)v.push_back(P(a[i] + b[i], -1));

    sort(v.begin(), v.end());
    ll t = 0, ans[n + 1], cnt = 0;
    memset(ans, 0, sizeof(ans));
    
    zep(i, 0, v.size()){
        // cout << v[i].first << " " << v[i].second << endl;
        if(v[i].first != t){
            ans[cnt] += v[i].first - t;
            t = v[i].first;
        }
        cnt += v[i].second;
    }

    printa(ans, 1, n)
    
    return 0;
}