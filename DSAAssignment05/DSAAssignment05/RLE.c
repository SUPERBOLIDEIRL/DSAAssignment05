#include "RLE.h"

//Adam Wajda -  DSA - Assignment 5

// Function to encode input string using RLE
int encode(char* in_buf, char* out_buf, char esc) 
{
    int in_len = 0;
    int out_len = 0;

    while (in_buf[in_len] != '\0') 
    {
        char curr_char = in_buf[in_len];
        int c = 1;

        while (in_buf[in_len + c] == curr_char && c < 255)  // Count count when same character
        {
            c++;
        }

        if (c > 3 || curr_char == esc)  // If the count is greater than 3 or the current character is the escape character
        {
            out_buf[out_len++] = esc; // Store the escape character, count, and character
            out_buf[out_len++] = c;
            out_buf[out_len++] = curr_char;
        }
        else {
            for (int i = 0; i < c; i++) 
            {
                out_buf[out_len++] = curr_char;
            }
        }

        in_len += c;
    }

    out_buf[out_len] = '\0';
    return out_len;
}

int decode(char* in_buf, char* out_buf, char esc)  // Function to decode previously encoded input string using RLE
{
    int in_len = 0;
    int out_len = 0;

    while (in_buf[in_len] != '\0') 
    {
        if (in_buf[in_len] == esc) 
        {
            int c = in_buf[in_len + 1];
            char curr_char = in_buf[in_len + 2];

            for (int i = 0; i < c; i++) // Repeat the character c(consecutive occurance) times in the decoded string
            {
                out_buf[out_len++] = curr_char;
            }

            in_len += 3;// Move to the next escape sequence
        }
        else {
            out_buf[out_len++] = in_buf[in_len++];
        }
    }

    out_buf[out_len] = '\0';
    return out_len;
}