#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(mp.find(val) == mp.end()){
            v.push_back(val);
            mp[val] = v.size()-1;
            return true;
        }
        else return false;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()){
            return false;
        }
        else{
            int idx = mp[val];
            swap(v[idx], v[v.size()-1]);
            v.pop_back();
            mp[v[idx]] = idx;
            mp.erase(val);
            return true;
        }
    }
    
    int getRandom() {
        if(v.size() == 0) return 0;
        int rndm = rand()%v.size();
        return v[rndm];
    }
    private:
        vector<int>v;
        unordered_map<int, int>mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main(){
    
}