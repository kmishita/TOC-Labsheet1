#include<stdio.h>
#include<string.h>
#define charLen 256

/* Function to build the transition table which represents Finite Automata for a given pattern */
void transitionTable(char *pattern, int M, int TF[][charLen]);
/* Function to print the occurences of the pattern in the string */
void patternPrint(char *pat, char *txt);

int main()
{
	char *string="xyzzyxzzyxyzz" ;
	char *pat="xyzz";
	/*printf("Enter the pattern \n");
	scanf("%c",&*pat);
	printf("\nEnter the string \n");
	scanf("%c",&*string);*/
	patternPrint(pat, string);
	getchar();
	return 0;
}

void transitionTable(char *pattern, int M, int TF[][charLen])
{
	int i, j;
	int longestPS=0; 					// always 0 for the first index
	
	for (j =0; j < charLen; j++)
		TF[0][j] = 0;					// Filling the first row with zeros
	TF[0][pattern[0]] = 1;					// exception case where we move to state 1

										
	for (i = 1; i<= M; i++)				// Filling the other rows
	{
		
		for (j = 0; j < charLen; j++)
			TF[i][j] = TF[longestPS][j];

		TF[i][pattern[i]] = i + 1;

		if (i < M)						// Updating longestPS for next row 
		longestPS = TF[longestPS][pattern[i]];
	}
}

void patternPrint(char *pattern, char *str)
{
	int M = strlen(pattern);
	int N = strlen(str);

	int TT[M+1][charLen];

	transitionTable(pattern, M, TT);

	
	int i, j=0;
	for (i = 0; i < N; i++)				// Evaluating string through finite automata to look for patterns
	{
	j = TT[j][str[i]];
	if (j == M)
	{
		printf ("\n pattern found at index %d", i-M+1);
	}
	}
}

