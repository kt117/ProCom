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
    string s[n]; zep(i, 0, n)cin >> s[i];

    map<string, ll> mp;
    zep(i, 0, n){
        if(mp.find(s[i]) == mp.end())mp[s[i]] = 0;
        mp[s[i]]++;
    }

    ll mx = -INF;
    string ans;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if((*it).second > mx){
            ans = (*it).first;
            mx = (*it).second;
        }
    }
    print(ans)
    
    return 0;
}