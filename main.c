#include <stdio.h>
#include "list.h"

void option_insert(List* self) {
	int input;
	printf("Enter an int to insert: ");
	scanf_s("%d", &input);
	insert_at_front(self, input);
}

void option_delete(List* self) {
	int input;
	printf("Enter an int to delete: ");
	scanf_s("%d", &input);
	delete_list(self, input);
}

void option_print(List* self) {
	print_list(self);
}

void main()
{
	/*
	// Code for testing the Linked list
	List a = new_list();
	//testing insert_at_front()
	insert_at_front(&a, 3);
	insert_at_front(&a,100);
	insert_at_front(&a,1);
	//print_list to test insert_at_front()
	printf("test insert_at_front()");
	print_list(&a);
	//testing insert_in_order()
	insert_in_order(&a,5);
	insert_in_order(&a,10);
	insert_in_order(&a,7);
	//print_list to test insert_in_order()
	printf("testing insert_in_order()");
	print_list(&a);
	//testing delete_list()
	delete_list(&a,10);
	delete_list(&a,5);
	delete_list(&a,3);
	//print_list to test delete_list()
	printf("testing delete_list()");
	print_list(&a);
	//test destroy_list()
	destroy_list(&a);
	printf("list has been destroyed.");
	*/

	/*
	//testing infastructure
	List my_list = new_list();
	int quit = 0; //tell the program when to stop
	while (!quit)
	{
		int option;
		printf("Enter an int: ");
		scanf_s("%d", &option);
		if (option == 0)
		{
			quit = 1;
		}
		if (option == 1)
		{
			option_insert(&my_list);
		}
		if (option == 2)
		{
			option_delete(&my_list);
		}
		if (option == 3)
		{
			option_print(&my_list);
		}
	}
	destroy_list(&my_list);
	*/
	/*
	//test new reverse and merge
	//create first list
	List first = new_list();
	insert_in_order(&first, 10);
	insert_in_order(&first, 70);
	insert_in_order(&first, 1000);
	printf("List 1: ");
	print_list(&first);
	List second = new_list();
	insert_in_order(&second, 55);
	insert_in_order(&second, 23);
	insert_in_order(&second, 6);
	printf("List 2: ");
	print_list(&second);
	// Merge the lists
	List combined = merge(&first, &second);
	printf("Merged list: ");
	print_list(&combined);
	// Reverse the merged list
	List reversed = reverse(&combined);
	printf("Reversed list: ");
	print_list(&reversed);
	// Free memory
	destroy_list(&first);
	destroy_list(&second);
	destroy_list(&combined);
	destroy_list(&reversed);
	*/

}