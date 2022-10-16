#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRMAXLEN 10000

struct paragraph_division
{
    char *parag;
    char **sent;
    char **word;
    short sentenceCount,wordCount;
};

void strInStdin(char *key,long max)
{
    fgets(key,max,stdin);
    key[strcspn(key,"\n")] = '\0';
}

char *paragraph_return()
{
    char *temp = malloc(STRMAXLEN * sizeof(char));
    strInStdin(temp,STRMAXLEN);
    temp = realloc(temp,(strlen(temp)+1)*sizeof(char));
    return temp;
}

char **sentences_return(char *parag,short *count)
{
    char **sentences;
    char temp, prev_space=0;
    short i,state=0;
    *count = 0;

    sentences = malloc(STRMAXLEN * sizeof(char *));

    sentences[0] = malloc(STRMAXLEN * sizeof(char));
    for (i=0;parag[i]!='\0';i++)
    {
        temp = parag[i];
        if ( temp=='.' || temp=='!' || temp=='?' || temp==';' )
        {
            if (state)
            {
                sentences[*count][state] = '\0';
                sentences[*count] = realloc(sentences[*count],(strlen(sentences[*count])+1)*sizeof(char));
                state=0;
                *count += 1;
                prev_space = 1;
                sentences[*count] = malloc(STRMAXLEN * sizeof(char));
            }
        }
        else if (temp == ' ')
        {
            if (!prev_space)
            {
                sentences[*count][state] = temp;
                state++;
                prev_space = 1;
            }
        }
        else
        {
            sentences[*count][state] = temp;
            state++;
            prev_space = 0;
        }
    }
    if (state)
    {
        sentences[*count][state] = '\0';
        sentences[*count] = realloc(sentences[*count],(strlen(sentences[*count])+1)*sizeof(char));
    }
    sentences = realloc(sentences,(*count+1)*sizeof(char *));
    return sentences;
}

char **words_return(char *parag,short *count)
{
    char **words;
    char temp;
    short i,state=0;
    *count = 0;

    words = malloc(STRMAXLEN * sizeof(char *));

    words[0] = malloc(STRMAXLEN * sizeof(char));
    for (i=0;parag[i]!='\0';i++)
    {
        temp = parag[i];
        if ( !( (temp>='a' && temp<='z') || (temp>='A' && temp<='Z') ))
        {
            if (state)
            {
                words[*count][state] = '\0';
                words[*count] = realloc(words[*count],(strlen(words[*count])+1)*sizeof(char));
                state=0;
                *count += 1;
                words[*count] = malloc(STRMAXLEN * sizeof(char));
            }
        }
        else
        {
            words[*count][state] = temp;
            state++;
        }
    }
    if (state)
    {
        words[*count][state] = '\0';
        words[*count] = realloc(words[*count],(strlen(words[*count])+1)*sizeof(char));
    }
    words = realloc(words,(*count+1)*sizeof(char *));
    return words;
}

void fw (char *test_string,struct paragraph_division *data,short counter)
{
    char **seenWords, exist;
    long seenlen=0,i,j,l;
    for (i=0;i<=counter;i++)
    {
        seenlen += data[i].wordCount;
    }
    seenWords = malloc(seenlen * sizeof(char *));
    seenlen=0;
    for (i=0;i<=counter;i++)
    {
        for (j=0;j<data[i].wordCount;j++)
        {
            if (strstr(data[i].word[j],test_string)!=NULL)
            {
                exist=0;
                for (l=0;l<seenlen;l++)
                {
                    if (!strcmp(seenWords[l],data[i].word[j]))
                    {
                        exist = 1;
                    }
                }
                if (!exist)
                {
                    printf("%s\n",data[i].word[j]);
                    seenWords[seenlen] = malloc((strlen(data[i].word[j])+1)*sizeof(char));
                    strcpy(seenWords[seenlen],data[i].word[j]);
                    seenlen++;
                }
            }
        }
    }

    for (i=0;i<seenlen;i++)
    {
        free(seenWords[i]);
    }
    free(seenWords);
}

