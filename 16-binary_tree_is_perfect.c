#include "binary_trees.h"

/**
 * find_depth - Finds the depth of the leftmost node.
 * @tree: Pointer to the root node.
 * Return: The depth.
 */
int find_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}

/**
 * is_perf - Checks if the tree is perfect recursively.
 * @tree: Pointer to node to check.
 * @d: Depth of the tree.
 * @level: Current level.
 * Return: 1 if perfect, 0 otherwise.
 */
int is_perf(const binary_tree_t *tree, int d, int level)
{
	if (!tree->left && !tree->right)
		return (d == level + 1);
	if (!tree->left || !tree->right)
		return (0);
	return (is_perf(tree->left, d, level + 1) &&
		is_perf(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);
	d = find_depth(tree);
	return (is_perf(tree, d, 0));
}
