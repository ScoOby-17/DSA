/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //vertical   //level      //values 
        map<int , map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int,int>>> q; //pair stores vertical , level

        q.push({root , {0 , 0}});

        //level Order traversal
        while(!q.empty()){
            auto p = q.front();
            int v = p.second.first , l = p.second.second;
            TreeNode* tmp = p.first;
            nodes[v][l].insert(tmp->val);

            if(tmp->left)q.push({tmp->left , {v-1 , l+1}});
            if(tmp->right) q.push({tmp->right , {v+1 , l+1}});

            q.pop();
        }


        vector<vector<int>>ans;

        for(auto& it : nodes){
            vector<int>col;
            auto mp = it.second;
            for(auto& m : mp){
                col.insert(col.end() , m.second.begin(), m.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};