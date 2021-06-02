/*

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

Example 1:

Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,2]
Output: [1,2]

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    -1000 <= Node.val <= 1000






*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    
    string serialize(TreeNode* root) {
        string s="";
        if(root==NULL){
            s+="#|";
            return s;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp==NULL){
                s+="#|";
                continue;
            }
            s+=(to_string(tmp->val)+"|");
            q.push(tmp->left);
            q.push(tmp->right);
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        //stringstream ss("bla bla");
        vector<string> v;
        string s;
        while(getline(ss, s, '|'))
            v.push_back(s);
        if(v[0]=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(v[0]));
        TreeNode* tmp=root;
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            tmp=q.front();
            if(v[i]!="#"){
                tmp->left=new TreeNode(stoi(v[i]));
                q.push(tmp->left);
            }
            i++;
            if(v[i]!="#"){
                tmp->right=new TreeNode(stoi(v[i]));
                q.push(tmp->right);
            }
            i++;
            q.pop();
            
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
