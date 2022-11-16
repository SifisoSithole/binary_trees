#include "binary_trees.h"
#include <stdlib.h>

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
/**
 * isComplete - ..
 * @tree: ...
 * @index: ...
 * @nodes: ...
 *
 * Return: ...
 */
int isComplete(binary_tree_t *tree, int index, int nodes)
{
	if (!tree)
		return (1);

	if (index >= nodes)
		return (0);

	return (isComplete(tree->left, 2 * index + 1, nodes) &&
		isComplete(tree->right, 2 * index + 2, nodes));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: ...
 */
int binary_tree_is_complete(binary_tree_t *tree)
{
	int nodes = binary_tree_size(tree);
	int index = 0;

	return (isComplete(tree, index, nodes));
}
