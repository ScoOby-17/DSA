/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        
         //  v         l    data
        map<int , map<int , int>> nodes;
        queue<pair<Node* , pair<int , int>>> q;  // in pair stor  v and l
        q.push({ root , {0,0} });
        
        while(!q.empty()){
            auto p = q.front();
            Node* tmp = p.first;
            int v = p.second.first;   // v mean vertical index
            int l = p.second.second;  // l mean level
            
            if(nodes[v].empty()){
                nodes[v][l] = tmp->data;
            }
            
            if(tmp->left) q.push({tmp->left , {v-1 , l+1}});
            if(tmp->right) q.push({tmp->right , {v+1 , l+1}});
            
            
            q.pop();
        }
        
        vector<int>ans;
        
        for(auto& it : nodes){
            auto mp = it.second;
            for(auto& m : mp){
                ans.push_back(m.second);
                break;
            }
        }
        
        return ans;
    }
};