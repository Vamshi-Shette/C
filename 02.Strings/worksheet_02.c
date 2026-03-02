#include<stdio.h>
#include<string.h>

/*
Swap the contents of two strings without using any extra temporary string variables. The strings' values should be exchanged completely.
Input: str1 = "hello", str2 = "world"
Output: str1 = "world", str2 = "hello"
*/
void swap_strings()
{
    char str1[100],str2[100];
    int len1=0,len2=0;
    int i;
    scanf("%s",str1);
    scanf("%s",str2);
    while(str1[len1]!='\0')
        len1++;
    while(str2[len2]!='\0')
        len2++;
    for(i=0;i<=len2;i++)
        str1[len1+i]=str2[i];
    for(i=0;i<len1;i++)
        str2[i]=str1[i];
    str2[len1]='\0';
    for(i=0;i<len2;i++)
        str1[i]=str1[len1+i];
    str1[len2]='\0';
    printf("str1 = %s\n",str1);
    printf("str2 = %s\n",str2);
}
/*
Reverse the order of words in a sentence without reversing the words themselves.
Input: "Hello world"
Output: "world Hello"
*/
void reverse_words()
{
    char str[200];
    int i=0,j,start,end,len=0;

    fgets(str,200,stdin);

    while(str[len]!='\0')
        len++;

    if(str[len-1]=='\n')
    {
        str[len-1]='\0';
        len--;
    }

    for(i=len-1;i>=0;i--)
    {
        if(str[i]==' '||i==0)
        {
            if(i==0)
                start=0;
            else
                start=i+1;

            end=start;

            while(str[end]!=' '&&str[end]!='\0')
            {
                printf("%c",str[end]);
                end++;
            }

            printf(" ");
        }
    }

    printf("\n");
}
/* 
2.Sort an array of strings in alphabetical order. The sorted array should list strings from A to Z.
Input: {"John", "Alice", "Bob"}
Output: {"Alice", "Bob", "John"}
 */
void sort_array()
{
	char str0[50], str1[50], str2[50], str3[50], str4[50];
    	char *str[5] = { str0, str1, str2, str3, str4 };
    	int n = 3;   // we want to store only 3 strings
    	for(int i = 0; i < n; i++)
    	{
        	printf("Enter string %d: ", i+1);
        	fgets(str[i], 50, stdin);
        	str[i][strcspn(str[i], "\n")] = '\0';
   	 }

	char *p;
	int num=n;
	for(int i=0;i<num-1;i++)
	{
		for(int j=i+1;j<num;j++)
		{
			if(str[i][0]>str[j][0])
			{
				p=str[i];
				str[i]=str[j];
				str[j]=p;
			}
		}
	}
	for(int i=0;i<num;i++)
		printf("%s, ",str[i]);
	return;
}
/*
3.Check whether a given string is a palindrome, i.e., it reads the same forwards and backwards.
Input: "madam"
Output: Palindrome
 */
