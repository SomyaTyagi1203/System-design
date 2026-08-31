#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;
    long long arr[n];
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    vector<long long>A,B;
    int n1 = n/2, n2 = n-n1;
    for(int mask = 0; mask<(1<<n1); mask++){
        long long sum = 0;
        for(int i=0;i<n1;i++) {
            if(mask&(1<<i)){
                sum+=arr[i];
            }
        }
        A.push_back(sum);
    }
    for(int mask = 0; mask<(1<<n2); mask++){
        long long sum = 0;
        for(int i=0;i<n2;i++) {
            if(mask&(1<<i)){
                sum+=arr[i+n1];
            }
        }
        B.push_back(sum);
    }
    sort(B.begin(),B.end());
    long long ans = 0;
    for(int i=0;i<A.size();i++){
        long long target = x - A[i];
        int lower = lower_bound(B.begin(),B.end(),target)-B.begin();
        int upper = upper_bound(B.begin(),B.end(),target)-B.begin();
        ans+=(upper-lower);
    }
    cout<<ans;
    return 0;
}