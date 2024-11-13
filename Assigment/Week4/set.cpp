#include<iostream>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
int n;
cin>>n;
int t = n;
vector<int> input;
int tmp;
while(t--){
        cin>>tmp;
        input.push_back(tmp);
}
set<int> group;
for(int tmp : input){
    int t = group.size();
    group.insert(tmp);
    int r = group.size();
    if(t == r){
        cout<<"1\n";
        continue;
    }
    cout<<"0\n";
}
}
