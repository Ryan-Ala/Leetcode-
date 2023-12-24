class Solution {
public:
    bool canChange(string start, string target) {
        string st, ta;
        for (auto& e : start)
        {
            if (e != '_')
                st.push_back(e);
        }
        for (auto& e : target)
        {
            if (e != '_')
                ta.push_back(e);
        }
        if (st != ta)
            return 0;

        int pos_st = 0, pos_ta = 0;
        while (pos_st < start.length())
        {
            if (start[pos_st] == '_')
            {
                pos_st++;
                continue;
            }

            while (pos_ta < start.size())
            {
                if (target[pos_ta] == '_')
                {
                    pos_ta++;
                    continue;
                }
                break;
            }
            if (start[pos_st] == 'R' && pos_st > pos_ta)
                return 0;
            else if (start[pos_st] == 'L' && pos_st < pos_ta)
                return 0;
            pos_st++;
            pos_ta++;

        }
        return 1;


    }
};