void fs (char *test_string,struct paragraph_division *data,short counter)
{
    long i,j;
    for (i=0;i<=counter;i++)
    {
        for (j=0;j<data[i].sentenceCount;j++)
        {
            if (strstr(data[i].sent[j],test_string)!=NULL)
            {
                    printf("%s\n",data[i].sent[j]);
            }
        }
    }

}


void fp (char *test_string,struct paragraph_division *data,short counter)
{
    long i,j;
    
    
    
    for (i=0;i<=counter;i++)
    {
        if (strstr(data[i].parag,test_string)!=NULL)
        {
            for (j=0;j<data[i].sentenceCount;j++)
            {
                printf("%s\n",data[i].sent[j]);
            }
        }
    }
    
}

void owf (struct paragraph_division *data,short counter)
{
    char **seenWords, exist;
    long seenlen=0,i,j,l;
    for (i=0;i<=counter;i++)
    {
        seenlen += data[i].wordCount;
    }
    seenWords = malloc(seenlen * sizeof(char *));
    long *timesSeen = calloc(seenlen,sizeof(long));
    seenlen=0;
    for (i=0;i<=counter;i++)
    {
        for (j=0;j<data[i].wordCount;j++)
        {
            exist=0;
            for (l=0;l<seenlen;l++)
            {
                if (!strcmp(seenWords[l],data[i].word[j]))
                {
                    exist = 1;
                    timesSeen[l] += 1;
                }
            }
            if (!exist)
            {
                seenWords[seenlen] = malloc((strlen(data[i].word[j])+1)*sizeof(char));
                strcpy(seenWords[seenlen],data[i].word[j]);
                seenlen++;
            }
        }
    }
    for (i=0;i<seenlen;i++)
    {
        timesSeen[i] ++ ;
    }
    char *tempPointer;
    long tempLong,max;
    for (i=0;i<seenlen;i++)
    {
        max = i;
        for (j=i+1;j<seenlen;j++)
        {
            if (timesSeen[j]>timesSeen[max])
            {
                max = j;
            }
        }
        tempPointer = seenWords[i];
        seenWords[i] = seenWords[max];
        seenWords[max] = tempPointer;
        tempLong = timesSeen[i];
        timesSeen[i] = timesSeen[max];
        timesSeen[max] = tempLong;
    }
    for (i=0;i<seenlen-1;i++)
    {
       for (j=0;j<seenlen-i-1;j++)
       {
           if (timesSeen[j]==timesSeen[j+1])
           {
               if(strcmp(seenWords[j],seenWords[j+1])>0)
               {
                    tempPointer = seenWords[j];
                    seenWords[j] = seenWords[j+1];
                    seenWords[j+1] = tempPointer;

               }
           }
       }
    }


    for (i=0;i<seenlen;i++)
    {
        printf("%s [%ld]\n",seenWords[i],timesSeen[i]);
    }


    for (i=0;i<seenlen;i++)
    {
        free(seenWords[i]);
    }
    free(seenWords);
}


