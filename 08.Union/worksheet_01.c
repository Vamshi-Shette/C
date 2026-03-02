#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*
 Union Declaration and Initialization
Declare a union named Data with an int, a float, and a char array of size 20.
Write a program to initialize and print each member, one after the other. Observe and explain the output.
 */
union Data
{
    int i;
    float f;
    char str[20];
};

void union_declaration()
{
    union Data d;
    d.i=10;
    printf("after setting int:\n");
    printf("i = %d\n",d.i);
    printf("f = %f\n",d.f);
    printf("str = %s\n\n",d.str);
    d.f=5.5;
    printf("after setting float:\n");
    printf("i = %d\n",d.i);
    printf("f = %f\n",d.f);
    printf("str = %s\n\n",d.str);
    strcpy(d.str,"hello");
    printf("after setting string:\n");
    printf("i = %d\n",d.i);
    printf("f = %f\n",d.f);
    printf("str = %s\n");
}

/*
 Size of Union
Write a program to declare a union containing an int, a double, and a char.
Print the size of this union using sizeof. Compare the result with the size of a structure having the same members.
 */
union sample_union
{
    int i;
    double d;
    char c;
};

struct sample_struct
{
    int i;
    double d;
    char c;
};

void size_of_union()
{
    union sample_union u;
    struct sample_struct s;
    printf("size of union = %zu\n",sizeof(u));
    printf("size of struct = %zu\n",sizeof(s));
}

/*
 Accessing Union Members
Using the union from exercise 1, assign values to more than one member at a time and print all members.
Observe which value is retained and explain why.
 */
union Data
{
    int i;
    float f;
    char str[20];
};

void accessing_members()
{
    union Data d;
    d.i=25;
    d.f=7.5;          /* overwrites int */
    strcpy(d.str, "abc"); /* overwrites float */
    printf("i = %d\n",d.i);
    printf("f = %f\n",d.f);
    printf("str = %s\n",d.str);
}

/*
 Nested Union
Log Session a union called Number which contains an int and a nested union with a float and a char.
Write code to assign and access values from both the outer and inner union members.
 */

union Number
{
    int i;
    union inner
    {
        float f;
        char c;
    } u;
};

void nested_union()
{
    union Number n;
    /* assign outer member */
    n.i = 50;
    printf("outer int = %d\n", n.i);
    /* assign inner float */
    n.u.f = 3.14f;
    printf("inner float = %.2f\n",n.u.f);
    /* assign inner char */
    n.u.c ='A';
    printf("inner char = %c\n",n.u.c);
    /* print all members */
    printf("outer int now = %d\n",n.i);
    printf("inner float now = %.2f\n",n.u.f);
}

/*
 Anonymous Union
Declare an anonymous union inside a structure.
Initialize and access its members without using a union name.
Demonstrate how this simplifies access in code.
 */
struct sample
{
    int id;
    union
    {
        int i;
        float f;
        char c;
    };   /* anonymous union */
};

void anonymous_union()
{
    struct sample s;
    s.id=1;
    s.i=100;
    printf("id = %d\n",s.id);
    printf("i = %d\n",s.i);
    s.f=5.5f;
    printf("f = %.2f\n",s.f);
    s.c='A';
    printf("c = %c\n",s.c);
}

/*
 Pointer to a Union
Write a program that defines a union called Sample with an int and a float.
Declare a pointer to the union. Assign values using the pointer and print the results.
 */
union Sample
{
    int i;
    float f;
};

void ptr_to_union()
{
    union Sample s;
    union Sample *ptr;
    ptr=&s;
    ptr->i=10;
    printf("int value = %d\n",ptr->i);
    ptr->f=5.5f;
    printf("float value = %.2f\n",ptr->f);
    printf("int value now = %d\n",ptr->i);
}

/*
 Unions in Structures
Log Session a structure Student with a union inside it that can hold either an int roll_number or a char id[10].
Add a member char type to indicate which member is active.
Write functions to initialize and display the data for both types of students.
 */
struct Student
{
    char type;   /* 'R' for roll_number, 'I' for id */
    union
    {
        int roll_number;
        char id[10];
    };
};

