#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_heights - Function that measures the height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

int binary_tree_heights(const binary_tree_t *tree)
{
	int l = 0;
	int r = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		l = tree->left ? 1 + binary_tree_heights(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_heights(tree->right) : 1;
		return ((l > r) ? l : r);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l = 0, r = 0;

	if (!tree)
		return (0);

	l = binary_tree_heights(tree->left);
	r = binary_tree_heights(tree->right);
	return (l - r);
}
