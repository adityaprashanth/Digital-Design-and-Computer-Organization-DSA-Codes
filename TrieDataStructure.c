#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

#define ALPHASIZE 26
#define GETSIZE(a) (sizeof(a)/sizeof(a[0]))
#define GETINDEX(a) ((int)a-(int)'a')

typedef struct TrieNode 
{
	struct TrieNode* alphaArray[ALPHASIZE];
	bool isLastLetter;
}TRIENODE;

TRIENODE* getNode()
{
	TRIENODE* newNode = (TRIENODE*)malloc(sizeof(TRIENODE));

	for (int i = 0; i < ALPHASIZE; i++)
	{
		newNode->alphaArray[i] = NULL;
	}

	newNode->isLastLetter = false;
	return newNode;
}

void insert(TRIENODE* root, const char* key)
{
	TRIENODE* temp = root;
	int length = strlen(key);
	int index;
	for (int i = 0; i < length; i++)
	{
		index = GETINDEX(key[i]);

		if (temp->alphaArray[index] == NULL)
        {
			temp->alphaArray[index] = getNode();
        }

		temp = temp->alphaArray[index];
	}
	temp->isLastLetter = true;

}

bool search(TRIENODE* root, const char* key)
{
	TRIENODE* temp = root;
	int length = strlen(key);
	int index;
	for (int i = 0; i < length; i++)
	{
		index = GETINDEX(key[i]);

		if (temp->alphaArray[index] == NULL)
		{
            return false;
        }

		temp = temp->alphaArray[index];
	}

	return temp->isLastLetter;
}

int main()
{
	TRIENODE* root = getNode();

	char input[][10] = { "the", "a", "there","answer","by", "bye","their" };
	char output[][20] = { "Not Present in Trie","present in Trie" };

	for (int i = 0; i < GETSIZE(input); i++)
	{
		insert(root, input[i]);
	}

	printf("%s-- - %s\n", "the", output[search(root, "the")]);
	printf("%s-- - %s\n", "these", output[search(root, "these")]);
	printf("%s-- - %s\n", "their", output[search(root, "their")]);
	printf("%s-- - %s\n", "thawn", output[search(root, "thawn")]);
}
