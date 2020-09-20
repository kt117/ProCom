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
    
    ll n; cin >> n;

    ll t[n + 1]; memset(t, -1, sizeof(t));

    rep(i, 2, n){
        if(t[i] == -1){
            for(ll j = 2; j * i <= n; j++){
                t[j * i] = i;
            }
        }
    }
    
    ll ans = 0;
    rep(i, 1, n - 1){
        if(i == 1){
            ans++;
        }else if(t[i] == -1){
            ans += 2;
        }else{
            map<ll, ll> mp;
            ll x = i;
            while(t[x] != -1){
                if(mp.find(t[x]) == mp.end()){
                    mp[t[x]] = 0;
                }
                mp[t[x]]++;
                x /= t[x];
            }
            if(mp.find(x) == mp.end()){
                mp[x] = 0;
            }
            mp[x]++;

            ll y = 1;
            for(auto it = mp.begin(); it != mp.end(); it++){
                y *= (*it).second + 1;
            }

            ans += y;
        }
    }
    print(ans)

    return 0;
}