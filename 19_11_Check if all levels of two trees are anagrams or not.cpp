/*

Given two binary trees, the task is to check if each of their levels are anagrams of each other or not. 

Example 1:

Input:

Output: 1
Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 3, 2
Level 2 : 5, 4

Tree 2:
Level 0 : 1
Level 1 : 2, 3
Level 2 : 4, 5

As we can clearly see all the levels of above two binary trees 
are anagrams of each other, hence return true.
Example 2:

Input:

Output: 0
Explanation: 
Tree 1:
Level 0 : 1
Level 1 : 2, 3 
Level 2 : 5, 4 

Tree 2: 
Level 0 : 1 
Level 1 : 2, 4 
Level 2 : 5, 3 

As we can clearly see that level 1 and leve 2 are not anagrams of each other, hence return false.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function areAnagrams() which takes the root of two trees as input and returns an 1 if all the levels are anagrams, else returns 0 as output.
 

Expected Time Complexity: O(NlogN)
Expected Auxiliary Space: O(N)

*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool areAnagrams(Node *root1, Node *root2)
    {
          if (root1 == NULL && root2 == NULL)
            return true;
        if (root1 == NULL || root2 == NULL)
            return false;
        queue<Node*>q1,q2;
        
        // push the root node
        q1.push(root1);
        q2.push(root2);
        
        
        unordered_map<int,int>mp;
        while(q1.size()>0 && q2.size()>0)
        {
            // size represent the size of current level
            int n1=q1.size();
            int n2=q2.size();
            
            if(n1!=n2)
               return false;
            
            while(n1>0)
            {
                auto front1=q1.front();
                q1.pop();
    
                mp[front1->data]++;
    
                // push the children
                if(front1->left!=NULL)
                    q1.push(front1->left);
                if(front1->right!=NULL)
                    q1.push(front1->right);
                n1--;
            }
            while(n2>0)
            {
                auto front2=q2.front();
                q2.pop();
        
                if (mp.find(front2->data) == mp.end())
                  return false;
                
                mp[front2->data]--;
                if(mp[front2->data]==0)
                   mp.erase(front2->data);
    
                // push the children 
                if(front2->left!=NULL)
                    q2.push(front2->left);
                if(front2->right!=NULL)
                    q2.push(front2->right);
                n2--;
            }
             if(mp.size()>0)
               return false;
        }
        if(q1.empty() && q2.empty())
             return true;
        return false;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends