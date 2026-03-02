#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*
 1. Program: Reverse order of words in a given string
          Input: "hello world from C"

         Output: "C from world hello"
 */
void reverse_words_in_string()
{
    char str[200];
    printf("enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // remove newline

    // split words and store pointers in an array
    char *words[50]; // max 50 words
    int count = 0;

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    // print words in reverse order
    printf("reversed string:\n");
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%s", words[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
}

/*
 2. Program: Remove all repeated characters from a given string
         Input: "programming"

        Output: "progamin"
 */
void remove_duplicate(char str[])
{
	int i,j;
	int size=strlen(str);
	for(i=0;str[i];i++)
	{
		for(j=i+1;str[j];j++)
		{
			if(str[i]==str[j])
			{
				memmove(str+j,str+j+1,strlen(str+j));
				j--;
			}
		}
	}
	printf("%s",str);
	return;
}

/*
 3. Program: Find highest frequency character in a string
          Input: "engineering"

          Output: 'e' appears 3 times
 */
void find_frequency(char str[])
{
	char character;
	char *ptr;
	int i,count,max_count=0;
	for(i=0;str[i];i++)
	{
		ptr=str+i+1;
		count=1;
		while(ptr=strchr(ptr,str[i]))
		{
			count++;
			ptr=ptr+1;
		}
		if(max_count<count)
		{
			max_count=count;
			character=str[i];
		}
	}

	printf("%c appears %d times",character,max_count);
        return;
}

/*
 4. Program: Find lowest frequency character in a string
          Input: "engineering"

         Output: 'g', 'r', 'n' each appear once
 */
void lowest_frequency(char str[])
{
	char character;
        char *ptr;
        int i,count,max_count=0;
        for(i=0;str[i];i++)
        {
		int flag,j;
                flag=0;

                for(j=i-1;j>=0;j--)
                {
                        if(str[i]==str[j])
                        {
                                flag++;
                                break;
                        }
                }
                if(flag)
                        continue;

                ptr=str+i+1;
                count=1;
                while(ptr=strchr(ptr,str[i]))
                {
                        count++;
                        ptr=ptr+1;
                }
                if(count==1)
			printf("'%c', ",str[i]);
        }
	printf("each appears once");
	return;

}

/*
 5. Program: Reverse a string without using library functions
         Input: "OpenAI"

         Output: "IAnepO"
 */
void reverse_string(char str[])
{
	int i,size=strlen(str);
	for(i=0;i<size/2;i++)
	{
		str[i]=str[size-1-i];
	}
	printf("%s",str);
	return;
}

/*
 6. Program: Remove all extra blank spaces from a given string
         Input: " This is ChatGPT "

         Output: "This is ChatGPT"
 */
void remove_extra_spaces(char str[])
{
	int i;
	for(i=0;str[i];i++)
	{
		if( (str[i]==' ')&&(str[i+1]==' '))
			memmove(str+i+1,str+i+2,strlen(str+i+1));
	}
	if(str[strlen(str)-1]==' ')
		str[strlen(str)-1]=0;
	printf("%s",str);
	return;

}

/*
7. Program: Replace all occurrences of a character with another in a string
Input: "banana", replace 'a' with 'o'

Output: "bonono"
 */
void replace_characters(char str[])
{
	char c1,c2;
	printf("replace ");
	scanf("%c",&c1);
	printf(" with ");
	scanf("%c",&c2);
	for(int i=0;str[i];i++)
	{
		if(str[i]==c1)
			str[i]=c2;
	}
	printf("%s",str);
	return;
}

/*
 8. Program: Count frequency of each character in a string
         Input: "success"

         Output:
          s = 3
         u = 1
         c = 2
         e = 1
 */
void count_frequency(char str[])
{
	 char character;
        char *ptr;
        int i,count;
        for(i=0;str[i];i++)
        {
                int flag,j;
                flag=0;

                for(j=i-1;j>=0;j--)
                {
                        if(str[i]==str[j])
                        {
                                flag++;
                                break;
                        }
                }
                if(flag)
                        continue;

                ptr=str+i+1;
                count=1;
                while(ptr=strchr(ptr,str[i]))
                {
                        count++;
                        ptr=ptr+1;
                }
                printf("%c = %d\n",str[i],count);
        }
	return;

}
/*
 9. Program: Find first occurrence of a word in a given string
         Input: "this is a test string", word: "test"

         Output: Found at position 11
 */
void first_occurrence_of_word(char str[])
{
	char s2[20];
	printf("word: ");
	scanf("%[^\n]s",s2);
	char *p=strstr(str,s2);
	printf("Found at position %d",p-str);
	return;
}

/*
 10. Program: Remove all occurrence of a word in given string
           Input: "hello world hello universe", remove: "hello"

          Output: "world universe"
 */
void remove_occurrence_of_word(char str[])
{
	char s2[20];
        printf("word: ");
        fflush(stdout);
       	//scanf("%[^\n]s",s2);
	fgets(s2, sizeof(s2), stdin);
	s2[strcspn(s2, "\n")] = '\0';
	int size=strlen(s2);
	printf("%d\n",size);
	char *ptr=str;
	while((ptr=strstr(ptr,s2))!=NULL)
	{
		strncpy(ptr,ptr+size+1,strlen(ptr+size)+1);

	}
	printf("%s",str);
	return;
}

/*11. Program: Count total number of words in a string
          Input: "C programming is fun"

          Output: 4
*/

void count_words(char str[])
{
	int count=0;
	char chr=' ';
	char *ptr=str;
	while(ptr=strchr(ptr,chr))
	{
		count++;
		ptr++;
	}
	printf("%d",count+1);
	return;
}

/*
 12. Program: Toggle case of each character of a string
         Input: "HeLLo"

         Output: "hEllO"
 */
void toggle_word("char str[]")
{
	for(i=0;str[i];i++)
		str[i]=str[i]^32;
	printf("%s",str);
	return;
}

/*
13. Program: Remove last occurrence of a character from string
          Input: "mississippi", remove 's'

          Output: "missisippi"
 */
void remove_last_occurrence(char str[])
{
	char chr;
	int num=0;
	scanf("%c",&chr);
	for(i=0;str[i],i++)
		if(str[i]==chr)
			num=i;
	char *ptr=str;
	memmove(ptr+num,ptr+num+1,strlen(ptr+num));
	printf("%s",ptr);
	return;
}

/*
 14. Program: Replace first occurrence of a character with another in a string
         Input: "google", replace 'o' with 'a'

         Output: "gagole"
 */
void replace_first_occurrence(char str[])
{
	char c1,c2;
        printf("replace ");
        scanf("%c",&c1);
        printf(" with ");
        scanf("%c",&c2);
	char *p=strchr(str,c1);
	*p=c2;
	printf("%s",str);
	return;

}

/*
 15. Program: Count occurrences of a word in a given string
          Input: "hi hello hi hey hi", word: "hi"

         Output: 3
 */
void count_occurrence_of_word(char str[])
{
	int count=0;
	char *p=str;
	char s2[20];
        printf("word: ");
        scanf("%[^\n]s",s2);
	while(p=strstr(p,s2))
	{
		count++;
		p++;
	}
	printf("%d",count);
	return;

}

/*
 16. Program: Check whether a string is palindrome or not
        Input: "madam"

       Output: "Palindrome"
 */
void check_palindrome(char str[])
{
	int len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		if(str[i]!=str[len-1-i])
		{
			printf("Not palindrome\n");
			return;
		}
	}
	printf("Palindrome\n");
	return;
}

