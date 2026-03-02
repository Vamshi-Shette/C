#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

/*
Make a new file and save some text entered by the user.
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.
*/
void make_new_file()
{
    char filename[100];
    char text[500];
    printf("file name: ");
    scanf("%s",filename);
    getchar();
    printf("text: ");
    fgets(text,500,stdin);
    FILE *fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("file cannot be created\n");
        return;
    }
    fputs(text,fp);
    fclose(fp);
    printf("file '%s' created and saved.\n",filename);
}

/*
Open an existing file and display its contents on the screen.
Input: File name: test.txt
Output: Hello, this is my first file!
*/
void open_existing_file()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
}

/*
Take several lines from the user and write all of them into a file.
Input: File name: lines.txt
Number of lines: 3
Lines: Line one, Line two, Line three
Output: All lines saved in 'lines.txt'.
*/
void write_to_file()
{
    char filename[100];
    int n,i;
    char line[200];
    printf("file name: ");
    scanf("%s",filename);
    printf("number of lines: ");
    scanf("%d",&n);
    getchar();
    FILE *fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("file cannot be created\n");
        return;
    }
   
    fclose(fp);
    printf("all lines saved in '%s'.\n",filename);
}

/*
Read every line from a file and store those lines in an array.
Input: File name: lines.txt
Output: Line one, Line two, Line three (as array elements)
*/
void read_from_file()
{
    char filename[100];
    char lines[50][200];
    int count=0,i;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(lines[count],200,fp)!=NULL)
    {
        count++;
    }
    fclose(fp);
    for(i=0;i<count;i++)
    {
        printf("%s",lines[i]);
    }
}

/*
Add more lines to the end of a file without erasing its current content.
Input: File name: lines.txt
Number of new lines: 2
New lines: Line four, Line five
Output: File now contains: Line one, Line two, Line three, Line four, Line five
*/
void add_more_lines()
{
    char filename[100];
    int n,i;
    char line[200];
    printf("file name: ");
    scanf("%s",filename);
    printf("number of new lines: ");
    scanf("%d",&n);
    getchar();
    FILE *fp=fopen(filename,"a");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    for(i=0;i<n;i++)
    {
        fgets(line,200,stdin);
        fputs(line,fp);
    }
    fclose(fp);
    printf("new lines added to '%s'.\n",filename);
}

/*
Copy everything from one file and save it into another file.
Input: Source file: lines.txt
Destination file: copy.txt
Output: File 'lines.txt' copied to 'copy.txt'.
*/
void copy_file()
{
    char source[100],destination[100];
    char ch;
    printf("source file: ");
    scanf("%s",source);
    printf("destination file: ");
    scanf("%s",destination);
    FILE *fs=fopen(source,"r");
    if(fs==NULL)
    {
        printf("source file not found\n");
        return;
    }
    FILE *fd=fopen(destination,"w");
    if(fd==NULL)
    {
        printf("cannot create destination file\n");
        fclose(fs);
        return;
    }
    while((ch=fgetc(fs))!=EOF)
    {
        fputc(ch,fd);
    }
    fclose(fs);
    fclose(fd);
    printf("file '%s' copied to '%s'.\n",source,destination);
}

/*
Delete a file from the computer.
Input: File name: temp.txt
Output: File 'temp.txt' deleted.
*/
void delete_file()
{
    char filename[100];
    printf("file name: ");
    scanf("%s",filename);
    if(remove(filename)==0)
        printf("file '%s' deleted.\n",filename);
    else
        printf("unable to delete file\n");
}

/*
Read a value from a file into a variable, and also write a variable’s value back into a file.
Input: File name: number.txt (contains: 42)
Output: Read variable: 42; After writing value 100, file now contains: 100
*/
void read_value()
{
    char filename[100];
    int num;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    fscanf(fp,"%d",&num);
    fclose(fp);
    printf("read variable: %d\n",num);
    fp=fopen(filename,"w");
    if(fp==NULL)
    {
        printf("cannot open file\n");
        return;
    }
    fprintf(fp,"%d",100);
    fclose(fp);
    printf("after writing value 100, file now contains: 100\n");
}
/*
Count how many lines are present in a text file.
Input: File name: lines.txt
Output: Total lines: 5
*/
void count_lines()
{
    char filename[100];
    char ch;
    int count=0;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        if(ch=='\n')
            count++;
    }
    fclose(fp);
    printf("total lines: %d\n",count);
}

