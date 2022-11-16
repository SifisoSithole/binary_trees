#include "binary_trees.h"

/**
 * binary_tree_depths - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depths(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depths(tree->parent) : 0);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: ...
 */
binary_tree_t *binary_trees_ancestor(binary_tree_t *first,
		binary_tree_t *second)
{
	int f_height, s_height;
	binary_tree_t *p1, *p2;

	if (!first || !second)
		return (NULL);
	p1 = first;
	p2 = second;
	if (p1 == p2)
		return (p1);
	f_height = binary_tree_depths(first);
	s_height = binary_tree_depths(second);
	if (f_height > s_height)
	{
		while (p1->parent && f_height != s_height)
		{
			f_height--;
			p1 = p1->parent;
		}
	}
	else if (s_height > f_height)
	{
		while (p2->parent && f_height != s_height)
		{
			s_height--;
			p2 = p2->parent;
		}
	}
	while (p2->parent && p1->parent)
	{
		if (p2 == p1)
			return (p1);
		p2 = p2->parent;
		p1 = p1->parent;
	}
	if (p2 == p1)
		return (p1);
	else
		return (NULL);
}

