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

ll f(char c){
    return c - '0';
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    string s, t; cin >> s >> t;
    ll h1 = f(s[0])* 10 + f(s[1]);
    ll m1 = f(s[3])* 10 + f(s[4]);
    ll h2 = f(t[0])* 10 + f(t[1]);
    ll m2 = f(t[3])* 10 + f(t[4]);
    
    m1 += h1 * 60;
    m2 += h2 * 60;
    ll m3 = (m1 + m2) / 2;

    cout << setfill('0') << std::right << std::setw(2) << to_string(m3 / 60) << ":" << setfill('0') << std::right << std::setw(2) << to_string(m3 % 60) << endl;

    return 0;
}