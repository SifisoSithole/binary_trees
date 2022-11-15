#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: ...
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
	{
		if (node->parent->right)
			return (node->parent->right);
		else
			return (NULL);
	}
	else
	{
		if (node->parent->left)
			return (node->parent->left);
		else
			return (NULL);
	}
}
