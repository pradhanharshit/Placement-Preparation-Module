// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    Node *level(Node *root, int target, unordered_map<Node *, Node *> &mp){
        
        queue<Node *> q;
        q.push(root);
        Node *tar;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                Node *curr = q.front();
                q.pop();
                if(curr->data == target){
                    tar = curr;
                }
                if(curr->left != nullptr){
                    mp[curr->left] = curr;
                    q.push(curr->left);
                }
                if(curr->right != NULL){
                    mp[curr->right] = curr;
                    q.push(curr->right);
                }
            }
        }
        return tar;
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<Node *, Node *> mp;
        unordered_map<Node *, bool> visited;
        Node *tar_loc = level(root, target, mp);
        queue<Node *> q;
        q.push(tar_loc);
        visited[tar_loc] = true;
        int ans = 0;
        // cout<<tar_loc->data<<" ";
        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0; i<size; i++){
                Node *curr = q.front();
                q.pop();
                if(curr->left and !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right and !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(mp[curr] and !visited[mp[curr]]){
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                }
            }
        }
        return ans-1;
        
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends