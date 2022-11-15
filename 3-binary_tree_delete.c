#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *c = tree, *temp;

	if (!tree)
		return;

	while (1)
	{
		if (!c->left && !c->right)
		{
			if (c->parent)
			{
				temp = c->parent;
				if (temp->left == c)
					temp->left = NULL;
				else
					temp->right = NULL;
				free(c);
				c = temp;
			}
			else
			{
				free(c);
				return;
			}
		}
		else
		{
			if (c->left)
				c = c->left;
			else
				c = c->right;
		}
	}
}
