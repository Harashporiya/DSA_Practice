// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<set>
// using namespace std;
// vector<vector<int>> threeSum(vector<int>& a, int n){
//    int sum = 0;
//    set<vector<int>> result;
//    for(int i=0;i<n-2;i++){
//     for(int j=i+1;j<n-1;j++){
//         for(int k=j+1;k<n;k++){
//             sum = a[i]+a[j]+a[k];
//             if(sum == 0){
//             vector<int> ans = {a[i],a[j],a[k]};
//             sort(ans.begin(),ans.end());
//             result.insert(ans);
//             }
//         }
//     }
//    }
//      vector<vector<int>> res(result.begin(), result.end());
//    return res;
   
// }
// int main(){
//     int n;
//     cin>>n;

//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }

//     vector<vector<int>> sum = threeSum(a,n);

//    for (const auto& triplet : sum) {
//         cout << "[" << triplet[0] << "," << triplet[1] << "," << triplet[2] << "]" << endl;
//     }
    
// }

#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> sum(vector<int>& a, int n){
    vector<vector<int>> result;
    for(int i=0;i<n;i++){
      int j=i+1;
      int k=n-1;
      int sum =0; 
      while(j<k){
        sum = a[i]+a[j]+a[k];
        if(sum == 0){
             result.push_back({a[i],a[j],a[k]});
        }else if(sum<0){
            j++;
        }else{
            k--;
        }
      }
    }

    return result;

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

  vector<vector<int>> ans = sum(a,n);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }

}