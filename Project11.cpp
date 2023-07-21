//LaBerge, Kaleena Ann
//COP-3530-01Z
//Project 11 (Shortest Branch)
//This program successfully runs with zero errors

#include <iostream>

using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;

//Constructor for BSTNode class takes 'int' parameter,
//sets 'data' member variable to parameter value.
//Sets 'left' and 'right' variables to 'nullptr'.
    BSTNode(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
public:
    BST() {
        root = nullptr;
    }

//'getRoot' method returns 'root' member variable of the 'BST' object.
    BSTNode* getRoot() {
        return root;
    }

//'shortestBranch' method recursively traverses Binary search tree, tracking each node depth.
//Shallowest branch will be one with smallest depth and 'shortestBranch' method
//will return the depth of that branch.
    int shortestBranch(BSTNode* p, int depth) {
        if (p == nullptr) {
        	//If node is null, depth is zero.
            return depth;
        }

//Recursively call the 'shortestBranch' method on the left and right subtrees.
//Minimum of two depths will be depth of shallowest branch.
        int leftDepth = shortestBranch(p->left, depth + 1);
        int rightDepth = shortestBranch(p->right, depth + 1);
        
//Return minimum of two depths.
        if (leftDepth < rightDepth) {
            return leftDepth;
        } else {
            return rightDepth;
        }
    }

public:
    BSTNode* root;
};

int main() {
    BST bst;
    bst.root = new BSTNode(1);
    bst.root->left = new BSTNode(2);
    bst.root->right = new BSTNode(3);
    bst.root->left->left = new BSTNode(4);
    bst.root->left->right = new BSTNode(5);
    bst.root->right->left = new BSTNode(6);
    bst.root->right->right = new BSTNode(7);

    int shallowestDepth = bst.shortestBranch(bst.root, 0);
    cout << "The shallowest branch has depth " << shallowestDepth << endl;

    return 0;
}

//Output is: The shallowest branch has depth 3
