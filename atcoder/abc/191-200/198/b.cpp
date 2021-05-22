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
    ll l = 0, r = n - 1;
    while(l < n && s[l] == '0')l++;
    while(r >= 0 && s[r] == '0')r--;

    if(l == n){
        print("Yes") return 0;
    }

    bool ans = true;
    rep(i, 0, r - l){
        if(s[l + i] != s[r - i])ans = false;
    }
    print(ans? "Yes" : "No")
    
    return 0;
}