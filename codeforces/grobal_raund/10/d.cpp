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
        string s; cin >> s;

        vector<ll> v;
        ll cnt = 0;
        zep(i, 0, n){
            if(i == 0 || s[i] == s[i - 1]){
                cnt++;
            }else{
                v.push_back(cnt);
                cnt = 1;
            }
        }

        if(v.empty()){
            print((n + 2) / 3)
            continue;
        }

        if(s[0] == s[n - 1]){
            v[0] += cnt;
        }else{
            v.push_back(cnt);
        }
        //printa(v, 0, v.size() -1)
        ll ans = 0;
        zep(i, 0, v.size())ans += v[i] / 3;
        print(ans)
    }
    
    return 0;
}