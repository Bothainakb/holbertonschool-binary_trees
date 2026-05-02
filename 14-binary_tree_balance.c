#include "binary_trees.h"

/**
 * bt_height - Measures height of a binary tree for balance factor.
 * @tree: Pointer to the root node.
 * Return: Height of the tree.
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (!tree)
		return (0);
	l = bt_height(tree->left);
	r = bt_height(tree->right);
	return ((l > r ? l : r) + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure.
 *
 * Return: The balance factor, or 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return ((int)bt_height(tree->left) - (int)bt_height(tree->right));
}
