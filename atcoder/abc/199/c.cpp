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
    ll q; cin >> q;

    bool muki = true;
    while(q--){
        ll t, a, b; cin >> t >> a >> b;
        a--; b--;

        if(t == 1){
            if(!muki){
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);
            }
            char tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
        }else{
            muki = !muki;
        }
    }

    if(muki){
        print(s)
    }else{
        zep(i, 0, n)cout << s[i + n];
        zep(i, 0, n)cout << s[i];
        cout << endl;
    }
    
    return 0;
}