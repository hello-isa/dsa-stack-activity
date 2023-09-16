#ifndef STACKLINKEDLIST_H
#define STACKLINKEDLIST_H

// Function definition goes here
typedef enum
{
	F,
	T
} boolean;

typedef struct node
{
	char data;
	struct node *link;
} *LIST;

void initialize(LIST *A);
void display(LIST A);
void push(LIST *A, char newElem);
void pop(LIST *A);
int top(LIST A);
boolean isEmpty(LIST A);
boolean isFull(LIST A);

void initialize(LIST *A)
{
	*A = NULL;
}

void display(LIST A)
{
	LIST temp;
	for (temp = A; temp != NULL; temp = temp->link)
	{
		printf("[%c]->", temp->data);
	}
}

void push(LIST *A, char newElem)
{
	LIST newNode;
	newNode = (LIST)malloc(sizeof(struct node));
	if (newNode == NULL)
	{
		printf("Allocation Failed!");
	}
	else
	{
		if (*A == NULL)
		{
			newNode->data = newElem;
			newNode->link = NULL;
			*A = newNode;
		}
		else
		{
			newNode->data = newElem;
			newNode->link = *A;
			*A = newNode;
		}
	}
}

void pop(LIST *A)
{
	LIST temp;
	temp = *A;
	*A = (*A)->link;
	free(temp);
}

int top(LIST A)
{
	int topVal;
}

boolean isEmpty(LIST A)
{
	return (A == NULL) ? T : F;
}

boolean isFull(LIST A)
{
	LIST newNode = (LIST)malloc(sizeof(struct node));

	// Check if memory allocation is successful
	if (newNode != NULL)
	{
		// Memory was successfully allocated, list not full
		free(newNode); // Deallocate the memory to avoid memory leaks
		return F;
	}
	else
	{
		// Memory allocation failed, list is full
		return T;
	}
}
#endif
