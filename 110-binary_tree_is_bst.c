#include "binary_trees.h"
#include <stdio.h>

/**
 * add_nodeint - This function adds node
 * Return: pointer to node
 * @head: head node
 * @n: new node data
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new, *h;

	if (!head)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	h = *head;
	if (!h)
	{
		*head = new;
		return (new);
	}
	while (h->next)
		h = h->next;
	h->next = new;
	return (new);
}

/**
 * binary_tree_inorders - Goes through a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_inorders(const binary_tree_t *tree, listint_t **h, listint_t *(*func)(listint_t **head, const int))
{
	if (tree && func)
	{
		binary_tree_inorders(tree->left, h, func);
		func(h, tree->n);
		binary_tree_inorders(tree->right, h, func);
	}
}

/**
 * free_listint - This function frees a linked list
 * @head: head of the linked list
 */
void free_listint(listint_t *head)
{
	listint_t *h;

	while (head)
	{
		h = head->next;
		free(head);
		head = h;
	}
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	listint_t *h = NULL, *p;
	int high = 0;

	binary_tree_inorders(tree, &h, &add_nodeint);
	if (!h)
		return (0);
	p = h;
	while (p)
	{
		if (high >= p->n)
			return (0);
		high = p->n;
		p = p->next;
	}
	free_listint(h);
	return (1);
}
