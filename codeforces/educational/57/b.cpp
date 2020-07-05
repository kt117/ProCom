#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 998244353;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(int i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s; cin >> s;

    ll l = 1, r = 1;
    while(l < n && s[l] == s[0])l++;
    while(r < n && s[n - 1 - r] == s[n - 1])r++;

    if(l + r < n){
        if(s[0] == s[n - 1]){
            print((l + 1)* (r + 1) % MOD)
        }else{
            print((l + r + 1) % MOD)
        }
    }else if(l + r == n){
        print((n + 1) % MOD)
    }else{
        print(((n + 1) * n / 2) % MOD)
    }
    
    return 0;
}