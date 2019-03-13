#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <queue>
using namespace std;

// Given a binary tree, find the leftmost value in the last row of the tree.
// 
// Example 1:
// Input:
// 
//     2
//    / \
//   1   3
// 
// Output:
// 1
// Example 2: 
// Input:
// 
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
// 
// Output:
// 7

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 思路：层序遍历，先把右边的入队列即可，最后一个遍历的元素即为所求
    int findBottomLeftValue(TreeNode* root) {
        std::queue<TreeNode*> node_q;
        node_q.push(root);
        while (node_q.empty() == false) {
            TreeNode* temp_node = node_q.front();
            node_q.pop();
            if (node_q.empty() == true && temp_node->left == NULL && temp_node->right == NULL) {
                // 队列为空，且最后一个节点无子节点
                return temp_node->val;
            }
            if (temp_node->right != NULL) { // 加入右子树
                node_q.push(temp_node->right);
            }
            if (temp_node->left != NULL) { // 加入左子树
                node_q.push(temp_node->left);
            }
        }
    }
};

int main(void) {
    TreeNode *tree1 = new TreeNode(2);
    TreeNode *tree2 = new TreeNode(1);
    Solution sln;
    tree1->left = new TreeNode(1);
    tree1->right = new TreeNode(3);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->left = new TreeNode(4);
    tree2->right->left =new TreeNode(5);
    tree2->right->right = new TreeNode(6);
    tree2->right->left->left = new TreeNode(7);
    
    assert(sln.findBottomLeftValue(tree1) == 1);
    assert(sln.findBottomLeftValue(tree2) == 7);
    return 0;
}