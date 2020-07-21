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

char r(char c){
    return (c == '0')? '1' : '0';
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        string a, b; cin >> a >> b;

        vector<ll> ans;
        rrep(i, n - 1, 0){
            if(a[i] != b[i]){
                if(a[0] == b[i]){
                    a[0] = r(a[0]);
                    ans.push_back(0);
                }

                string buf = a.substr(0, i + 1);
                reverse(buf.begin(), buf.end());

                rep(j, 0, i){
                    a[j] = r(buf[j]);
                }

                ans.push_back(i);
            }
        }

        cout << ans.size() << " ";
        zep(i, 0, ans.size())cout << ans[i] + 1 << " "; cout << endl;
    }
    
    return 0;
}