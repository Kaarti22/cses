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
    void method(vvi& a, int n){
        vector<pair<vi, int>> v(n);
        rep(i,0,n){
            v[i] = {a[i], i};
        }
        sort(all(v), [&](pair<vi, int>& p1, pair<vi, int>& p2){
            return p1.first < p2.first;
        });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vi ans(n);
        int room = 0;
        for(auto it: v){
            if(!pq.empty() && pq.top().first < it.first[0]){
                auto p = pq.top();
                pq.pop();
                ans[it.second] = p.second;
                pq.push({it.first[1], p.second});
            } else {
                room++;
                ans[it.second] = room;
                pq.push({it.first[1], room});
            }
        }
        cout<<room<<endl;
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vvi v(n, vi(2));
    rep(i,0,n){
        cin>>v[i][0]>>v[i][1];
    }
    Kaarti ob;
    ob.method(v, n);
    return 0;
}