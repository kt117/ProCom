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

    ll cnt[8]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, s.size()){
        ll x = s[i] - '0';
        cnt[x % 8]++;
    }

    bool ans = false;
    if(s.size() == 1){
        if(cnt[0] > 0)ans = true;
    }else if(s.size() == 2){
        zep(i, 0, 8){
            zep(j, 0, 8){
                cnt[i]--; cnt[j]--;
                if((10 * i + j) % 8 == 0 && cnt[i] >= 0 && cnt[j] >= 0)ans = true;
                cnt[i]++; cnt[j]++;
            }
        }
    }else{
        zep(i, 0, 8){
            zep(j, 0, 8){
                zep(k, 0, 8){
                    cnt[i]--; cnt[j]--; cnt[k]--;
                    if((100 * i + 10 * j + k) % 8 == 0 && cnt[i] >= 0 && cnt[j] >= 0 && cnt[k] >= 0)ans = true;
                    cnt[i]++; cnt[j]++; cnt[k]++;
                }
            }
        }
    }

    print(ans? "Yes" : "No")
    
    return 0;
}