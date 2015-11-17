/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 6
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"

 #define HASH_TBL 500
 #define SIZE 31

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // TODO
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
	//hash function prototype
	int hash_function(char* key);

	// global variable for the head of the list
	node* head = NULL;

	//open dictionary file 
	FILE* dict = fopen(DICTIONARY, "r");
	if(dict == NULL)
	{
		// prompt user for retry
    	printf("File is not supported\n");
    	return 1;
	}

	// struct for linked list
	typedef struct node
	{
		char word[LENGTH +1];
		struct node* next;
	}
	node;

	// declare table of node pointers
	node* hashtable[HASH_TBL] = {NULL};

    //loop thru dictionary until no words - dictionary is single listed words
	while(fscanf(dictionary, %s) == 1)
	{ 
		//make memory for new word
		node* new_node = malloc(sizeof(node));
		if (new_node == NULL)
		{
			printf("File is not supported\n");
			return 2;
		}
		fscanf(dictionary, %s, new_node->word);

		//hash the new node
		index = hash_function(new_node->word);

		node* cursor = head;	

		//if first entry to hashtable
		if(hashtable[index] == NULL)
		{

		hashtable[index] = new_node;

		new_node->next = head;

		head = new_node;
		}

		// keep track of previous and current nodes
		node* curr = head;
		node* prev = NULL;

		// go through list
		while (curr != NULL)
		{

			// dont insert duplicates
			if (new_node->word == curr->word)
			{
				printf("Found duplicate: %s", new_node->word);
				free(new_node);
			}

			// keep looking for correct spot
			else if ()
			{

			}
			
		}
	}


		//run hash function
		int hash_function(char* key)
		{
			// hash on first letter of string
				int hash = toupper(key[0] - 'A');
				return hash % SIZE;
		}

}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
