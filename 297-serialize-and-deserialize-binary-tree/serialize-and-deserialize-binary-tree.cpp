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
        string str="";
        if(root==NULL)return str;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* tmp = q.front();  q.pop();
            if(tmp==NULL){
                str += "#,";
            }else{
                str += to_string(tmp->val)+",";
            }

            if(tmp){
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        if(data == "")return root;

        queue<TreeNode*>q;
        int n=data.size();

        int firstData=0;
        int i=0;
        bool isNeg = false;
        while(i<n && data[i]!=','){
            if(data[i]=='-') isNeg = 1;
            else{
                firstData *= 10;
                firstData += data[i]-'0';
            }
            i++;
        }
        i++; //skip ','

        if(isNeg) firstData = -firstData; //handle -ve case

        TreeNode* fst = new TreeNode(firstData);
        root = fst;
        q.push(root);

        while(!q.empty()){
            TreeNode* tmp = q.front(); q.pop();

            //left part
            if(data[i]=='#'){
                tmp->left = NULL;
                i+=2; //skip # and ,
            }else{
                int val=0;
                bool Neg = false;
                while(i<n && data[i]!=','){
                    if(data[i]=='-')Neg = true;
                    else{
                        val *= 10;
                        val += data[i]-'0';
                    }
                    i++;
                }
                i++; //skip ','

                if(Neg) val = -val;
                TreeNode* left = new TreeNode(val);
                tmp->left = left;
                q.push(left);
            }

            //rught part
            if(data[i]=='#'){
                tmp->right = NULL;
                i+=2; //skip # and ,
            }else{
                int val=0;
                bool Neg = false;
                while(i<n && data[i]!=','){
                    if(data[i]=='-')Neg = true;
                    else{
                        val *= 10;
                        val += data[i]-'0';
                    }
                    i++;
                }
                i++; //skip ','

                if(Neg) val = -val;
                TreeNode* right = new TreeNode(val);
                tmp->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));