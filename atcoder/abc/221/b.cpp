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
    
    string s, t; cin >> s >> t;
    if(s == t){
        print("Yes") return 0;
    }
    
    ll count = 0;
    zep(i, 1, s.size()){
        zep(j, 0, s.size()){
            char tmp = s[i];
            s[i] = s[i - 1];
            s[i - 1] = tmp;

            if(s == t){
                print("Yes") return 0;
            }

            s[i - 1] = s[i];
            s[i] = tmp;
        }
    }
    print("No")

    return 0;
}