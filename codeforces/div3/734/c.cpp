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
        string s[n]; zep(i, 0, n)cin >> s[i];

        ll ans = 0;
        zep(k, 0, 5){
            ll cnt[n]; memset(cnt, 0, sizeof(cnt));

            zep(i, 0, n){
                zep(j, 0, s[i].size()){
                    if(s[i][j] - 'a' == k){
                        cnt[i]++;
                    }else{
                        cnt[i]--;
                    }
                }
            }

            sort(cnt, cnt + n, greater<>());
            // printa(cnt, 0, n - 1);
            zep(i, 1, n)cnt[i] += cnt[i - 1];
            zep(i, 0, n)if(cnt[i] > 0)ans = max(ans, i + 1);
        }
        print(ans)
    }
    
    return 0;
}