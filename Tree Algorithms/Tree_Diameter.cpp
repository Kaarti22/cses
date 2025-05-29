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
    int height(int node, int par, vvi& adj, int& diameter){
        vi heights;
        for(auto it: adj[node]){
            if(it == par) continue;
            heights.pb(height(it, node, adj, diameter));
        }
        sort(all(heights));
        int len = heights.size();
        int maxi = 0, secondMaxi = 0;
        if(len > 0){
            maxi = heights[len-1];
        }
        if(len > 1){
            secondMaxi = heights[len-2];
        }
        diameter = max(diameter, maxi + secondMaxi);
        return maxi + 1;
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        int diameter = 0;
        height(1, 0, adj, diameter);
        cout<<diameter<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vvi v(n-1, vi(2));
    rep(i,0,n-1) cin>>v[i][0]>>v[i][1];
    Kaarti ob;
    ob.method(v, n);
    return 0;
}