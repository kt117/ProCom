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

        vector<ll> v;
        ll cnt = 0;
        zep(i, 0, s.size()){
            if(s[i] == '1'){
                cnt++;
            }else{
                if(cnt > 0){
                    v.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        if(cnt > 0)v.push_back(cnt);

        sort(v.begin(), v.end(), greater<>());

        ll ans = 0;
        zep(i, 0, v.size()){
            if(i % 2 == 0)ans += v[i];
        }
        print(ans)
    }
    
    return 0;
}