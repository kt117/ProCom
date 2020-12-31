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

ll n, k;
string s;

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    ll q; cin >> q;
    while(q--){
        cin >> n >> k >> s;
        ll z = n - k + 1;

        ll b[n]; memset(b, -1, sizeof(b));
        zep(i, 0, n)if(s[i] == '0')b[i] = i;
        zep(i, 1, n)if(b[i] == -1)b[i] = b[i - 1];

        ll x = z;
        ll y = 0;
        while(x > 0){
            x /= 2;
            y++;
        }
        y = min(y, k);
        
        bool ban[1LL << y]; memset(ban, 0, sizeof(ban));
        zep(i, 0, z){
            if(y == k || b[i + k - 1 - y] < i){
                ll bit = 0;
                zep(j, 0, y){
                    bit += (1LL << j) * (s[i + k - 1 - j] - '0');
                }
                
                ban[((1LL << y) - 1) ^ bit] = true;
            }
        }

        ll ans = -1;
        zep(bit, 0, (1LL << y)){
            if(!ban[bit]){
                ans = bit;
                break;
            }
        }

        if(ans == -1){
            print("NO")
        }else{
            print("YES")
            zep(i, 0, k - y)cout << 0;
            zep(i, 0, y){
                if((1LL << (y - 1 - i)) & ans){
                    cout << 1;
                }else{
                    cout << 0;
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}