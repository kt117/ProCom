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
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        ll a[n]; zep(i, 0, n)cin >> a[i];

        bool use[n + 1]; memset(use, 0, sizeof(use));
        vector<ll> v;
        use[a[0]] = true;
        v.push_back(a[0]);
        zep(i, 1, n){
            use[a[i]] = true;
            if(a[i] != v.back())v.push_back(a[i]);
        }

        ll cnt[n + 1]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, v.size())cnt[v[i]]++;
        cnt[v[0]]--;
        cnt[v.back()]--;

        ll ans = INF;
        rep(i, 1, n){
            if(use[i])ans = min(ans, cnt[i] + 1);
        }
        print(ans)
    }
    
    return 0;
}