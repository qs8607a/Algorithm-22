/*Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2 5
/ \ \
3 4 6
The flattened tree should look like:
1
\
 2
   \
	 3
	  \
		4
		\
		 5
	      \
			6
Hints:
If you notice carefully in the flattened tree, each node��s right child points to the next node of a pre-order traversal.
*/

class Solution {
public:
	void flatten(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		Flatten(root);
	}
private:
	void Flatten(TreeNode *root)
	{
		if( root != NULL)
		{
			Flatten(root->left);
			Flatten(root->right);

			TreeNode * p = root;
			if( p->left != NULL)
			{
				p = p->left;
				while(p->right) 
					p = p->right;
				p->right = root->right;
				root->right = root->left;
				root->left = NULL;
			}
		}
	}
};