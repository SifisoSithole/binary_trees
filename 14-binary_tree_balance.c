#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor 
 */
int binary_tree_balance(binary_tree_t *tree)
{
	binary_tree_t *c = tree;
	int l = 0, r = 0;

	if (!tree)
		return (0);

	while (c)
	{
		l++;
		c = c->left;
	}

	c = tree;
	while (c)
	{
		r++;
		c = c->right;
	}
	return (l - r);
}

