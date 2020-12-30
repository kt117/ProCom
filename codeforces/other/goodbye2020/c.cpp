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
        ll n = s.size();

        //if(n == 1){print(0) continue;}

        ll ans = 0;
        zep(i, 1, n){
            if(s[i] == s[i - 1]){
                s[i] = 'Z';
                ans++;
            }else if(i > 1 && s[i] == s[i - 2]){
                s[i] = 'Z';
                ans++;
            }
        }

        print(ans)
    }
    
    return 0;
}