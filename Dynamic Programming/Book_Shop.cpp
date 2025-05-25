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
    void method(vi& h, vi& s, int n, int x){
        vi dp(x+1);
        dp[0] = 0;
        rep(i,1,n+1){
            vi temp(x+1);
            temp[0] = 0;
            rep(j,1,x+1){
                if(h[i-1] <= j){
                    temp[j] = max(dp[j-h[i-1]] + s[i-1], dp[j]);
                } else {
                    temp[j] = dp[j];
                }
            }
            dp = temp;
        }
        cout<<dp[x]<<endl;
    }
};

int32_t main(){
    int n, x;
    cin>>n>>x;
    vi h(n), s(n);
    inpvec(h, n);
    inpvec(s, n);
    Kaarti ob;
    ob.method(h, s, n, x);
    return 0;
}