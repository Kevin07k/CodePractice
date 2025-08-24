#include <iostream>
#include <vector>
using namespace std;
string s1,s2;
vector<vector<int> > memo;
int edit_distance(int m, int n){
    if(m==0) return n;
    if(n==0) return m;
    if(memo[m][n]!=-1) return memo[m][n];
    if(s1[m-1]==s2[n-1]){
        return edit_distance(m-1,n-1);
    }
    else{
        int o1=1+edit_distance(m,n-1);
        int o2=1+edit_distance(m-1,n);
        int o3=1+edit_distance(m-1,n-1);
        memo[m][n]=min(o1,min(o2,o3));
        return memo[m][n];
    }
}
int main(){
    cin>>s1;
    cin>>s2;
    vector<int> v(s2.size()+1,-1);
    memo.assign(s1.size()+1,v);
    cout<<edit_distance(s1.size(),s2.size())<<endl;
    return 0;
}