void init_roll(struct Student *s, int roll)
{
    if(s==NULL)
        return;
    s->type='R';
    s->roll_number=roll;
}

void init_id(struct Student *s, const char *id_value)
{
    if(s==NULL)
        return;
    s->type='I';
    strcpy(s->id,id_value);
}

void display_student(struct Student *s)
{
    if(s==NULL)
        return;
    if(s->type=='R')
    {
        printf("roll_number=%d\n",s->roll_number);
    }
    else if(s->type=='I')
    {
        printf("id=%s\n",s->id);
    }
    else
    {
        printf("unknown type\n");
    }
}

void unions_in_structure()
{
    struct Student s1,s2;

    init_roll(&s1,101);
    init_id(&s2,"STU123");
    display_student(&s1);
    display_student(&s2);
}

/*
 Structure Inside a Union
Define a union that contains a structure (for example, struct { int x, y; }) and an int.
Write a program to set and access the structure members through the union.
 */

union Data
{
    struct
    {
        int x;
        int y;
    } point;
    int value;
};

void structure_in_union()
{
    union Data d;
    d.point.x=10;
    d.point.y=20;
    printf("x = %d\n",d.point.x);
    printf("y = %d\n",d.point.y);
    printf("value = %d\n",d.value);
}

/*
 Union Array
Declare an array of unions, each holding an int, a float, or a char.
Write a program to assign values of different types to each element and display them. Observe any issues
 */
union Data
{
    int i;
    float f;
    char c;
};

void union_array()
{
    union Data arr[3];
    arr[0].i=100;      /* first element as int */
    arr[1].f=5.5f;     /* second element as float */
    arr[2].c='A';      /* third element as char */
    printf("element 0 as int = %d\n",arr[0].i);
    printf("element 1 as float = %.2f\n",arr[1].f);
    printf("element 2 as char = %c\n\n",arr[2].c);
    /* accessing with wrong member */
    printf("accessing with different members:\n");
    printf("element 0 as float = %.2f\n",arr[0].f);
    printf("element 1 as int = %d\n",arr[1].i);
    printf("element 2 as int = %d\n",arr[2].i);
}

/*
 Use Case – Variant Data Storage
Design a simple employee record system using a structure with a union that can store either salary (float) or hourly wage (float), depending on employee type.
Add code to input and print details for a list of employees.
 */
struct Employee
{
    char name[20];
    char type;   /* 'S' for salary, 'H' for hourly */
    union
    {
        float salary;
        float hourly_wage;
    };
};

void input_employee(struct Employee *e)
{
    if(e==NULL)
        return;
    printf("Enter name: ");
    scanf("%s",e->name);
    printf("Enter type (S for salary, H for hourly): ");
    scanf(" %c",&e->type);
    if(e->type=='S')
    {
        printf("Enter salary: ");
        scanf("%f",&e->salary);
    }
    else if(e->type=='H')
    {
        printf("Enter hourly wage: ");
        scanf("%f",&e->hourly_wage);
    }
}

void print_employee(struct Employee *e)
{
    if(e==NULL)
        return;
    printf("Name: %s\n",e->name);
    if(e->type=='S')
    {
        printf("Salary: %.2f\n",e->salary);
    }
    else if(e->type=='H')
    {
        printf("Hourly Wage: %.2f\n",e->hourly_wage);
    }
    printf("\n");
}

void employee()
{
    int n,i;

    printf("Enter number of employees: ");
    scanf("%d",&n);

    struct Employee emp[n];

    for(i=0;i<n;i++)
    {
        printf("\nEmployee %d\n",i+1);
        input_employee(&emp[i]);
    }

    printf("\nEmployee Details:\n\n");

    for(i=0;i<n;i++)
    {
        print_employee(&emp[i]);
    }
}

int main()
{
	union_declaration();
	size_of_union();
	accessing_members();
	nested_union();
	anonymous_union();
	ptr_to_union();
	unions_in_structure();
	structure_in_union();
	union_array();
	employee();
	return 0;
}
