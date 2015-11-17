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

	// make temp node for while loop
	node* temp_node = malloc(sizeof(node));

    //loop thru dictionary until no words - dictionary is single listed words
	while(fscanf(dictionary, %s, temp_node->word) == 1)
	{ 
		//make memory for new word
		node* new_node = malloc(sizeof(node));
		if (new_node == NULL)
		{
			printf("File is not supported\n");
			return 2;
		}
		new_node->word = temp_node->word;

		//hash the new node
		int index = hash_function(new_node->word);

		//if first entry to hashtable
		if(hashtable[index] == NULL)
		{
			hashtable[index] = new_node;
			head = new_node;
		}

		// collision - each subsequent hashtable entry
		new_node->next = head;
		head = new_node;

		
	}

	free(new_node);
	free(temp_node);


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
