#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: Size of tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 0, l = 0, r = 0;

	if (tree)
	{
		l = size + binary_tree_size(tree->left);
		r = size + binary_tree_size(tree->right);
		size = r + l + 1;
	}
	else
		return (0);
	return (size);
}
