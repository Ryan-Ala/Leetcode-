class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string, int> words;
        for (auto& e : positive_feedback)
            words[e] = 3;
        for (auto& e : negative_feedback)
            words[e] = -1;

        vector<vector<int>> ans;


        for (int i = 0; i < report.size(); i++)
        {
            stringstream str;
            string ss;
            str << report[i];
            int num = 0;
            while (str >> ss)
            {
                if (words.count(ss))
                    num += words[ss];
            }
            ans.push_back({ num,student_id[i] });
        }
        sort(ans.begin(), ans.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            else return a[1] < b[1];
            });

        vector<int> ret;
        for (int i = 0; i < k; i++)
        {
            ret.push_back(ans[i][1]);
        }
        return ret;
    }
};