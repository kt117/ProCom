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
        string s; cin >> s;

        ll cnt[26]; memset(cnt, 0, sizeof(cnt));
        zep(i, 0, s.size()){
            cnt[s[i] - 'a']++;
        }

        ll ans = 0;
        zep(j, 0, 26){
            if(cnt[j] >= 2)ans += 2;
            if(cnt[j] == 1)ans++;
        }

        print(ans / 2)
    }
    
    return 0;
}