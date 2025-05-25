#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define MOD 1000000007
#define pb push_back
#define popb pop_back
#define rep(i,a,b) for(int i=a; i<b; i++)
#define all(v) v.begin(),v.end()

void inparr(int arr[], int n){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void disarr(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void inpvec(vi &v, int n){
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
}

void disvec(vi v, int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;
}

int madd(int a,int b) {
    return (a+b)%MOD;
}

int msub(int a,int b){
    return (((a-b)%MOD)+MOD)%MOD;
}

int mmul(int a,int b){
    return ((a%MOD)*(b%MOD))%MOD;
}

class Kaarti{
public:
    void method(vi &v, int n, int m){
        vvi dp(n+1, vi(m+1));
        rep(j,1,m+1){
            if(v[0] == j || v[0] == 0){
                dp[1][j] = 1;
            }
        }
        rep(i,2,n+1){
            rep(k,1,m+1){
                if(v[i-1] != 0 && v[i-1] != k){
                    dp[i][k] = 0;
                    continue;
                }
                rep(prev,k-1,k+2){
                    if(prev < 1 || prev > m) continue;
                    dp[i][k] = madd(dp[i][k], dp[i-1][prev]);
                }
            }
        }
        int ans = 0;
        rep(j,1,m+1){
            ans = madd(ans, dp[n][j]);
        }
        cout<<ans<<endl;
    }
};

int32_t main(){
    int n, m;
    cin>>n>>m;
    vi v(n);
    inpvec(v, n);
    Kaarti ob;
    ob.method(v, n, m);
    return 0;
}