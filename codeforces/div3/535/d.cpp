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
    string s; cin >> s;
    vector<ll> v(n);
    zep(i, 0, n){
        if(s[i] == 'R'){
            v[i] = 0;
        }else if(s[i] == 'G'){
            v[i] = 1;
        }else{
            v[i] = 2;
        }
    }

    ll ans = 0;
    zep(i, 1, n){
       if(v[i - 1] == v[i]){
           if(i < n - 1 && v[i - 1] != v[i + 1]){
               v[i] = 3 - v[i - 1] - v[i + 1];
           }else{
               v[i] = (v[i - 1] + 1) % 3;
           }
           ans++;
       } 
    }
    
    string t = "RGB";
    print(ans)
    zep(i, 0, n)cout << t[v[i]]; cout << endl;

    return 0;
}