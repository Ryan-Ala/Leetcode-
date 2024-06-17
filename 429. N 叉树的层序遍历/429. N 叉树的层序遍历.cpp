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
        bool reversed = false, found = false; // һЩ��ʼ��׼��
        while (!head.empty()) {
            unordered_set<string> temp; // ������ת������ string
            for (const auto& w : head) { // �� ����
                string s = w;
                for (size_t i = 0; i < s.size(); ++i) { // ���ݲ����ӽڵ�
                    char c = s[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        s[i] = j;
                        if (tail.count(s)) { // �˳�����
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            found = true;
                        }
                        if (dict.count(s)) { // ������ת�����ӽڵ�
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            temp.insert(s);
                        }
                    }
                    s[i] = c;
                }
            }
            if (found) break; // �˳�
            for (const auto& w : temp) dict.erase(w); // ɾ����ת���� string
            if (temp.size() <= tail.size()) head = temp; // �������Ҳ�ڵ��С���л���������
            else {
                reversed = !reversed;
                head = tail;
                tail = temp;
            }
        }
        if (found) { // ��������˫��BFS�������������ݽṹ���������ͬ��ת����
            vector<string> path = { beginWord };
            backtracking(beginWord, endWord, next, path, res); // �����㷨��Ӧ��
        }
        return res;
    }

private:
    void backtracking(const string& src, const string& dst, unordered_map<string, vector<string>>& next,
        vector<string>& path, vector<vector<string>>& res) {
        if (src == dst) res.push_back(path);
        for (const auto& w : next[src]) { // �� �� Ϊ��λ������ͬ��ת����
            path.push_back(w);
            backtracking(w, dst, next, path, res);
            path.pop_back();
        }
    }
};