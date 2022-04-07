#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include "hashtable/hashtable.h"


void TextInput (struct Hashtable* HashT, char *fillename);
char** WordsInput (size_t N);
void End (struct Hashtable *HashT, char *word);
int ScanWord (FILE *textfile, char* temp_str);
//======================================================================


int ScanWord(FILE *textfile, char* temp_str)
{
    int c = fgetc (textfile);
    int i = 0;
    while (c == ' ' || c == '\n' || c == '\t')
        c = fgetc (textfile);

    while (c != ' ' && c != '\n' && c != '\t' && c != EOF)
    {
        temp_str[i] = (char)c;
        i++;
        c = fgetc (textfile);
    }
    temp_str[i] = '\0';
    if (c == EOF)
        return -1;
    return (int)strlen (temp_str);
}   





#define MAX_WORD_LEN 128
void TextInput (struct Hashtable* HashT, char *filename)
{
    int res = 0;
    char *word  = NULL;
    FILE *textfile = fopen (filename, "r");
    for ( ; ; )
    {
        word = calloc (MAX_WORD_LEN, sizeof (char));
        res = ScanWord (textfile, word);
        HashtableInsert (HashT, word);
        if (res == -1)
            break;
    }
    fclose (textfile);
}



void End (struct Hashtable *HashT, char *word)
{
    DeleteHastable (HashT);
    free(word);
}

#define START_HASH_TABLE_SIZE 128
int main (int argc, char **argv)
{
    struct Hashtable* HashT = 0;
    char *word = calloc (MAX_WORD_LEN, sizeof(char));
    
    HashT = HashTableInit (START_HASH_TABLE_SIZE, Hash);
    TextInput (HashT, argv[argc - 1]);

    for ( ; ; )
    {
        printf ("What word are you intrested in? (To close the program use 'q')\n");
        scanf ("%s", word);
        if (strcmp (word, "q") == 0)
            break;
        printf ("The word \"%s\" appeared in the text %d times\n", word, NumOfWord (HashT, word));
    }

    End (HashT, word);
    return 0;
}
#undef START_HASH_TABLE_SIZE
#undef MAX_WORD_LEN
