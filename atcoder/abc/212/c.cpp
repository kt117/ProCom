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
    
    ll n, m; cin >> n >> m;
    ll a[n]; zep(i, 0, n)cin >> a[i];
    ll b[m]; zep(i, 0, m)cin >> b[i];
    
    vector<P> v;
    zep(i, 0, n)v.push_back(P(a[i], 0));
    zep(i, 0, m)v.push_back(P(b[i], 1));
    sort(v.begin(), v.end());

    ll ans = INF;
    ll aa = INF, bb = INF;
    zep(i, 0, v.size()){
        if(v[i].second == 0){
            aa = v[i].first;
        }else{
            bb = v[i].first;
        }

        ans = min(ans, abs(aa - bb));
    }
    print(ans)

    return 0;
}