#include <stdio.h>
#include <ctype.h>

int main() {
    FILE* file;
    int count[256] = {0};
    int ch;
    int charCount = 0, wordCount = 0, inWord = 0, paragraphCount = 0;

    file = fopen("sample.txt","r");
    if (file == NULL){
        printf("error opening file\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF){
        count[ch]++;
        charCount++;

        //counting the words
        if (isspace(ch)){
            if (inWord){
                wordCount++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }

        //counting the paragraphs
        if (ch == '\n'){
            int nextChar = fgetc(file);
            if (nextChar == '\n')  paragraphCount++;
            
            ungetc(nextChar, file);
        }
    }

    //if file ends in a word, then counting it:
    if (inWord) {
        wordCount++;
    }

    fclose(file);

    printf("No of Characters: %d\n", charCount);
    printf("No of Words: %d\n", wordCount);
    printf("No of Paragraph: %d\n", paragraphCount);
    
    printf("Each term is <Character> : (<Ascii Value>) : Occurence Count\n");
    for (int i = 0; i < 256; i++)
    {
        if (count[i]>0){
            if (i<32 || i==127) //handle non printable characters
                printf("ASCII %d: %d times\n", i, count[i]);
            
            else 
                printf("'%c' : (%d) : %d\t\t", i, i, count[i]);
        }
    }

    //count and print the characters not present in sample.txt
    printf("\n\nCharacters that do not occur: (<Character> : <AsciiValue>)\n");
    for (int i = 0; i < 128; i++)
    {
        if(count[i] == 0){
            if (i<32 || i == 127)
                continue;
            else
                printf("'%c' : (%d)\t\t", i, i);
        }
    }

    return 0;
}