#include <string.h>
#include "cutils.h"

/**
 * @brief Get the Pointer Data Length size
 * 
 * @param source Buffer to search on
 * @return int Last data position
 */
int getPointerDataLen(char* source){
    for(int i = 0; true; i++){
        if(source[i] == '\0') return i;
    }
}

/**
 * @brief Splits the given [source] string on the first [regex] found, loading the results into [dest1] and [dest2]
 * 
 * @param source Source string to search on
 * @param sourceLen Max source size to copy
 * @param dest1 Buffer to save the split resut Before the [regex]
 * @param dest2 Buffer to save the split result After the [regex]
 * @param regex Character that generates the split once reached
 * @param saveRegex Whether to save the given regex into [dest1] or discard it [dest2]
 * @return bool Whether the action was possible or not
 */
bool splitFirstLen(char* source, int sourceLen, char* dest1, char* dest2, char regex, bool saveRegex){
    for(int i = 0; i < sourceLen; i++){
        if(source[i] == regex){
            memcpy(dest1, source, saveRegex ? (i + 1) : i);
            memcpy(dest2, source + (saveRegex ? (i + 1) : i), sourceLen);
            return true;
        }
    }
    memcpy(dest1, source, sourceLen);
    return false;
}

/**
 * @brief Same as {splitFirstLen()} function but clearing dest's buffers before calling the split action
 * 
 * @param source Source string to search on
 * @param dest1 Buffer to save the split resut Before the [regex]
 * @param dest1MallocSize Buffer size (in order to clear)
 * @param dest2 Buffer to save the split result After the [regex]
 * @param dest2MallocSize Buffer size (in order to clear)
 * @param regex Character that generates the split once reached
 * @param saveRegex Whether to save the given regex into [dest1] or discard it [dest2]
 * @return bool Whether the action was possible or not
 */
bool splitFirstLenNClear(char* source, int sourceLen, char* dest1, int dest1MallocSize, char* dest2, int dest2MallocSize, char regex, bool saveRegex){
    memset(dest1, 0, dest1MallocSize);
    memset(dest2, 0, dest2MallocSize);
    return splitFirstLen(source, sourceLen, dest1, dest2, regex, saveRegex);
}

/**
 * @brief Splits the given [source] string on the first [regex] found, loading the results into [dest1] and [dest2]
 * 
 * @param source Source string to search on
 * @param dest1 Buffer to save the split resut Before the [regex]
 * @param dest2 Buffer to save the split result After the [regex]
 * @param regex Character that generates the split once reached
 * @param saveRegex Whether to save the given regex into [dest1] or discard it [dest2]
 * @return bool Whether the action was possible or not
 */
bool splitFirst(char* source, char* dest1, char* dest2, char regex, bool saveRegex){
    splitFirstLen(source, getPointerDataLen(source), dest1, dest2, regex, saveRegex);
}

/**
 * @brief Same as {splitFirst()} function but clearing dest's buffers before calling the split action
 * 
 * @param source Source string to search on
 * @param dest1 Buffer to save the split resut Before the [regex]
 * @param dest1MallocSize Buffer size (in order to clear)
 * @param dest2 Buffer to save the split result After the [regex]
 * @param dest2MallocSize Buffer size (in order to clear)
 * @param regex Character that generates the split once reached
 * @param saveRegex Whether to save the given regex into [dest1] or discard it [dest2]
 * @return bool Whether the action was possible or not
 */
bool splitFirstNClear(char* source, char* dest1, int dest1MallocSize, char* dest2, int dest2MallocSize, char regex, bool saveRegex){
    return splitFirstLenNClear(source, getPointerDataLen(source), dest1, dest1MallocSize, dest2, dest2MallocSize, regex, saveRegex);
}

/**
 * @brief Copies the [source] string into [dest] buffer untile [regex] is reached
 * 
 * @param source Source string to search on
 * @param sourceLen Max source size to copy
 * @param dest Destinatino buffer where the copy is saved
 * @param regex Regex to break copy once reached
 * @param saveRegex Flag to save or discard the reached regex
 * @return bool If the action was performed 
 */
bool substringLen(char* source, int sourceLen, char* dest, char regex, bool saveRegex){
    for(int i = 0; i < sourceLen; i++){
        if(source[i] == regex){
            memcpy(dest, source, saveRegex ? (i + 1) : i);
            return true;
        }
    }
    return false;
}

/**
 * @brief Same as {substringLen()} function but celaring the result buffer before calling the substring
 * 
 * @param source Source string to search on
 * @param sourceLen Max source size to copy
 * @param dest Destination buffer where the copy is saved
 * @param destMallocSize Buffer Size (in order to clear)
 * @param regex Regex to break copy once reached
 * @param saveRegex Flag to save or discard the reached regex
 * @return bool If the action was performed 
 */
bool substringLenNClear(char* source, int sourceLen, char* dest, int destMallocSize, char regex, bool saveRegex){
    memset(dest, 0, destMallocSize);
    return substringLen(source, sourceLen, dest, regex, saveRegex);
}

/**
 * @brief Copies the [source] string into [dest] buffer untile [regex] is reached
 * 
 * @param source Source string to search on
 * @param dest Destinatino buffer where the copy is saved
 * @param regex Regex to break copy once reached
 * @param saveRegex Flag to save or discard the reached regex
 * @return bool If the action was performed 
 */
bool substring(char* source, char* dest, char regex, bool saveRegex){
    return substringLen(source, getPointerDataLen(source), dest, regex, saveRegex);
}

/**
 * @brief Same as {substring()} function but celaring the result buffer before calling the substring
 * 
 * @param source Source string to search on
 * @param dest Destination buffer where the copy is saved
 * @param destMallocSize Buffer Size (in order to clear)
 * @param regex Regex to break copy once reached
 * @param saveRegex Flag to save or discard the reached regex
 * @return bool If the action was performed 
 */
bool substringNClear(char* source, char* dest, int destMallocSize, char regex, bool saveRegex){
    return substringLenNClear(source, getPointerDataLen(source), dest, destMallocSize, regex, saveRegex);
}
