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
private:
    int dfs(int node, vvi& adj, vi& dp){
        if(dp[node] != -1) return dp[node];
        int ans = 0;
        for(auto it: adj[node]){
            ans += dfs(it, adj, dp);
        }
        return dp[node] = ans + 1;
    }

public:
    void method(vi& v, int n){
        vvi adj(n+1, vi());
        rep(i,2,n+1){
            adj[v[i-2]].pb(i);
        }
        vi dp(n+1, -1);
        dfs(1, adj, dp);
        rep(i,1,n+1){
            cout<<dp[i]-1<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi v(n-1);
    inpvec(v, n-1);
    Kaarti ob;
    ob.method(v, n);
    return 0;
}