/*
 17. Program: Find last occurrence of a character in a string
        Input: "ababcabc", find 'b'

        Output: Position: 6
*/
void last_occurrence(char str[])
{
	char chr;
        scanf("%c",&chr);
	char *p=strrchr(str,chr);
	printf("%d",str-p);
	return;
}

/*
 18. Program: Trim both leading and trailing white space characters from given string
        Input: " Hello World "

        Output: "Hello World"
 */
void trim_front_back_spaces(char str[])
{
	while(str[i]!=' ')
		memmove(str,str+1,strlen(str));
	int len=strlen(str);
	while(str[len-1]!=' ')
	{
		str[len-1]=0;
		len--;
	}
	printf("%s",str);
}

/*
 19. Program: Find first occurrence of a character in a given string
       Input: "elephant", find 'e'

        Output: Position: 0
 */
void first_occurrence_of_char(char str[])
{
        char chr;
        scanf("%c",&chr);
        char *p=strchr(str,chr);
        printf("%d",str-p);
        return;
}
/*
20. Program: Find all occurrences of a word in given string
        Input: "the sky is the limit in the sky", search "the"

       Output: Found at positions: 0, 15, 30
*/
void find_all_occurrence_of_word(char str[])
{
        
        char *p=str;
        char s2[20];
        printf("word: ");
        scanf("%[^\n]s",s2);
	printf("Found at positions: ");
        while(p=strstr(p,s2))
        {
               printf("%d, ",p-str);
                p++;
        }
        printf("%d",count);
        return;

}

int main()
{
	char str[50];
	printf("Input:");
	scanf("%[^\n]s",str);
	reverse_words_in_string();
	reverse_words(str);
	remove_duplicate(str);
	find_frequency(str);
	lowest_frequency(str);
	reverse_string(str);
	remove_extra_spaces(str);
	replace_characters(str);
	count_frequency(str);
	first_occurence_of_word(str);
	remove_occurrence_of_word(str);
	count_words(str);
	toggle_word(str);
	remove_last_occurrence(str);
	replace_first_occurrence(str);
	count_occurrence_of_word(str);
	check_palindrome(str);
	last_occurrence(str);
	trim_front_back_spaces(str);
	first_occurrence_of_char(str);
	find_all_occurrence_of_word(str);
	return 0;
}

