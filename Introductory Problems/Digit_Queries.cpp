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
    int count(int n){
        int ans = 0;
        for(auto it: v){
            if(it > n) continue;
            int rem = n - it;
            string s = to_string(it);
            int len = s.size() + 1;
            ans += (rem * len);
            n = it;
        }
        return ans + n;
    }

public:
    vi v = {99999999999999999, 9999999999999999, 999999999999999, 99999999999999, 9999999999999, 999999999999, 99999999999, 9999999999, 999999999, 99999999, 9999999, 999999, 99999, 9999, 999, 99, 9};

    void method(int k){
        int low = 1, high = 1e18;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(count(mid) >= k) high = mid - 1;
            else low = mid + 1;
        }
        int rem = k - count(high);
        string s = to_string(low);
        cout<<s[rem-1]<<endl;
    }
};

int32_t main(){
    int testcase;
    cin>>testcase;
    for(int t=0; t<testcase; t++){
        int k;
        cin>>k;
        Kaarti *ob = new Kaarti;
        ob->method(k);
    }
    return 0;
}