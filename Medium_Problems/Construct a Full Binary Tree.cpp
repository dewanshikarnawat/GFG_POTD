//Problem: Construct a Full Binary Tree
//Topic: Binary Tree
//Pattern: Medium

/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    unordered_map<int, int> mp;

    Node* solve(vector<int>& pre, vector<int>& preMirror,
                int &preIndex, int l, int h) {

        if (preIndex >= pre.size() || l > h)
            return nullptr;

        Node* root = new Node(pre[preIndex++]);

        if (l == h || preIndex >= pre.size())
            return root;

        int i = mp[pre[preIndex]];

        if (i <= h) {
            root->left = solve(pre, preMirror, preIndex, i, h);
            root->right = solve(pre, preMirror, preIndex, l + 1, i - 1);
        }

        return root;
    }

public:
    Node *constructBinaryTree(vector<int> &pre, vector<int> &preMirror) {
        int n = preMirror.size();

        for (int i = 0; i < n; i++)
            mp[preMirror[i]] = i;

        int preIndex = 0;
        return solve(pre, preMirror, preIndex, 0, n - 1);
    }
};
