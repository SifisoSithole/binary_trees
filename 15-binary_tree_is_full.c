#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: ...
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int l, r;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	else if (tree->left && tree->right)
	{
		l = binary_tree_is_full(tree->left);
		r = binary_tree_is_full(tree->right);
		if (!l || !r)
			return (0);
		return (1);
	}
	else
		return (0);
}
