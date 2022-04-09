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
    ll x[n], y[n]; zep(i, 0, n)cin >> x[i] >> y[i];
    string s; cin >> s;

    map<ll, ll> mp;
    zep(i, 0, n){
        if(s[i] == 'L'){
            if(mp.find(y[i]) == mp.end())mp[y[i]] = -INF;
            mp[y[i]] = max(mp[y[i]], x[i]);
        }
    }

    zep(i, 0, n){
        if(s[i] == 'R' && mp.find(y[i]) != mp.end() && x[i] < mp[y[i]]){
            print("Yes")
            return 0;
        }
    }
    print("No")
    
    return 0;
}