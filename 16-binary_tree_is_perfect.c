#include "binary_trees.h"

/**
 * binary_tree_is_fulls - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: ...
 */
int binary_tree_is_fulls(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	else if (tree->left && tree->right)
	{
		l = 1 + binary_tree_is_fulls(tree->left);
		r = 1 + binary_tree_is_fulls(tree->right);
		if (l != 0 && r != 0 && r == l)
			return (r);
		return (0);
	}
	else
		return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: ...
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	return ((binary_tree_is_fulls(tree) != 0) ? 1 : 0);
}
