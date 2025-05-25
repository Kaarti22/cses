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
    void method(vector<string>& v, int n){
        vvi dp(n, vi(n));
        int ind = -1;
        rep(i,0,n){
            if(v[i][0] == '.') dp[i][0] = 1;
            else {
                ind = i;
                break;
            }
        }
        if(ind != -1){
            rep(i,ind,n){
                dp[i][0] = 0;
            }
        }
        ind = -1;
        rep(j,0,n){
            if(v[0][j] == '.') dp[0][j] = 1;
            else {
                ind = j;
                break;
            }
        }
        if(ind != -1){
            rep(j,ind,n){
                dp[0][j] = 0;
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                if(v[i][j] == '*') dp[i][j] = 0;
                else dp[i][j] = madd(dp[i-1][j], dp[i][j-1]);
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
};

int32_t main(){
    int n;
    cin>>n;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}