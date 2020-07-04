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

    ll l = 0;
    while(l < n && s[l] != '[')l++;
    while(l < n && s[l] != ':')l++;
    
    ll r = n - 1;
    while(r >= 0 && s[r] != ']')r--;
    while(r >= 0 && s[r] != ':')r--;

    if(l >= r){
        print(-1)
    }else{
        ll ans = 4;
        rep(i, l + 1, r - 1){
            if(s[i] == '|')ans++;
        }
        print(ans)
    }

    return 0;
}