void check_palindrome()
{
	char str[50];
        printf("Input:");
        scanf("%[^\n]s",str);
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
4.Find the character that appears most frequently in the input string and print it.
Input: "sample string"
Output: 's'
 */
void character_frequency()
{
	char str[50];
        printf("Input:");
        scanf("%[^\n]s",str);
	getchar();
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
5.Remove all duplicate characters from a string, keeping only the first occurrence of each character.
Input: "programming"
Output: "progamin"
 */
void remove_duplicate()
{
	char str[50];
        printf("Input:");
        scanf("%[^\n]s",str);
        getchar();
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
6.Print all characters that occur more than once in a string.
Input: "programming"
Output: r g m
 */
void non_repeat_characters()
{
	char str[50];
        printf("Input:");
        scanf("%[^\n]s",str);
        getchar();
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
        return;
/*
7.Remove from the first string all characters that appear in the second string.
Input: str1 = "hello world", str2 = "low"
Output: "he rd"
 */
void remove_characters()
{
	char str[50];
	fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
	char s2[20];
	fgets(s2, sizeof(s2), stdin);
        s2[strcspn(s2, "\n")] = '\0';
	char *ptr=str;
	while((n = strcspn(ptr, s2)) != strlen(ptr))
	{
		memmove(ptr+n,ptr+n+1,strlen(ptr+n));
		ptr=ptr+n;
	}
	printf("%s",str);
	return;
}
/*
8.Check if one string is a rotation of another, i.e., one string can be shifted to get the other.
Input: "abcd", "cdab"
Output: Yes
 */
void string_rotate_match()
{
	char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
        char s2[20];
        fgets(s2, sizeof(s2), stdin);
        s2[strcspn(s2, "\n")] = '\0';
	if(strlen(str)!=strlen(s2))
	{
		printf("No\n");
		return;
	}
	int size=strlen(str);
	int count=0;
	while(count!=size)
	{
		chr=str[0];
		for(i=0;i<size-1;i++)
			str[i]=str[i+1];
		str[size-1]=chr;
		if(strcmp(str,s2)==0)
		{
			printf("Yes\n");
			break;
		}
		count++;
	}
	if(count>=size)
		printf("No\n");
	return;

}
/*
9.Print the reverse of a string using recursion.
Input: "hello"
Output: "olleh" 
*/
void recursion(char *str)
{
	int i=0;
	if(str[i]==0)
		return;
	recursion(str+i);
	printf("%c",str[i]);
}
void reverse_string()
{
	char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
	recursion(str);
}

/*
11.Divide a string into N equal parts and print each part separately.
Input: "abcdefgh", N=4
Output: "ab", "cd", "ef", "gh"
 */
void string_division()
{
	char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
	int n,len;
	printf("N:");
	scanf("%d",&n);
	len=strlen(str)/n;
	for(i=0;i<strlen(str);i=i+j)
	{
		for(j=0;j<len;j++)
		{
			printf("%c",str[j]);
		}
		printf(", ");
	}
	return;
}
/*
12.Find the first non-repeating character in a string and print it.
Input: "swiss"
Output: 'w'
 */
void fisrt_non_repeat_element()
{
	char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';


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
		break;
        }
}

/*
 Given a list of strings and a word, print the strings containing all characters of that word.
Input: Word = "act", List = ["cat", "tac", "act", "dog"]
Output: "cat", "tac", "act"
 */
void list_of_strings_match_word()
{
	char str[50];
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';
	
	char str0[50], str1[50], str2[50], str3[50], str4[50];
        char *list[5] = { str0, str1, str2, str3, str4 };
        int n=4; 
									// SIZE IS FIXED need to change it as runtime input
        for(int i = 0; i < n; i++)
        {
                printf("Enter string %d: ", i+1);
                fgets(list[i], 50, stdin);
                list[i][strcspn(list[i], "\n")] = '\0';
         }

	for(i=0;str[i];i++)
	{
		while(n=(strcspn(str,list[i]))!=strlen(str))
		{
			count++;
		}

}

/*
 Find the length of the longest substring with no repeating characters.
Input: "abcabcbb"
Output: 3
*/
void void longest_unique_substring()
{
    char str[200];
    int n=0;
    int i,j;

    scanf("%s",str);

    while(str[n]!='\0')
        n++;

    int maxlen=0;

    for(i=0;i<n;i++)
    {
        int visited[256]={0};
        int len=0;

        for(j=i;j<n;j++)
        {
            if(visited[(int)str[j]]==1)
                break;

            visited[(int)str[j]]=1;
            len++;
        }

        if(len>maxlen)
            maxlen=len;
    }

    printf("%d\n",maxlen);
}
/*
 Check if a string is an interleaving of two other strings, i.e., formed by merging them maintaining order.
Input: s1 = "abc", s2 = "def", s3 = "adbcef"
Output: True
*/
void compare_string_match(char str[])
{
	char s2[50];
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';

    char s3[50];
    fgets(s3, sizeof(s3), stdin);
    s3[strcspn(s3, "\n")] = '\0';

    int count1=0,count2=0,i,j;
    for(i=0;str[i];i++)
    {
	    for(j=0;s3[j];j++)
	    {
		    if(str[i]==str[j])
		    {
			    count1++;
			    break;
		    }
	    }
    }
    if(count1==strlen(str))
    {
	    for(i=0;s2[i];i++)
	    {
        	    for(j=0;s3[j];j++)
        	    {
        	            if(s2[i]==str[j])
        	            {
        	                    count2++;
        	                    break;
        	            }
    	    	    }
	    }
    }
    if(count2==strlen(s2))
	    printf("True\n");
    else
	    printf("False\n");
    return;
}

/*
 Check if two strings are anagrams of each other by comparing character counts.
Input: "listen", "silent"
Output: True
 */

void sort_word(char str[])
{
	int len=strlen(str),i,j;
	char temp;
	for(i=0;str[i];i++)
	{
		for(j=i+1;str[j];j++)
		{
			if(str[i]>str[j])
			{
				temp=str[i];
				str[i]=str[j];
				str[j]=temp;
			}
		}
	}
	printf("%s",str);
	return;

}
void check_anagram(char str[])
{
	char s2[50];
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';
    sort_word(str);
    sort_word(s2);
    if(strcmp(str,s2)==0)
	    printf("True\n");
    else
	    printf("False\n");
    return;

}

/*
 Partition a string into the minimum number of palindromic substrings (Palindrome Partitioning).
Input: "ababbbabbababa"
Output: 3
*/
void palindrome_partitioning()
{
    char str[200];
    int n=0;
    int i,j,k;

    scanf("%s",str);

    while(str[n]!='\0')
        n++;

    int dp[200];

    for(i=0;i<n;i++)
        dp[i]=i;

    for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            int left=j;
            int right=i;
            int flag=1;

            while(left<right)
            {
                if(str[left]!=str[right])
                {
                    flag=0;
                    break;
                }
                left++;
                right--;
            }

            if(flag==1)
            {
                if(j==0)
                    dp[i]=0;
                else if(dp[j-1]+1<dp[i])
                    dp[i]=dp[j-1]+1;
            }
        }
    }

    printf("%d\n",dp[n-1]);
}

/*
 Find the longest palindromic substring inside a given string.
Input: "babad"
Output: "bab" or "aba"
*/
void longest_palindromic_substring()
{
    char str[100];
    int n=0;
    int i,left,right;
    int start=0,maxlen=1;

    scanf("%s",str);

    while(str[n]!='\0')
        n++;

    for(i=0;i<n;i++)
    {
        left=i;
        right=i;

        while(left>=0&&right<n&&str[left]==str[right])
        {
            if(right-left+1>maxlen)
            {
                start=left;
                maxlen=right-left+1;
            }
            left--;
            right++;
        }

        left=i;
        right=i+1;

        while(left>=0&&right<n&&str[left]==str[right])
        {
            if(right-left+1>maxlen)
            {
                start=left;
                maxlen=right-left+1;
            }
            left--;
            right++;
        }
    }

    for(i=start;i<start+maxlen;i++)
        printf("%c",str[i]);

    printf("\n");
}
/*
 Count the number of words in a string separated by spaces.
Input: "Hello world"
Output: 2
 */
void count_words(char str[])
{
	int count=0;
	char *ptr=str;
	while(ptr=strchr(ptr,' '))
		count++;
	printf("%d",count+1);
	return;
}

/*
 Match a string against a pattern containing wildcards '*' (any sequence) and '?' (single character).
Input: Pattern = "g*ks", String = "geeks"
Output: Match
 */
void string_match_with_sequence(char pattern[])
{
       	char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    int i,j;

    for(i=0,j=0;pattern[i];i++,j++)
    {
            if(pattern[i]==str[j])
                    continue;
            else if(pattern[i]=='*')
            {

                    while(1)
                    {
                            if(str[j]==str[j+1])
                                    j++;
                            else if(str[j+1]==pattern[i+1])
                                    break;
                            else
                            {
                                    printf("No Match\n");
                                    return;
                    }

                    }
            }
            else if(pattern[i]=='?')
                    continue;
            else if(pattern[i]!=str[j])
            {
                    printf("No Match\n");
                    return;
            }
    }
        printf("Match\n");
        return;

}

/*
 Convert a numeric string to an integer without using built-in functions.
Input: "1234"
Output: 1234
 */
void ascii_to_int(char str[])
{
	int num;
	for(int i=0;str[i];i++)
	{	if(str[i]>='0' && str[i]<='9')
		 	num=num*10+(str[i]-48);
		else
			break;
	}
	printf("%d",num);
	return;
				
}

/*
Print all permutations of a given string. All possible arrangements of characters should be printed.
Input: "ABC"
Output: "ABC", "ACB", "BAC", "BCA", "CAB", "CBA"
*/
void string_permutations(char *str)
{
    
    int n=strlen(str);
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(j==i)
                continue;

            for(k=0;k<n;k++)
            {
                if(k==i||k==j)
                    continue;

                printf("%c%c%c\n",str[i],str[j],str[k]);
            }
        }
    }
}
/*
 Find the longest substring common to two given strings.
Input: "abcdxyz", "xyzabcd"
Output: "abcd"
 */
