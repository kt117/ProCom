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

    ll y = s[n - 1] - '0';

    if(0 <= y && y <= 2){
        cout << s.substr(0, n - 2) << "-" << endl;
    }else if(3 <= y && y <= 6){
        cout << s.substr(0, n - 2) << endl;
    }else{
        cout << s.substr(0, n - 2) << "+" << endl;
    }
    
    return 0;
}