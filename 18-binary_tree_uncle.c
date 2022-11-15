#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the sibling of a node
 * @node: pointer to the node to find the sibling
 *
 * Return: ...
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent == node->parent->parent->left)
	{
		if (node->parent->parent->right)
			return (node->parent->parent->right);
		else
			return (NULL);
	}
	else
	{
		if (node->parent->parent->left)
			return (node->parent->parent->left);
		else
			return (NULL);
	}
}
