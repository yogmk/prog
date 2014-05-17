# ident "@(#) Extract UPPERCASE words, or unique words from a file (binary tree version)."

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

# define MWORDS 50


int LIM=100;

typedef struct tnode Treenode;
struct tnode
{
	char* word;
	Treenode *left;
	Treenode *right;
};


int
main (int argc, char** argv)
{
	void uniqwords(FILE*);
	void ucasewords(FILE*);
	FILE* is;

	if (argc < 2)
	{
		puts("usage: ext -U[ppercase] / -u[nique] <input-file>");
		return 0;
	}
	if (argc < 3)
	{
		puts("accepting input from stdin..");
		is = stdin;
	}
	else if ((is = fopen(argv[2], "r")) == NULL)
	{
		perror(argv[2]);
		exit (EXIT_FAILURE);
	}

	
	if (strcmp(argv[1], "-u") == 0)
		uniqwords(is);
	else if (strcmp(argv[1], "-U") ==0)
		ucasewords(is);
	else
		printf("%s: Illegal option.", argv[1]);

		
	close(is);
	return 0;
}


/* getword: get next word from input stream */

int
getword(char* word, FILE* is)
{
	int c;
	char *w=word;

	while(isspace(c=fgetc(is)))
		;
	if (c !=EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		*w = '\0';
		return c;
	}
	for (LIM=100 ; --LIM > 0; w++)
	{
		if (!isalnum(*w=fgetc(is))) 
		{
			ungetc(*w, is);
			break;
		}
	}
	*w = '\0';
	return word[0];
}



void
uniqwords(FILE* is)
{
	int found(char*, Treenode*);
	int getword(char*, FILE*);
	Treenode* addtree(Treenode*, char*);
	void treeprint(Treenode*);
	char word[LIM];		/* biggest word we'll encounter */
	Treenode *root;

	root = NULL;

	while (getword(word, is) != EOF)
		root = addtree(root, word);

	treeprint(root);
}

/* addtree: add a node with w, at orbelow p */

struct tnode *addtree(Treenode* p, char *w)
{
	int cond;
	if (p == NULL)				/* new word here */
	{
		p = malloc (sizeof (Treenode));
		p->word = strdup(w);
		p->left = NULL;
		p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		;
	else if (cond > 0)
		p->right = addtree(p->right, w);
	else
		p->left = addtree(p->left, w);
	
	return p;
}

void
treeprint(Treenode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		treeprint(p->right);
		printf(" %s ", p->word);
		free(p->word);
	}
	free(p);
}
/* ucasewords: scan word as it comes for UPPERCASE */
void
ucasewords(FILE* is)
{
	int i, ucase;
	int getword(char*, FILE*);
	char word[LIM];		/* biggest word we'll encounter */

	while (getword(word, is) != EOF)
	{
		for(i=0, ucase=1; isupper(word[i]); i++)
			;
		if (word[i] != '\0')
			ucase = 0;
		if(ucase)
			puts(word);
	}
}
