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
    
    string s; cin >> s;
    ll n = s.size();

    ll ans = 0;
    ll cnt[26]; memset(cnt, 0, sizeof(cnt));
    rep(i, 1, n - 2){
        cnt[s[n - i] - 'a']++;

        if(s[n - i - 2] == s[n - i - 1]){
            zep(j, 0, 26){
                if(j != s[n - i - 1] - 'a'){
                    ans += cnt[j];
                    cnt[s[n - i - 1] - 'a'] += cnt[j];
                    cnt[j] = 0;
                }
            }
        }
    }
    print(ans)
    
    return 0;
}