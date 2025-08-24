#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    vi x(n);
    vi lis;
    for (int i = 0; i < n; ++i) {
        cin>> x[i];
        if(i == 0){
            lis.push_back(x[i]);
        }else{
            if(x[i] > lis.back()){
                lis.push_back(x[i]);
            }else{
                int pos = lower_bound(lis.begin(), lis.end(), x[i])- lis.begin();
                lis[pos] = x[i];
            }
        }
    }
    cout<< lis.size()<<endl;
    return 0;
}