void longest_common_substring()
{
        char s1[]="abcdxyz";
        char s2[]="xyzabcd";
        int len1=strlen(s1);
        int len2=strlen(s2);
        int maxlen=0;
        int endindex=0;
        int i,j,k;
        for(i=0;i<len1;i++)
        {
                for(j=0;j<len2;j++)
                {
                        k=0;
                        while(i+k<len1 && j+k<len2 && s1[i+k]==s2[j+k])
                        {
                                k++;
                        }
                        if(k>maxlen)
                        {
                                maxlen=k;
                                endindex=i+k-1;
                        }
                }
        }
        printf("longest common substring: ");
        for(i=endindex-maxlen+1;i<=endindex;i++)
        printf("%c",s1[i]);
        printf("\n");
        return;
}

/*
 Remove all occurrences of character 'b' and substring "ac" from a string.
Input: "abacb"
Output: "a"
 */
void remove_b_ac_from_string(char str[])
{
	char *ptr;
	for(i=0;str[i];i++)
	{
		if(str[i]=='b')
			memmove(str+i,str+i+1,strlen(str+i));
		else if(ptr=strstr(str,"ac"))
			memmove(ptr,ptr+2,2);
	}
	printf("%s",str);
	return;
}
int main()
{ 
    reverse_words();
    swap_strings();
    sort_array();
    check_palindrome();
    character_frequency();
    remove_duplicate();
    palindrome_partitioning();
    non_repeat_characters();
    remove_characters();
    string_rotate_match();
    reverse_string();
    longest_unique_substring();
    string_division();
    fisrt_non_repeat_element();
    longest_common_substring();
    longest_palindromic_substring();
    char str[50];
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    length_of_longest_substring(str);
    compare_string_match(str);
    string_permutations(str);
    sort_word(str);
    check_anagram(str);
    remove_b_ac_from_string(str);
    count_words(str);
    string_match_with_sequence(str);
    ascii_to_int(str);
    return 0;
}


