#include "binary_trees.h"

/**
 * _height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the tree.
 */
size_t _height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = _height(tree->left);
	right_h = _height(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
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

	return ((int)_height(tree->left) - (int)_height(tree->right));
}
