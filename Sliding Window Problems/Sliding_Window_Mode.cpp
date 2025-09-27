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
    void method(vi& v, int n, int k){
        unordered_map<int, int> freq;
        map<int, set<int>> m;
        int i = 0, j = 0;
        while(j < n){
            if(j - i == k){
                int count = freq[v[i]];
                m[count].erase(v[i]);
                if(m[count].size() == 0) m.erase(count);
                count = --freq[v[i]];
                if(count > 0){
                    m[count].insert(v[i]);
                } else {
                    freq.erase(v[i]);
                }
                i++;
            }
            freq[v[j]]++;
            m[freq[v[j]]].insert(v[j]);
            if(freq[v[j]] > 1){
                int prevCount = freq[v[j]] - 1;
                m[prevCount].erase(v[j]);
                if(m[prevCount].size() == 0) m.erase(prevCount);
            }
            j++;
            if(j - i == k){
                auto maxi = m.rbegin();
                cout<<*(maxi->second.begin())<<" ";
            }
        }
        cout<<endl;
    }
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin>>n>>k;
    vi v(n);
    inpvec(v, n);
    Kaarti ob;
    ob.method(v, n, k);
    return 0;
}