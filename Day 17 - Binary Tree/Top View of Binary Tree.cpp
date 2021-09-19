#include <iostream>
#include <map>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int key;
    Node *left, *right;
 
    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to perform preorder traversal on the tree and fill the map.
// Here, the node has `dist` horizontal distance from the tree's root,
// and the level represents the node's level.
void printTop(Node* root, int dist, int level, auto &map)
{
    if (root == nullptr) {
        return;
    }
    if (map.find(dist) == map.end() || level < map[dist].second) {
        map[dist] = { root->key, level };
    }
    printTop(root->left, dist - 1, level + 1, map);
    printTop(root->right, dist + 1, level + 1, map);
}
 
// Function to print the top view of a given binary tree
void printTop(Node* root)
{
    map<int, pair<int, int>> map;
    printTop(root, 0, 0, map);
    for (auto it: map) {
        cout << it.second.first << " ";
    }
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    printTop(root);
 
    return 0;
}