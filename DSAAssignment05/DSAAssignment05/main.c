#include <stdio.h>
#include <stdlib.h> 
#include "RLE.h"

//Adam Wajda -  DSA - Assignment 5


int main() 
{
    char test1[] = "CCCCDDDDJJJJKKKKEEEEFGYX";
    char out1[BUFFER_SIZE];// Buffer to hold encoded string
    char decoded1[BUFFER_SIZE];// Buffer to hold decoded string
    //test case 1
    printf("Original: %s\n", test1);  //printing original
    printf("Length: %d\n", sizeof(test1) - 1);

    int encoded_length = encode(test1, out1, '*');  // Encoding and printing encoded result
    if (encoded_length == -1) 
    {
        printf("Compression failed for test case 1.\n");
    }
    else 
    {
        printf("Encoded: %s\n", out1);
        printf("Encoded length: %d\n", encoded_length);

        int decoded_length = decode(out1, decoded1, '*');   // Decoding the encoded string and printing the decoded result
        printf("Decoded: %s\n", decoded1);
        printf("Decoded length: %d\n", decoded_length);
    }
    //test case 2
    char test2[] = "ABCLKMXYZ";
    char out2[BUFFER_SIZE];

    printf("Original: %s\n", test2);
    printf("Original length: %d\n", sizeof(test2) - 1);

    int encode_result = encode(test2, out2, '*'); // Encoding and printing the encoded result
    if (encode_result == -1) {
        printf("Compression failed for test case 2.\n");
    }
    else 
    {
        printf("Encoded: %s\n", out2);
        printf("Encoded length: %d\n", encode_result);
    }

    return 0;
}