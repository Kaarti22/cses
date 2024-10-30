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
    void method(vi &v, int n, int x){
        set<int>s;
        s.insert(0);
        s.insert(x);
        auto lb = s.lower_bound(v[0]);
        auto ub = s.upper_bound(v[0]);
        int ans = max(v[0] - *lb, *ub - v[0]);
        cout<<ans<<" ";
        int left, right;
        if(v[0] - *lb > *ub - v[0]){
            left = 0, right = v[0];
        } else {
            left = v[0], right = x;
        }
        int firstMax = max(v[0] - *lb, *ub - v[0]);
        int secondMax = min(v[0] - *lb, *ub - v[0]);
        rep(i,1,n){
            lb = s.lower_bound(v[i]);
            ub = s.upper_bound(v[i]);
            if(*lb == left && *ub == right){
                int a = v[i] - *lb;
                int b = *ub - v[i];
                int temp = max(a, b);
                ans = max(ans, secondMax);
                cout<<ans<<" ";
            } else {
                
            }
        }
    }
};

int32_t main(){
    int x, n;
    cin>>x>>n;
    vi v(n);
    inpvec(v, n);
    Kaarti *ob = new Kaarti;
    ob->method(v, n, x);
    return 0;
}