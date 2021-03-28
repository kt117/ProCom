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

string s;

ll f(ll l, ll r, char c){
    if(r - l == 1)return (s[l] == c)? 1 : 0;

    ll m = (l + r) / 2;
    ll suml = 0;
    zep(i, l, m){
        if(s[i] == c)suml++;
    }

    ll sumr = 0;
    zep(i, m, r){
        if(s[i] == c)sumr++;
    }

    return max(suml + f(m, r, c + 1), sumr + f(l, m, c + 1));
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        cin >> s;

        print(n - f(0, n, 'a'))
    }
    
    return 0;
}