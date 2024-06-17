/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

//class Solution {
//public:
//    vector<vector<int>> levelOrder(Node* root) {
//        vector<vector<int>> ans;
//        if(!root)
//        return ans;
//
//        queue<Node*> q;
//        q.push(root);
//
//        while(q.size())
//        {
//            int sz = q.size();
//            vector<int> ret;
//            while(sz--)
//            {
//                Node* tmp = q.front();
//                q.pop();
//                ret.push_back(tmp->val);
//                for(auto e:tmp->children)
//                q.push(e);
//
//            }
//            ans.push_back(ret);
//        }
//        return ans;
//    }
//};

#include<iostream>
#include<deque>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end()), head{ beginWord }, tail{ endWord };
        if (!dict.count(endWord)) return res;
        dict.erase(beginWord), dict.erase(endWord);
        unordered_map<string, vector<string>> next;
        bool reversed = false, found = false; // 一些初始化准备
        while (!head.empty()) {
            unordered_set<string> temp; // 保存已转化过的 string
            for (const auto& w : head) { // 层 遍历
                string s = w;
                for (size_t i = 0; i < s.size(); ++i) { // 回溯查找子节点
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if (tail.count(s)) { // 退出条件
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s)) { // 保存已转换的子节点
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            temp.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            if (found) break; // 退出
            for (const auto& w : temp) dict.erase(w); // 删除已转换的 string
            if (temp.size() <= tail.size()) head = temp; // 根据左右层节点大小来切换遍历方向
            else {
                reversed = !reversed;
                head = tail;
                tail = temp;
            }
        }
        if (found) { // 根据上面双向BFS构建的树型数据结构来梳理出不同的转换序
            vector<string> path = { beginWord };
            backtracking(beginWord, endWord, next, path, res); // 回溯算法的应用
        }
        return res;
    }

private:
    void backtracking(const string& src, const string& dst, unordered_map<string, vector<string>>& next,
        vector<string>& path, vector<vector<string>>& res) {
        if (src == dst) res.push_back(path);
        for (const auto& w : next[src]) { // 按 层 为单位回溯求不同的转换序
            path.push_back(w);
            backtracking(w, dst, next, path, res);
            path.pop_back();
        }
    }
};