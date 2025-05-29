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
    void outDfs(vvi& adj, int node, int par, vi& in, vi& out){
        int maxi = -1, secondMaxi = -1;
        for(auto it: adj[node]){
            if(it == par) continue;
            if(in[it] > maxi){
                secondMaxi = maxi;
                maxi = in[it];
            } else if(in[it] > secondMaxi){
                secondMaxi = in[it];
            }
        }
        for(auto it: adj[node]){
            if(it == par) continue;
            int longest = maxi;
            if(maxi == in[it]){
                longest = secondMaxi;
            }
            out[it] = 1 + max(out[node], 1 + longest);
            outDfs(adj, it, node, in, out);
        }
    }

    void inDfs(vvi& adj, int node, int par, vi& in){
        for(auto it: adj[node]){
            if(it == par) continue;
            inDfs(adj, it, node, in);
            in[node] = max(in[node], 1 + in[it]);
        }
    }

public:
    void method(vvi& v, int n){
        vvi adj(n+1, vi());
        for(auto it: v){
            adj[it[0]].pb(it[1]);
            adj[it[1]].pb(it[0]);
        }
        vi in(n+1, 0), out(n+1, 0);
        inDfs(adj, 1, 0, in);
        outDfs(adj, 1, 0, in, out);
        rep(i,1,n+1){
            cout<<max(in[i], out[i])<<" ";
        }
        cout<<endl;
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