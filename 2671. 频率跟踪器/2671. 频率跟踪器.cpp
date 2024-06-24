class FrequencyTracker {
public:
    unordered_map<int,int> Hash,frequence;
    FrequencyTracker() {

    }
    
    void add(int number) {
        if(Hash.count(number))
        {
            int fre = ++Hash[number];
            frequence[fre]++;
            int old = --frequence[fre-1];
            if(old==0)
            {
                frequence.erase(fre-1);
            }
        }
        else
        {
            frequence[++Hash[number]]++;
        }
    }
    
    void deleteOne(int number) {
        if(Hash.count(number))
        {
            int fre = --Hash[number];
            int old = --frequence[fre+1];
            if(old==0)
            {
                frequence.erase(fre+1);
            }
            if(fre==0)
            {
                Hash.erase(number);
            }
            else
            {
                frequence[fre]++;
            }
        }
    }
    
    bool hasFrequency(int frequency) {
        return frequence.count(frequency);
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */