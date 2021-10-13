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

    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        print("Weak")
    }else if((s[0] - '0' + 1) % 10 == (s[1] - '0') % 10 && (s[1] - '0' + 1) % 10 == (s[2] - '0') % 10 && (s[2] - '0' + 1) % 10 == (s[3] - '0') % 10){
        print("Weak")
    }else{
        print("Strong")
    }
    
    return 0;
}