#include <stdio.h>
#include <iostream>
#include <list>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;

    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;     
        if (root == nullptr) {
            return "none,";
        }

        res += to_string(root->val) + ",";
        string leftstr = serialize(root->left);
        string rightstr = serialize(root->right);

        return res + leftstr + rightstr;
    }

    TreeNode* redeserialize(list<TreeNode*>& lst) {
        if (lst.size() == 0) {
            return nullptr;
        }

        TreeNode* root = lst.front();
        lst.pop_front();
        if (root == nullptr) return nullptr;

        root->left = redeserialize(lst);
        root->right = redeserialize(lst);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
       int l = 0, r = 0;
       list<TreeNode*> lst;

       for (r = 0; r < data.length(); ++r) {
           if (data[r] == ',') {
                string tmp = data.substr(l, r - l);
                if (tmp == "none") {
                    lst.push_back(nullptr);
                } else {
                    lst.push_back(new TreeNode(stoi(tmp)));
                }
                l = r + 1;
           }
       }

       //cout << data << endl;

       //for (auto l : lst) {
       //    if (l == nullptr) {
       //        cout << "none ";
       //    } else {
       //        cout << l->val << " ";
       //    }
       //}

       TreeNode* root = redeserialize(lst);

       return root;
    }
};

int main (int argc, char ** argv) {
    TreeNode * root = new TreeNode(2);
    TreeNode * left = new TreeNode(1);
    TreeNode * right = new TreeNode(3);
    root->left = left;
    root->right = right;

    Solution sol;
    string treeStr = sol.serialize(root);
    cout << treeStr << endl;
    TreeNode* res = sol.deserialize(treeStr);
    cout << res->val << ", " << res->left->val << ", " << res->right->val << endl;
    return (0);
}
