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
    
    ll n, c; cin >> n >> c;
    ll a[n + 10]; rep(i, 1, n)cin >> a[i]; 
    
    ll r[n + 10]; memset(r, 0, sizeof(r));
    rep(i, 1, n)if(a[i] == c)r[i]++;
    rrep(i, n - 1, 0)r[i] += r[i + 1];
    //printa(r, 0, n)

    ll cnt[500050]; memset(cnt, 0, sizeof(cnt));
    map<ll, ll> mp; 
    ll ans = r[0], ccnt = 0;
    rep(i, 1, n){
        if(a[i] == c){
            ccnt++;
        }else{
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = -ccnt;
            }else{
                mp[a[i]] = min(mp[a[i]], cnt[a[i]] - ccnt);
            }

            cnt[a[i]]++;
            ans = max(ans, cnt[a[i]] - mp[a[i]] + r[i + 1]);
        }    
    }

    print(ans)
    
    return 0;
}