/*
Count both the number of words and the number of characters in a file.
Input: File name: info.txt (content: This is a test file.)
Output: Words: 5
Characters: 21
*/
void count_words_characters()
{
    char filename[100];
    char ch;
    int words=0,chars=0,inword=0;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while((ch=fgetc(fp))!=EOF)
    {
        chars++;
        if(ch==' '||ch=='\n'||ch=='\t')
            inword=0;
        else if(inword==0)
        {
            inword=1;
            words++;
        }
    }
    fclose(fp);
    printf("words: %d\n",words);
    printf("characters: %d\n",chars);
}

/*
Show all the contents in a file and also print the total number of lines.
Input: File name: lines.txt
Output: (shows all lines)
Total lines: 5
*/
void show_all_contents()
{
    char filename[100];
    char line[200];
    int count=0;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(line,200,fp)!=NULL)
    {
        printf("%s",line);
        count++;
    }
    fclose(fp);
    printf("total lines: %d\n",count);
}

/*
Remove a specific line (by line number) from a file.
Input: File name: lines.txt
Line to remove: 2
Output: File now contains all lines except line 2.
*/
void remove_line()
{
    char filename[100],temp[]="temp.txt";
    char line[200];
    int lineno,current=1;
    printf("file name: ");
    scanf("%s",filename);
    printf("line to remove: ");
    scanf("%d",&lineno);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen(temp,"w");
    while(fgets(line,200,fp)!=NULL)
    {
        if(current!=lineno)
            fputs(line,ft);
        current++;
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename(temp,filename);
    printf("file now contains all lines except line %d.\n",lineno);
}

/*
Change a particular line in a file to some new text.
Input: File name: lines.txt
Line number: 3
New text: This line has been changed!
Output: File now contains new text at line 3.
*/
void change_a_line()
{
    char filename[100],temp[]="temp.txt";
    char line[200],newline[200];
    int lineno,current=1;
    printf("file name: ");
    scanf("%s",filename);
    printf("line number: ");
    scanf("%d",&lineno);
    getchar();
    printf("new text: ");
    fgets(newline,200,stdin);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen(temp,"w");
    while(fgets(line,200,fp)!=NULL)
    {
        if(current==lineno)
            fputs(newline,ft);
        else
            fputs(line,ft);
        current++;
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename(temp,filename);
    printf("file now contains new text at line %d.\n",lineno);
}

/*
Replace every use of a chosen word in a file with a different word.
Input: File name: info.txt
Word to replace: file
Replacement: document
Output: Content after: This is a test document.
*/
void replace_word()
{
    char filename[100],old[50],neww[50];
    char word[100];
    printf("file name: ");
    scanf("%s",filename);
    printf("word to replace: ");
    scanf("%s",old);
    printf("replacement: ");
    scanf("%s",neww);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while(fscanf(fp,"%s",word)!=EOF)
    {
        if(strcmp(word,old)==0)
            fprintf(ft,"%s ",neww);
        else
            fprintf(ft,"%s ",word);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("replacement done\n");
}

/*
Change all the letters in a file to uppercase.
Input: File name: info.txt (content: Hello World!)
Output: HELLO WORLD!
*/
void uppercase_letters()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(toupper(ch),ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file converted to uppercase\n");
}

/*
Change all the letters in a file to lowercase.
Input: File name: info.txt (content: Hello World!)
Output: hello world!
*/
void lowercase_letters()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(tolower(ch),ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file converted to lowercase\n");
}

/*
Capitalize the first letter of each word in a file.
Input: File name: info.txt (content: hello world!)
Output: Hello World!
*/
void capitalize_first_letter()
{
    char filename[100];
    char ch;
    int newword=1;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
        if(newword&&isalpha(ch))
        {
            fputc(toupper(ch),ft);
            newword=0;
        }
        else
        {
            fputc(ch,ft);
            if(ch==' '||ch=='\n'||ch=='\t')
                 newword=1;
        }
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("first letter of each word capitalized\n");
}

/*
Display the lines of a file in reverse order (from last to first).
Input: File name: lines.txt
Output: Shows lines from bottom to top
*/
void display_in_reverse_order()
{
    char filename[100];
    char lines[100][200];
    int count=0,i;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(lines[count],200,fp)!=NULL)
        count++;
    fclose(fp);
    for(i=count-1;i>=0;i--)
        printf("%s",lines[i]);
}

/*
Encrypt (scramble) a file’s content so it can’t be read easily.
Input: File name: secret.txt (content: my password)
Output: File now contains: (garbled/encrypted text)
*/
void encrypt_file()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(ch+3,ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file encrypted\n");
}

/*
Decrypt a scrambled (encrypted) file and make it readable again.
Input: File name: secret.txt (content: encrypted)
Output: File now contains: my password
*/
void decrypt_file()
{
    char filename[100];
    char ch;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    FILE *ft=fopen("temp.txt","w");
    while((ch=fgetc(fp))!=EOF)
    {
        fputc(ch-3,ft);
    }
    fclose(fp);
    fclose(ft);
    remove(filename);
    rename("temp.txt",filename);
    printf("file decrypted\n");
}

/*
Join two files together and save the result in a new file.
Input: File 1: a.txt (AAA)
File 2: b.txt (BBB)
New file: ab.txt
Output: ab.txt content: AAA
BBB
*/
void join_two_files()
{
    char file1[100],file2[100],newfile[100];
    char ch;
    printf("file 1: ");
    scanf("%s",file1);
    printf("file 2: ");
    scanf("%s",file2);
    printf("new file: ");
    scanf("%s",newfile);
    FILE *f1=fopen(file1,"r");
    FILE *f2=fopen(file2,"r");
    FILE *fn=fopen(newfile,"w");
    if(f1==NULL||f2==NULL||fn==NULL)
    {
        printf("file error\n");
        return;
    }
    while((ch=fgetc(f1))!=EOF)
        fputc(ch,fn);
    fputc('\n',fn);
    while((ch=fgetc(f2))!=EOF)
        fputc(ch,fn);
    fclose(f1);
    fclose(f2);
    fclose(fn);
    printf("files joined into '%s'\n",newfile);
}

/*
Take everything from one file and append it to the end of another file.
Input: File1: main.txt (Main)
File2: extra.txt (Extra)
Output: main.txt now contains: Main, Extra
*/
void append_file()
{
    char file1[100],file2[100];
    char ch;
    printf("file1: ");
    scanf("%s",file1);
    printf("file2: ");
    scanf("%s",file2);
    FILE *f1=fopen(file1,"a");
    FILE *f2=fopen(file2,"r");
    if(f1==NULL||f2==NULL)
    {
        printf("file error\n");
        return;
    }
    while((ch=fgetc(f2))!=EOF)
        fputc(ch,f1);
    fclose(f1);
    fclose(f2);
    printf("content appended successfully\n");
}

/*
Check if two files are exactly the same or not.
Input: File1: a.txt, File2: b.txt
Output: Files are identical or Files are different
*/
void compare_files()
{
    char file1[100],file2[100];
    char ch1,ch2;
    int same=1;
    printf("file1: ");
    scanf("%s",file1);
    printf("file2: ");
    scanf("%s",file2);
    FILE *f1=fopen(file1,"r");
    FILE *f2=fopen(file2,"r");
    if(f1==NULL||f2==NULL)
    {
        printf("file error\n");
        return;
    }
    while(1)
    {
        ch1=fgetc(f1);
        ch2=fgetc(f2);
        if(ch1!=ch2)
        {
            same=0;
            break;
        }
        if(ch1==EOF||ch2==EOF)
            break;
    }
    fclose(f1);
    fclose(f2);
    if(same&&ch1==ch2)
        printf("files are identical\n");
    else
        printf("files are different\n");
}

/*
List all the files found inside a directory (folder).
Input: Directory: myfolder/
Output: file1.txt, file2.txt, notes.doc
*/
#include<dirent.h>

void list_all_the_files()
{
    char dirname[100];
    struct dirent *entry;
    printf("directory: ");
    scanf("%s",dirname);
    DIR *dir=opendir(dirname);
    if(dir==NULL)
    {
        printf("cannot open directory\n");
        return;
    }
    while((entry=readdir(dir))!=NULL)
    {
        printf("%s\n",entry->d_name);
    }
    closedir(dir);
}

/*
Find out how big a file is (in bytes).
Input: File name: a.txt
Output: Size: 36 bytes
*/
void file_size()
{
    char filename[100];
    long size;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    fseek(fp,0,SEEK_END);
    size=ftell(fp);
    fclose(fp);
    printf("size: %ld bytes\n",size);
}

/*
Store employee details in a file and update them as needed.
Input: Add new employee: Name: John, Age: 25
Output: Employee added (info saved in file)
*/
void employee_details()
{
    char name[100];
    int age;
    printf("name: ");
    scanf("%s",name);
    printf("age: ");
    scanf("%d",&age);
    FILE *fp=fopen("employees.txt","a");
    if(fp==NULL)
    {
        printf("file error\n");
        return;
    }
    fprintf(fp,"%s %d\n",name,age);
    fclose(fp);
    printf("employee added\n");
}

/*
Log Session a grocery store inventory where you can add, update, or remove items using a file.
Input: Add item: Milk, 2 litres, Rs.40
Output: Inventory file now includes the new item
*/
void grocery_store()
{
    char item[100];
    char quantity[100];
    float price;
    printf("add item: ");
    scanf("%s",item);
    printf("quantity: ");
    scanf("%s",quantity);
    printf("price: ");
    scanf("%f",&price);
    FILE *fp=fopen("inventory.txt","a");
    if(fp==NULL)
    {
        printf("file error\n");
        return;
    }
    fprintf(fp,"%s %s %.2f\n",item,quantity,price);
    fclose(fp);
    printf("inventory updated\n");
}

/*
Add up numbers given as command line arguments and write the answer into a file.
Input: Arguments: 3 4 5, Output file: sum.txt
Output: sum.txt contains: 12
*/
/* void add_numbers(int argc,char *argv[])
{
    int i,sum=0;
    FILE *fp=fopen("sum.txt","w");
    if(fp==NULL)
    {
        printf("file error\n");
        return;
    }
    for(i=1;i<argc;i++)
        sum+=atoi(argv[i]);
    fprintf(fp,"%d",sum);
    fclose(fp);
    printf("sum written to file\n");
} */

/*
Count how many lines in a file end with a semicolon.
Input: File: data.txt (lines, some end with ;)
Output: Lines ending with semicolon: 2
*/
void count_lines_ending_with_semicolon()
{
    char filename[100];
    char line[200];
    int count=0,len;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(line,200,fp)!=NULL)
    {
        len=strlen(line);
        if(len>1&&line[len-2]==';')
            count++;
    }
    fclose(fp);
    printf("lines ending with semicolon: %d\n",count);
}

/*
Count how many empty (blank) lines are in a file.
Input: File: data.txt
Output: Blank lines: 1
*/
void count_blank_lines()
{
    char filename[100];
    char line[200];
    int count=0;
    printf("file name: ");
    scanf("%s",filename);
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        printf("file not found\n");
        return;
    }
    while(fgets(line,200,fp)!=NULL)
    {
        if(line[0]=='\n')
            count++;
    }
    fclose(fp);
    printf("blank lines: %d\n",count);
}

int main()
{
    make_new_file();
    open_existing_file();
    write_to_file();
    read_from_file();
    add_more_lines();
    copy_file();
    list_all_the_files();
    delete_file();
    read_value();
    count_lines();
    count_words_characters();
    show_all_contents();
    remove_line();
    change_a_line();
    replace_word();
    uppercase_letters();
    lowercase_letters();
    capitalize_first_letter();
    display_in_reverse_order();
    encrypt_file();
    decrypt_file();
    join_two_files();
    append_file();
    compare_files();
    file_size();
    employee_details();
    grocery_store();
    // add_numbers();
    count_lines_ending_with_semicolon();
    count_blank_lines();
    return 0;
}