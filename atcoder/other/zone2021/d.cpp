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

    bool muki = true;
    deque<char> q;
    
    zep(i, 0, s.size()){
        //print(i)
        if(s[i] == 'R'){
            muki = !muki;
        }else{
            if(q.empty()){
                q.push_back(s[i]);
            }else{
                if(muki){
                    if(s[i] == q.back()){
                        q.pop_back();
                    }else{
                        q.push_back(s[i]);
                    }
                }else{
                    if(s[i] == q.front()){
                        q.pop_front();
                    }else{
                        q.push_front(s[i]);
                    }
                }
            }
        }
    }
    
    if(!muki){
        reverse(q.begin(), q.end());
    }

    zep(i, 0, q.size()){
        cout << q[i];
    }
    cout << endl;
    
    return 0;
}