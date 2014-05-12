#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next; 
};

struct node *insert_in_end(struct node *start, int x);
struct node *insert_in_beginning(struct node *start, int x);
struct node *delete_in_end(struct node *start);
struct node *delete_in_beginning(struct node *start);
int size_of_link_list(struct node *start);
void search_element(int x);
void output(struct node *start);

int freq[100005] = {0};

int main()
{
	struct node *start;
	start = NULL;
	int ch, x;
	
	printf("1.Insertion in end\n2.Insertion in beginning\n5.Deletion in end\n6.Deletion in beginning\n7.Size of link list\n8.Printing\n9.Search for an element\n>9.Exit\n");
	
	while (1) {
		printf("Enter your choice ---->  ");
		scanf("%d", &ch);
		if (ch == 1) {
			printf("Number to be inserted in end ---->  ");
			scanf("%d", &x);
			start = insert_in_end(start, x);
		} else if (ch == 2) {
			printf("Number to be inserted in beginning ---->  ");
			scanf("%d", &x);
			start = insert_in_beginning(start, x);
		} else if (ch == 5) {
			start = delete_in_end(start);
		} else if (ch == 6) {
			start = delete_in_beginning(start);
		} else if (ch == 7) {
			printf("Size of link list ---->  %d\n", size_of_link_list(start));
		} else if (ch == 8) {
			output(start);
		} else if (ch == 9) {
			printf("Enter the number to be searched ---->  ");
			scanf("%d", &x);
			search_element(x);
		} else {
			break;
		}
	}
	return 0;
}

struct node *insert_in_end(struct node *start, int x)
{
	struct node *ptr, *tmp;
	ptr = start;
	tmp = NULL;
	tmp = (struct node *) malloc (sizeof(struct node));
	freq[x]++;
	
	if (start == NULL) {
		tmp->data = x;
		tmp->next = NULL;
		start = tmp;
 	} else {
 		while (ptr->next != NULL) {
 			ptr = ptr->next;
 		}
 		tmp->data = x;
 		ptr->next = tmp;
 		tmp->next = NULL;
 	}
 	return start;
}

struct node *insert_in_beginning(struct node *start, int x)
{
	struct node *tmp;
	tmp = NULL;
	tmp = (struct node *) malloc (sizeof(struct node));
	freq[x]++;
	
	if (start == NULL) {
		tmp->data = x;
		tmp->next = NULL;
		start = tmp;
	} else  {
		tmp->data = x;
		tmp->next = start;
		start = tmp;
	}
	return start;
}

struct node *delete_in_end(struct node *start)
{
	if (start == NULL) {
		printf("No element in link list.Deletion not possible\n");
		return start;
	}
	
	struct node *ptr, *tmp;
	ptr = start;
	
	if (ptr->next == NULL) {
		freq[ptr->data]--;
		start = NULL;
		return start;
	}
	
	while (ptr->next->next != NULL) {
		ptr = ptr->next;
	}
	tmp = ptr->next;
	freq[tmp->data]--;
	ptr->next = NULL;
	free(tmp);
	
	return start;
}

struct node *delete_in_beginning(struct node *start)
{
	if (start == NULL) {
		printf("No element in link list.Deletion not possible\n");
		return start;
	}
	
	struct node *ptr, *tmp;
	ptr = tmp = start;
	
	ptr = ptr->next;
	freq[tmp->data]--;
	start = ptr;
	
	free(tmp);
	
	return start;
}

int size_of_link_list(struct node *start)
{
	struct node *ptr;
	int cnt = 0;
	ptr = start;
	
	while (ptr != NULL) {
		cnt++;
		ptr = ptr->next;
	}
	return cnt;
}

void search_element(int x)
{
	if (freq[x]) {
		printf("Element present in link list\n");
	} else {
		printf("Element not present in link list\n");
	}
}

void output(struct node *start)
{
	struct node *ptr;
	ptr = start;
	
	while (ptr != NULL) {
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}
