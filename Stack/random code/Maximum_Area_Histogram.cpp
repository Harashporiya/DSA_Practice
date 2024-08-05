#include<bits/stdc++.h>
using namespace std;
int maximumAreaHistogram1(vector<int> a, int n){
    vector<int> left;
    int psudoValue = -1;
    stack<pair<int,int>> s;
    for(int i=0;i<n;i++){
        if(s.size() == 0){
            left.push_back(psudoValue);
        }else if(s.size()>0 && s.top().first < a[i]){
            left.push_back(s.top().second);
        }
        else if(s.size()>0 && s.top().first >= a[i]){
            while(s.size()>0 && s.top().first >= a[i]){
            s.pop();
            }
             if(s.size()==0){
                left.push_back(psudoValue); 
             }else{
                 left.push_back(s.top().second);
             }
        }
        s.push({a[i],i});
    }


    vector<int> right;
    int psudoValue1 = 7;
    stack<pair<int,int>> s1;
    for(int i=n-1;i>=0;i--){
        if(s1.size() == 0){
            right.push_back(psudoValue1);
        }else if(s1.size()>0 && s1.top().first < a[i]){
            right.push_back(s1.top().second);
        }
        else if(s1.size()>0 && s1.top().first >= a[i]){
            while(s1.size()>0 && s1.top().first >= a[i]){
            s1.pop();
            }
             if(s1.size()==0){
                right.push_back(psudoValue1); 
             }else{
                 right.push_back(s1.top().second);
             }
        }
        s1.push({a[i],i});
    }
    reverse(right.begin(), right.end());
     
      int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = right[i] - left[i] - 1;
        int area = a[i] * width;
        maxArea = max(maxArea, area);
    }

    return maxArea;

    

}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int area = maximumAreaHistogram1(a, n);
    cout<<area;
}