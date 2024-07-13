#include<iostream>
#include<vector>
using namespace std;
vector<int> sorting(int n1,vector<int>& a1, int n2, vector<int>& a2){
    vector<int> result;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a1[i] == a2[j]){
                result.push_back(a1[i]);
            }
        }
    }   
}
int main(){
    int n1;
    cin>>n1;
    vector<int> a1(n1);
    for(int i=0;i<n1;i++){
        cin>>a1[i];
    }
    int n2;
    cin>>n2;
    vector<int> a2(n2);
    for(int i=0;i<n2;i++){
        cin>>a2[i];
    }

    vector<int> sort = sorting(n1,a1,n2,a2);


}