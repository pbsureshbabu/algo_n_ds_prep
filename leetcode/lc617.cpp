// Leetcode prob #617 - merge two binary trees


#include <iostream>
#include <queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(t1==NULL)
			return t2;
		if(t2==NULL)
			return t1;
		t1->val+=t2->val;
		t1->left=mergeTrees(t1->left, t2->left);
		t1->right=mergeTrees(t1->right, t2->right);
		return t1;
    }
};

int main()
{
	Solution sol;
	TreeNode *res=NULL;
	TreeNode *t1=NULL;
	TreeNode *t2=NULL;
	
	t1=new TreeNode(1);
	t1->left=new TreeNode(3);
	t1->right=new TreeNode(2);
	t1->left->left = new TreeNode(5);

	t2=new TreeNode(2);
	t2->left=new TreeNode(1);
	t2->right=new TreeNode(3);
	t2->left->right=new TreeNode(4);
	t2->right->right=new TreeNode(7);

	res=sol.mergeTrees(t1, t2);
	queue<TreeNode *> nq;
	if(res!=NULL)
		nq.push(res);
	while(!nq.empty())
	{
		TreeNode *temp = nq.front();nq.pop();
		cout << temp->val << " ";
		if(temp->left)
			nq.push(temp->left);
		if(temp->right)
			nq.push(temp->right);
	}
	cout << endl;
	
	return 0;
}

