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
    
    ll t; cin >> t;
    while(t--){
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        vector<ll> v(n); zep(i, 0, n)v[i] = s[i] - 'a';

        zep(i, 0, n){
            if(i > 0 && v[i - 1] > v[i]){
                swap(v[i - 1], v[i]);
            }else if(v[i] != 0){
                if(i < n - 2){
                    ll mn = min((v[i] + k - 1) % k, (v[i] + 1) % k);
                }
            }

            if(i < n - 1){
                if(v[i] != 0){
                    ll mn = min((v[i] + k - 1) % k, (v[i] + 1) % k);

                    if(mn == 0){
                        v[i] = 0;
                    }else{
                        if(v[i + 1] == 0){
                            v[i] = 0;
                            v[i + 1] = mn;
                            i++;
                        }else{
                            ll mnr = min((v[i + 1] + k - 1) % k, (v[i + 1] + 1) % k);
                            if(mnr < mn){
                                v[i + 1] = v[i];
                                v[i] = mnr;
                                i++;
                            }else{
                                v[i] = mn;
                            }
                        }
                    }
                }
            }else{
                v[i] = min(v[i], min((v[i] + k - 1) % k, (v[i] + 1) % k));
            }
        }

        zep(i, 0, n){
            cout << char('a' + v[i]);
        }
        cout << endl;
    }
    
    return 0;
}