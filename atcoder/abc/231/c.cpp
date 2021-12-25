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
    
    ll n, q; cin >> n >> q;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll x[q]; zep(i, 0, q)cin >> x[i];

    vector<P> v;
    zep(i, 0, n)v.push_back(P(a[i], INF));
    zep(i, 0, q)v.push_back(P(x[i], i));
    sort(v.begin(), v.end(), greater<>());

    ll ans[q], cnt = 0;
    zep(i, 0, v.size()){
        if(v[i].second == INF){
            cnt++;
        }else{
            ans[v[i].second] = cnt;
        }
    }

    zep(i, 0, q)print(ans[i])
    
    return 0;
}