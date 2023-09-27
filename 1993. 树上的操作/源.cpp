class LockingTree {
    vector<int>parent;
    vector<int>lockNodeUser;
    vector<vector<int>> child;
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->lockNodeUser = vector<int>(n, -1);  //n号节点被 -1 号用户上锁
        this->child = vector<vector<int>>(n);
        for (int i = 1; i < n; i++)
        {
            child[parent[i]].emplace_back(i);
        }

    }

    bool lock(int num, int user) {
        if (lockNodeUser[num] == -1)
        {
            lockNodeUser[num] = user;
            return 1;
        }
        return 0;
    }

    bool unlock(int num, int user) {
        if (lockNodeUser[num] == user)
        {
            lockNodeUser[num] = -1;
            return 1;
        }
        return 0;

    }

    bool upgrade(int num, int user) {
        if (lockNodeUser[num] == -1 && check_ansert(num) && check_child(num))
        {
            lockNodeUser[num] = user;
            return 1;
        }
        return 0;

    }


    bool check_ansert(int num)
    {
        num = parent[num];
        while (num != -1)
        {
            if (lockNodeUser[num] != -1)
                return 0;
            num = parent[num];
        }
        return 1;
    }


    bool check_child(int num)
    {

        bool tmp = lockNodeUser[num] != -1;
        lockNodeUser[num] = -1;
        for (auto& e : child[num])
        {
            tmp |= check_child(e);
        }
        return tmp;
    }
};
