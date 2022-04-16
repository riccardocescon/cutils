#include <stdio.h>
#include <stdlib.h>
#include "cutils.h"

void _splitFirstExample();
void _substringExample();

int main(int argc, char const *argv[])
{
    // Uncomment the method in order to run the example
    // _splitFirstExample();
    // _substringExample();
    return 0;
}

void _splitFirstExample(){

    // String with data to split
    char source[] = {"Hello world!\0"};

    int _maxBufferSize = sizeof(source);

    // Buffers to store data 
    char* validData = malloc(_maxBufferSize);
    char* uselessData = malloc(_maxBufferSize);

    // Call split function by passing: 
    // source string, 
    // dest buffers, 
    // buffer sizes, 
    // regex to split, 
    // flag to save or discard the regex value 
    splitFirstNClear(source, validData, _maxBufferSize, uselessData, _maxBufferSize, 'r', true);

    // {splitFirst} will do the same without clearing the dest buffers
    // splitFirst(source, validData, uselessData, 'r', false);

    // Print result
    printf("\n%s", validData);
    printf("\n%s\n", uselessData);

    free(validData);
    free(uselessData);
}

void _substringExample(){

    // String with data to split
    char source[] = {"Hello world!\0"};

    int _maxBufferSize = sizeof(source);
    
    // Buffer to store data 
    char* result = malloc(_maxBufferSize);

    // Call substring function by passing: 
    // source string, 
    // dest buffer, 
    // buffer size, 
    // regex to split, 
    // flag to save or discard the regex value 
    substringNClear(source, result, _maxBufferSize, 'r', true);

    // {substring} will do the same without clearing the dest buffer
    // substring(source, result, 'r', false);

    printf("\n%s\n", result);

    free(result);
}
