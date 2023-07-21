//LaBerge, Kaleena Ann
//COP-3530-01Z
//Project 10 (Binary Tree- Insertion, Traversal, Search, Delete)
//This program creates a Binary Tree of Circle Objects.
//This compiles and runs successfully with zero errors (in Dev C++).

#include <iostream>

using namespace std;

//'Circle' class represents a circle object. 
//It has a radius and two pointers to its left and right children.
class Circle {
public:
  int radius;
  Circle* left;
  Circle* right;

//Circle class constructor.
  Circle(int radius) {
    this->radius = radius;
    left = NULL;
    right = NULL;
  }
};

// This function adds a new Circle object to the binary tree.
// The new node is added to the left child of the root node if the radius of the new node is less than or equal to the radius of the root node.
// Otherwise, the new node is added to the right child of the root node.
void addCircle(Circle* root, Circle* newCircle) {
  if (root->radius > newCircle->radius) {
    if (root->left == NULL) {
      root->left = newCircle;
    } else {
      addCircle(root->left, newCircle);
    }
  } else {
    if (root->right == NULL) {
      root->right = newCircle;
    } else {
      addCircle(root->right, newCircle);
    }
  }
}

// This function searches for a Circle object in the binary tree.
// The function returns a pointer to the Circle object if it is found.
// Otherwise, the function returns `NULL`.
Circle* searchCircle(Circle* root, int radius) {
  if (root == NULL) {
    return NULL;
  } else if (root->radius == radius) {
    return root;
  } else if (root->radius > radius) {
    return searchCircle(root->left, radius);
  } else {
    return searchCircle(root->right, radius);
  }
}

// Prints the contents of the binary tree in preorder traversal.
void preorderTraversal(Circle* root) {
  if (root != NULL) {
    cout << root->radius << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// Prints the contents of the binary tree in inorder traversal.
void inorderTraversal(Circle* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    cout << root->radius << " ";
    inorderTraversal(root->right);
  }
}

// Prints the contents of the binary tree in postorder traversal.
void postorderTraversal(Circle* root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->radius << " ";
  }
}

// Deletes a Circle object from the Binary Tree.
void deleteCircle(Circle* root, int radius);


int main() {
// Creates a new Circle object with radius 10 and assigns it to the root node.
// Then, radii 5, 15, 20, and 25 are added to Binary Tree, recursively. 
  Circle* root = new Circle(10);
  addCircle(root, new Circle(5));
  addCircle(root, new Circle(15));
  addCircle(root, new Circle(20));
  addCircle(root, new Circle(25));

// The `choice` variable stores the user's choice from the menu.
// The `while` loop continues to run as long as the user does not choose to exit.
  int choice;
  while (true) {
  	
// Prints the menu options to the console.	
    cout << "1. Add Circle Object to Binary Tree" << endl;
    cout << "2. Search for Circle Object in Binary Tree" << endl;
    cout << "3. Display all Binary Tree Circle Objects (preorder traversal)" << endl;
    cout << "4. Display all Binary Tree Circle Objects (inorder traversal)" << endl;
    cout << "5. Display all Binary Tree Circle Objects (postorder traversal)" << endl;
    cout << "6. Delete a Node" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

//To summarize, the next 7 cases execute the user choice from the menu.
    switch (choice) {
      case 1: {
        int radius;
        cout << "Enter the radius of the circle: ";
        cin >> radius;
        Circle* newCircle = new Circle(radius);
        addCircle(root, newCircle);
        break;
      }
      case 2: {
        int radius;
        cout << "Enter the radius of the circle to search: ";
        cin >> radius;
        Circle* foundCircle = searchCircle(root, radius);
        if (foundCircle != NULL) {
          cout << "Found circle with radius " << radius << endl;
        } else {
          cout << "Circle with radius " << radius << " not found" << endl;
        }
        break;
      }
      case 3: {
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
        break;
      }
      case 4: {
        cout << "Inorder traversal: ";
        inorderTraversal(root);
        cout << endl;
        break;
      }
      case 5: {
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
        break;
 	  }
       case 6: {
        int radius;
        cout << "Enter the radius of the circle to delete: ";
        cin >> radius;
        deleteCircle(root, radius);
        break;
      }
      case 7: {
        cout << "Exiting..." << endl;
        return 0;
      }
      default: {
        cout << "Invalid choice" << endl;   
   	  }
	}
  }
}

// Deletes a Circle object from the Binary Tree.
void deleteCircle(Circle* root, int radius) {
  if (root == NULL) {
    return;
  } else if (root->radius == radius) {
    delete root;
  } else if (root->radius > radius) {
    deleteCircle(root->left, radius);
  } else {
    deleteCircle(root->right, radius);
  }
}

//This program executes successfully with zero errors or warnings.
