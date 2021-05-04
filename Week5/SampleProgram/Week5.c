/*****************************************************
 *
 * Author:  CYBV310 Students and Instructor
 *
******************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

///////////////////////////////////////////////////////
//                CONSTANTS
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               typedefs and structures
//////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               globalVariables
///////////////////////////////////////////////////////

///////////////////////////////////////////////////////
//               FunctionPrototypes
///////////////////////////////////////////////////////


///////////////////////////////////////////////////////
//                FunctionPrototypes
///////////////////////////////////////////////////////
void PrintArguments(int argc, char** argv);


/*****************************************************
 *
 *  Function:  main()
 *
 *  Parameters:
 *
 *      argc - main parameter for argument count
 *      argv - main parameter for argument values
 *
******************************************************/
int main(int argc, char** argv)
{
    FILE* pInputFile;
    unsigned char buffer[50];
    int bytesRead;

    /* Verify the arguments */
    if (argc < 2)
    {
        printf("Usage: week5 <filename>\n\n");
        exit(1);
    }

    PrintArguments(argc, argv);

    /* Open the file */
    pInputFile = fopen(argv[1], "r");
    if (pInputFile == NULL)
    {
        printf("\nCould not open file: %s\n", argv[1]);
    }
    else
    {
        bytesRead = (int)fread(buffer, 1, 50, pInputFile);
        if (bytesRead > 1)
        {

            printf("Hex\tDecimal\tASCII\n");
            for (int i = 0; i < bytesRead; ++i)
            {
                printf("0x%02x\t%03d\t%c\n", buffer[i], buffer[i], buffer[i]);
            }
        }
        fclose(pInputFile);
    }

    return 0;
}


/******************************************************************************
 *
 * PrintArguments()
 *
 * Prints the program's arguments.
 *
 *****************************************************************************/
void PrintArguments(int argc, char** argv)
{
    printf("\n");
    for (int i = 0; i < argc; ++i)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
}

/******************************************************************************
 *
 * TrimRight()
 *
 * Removes characters from the end of a string, defaults to whitespace
 * characters is trimChars is null.
 *
 *****************************************************************************/
char* TrimRight(char* str, const char* trimChars)
{
    int i;

    if (trimChars == NULL)
    {
        trimChars = "\t\n\v\f\r ";
    }

    i = (int) strlen(str) - 1;
    while (i >= 0 && strchr(trimChars, str[i]) != NULL)
    {
        str[i] = '\0';
        i--;
    }

    return str;
}
