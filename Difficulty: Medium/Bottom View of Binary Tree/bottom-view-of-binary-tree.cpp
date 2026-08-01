/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        map<int , int>mp;
        queue<pair<Node* , pair<int , int>>> q;
        q.push({root , {0,0}});
        
        while(!q.empty()){
            auto p = q.front();
            Node* tmp = p.first;
            int v = p.second.first;
            int l = p.second.second;
            mp[v] = tmp->data;
            
            if(tmp->left) q.push({tmp->left , {v-1 , l+1}});
            if(tmp->right) q.push({tmp->right , {v+1 , l+1}});
            
            q.pop();
        }
        
        vector<int>ans;
        
        for(auto& it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};