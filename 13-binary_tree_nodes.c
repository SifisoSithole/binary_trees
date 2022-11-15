#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: Size of tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size = 0;

	if (tree)
	{
		if (tree->left || tree->right)
			size = 1;
		else
			size = 0;
		size += binary_tree_nodes(tree->left);
		size += binary_tree_nodes(tree->right);
		return (size);
	}
	else
		return (0);
	return (size);
}
