#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: Size of tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t size = 0, l = 0, r = 0;

	if (tree)
	{
		l = binary_tree_leaves(tree->left);
		r = binary_tree_leaves(tree->right);
		size = l + r;
		return ((!l && !r) ? size + 1 : size + 0);
	}
	else
		return (0);
	return (size);
}
