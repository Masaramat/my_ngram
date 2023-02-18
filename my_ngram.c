#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 20000
// calculates the length of a string
int my_strlen(char *str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;
}
// sorts a string in ascending order
char *my_sort(char *str)
{
    int i, j, length;
    length = my_strlen(str);
    char temp;
    // loops through the string
    for (i = 0; i < length; i++)
    {
        // gets an element in the string and compares it with the next element
        for (j = 0; j < (length - 1); j++)
        {
            // switches elements if it is not sorted
            if (str[j] > str[j + 1])
            {
                temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
    return str;
}
// method to check if an character in the string is counted already
bool isCounted(char c, char *str)
{
    bool counted;
    counted = false;
    if (my_strlen(str) > 0)
    {
        for (int i = 0; i < my_strlen(str); i++)
        {
            if (str[i] == c)
            {
                counted = true;
                break;
            }
        }
    }

    return counted;
}
// method to count and print the frequency of a character
void print_char_frequecy(char *str)
{
    int i, j, count;
    int length = my_strlen(str);
    // keeps characters that are counted in an array counted
    char counted[MAX_BUFFER_SIZE];

    for (i = 0; i < length; i++)
    {
        // checks if a character is not counted
        if (!isCounted(str[i], counted))
        {
            count = 1;
            if (str[i])
            {

                for (j = i + 1; j < length; j++)
                {
                    if (str[i] == str[j])
                    {
                        count++;
                    }
                }

                printf("%c:%d\n", str[i], count);
            }
        }

        // adds the processed character to the counted array
        counted[my_strlen(counted)] = str[i];
    }
}

int main(int numArgs, char *args[])
{
    // variable to store the arguments passed as a string
    char *str = (char *)malloc(sizeof(char *) * MAX_BUFFER_SIZE);
    int index = 0;
    // combines arguments into a single string
    for (int i = 1; i < numArgs; i++)
    {
        for (int j = 0; j < my_strlen(args[i]); j++)
        {
            str[index] = args[i][j];
            index++;
        }
    }
    // sorts the arguments received
    str = my_sort(str);
    print_char_frequecy(str);
    // frees memory used to store the string
    free(str);
    return 0;
}