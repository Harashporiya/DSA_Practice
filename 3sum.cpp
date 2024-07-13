#include<iostream>
#include<vector>
using namespace std;
vector<int> threeSum(vector<int>& a, int n){
   int sum = 0;
   for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        for(int k=j+1;k<n;k++){
            sum = a[i]+a[j]+a[k];
            if(sum == 0){
      return {i,j,k};
            }
        }
    }
   }
   
}
int main(){
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> sum = threeSum(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    
}