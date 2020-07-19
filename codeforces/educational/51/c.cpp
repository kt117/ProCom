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
    ll s[n]; zep(i, 0, n)cin >> s[i];

    ll cnt[108]; memset(cnt, 0, sizeof(cnt));
    zep(i, 0, n)cnt[s[i]]++;

    bool ok = false;
    rep(i, 1, 100){
        if(cnt[i] >= 3)ok = true;
    }

    ll one = 0;
    rep(i, 1, 100){
        if(cnt[i] == 1)one++;
    }

    if(one % 2 == 0)ok = true;

    if(!ok){
        print("NO") return 0;
    }

    print("YES")
    
    bool ans[n];
    
    if(one % 2 == 0){
        bool isA = true;
        zep(i, 0, n){
            if(cnt[s[i]] == 1){
                ans[i] = isA;
                isA = !isA;
            }else{
                ans[i] = true;
            }
        }
    }else{
        bool isA = true;
        bool flag = true;
        zep(i, 0, n){
            if(cnt[s[i]] == 1){
                ans[i] = isA;
                isA = !isA;
            }else{
                if(flag && cnt[s[i]] >= 3){
                    ans[i] = false;
                    flag = false;
                }else{
                    ans[i] = true;
                }
            }
        }
    }

    zep(i, 0, n)cout << ((ans[i])? 'A' : 'B'); cout << endl;

    
    return 0;
}