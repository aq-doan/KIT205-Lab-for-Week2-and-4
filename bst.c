#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

// create an empty bst
BST new_bst() {
	BST temp;
	temp.root = NULL;
	return temp;
}

// recursive function to find a value and return the containing node
BSTNodePtr find_bst_node(BSTNodePtr self, int n) {
	if (self != NULL || (n == self->data_item)) { /* not present, or here */
		return self;
	}
	else if (n < self->data_item) {
		return find_bst_node(self->left, n);
	}
	else {
		return find_bst_node(self->right, n);
	}
}

// find a value in the tree and return the node
BSTNodePtr find_bst(BST* self, int n) {
	return find_bst_node(self->root, n);
}

// recursive function to insert a value
BSTNodePtr insert_bst_node(BSTNodePtr self, int n) {
	if (self == NULL) { /* found where to put it*/
		self = malloc(sizeof * self);
		self->data_item = n;
		self->left = self->right = NULL;
	}
	else if (n < self->data_item) {
		self->left = insert_bst_node(self->left, n);
	}
	else if (n > self->data_item) {
		self->right = insert_bst_node(self->right, n);
	}
	return self;
}

// insert a value into the tree
void insert_bst(BST* self, int n) {
	self->root = insert_bst_node(self->root, n);
}

// helper function for delete
BSTNodePtr min_node(BSTNodePtr self) {
	BSTNodePtr current = self;
	while (current->left != NULL) {
		current = current->left;
	}
	return current;
}

// recursive function to delete a value
BSTNodePtr delete_bst_node(BSTNodePtr self, int n) {
	if (self != NULL) {
		if (n == self->data_item) { // found item 
			if (self->left != NULL && self->right != NULL) {
				// two child case 
				BSTNodePtr successor = min_node(self->right);
				self->data_item = successor->data_item;
				self->right = delete_bst_node(self->right, self->data_item);
			}
			else { // one or zero child case 
				BSTNodePtr to_free = self;
				if (self->left) {
					self = self->left;
				}
				else {
					self = self->right;
				}
				free(to_free);
			}
		}
		else if (n < self->data_item) {
			self->left = delete_bst_node(self->left, n);
		}
		else {
			self->right = delete_bst_node(self->right, n);
		}
	}
	return self;
}

// delete a value from the tree
void delete_bst(BST* self, int n) {
	self->root = delete_bst_node(self->root, n);
}

// recursive function to print in order
void print_in_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		print_in_order_bst_node(self->left);
		printf(" %d ", self->data_item);
		print_in_order_bst_node(self->right);
		printf(")");
	}
}

// print the tree in order
void print_in_order_bst(BST* self) {
	print_in_order_bst_node(self->root);
}

//recursive function to print preorder
void print_pre_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		printf(" %d ", self->data_item);
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
		printf(")");
	}
}

//print the tree pre order
void print_pre_order_bst(BST* self) {
	print_pre_order_bst_node(self->root);
}

//recursive function to print the tree post order
void print_post_order_bst_node(BSTNodePtr self) {
	if (self == NULL) {
		printf("_");
	}
	else {
		printf("(");
		print_pre_order_bst_node(self->left);
		print_pre_order_bst_node(self->right);
		printf(" %d ", self->data_item);
		printf(")");
	}
}
//print the tree post order
void print_post_order_bst(BST* self) {
	print_post_order_bst_node(self->root);
}

//recursive function to calculate the bst height and return it as an integer (private)
int height_bst_node(BSTNodePtr self) {
	int height = 0;
	if (self == NULL) { //the terminating case
		height = 0;
	}
	else {
		height = 1 + (height_bst_node(self->left) > height_bst_node(self->right) ? height_bst_node(self->left) : height_bst_node(self->right));
	}
	return height;
}

//Public function of height 
int height_bst(BST* self) {
	return height_bst_node(self->root);
}

// recursive function to destroy all node
void destroy_bst_node(BSTNodePtr self) {
	if (self != NULL) {
		destroy_bst_node(self->left);
		self->left = NULL;
		destroy_bst_node(self->right);
		self->right = NULL;
		free(self);
	}
}

// destroy the tree
void destroy_bst(BST* self) {
	destroy_bst_node(self->root);
	self->root = NULL;
}

void bst_test() {
	BST tree = new_bst();
	int quit = 0;
	int data;
	while (quit == 0) {
		printf("Enter some data: ");
		scanf_s("%d", &data);
		if (data != 0) {
			insert_bst(&tree, data);
		}
		else {
			quit = 1;
		}
	}
	//test in-order
	printf("Test in-order:\n");
	print_in_order_bst(&tree);
	printf("\n");

	//test pre-order
	printf("Test pre-order:\n");
	print_pre_order_bst(&tree);
	printf("\n");

	//test post-order
	printf("Test post-order:\n");
	print_post_order_bst(&tree);
	printf("\n");

	//test height()
	printf("Test height:\n");
	printf("%d",height_bst(&tree));
	printf("\n");
}