void owl (struct paragraph_division *data,short counter)
{
    char **seenWords, exist;
    long seenlen=0,i,j,l;
    for (i=0;i<=counter;i++)
    {
        seenlen += data[i].wordCount;
    }
    seenWords = malloc(seenlen * sizeof(char *));
    long *SeenWordsLength = calloc(seenlen,sizeof(long));
    seenlen=0;
    for (i=0;i<=counter;i++)
    {
        for (j=0;j<data[i].wordCount;j++)
        {
            exist=0;
            for (l=0;l<seenlen;l++)
            {
                if (!strcmp(seenWords[l],data[i].word[j]))
                {
                    exist = 1;
                }
            }
            if (!exist)
            {
                seenWords[seenlen] = malloc((strlen(data[i].word[j])+1)*sizeof(char));
                strcpy(seenWords[seenlen],data[i].word[j]);
                seenlen++;
            }
        }
    }
    for (i=0;i<seenlen;i++)
    {
        SeenWordsLength[i] = strlen(seenWords[i]);
    }
    char *tempPointer;
    long tempLong,min;
    for (i=0;i<seenlen;i++)
    {
        min = i;
        for (j=i+1;j<seenlen;j++)
        {
            if (SeenWordsLength[j]<SeenWordsLength[min])
            {
                min = j;
            }
        }
        tempPointer = seenWords[i];
        seenWords[i] = seenWords[min];
        seenWords[min] = tempPointer;
        tempLong = SeenWordsLength[i];
        SeenWordsLength[i] = SeenWordsLength[min];
        SeenWordsLength[min] = tempLong;
    }
    for (i=0;i<seenlen-1;i++)
    {
       for (j=0;j<seenlen-i-1;j++)
       {
           if (SeenWordsLength[j]==SeenWordsLength[j+1])
           {
               if(strcmp(seenWords[j],seenWords[j+1])>0)
               {
                    tempPointer = seenWords[j];
                    seenWords[j] = seenWords[j+1];
                    seenWords[j+1] = tempPointer;

               }
           }
       }
    }


    for (i=0;i<seenlen;i++)
    {
        printf("%s [%ld]\n",seenWords[i],SeenWordsLength[i]);
    }


    for (i=0;i<seenlen;i++)
    {
        free(seenWords[i]);
    }
    free(seenWords);
}

int main()
{
    char controlStr[4];
    char *test_String;
    
    scanf(" %c %c",&controlStr[0],&controlStr[1]);
    if (controlStr[0]=='q' && controlStr[1]=='t')
    {
        controlStr[2]='\0';
    }
    else
    {
        scanf("%c",&controlStr[2]);
        if(controlStr[2]==':')
        {
            controlStr[2]='\0';
        }
        else
        {
            controlStr[3]='\0';
        }
    }


    struct paragraph_division *data;

    data = NULL;
    short counter=-1;
    

    while ( strcmp(controlStr,"qt") )
    {
        if (!strcmp(controlStr,"ap"))
        {
            counter++;
            data = realloc(data,(counter+1) * sizeof(struct paragraph_division) );
            data[counter].parag = paragraph_return();
            data[counter].sent = sentences_return(data[counter].parag,&data[counter].sentenceCount); 
            data[counter].word = words_return(data[counter].parag,&data[counter].wordCount);    
        }
        else if (!strcmp(controlStr,"fw"))
        {
            test_String = malloc(STRMAXLEN * sizeof(char));
            strInStdin(test_String,STRMAXLEN);
            fw(test_String,data,counter);
            free(test_String);
        }
        else if (!strcmp(controlStr,"fs"))
        {
            test_String = malloc(STRMAXLEN * sizeof(char));
            strInStdin(test_String,STRMAXLEN);
            fs(test_String,data,counter);
            free(test_String);
        }
        else if (!strcmp(controlStr,"fp"))
        {
            test_String = malloc(STRMAXLEN * sizeof(char));
            strInStdin(test_String,STRMAXLEN);
            fp(test_String,data,counter);
            free(test_String);
        }
        else if (!strcmp(controlStr,"owf"))
        {
            owf(data,counter);
        }
        else if (!strcmp(controlStr,"owl"))
        {
            owl(data,counter);
        }

        
        scanf(" %c %c",&controlStr[0],&controlStr[1]);
        if (controlStr[0]=='q' && controlStr[1]=='t')
        {
            controlStr[2]='\0';
        }
        else
        {
            scanf("%c",&controlStr[2]);
            if(controlStr[2]==':')
            {
                controlStr[2]='\0';
            }
            else
            {
                controlStr[3]='\0';
            }
        }
    }

    return 0;
}
