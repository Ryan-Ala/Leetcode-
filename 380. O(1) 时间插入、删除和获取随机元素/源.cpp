class RandomizedSet {
    unordered_map<int, int> Hash;
    vector<int> ret;
public:
    RandomizedSet() {
        srand(time(0));
    }

    bool insert(int val) {
        if (Hash.count(val))
            return 0;
        Hash[val] = ret.size();
        ret.push_back(val);
        return 1;
    }

    bool remove(int val) {
        if (!Hash.count(val))
            return 0;
        int a = Hash[val];
        int b = ret.back();
        ret[a] = b;
        Hash[b] = a;
        ret.pop_back();
        Hash.erase(val);
        return 1;
    }

    int getRandom() {
        return ret[rand() % ret.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */