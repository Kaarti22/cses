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
    int dfs(int node, vvi& adj, vi& dp, vi& maxChild){
        if(dp[node] != -1) return dp[node];
        int ans = LLONG_MIN;
        for(auto it: adj[node]){
            int newDist = dfs(it, adj, dp, maxChild);
            if(newDist != LLONG_MIN && 1 + newDist > ans){
                ans = newDist + 1;
                maxChild[node] = it;
            }
        }
        return dp[node] = ans;
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
        }
        vi dp(n+1, -1);
        dp[n] = 1;
        vi maxChild(n+1, -1);
        int ans = dfs(1, adj, dp, maxChild);
        if(ans == LLONG_MIN){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        vi path;
        int curr = 1;
        while(curr != -1){
            path.pb(curr);
            if(curr == n) break;
            curr = maxChild[curr];
        }
        if(path.back() != n){
            cout<<"IMPOSSIBLE"<<endl;
            return;
        }
        cout<<path.size()<<endl;
        for(auto it: path){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vvi v(m, vi(2));
    rep(i,0,m) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}