#include <iostream>
#include <string>
#include <vector>

using namespace std;



void posibleCombination(string s,int si, int len,vector<char> v){
    if(si == len){
        for(auto it : v){
            cout << it << ", ";
        }
        cout << endl;
        return;
    }
    
    v.push_back(s[si]);
    
    posibleCombination(s,si+1,len,v);
    v.pop_back();
    posibleCombination(s,si+1,len,v);
    
}

int main() {
    string arr = "abcd";
    vector<char> v;
    posibleCombination(arr,0,4,v);
    return 0;
}