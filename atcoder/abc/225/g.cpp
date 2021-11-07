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

ll n, cnt[3];
string s, t;

bool ok(ll i){
    string sub = s.substr(i, 3);
    return (sub == "ABC" || sub == "BCA" || sub == "CAB")
}

void step(ll i){
    char tmp = s[i];
    s[i] = s[i + 1];
    s[i + 1] = s[i + 2];
    s[i + 2] = tmp;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    
    cin >> n >> s >> t;
    
    zep(i, 0, n){
        cnt[s[i] - 'A']++;
        cnt[t[i] - 'A']--;
    }

    if(cnt[0] * cnt[1] * cnt[2] != 0){
        print("NO") return 0;
    }

    zep(i, 0, n - 2){
        if(s[i] == t[i])continue;

        ll at = i;
        while(s[at] != t[i])at++;

        // if((i - at % 2) == 1){
        //     if(ok(at - 1)){
        //         step()
        //     }else{
        //         print("NO") return 0;
        //     }
        // }


    }


    
    return 0;
}