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
    void method(vi &v, int n){
        int sum = accumulate(all(v), 0ll);
        vi dp(sum/2 + 1, 0);
        dp[0] = 1;
        for(auto it: v){
            for(int j=sum/2; j>=it; j--){
                dp[j] = dp[j] || dp[j-it];
            }
        }
        int mini = LLONG_MAX;
        rep(j,0,sum/2+1){
            if(dp[j]){
                int diff = abs(j - (sum - j));
                mini = min(mini, diff);
            }
        }
        cout<<mini<<endl;
    }
};

int32_t main(){
    int n;
    cin>>n;
    vi v(n);
    inpvec(v, n);
    Kaarti *ob = new Kaarti;
    ob->method(v, n);
    return 0;
}