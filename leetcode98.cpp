#include <stdio.h>
#include <iostream>
#include <stack>
#include <list>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {

    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

    }
};

class Solution {
public:
    //迭代方式进行前序遍历
    void preTravel(TreeNode* root) {
       stack<TreeNode*> st;

       while (!st.empty() || root != nullptr) {
           //将左子树全部入栈
           while (root != nullptr) {
               st.push(root);
               root = root->left;
           }

           //左子树为空之后，将左子树出栈 
           root = st.top();
           st.pop();
           cout << root->val << " ";

           //右子树入栈
           root = root->right;
       }
    }

    int step = 0;
    //迭代方式进行后续遍历
    void afterTravel(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* pre = nullptr;

        while (!st.empty() || root != nullptr) {
            while (root != nullptr) {
                st.push(root);
                cout << "push to stack " << root->val << endl;
                root = root->left;
            }

            //后序遍历等到right节点为空之后，或者左右子树已经被访问过了
            root = st.top();
            if (root->right == nullptr || pre == root->right) {
                st.pop();
                cout << "pop from stack " << root->val << endl;
                pre = root;
                root = nullptr;
            } else {
                root = root->right;
                pre = nullptr;
            }

            if (step++ > 50) {
                return ;
            }
        }

    }

    TreeNode* decodeToTree(list<TreeNode*>& lst) {
        if (lst.empty()) {
            return nullptr;
        }

        TreeNode* root  = lst.front();
        lst.pop_front();
        if (root == nullptr) return nullptr;
        root->left = decodeToTree(lst);
        root->right = decodeToTree(lst);
        return root;
    }
};

int main(int argc, char ** argv) {
    string treeStr("5,1,null,null,4,3,null,null,6,null");
    list<TreeNode*> ls;

    treeStr += ",";
    cout << treeStr << endl;
    int l = 0, r = 0;
    for (r = 0; r < treeStr.length(); ++r) {
        if (treeStr[r] == ',') {
            string tmp = treeStr.substr(l, r - l);
            if (tmp == "null") {
                ls.push_back(nullptr);
            } else {
                ls.push_back(new TreeNode(stoi(tmp)));
            }
            l = r + 1;
        }
    }

    for (auto l : ls) {
        if (l != nullptr) {
            cout << l->val << " ";
        } else {
            cout << "null ";
        }
    }
    cout << endl;

    Solution sol;
    TreeNode* root = sol.decodeToTree(ls);
    cout << "preTravel " << endl;
    sol.preTravel(root);
    cout << endl;
    cout << root->val << ", " << root->left->val << ", " << root->right->val << endl;
    cout << "afterTravel " << endl;
    sol.afterTravel(root);
    return (0);
}
