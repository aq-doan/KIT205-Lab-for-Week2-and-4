#include <stdio.h>
#include <stdlib.h>
#include "list.h"


// Function to create and return a new empty list.
List new_list() {
	List temp;
	temp.head = NULL;
	return temp;
}

// Function to print the contents of a list.
void print_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		printf("%d", current->data);
		current = current->next;

		if (current != NULL)
			printf(", ");
	}
	printf("\n");
}

// Function to insert a new node with given data at the front of the list.
void insert_at_front(List* self, int data) {
	ListNodePtr new_node = malloc(sizeof * new_node);

	new_node->data = data;
	new_node->next = self->head;
	self->head = new_node;
}

// Function to insert a new node with given data in the list in ascending order.
void insert_in_order(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	ListNodePtr new_node = malloc(sizeof * new_node);
	new_node->data = data;
	new_node->next = NULL;

	while (current != NULL && current->data < data) {
		prev = current;
		current = current->next;
	}

	if (current == self->head) { // at front
		new_node->next = current;
		self->head = new_node;
	}
	else {                     // middle
		new_node->next = current;
		prev->next = new_node;
	}
}

// Function to delete the first occurrence of a node with given data from the list.
void delete_list(List* self, int data) {
	ListNodePtr current = self->head;
	ListNodePtr prev = NULL;

	while (current != NULL) {
		if (current->data == data) {
			if (prev == NULL) {        // front of list
				self->head = current->next;
				free(current);
				current = self->head;
			}
			else {                    // middle of list
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		}
		else {
			prev = current;
			current = current->next;
		}
	}
}

// Function to free the memory allocated to a list and all its nodes.
void destroy_list(List* self) {
	ListNodePtr current = self->head;
	while (current != NULL) {
		ListNodePtr to_free = current;
		current = current->next;
		free(to_free);
	}
	self->head = NULL;
}

//Function to reverse a list
List reverse(List* self) {
	List reversed = new_list();

	//reverse using inseart_at_front
	for (ListNodePtr cNode = self->head; cNode != NULL; cNode = cNode->next) {
		insert_at_front(&reversed, cNode->data);
	}
	return reversed;
}

//Function to merge 2 ordered lists
List merge(List* first, List* second) {
	//creating variable for both lists and a list to combine
	List list = new_list();
	ListNodePtr current_first = first->head;
	ListNodePtr current_second = second->head;

	while (current_first != NULL && current_second != NULL) {
		if (current_first->data <= current_second->data) {
			insert_in_order(&list, current_first->data);
			current_first = current_first->next;
		}
		else {
			insert_in_order(&list, current_second->data);
			current_second = current_second->next;
		}
	}

	for (; current_first != NULL; current_first = current_first->next) {
		insert_in_order(&list, current_first->data);
	}

	for (; current_second != NULL; current_second = current_second->next) {
		insert_in_order(&list, current_second->data);
	}

	return list;
}