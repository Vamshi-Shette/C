#include <stdio.h>
#include <string.h>
#include<stdlib.h>
/*
 1. Structure vs Union in Embedded Systems
Goal
Understand how structures and unions differ in terms of memory layout, access, and use in embedded systems, particularly in data interpretation and memory saving.

Activity
Define a structure and a union with three different data types (e.g., char, int, float).
Print the size of each and compare.
Write values to each member and observe the behavior.
Map the union onto a byte buffer and visualize how different types share memory.
Document a scenario where only one data type is valid at a time (e.g., packet command structure).
Tip: Use sizeof() and printf() to track memory usage and value overlap.
 */

struct data_struct
{
    char c;
    int i;
    float f;
};

union data_union
{
    char c;
    int i;
    float f;
};

union packet_data
{
    unsigned char cmd;
    int value;
    float measurement;
};

void struct_union()
{
    struct data_struct s;
    union data_union u;
    printf("size of struct = %zu\n",sizeof(s));
    printf("size of union  = %zu\n\n",sizeof(u));
    s.c='A';
    s.i=100;
    s.f=3.14f;
    printf("struct values:\n");
    printf("c = %c\n",s.c);
    printf("i = %d\n",s.i);
    printf("f = %.2f\n\n",s.f);
    u.c='A';
    printf("union after writing char:\n");
    printf("c = %c\n",u.c);
    printf("i = %d\n",u.i);
    printf("f = %.2f\n\n",u.f);
    u.i=100;
    printf("union after writing int:\n");
    printf("c = %c\n",u.c);
    printf("i = %d\n",u.i);
    printf("f = %.2f\n\n",u.f);
    u.f=3.14f;
    printf("union after writing float:\n");
    printf("c = %c\n",u.c);
    printf("i = %d\n",u.i);
    printf("f = %.2f\n\n",u.f);
    unsigned char buffer[sizeof(union data_union)];
    memcpy(buffer,&u,sizeof(u));
    printf("raw bytes of union:\n");
    for (size_t idx=0;idx<sizeof(u);idx++)
        printf("byte[%zu] = 0x%02x\n",idx,buffer[idx]);
    union packet_data packet;
    packet.cmd=0x01;
    printf("\npacket cmd = 0x%02x\n",packet.cmd);
    packet.value=12345;
    printf("packet value = %d\n",packet.value);
    packet.measurement=25.5f;
    printf("packet measurement = %.2f\n",packet.measurement);
}

/*
 2. Bit-fields in Structures
Goal
Learn to define and use bit-fields to manage individual bits for hardware register simulation.

Activity
Log Session a structure using bit-fields to represent an 8-bit status register.
Assign values to specific flags.
Log Session a mock register with error, ready, and mode bits.
Write code to toggle specific flags without using bitwise operators.
Reflect on how compilers handle ordering and alignment of bit-fields.
 */

struct status_register
{
    unsigned int ready:1;
    unsigned int error:1;
    unsigned int mode:2;
    unsigned int reserved:4;
};

void print_status(struct status_register reg)
{
    printf("ready=%u error=%u mode=%u reserved=%u\n",reg.ready,reg.error,reg.mode,reg.reserved);
}

void bitfield()
{
    struct status_register reg={0};
    printf("size of status_register = %zu\n\n", sizeof(reg));
    reg.ready=1;
    reg.error=0;
    reg.mode=2;
    printf("after assignment:\n");
    print_status(reg);
    reg.error=1;
    reg.ready=0;
    printf("after toggling flags:\n");
    print_status(reg);
    reg.mode=(reg.mode==0)?1:0;
    printf("after changing mode:\n");
    print_status(reg);
}

/*
 3. Structure Padding, Alignment, and Packing
Goal
Understand how padding affects structure size and how to control layout using packing directives.

Activity
Log Session a structure with mixed data types (char, int, short).
Check the size and member offsets using sizeof() and pointer arithmetic.
Reorder members to reduce padding and observe the change in size.
Use #pragma pack(1) and compare memory layout.
Simulate a communication packet where field alignment matters.
 */
struct mixed1
{
    char a;
    int b;
    short c;
};
struct mixed2
{
    int b;
    short c;
    char a;
};
#pragma pack(1)
struct mixed3
{
    char a;
    int b;
    short c;
};
#pragma pack()
void check_mixed1()
{
    struct mixed1 x;
    printf("mixed1 size = %zu\n",sizeof(x));
    printf("a offset = %zu\n",(size_t)((char*)&x.a-(char*)&x));
    printf("b offset = %zu\n",(size_t)((char*)&x.b-(char*)&x));
    printf("c offset = %zu\n\n",(size_t)((char*)&x.c-(char*)&x));
}
void check_mixed2()
{
    struct mixed2 x;
    printf("mixed2 size = %zu\n",sizeof(x));
    printf("b offset = %zu\n",(size_t)((char*)&x.b-(char*)&x));
    printf("c offset = %zu\n",(size_t)((char*)&x.c-(char*)&x));
    printf("a offset = %zu\n\n",(size_t)((char*)&x.a-(char*)&x));
}

void check_mixed3()
{
    struct mixed3 x;
    printf("mixed3 (packed) size = %zu\n", sizeof(x));
    printf("a offset = %zu\n",(size_t)((char*)&x.a-(char*)&x));
    printf("b offset = %zu\n",(size_t)((char*)&x.b-(char*)&x));
    printf("c offset = %zu\n\n",(size_t)((char*)&x.c-(char*)&x));
}
struct packet
{
    unsigned char header;
    unsigned short id;
    unsigned int length;
    unsigned char checksum;
};
void check_packet(void)
{
    struct packet p;
    printf("packet size = %zu\n",sizeof(p));
    printf("header offset = %zu\n",(size_t)((char*)&p.header-(char*)&p));
    printf("id offset = %zu\n",(size_t)((char*)&p.id-(char*)&p));
    printf("length offset = %zu\n",(size_t)((char*)&p.length-(char*)&p));
    printf("checksum offset = %zu\n\n",(size_t)((char*)&p.checksum-(char*)&p));
    p.header=1;
    p.id=100;
    p.length=500;
    p.checksum=9;
    printf("packet values: %u %u %u %u\n",
           p.header,p.id,p.length,p.checksum);
}
void struct_padding_alignment()
{
    check_mixed1();
    check_mixed2();
    check_mixed3();
    check_packet();
}

/*
 4. Function Pointers in Structures
Goal
Learn how to include and use function pointers inside structures for callback mechanisms and dynamic behavior in embedded systems.

Activity
Define a structure containing function pointers.
Initialize it with different functions and invoke them.
Use this setup to simulate a hardware driver interface with different behavior implementations.
Demonstrate dynamic assignment and execution of function pointers based on a condition or input.
Tip: Use typedef for cleaner function pointer declarations.
 */
/* function pointer typedef */
typedef void (*init_func)();
typedef int  (*read_func)();
typedef void (*write_func)(int);
/* driver structure */
struct driver
{
    init_func  init;
    read_func  read;
    write_func write;
};
/* driver 1 implementation */
void driver1_init()
{
    printf("driver1 init\n");
}
int driver1_read()
{
    printf("driver1 read\n");
    return 10;
}
void driver1_write(int value)
{
    printf("driver1 write: %d\n",value);
}
/* driver 2 implementation */
void driver2_init()
{
    printf("driver2 init\n");
}
int driver2_read()
{
    printf("driver2 read\n");
    return 20;
}
void driver2_write(int value)
{
    printf("driver2 write: %d\n",value);
}
void driver_interface()
{
    struct driver drv;
    int choice;
    printf("select driver (1 or 2): ");
    scanf("%d",&choice);
    if (choice==1)
    {
        drv.init=driver1_init;
        drv.read=driver1_read;
        drv.write=driver1_write;
    }
    else
    {
        drv.init=driver2_init;
        drv.read=driver2_read;
        drv.write=driver2_write;
    }
    drv.init();
    int data=drv.read();
    drv.write(data);
}

/*
 5. Dynamic Memory with Structures
Goal
Understand how to allocate and free memory dynamically for structures, including use cases like linked lists and memory pools in embedded systems.

Activity
Use malloc() to allocate a structure dynamically and assign values to members.
Build a simple singly linked list using structure and pointers.
Implement a queue using structure-based nodes.
Write a memory pool manager that uses an array of structures and a free list.
Tip: Always check malloc() return and release memory using free() after usage.
 */
/* basic structure */
struct student
{
    int id;
    float marks;
};

/* singly linked list node */
struct node
{
    int data;
    struct node *next;
};

/* queue structure */
struct queue
{
    struct node *front;
    struct node *rear;
};

/* memory pool node */
struct pool_node
{
    int used;
    int value;
    struct pool_node *next;
};

#define POOL_SIZE 5
struct pool_node pool[POOL_SIZE];
struct pool_node *free_list=NULL;

/* dynamic allocation of structure */
void dynamic_struct_demo()
{
    struct student *s=(struct student *)malloc(sizeof(struct student));
    if (s==NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    s->id=1;
    s->marks=88.5;
    printf("student id=%d marks=%.2f\n",s->id,s->marks);
    free(s);
}

/* linked list */
void linked_list_demo()
{
    struct node *head=NULL;
    struct node *temp;
    int i;
    for (i=1;i<=3;i++)
    {
        temp=(struct node *)malloc(sizeof(struct node));
        if (temp==NULL)
            return;
        temp->data=i*10;
        temp->next=head;
        head=temp;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("list value=%d\n",temp->data);
        temp=temp->next;
    }
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}

/* queue functions */
void init_queue(struct queue *q)
{
    q->front=NULL;
    q->rear=NULL;
}

void enqueue(struct queue *q, int value)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
        return;
    temp->data=value;
    temp->next=NULL;
    if (q->rear==NULL)
    {
        q->front=q->rear=temp;
    }
    else
    {
        q->rear->next=temp;
        q->rear=temp;
    }
}

void dequeue(struct queue *q)
{
    if (q->front==NULL)
        return;
    struct node *temp=q->front;
    printf("dequeued=%d\n",temp->data);
    q->front=temp->next;
    if (q->front==NULL)
        q->rear=NULL;
    free(temp);
}

void queue_demo()
{
    struct queue q;
    init_queue(&q);
    enqueue(&q,5);
    enqueue(&q,10);
    enqueue(&q,15);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
}

/* memory pool functions */
void init_pool()
{
    int i;
    for(i=0;i<POOL_SIZE;i++)
    {
        pool[i].used=0;
        pool[i].next=free_list;
        free_list=&pool[i];
    }
}

struct pool_node* pool_alloc()
{
    if(free_list==NULL)
        return NULL;

    struct pool_node *temp=free_list;
    free_list=free_list->next;
    temp->used=1;
    return temp;
}

void pool_free(struct pool_node *node)
{
    node->used=0;
    node->next=free_list;
    free_list=node;
}

void memory_pool_demo()
{
    init_pool();
    struct pool_node *a=pool_alloc();
    struct pool_node *b=pool_alloc();
    if(a) 
        a->value=100;
    if(b)  
        b->value=200;
    if(a) 
        printf("pool value a=%d\n",a->value);
    if(b) 
        printf("pool value b=%d\n",b->value);
    if(a) 
        pool_free(a);
    if(b) 
        pool_free(b);
}

void dynamic_memory()
{
    dynamic_struct_demo();
    linked_list_demo();
    queue_demo();
    memory_pool_demo();
}

/*
 6. Structure Pointers and Memory Access
Goal
Understand the use of pointers to structures for efficient memory access and how to use the arrow operator for member access.

Activity
Declare a pointer to a structure and allocate memory using malloc().
Use arrow operator to assign and print structure member values.
Simulate memory-mapped peripheral access using structure pointers.
Illustrate how structure pointers simplify code in register programming.
Tip: Always initialize structure pointers and check for NULL before dereferencing.
*/
struct device
{
    int id;
    float value;
};

struct peripheral
{
    unsigned int control;
    unsigned int status;
    unsigned int data;
};

void struct_pointer()
{
    struct device *ptr;
    ptr=(struct device *)malloc(sizeof(struct device));
    if(ptr==NULL)
    {
        printf("memory allocation failed\n");
        return;
    }
    ptr->id =101;
    ptr->value =45.5;
    printf("device id=%d\n",ptr->id);
    printf("device value=%.2f\n",ptr->value);
    free(ptr);
}

void peripheral()
{
    struct peripheral reg;
    struct peripheral *p=&reg;
    p->control=1;
    p->status=0;
    p->data=255;
    printf("control=%u\n",p->control);
    printf("status=%u\n",p->status);
    printf("data=%u\n",p->data);
    p->status=1;
    printf("updated status=%u\n",p->status);
}

void pointer()
{
    struct_pointer();
    peripheral();
}

/*
 8. Structures and Functions
Goal
Learn how to pass structures to and return structures from functions and understand the trade-offs between pass-by-value and pass-by-reference.

Activity
Write a function that takes a structure as a value argument and modifies it.
Write a function that takes a pointer to structure and modifies it.
Return a structure from a function and print its values.
Measure memory usage and performance difference between pass-by-value and reference.
Tip: Prefer passing by pointer in embedded systems for performance and memory efficiency.
 */
struct data
{
    int a;
    int b;
};

/* pass by value */
void change_value(struct data x)
{
    x.a=10;
    x.b=20;
}

/* pass by reference */
void change_reference(struct data *x)
{
    if (x==NULL)
        return;
    x->a=30;
    x->b=40;
}

/* return structure */
struct data create_data(int x,int y)
{
    struct data temp;
    temp.a=x;
    temp.b=y;
    return temp;
}

void structure_function()
{
    struct data d;
    d.a=1;
    d.b=2;
    printf("before change_value: %d %d\n",d.a,d.b);
    change_value(d);
    printf("after change_value: %d %d\n",d.a,d.b);
    printf("before change_reference: %d %d\n",d.a,d.b);
    change_reference(&d);
    printf("after change_reference: %d %d\n",d.a,d.b);
    struct data d2=create_data(5,6);
    printf("returned struct: %d %d\n",d2.a,d2.b);
    printf("size of struct = %zu\n",sizeof(struct data));
}

/*
 9. Introduction to Structures in C
Goal
Grasp the basic concept of structures in C, including their need, syntax, and difference from arrays and unions.

Activity
Define a simple structure with multiple data types.
Compare it with an array and a union with similar members.
Initialize the structure in different ways and print values.
Analyze why structures are preferred in peripheral register grouping.
Tip: Structures allow logically grouping different data types under one name.
 */
/* structure */
struct student
{
    int roll;
    float marks;
    char grade;
};

/* union */
union student_union
{
    int roll;
    float marks;
    char grade;
};

void struct_union()
{
    struct student s={1,85.5,'A'};
    int arr[3]={10,20,30};
    union student_union u;
    u.roll=5;
    printf("structure values:\n");
    printf("%d %.2f %c\n\n",s.roll,s.marks,s.grade);
    printf("array values:\n");
    printf("%d %d %d\n\n", arr[0],arr[1],arr[2]);
    printf("union values after setting roll:\n");
    printf("roll = %d\n",u.roll);
    printf("marks = %.2f\n",u.marks);
    printf("grade = %c\n\n",u.grade);
    printf("size of structure = %zu\n",sizeof(struct student));
    printf("size of union = %zu\n",sizeof(union student_union));
    printf("size of array = %zu\n",sizeof(arr));
}

/*
 10. Structure Declaration and Initialization
Goal
Understand the proper way to declare and initialize structures using multiple techniques and best practices.

Activity
Declare structure variables globally, locally, and statically.
Use designated initializers for clarity.
Use typedef to create aliases for complex structures.
Discuss structure initialization in embedded register mapping.
Tip: Static initialization is preferred for compile-time register definitions.
 */
/* typedef structure */
typedef struct
{
    int x;
    int y;
} point;
/* global variable */
struct data
{
    int a;
    int b;
};

struct data global_var={1,2};

/* static global variable */
static struct data static_global_var={3, 4};

void struct_init()
{
    /* local variable */
    struct data local_var={5, 6};
    /* designated initializer */
    struct data designated_var = {.b = 20, .a = 10};

    /* using typedef */
    point p1 = {7, 8};
    point p2 = {.y = 15, .x = 12};

    /* static local variable */
    static struct data static_local_var={9,10};

    printf("global_var: %d %d\n", global_var.a, global_var.b);
    printf("static_global_var: %d %d\n", static_global_var.a, static_global_var.b);

    printf("local_var: %d %d\n", local_var.a, local_var.b);
    printf("designated_var: %d %d\n", designated_var.a, designated_var.b);

    printf("p1: %d %d\n", p1.x, p1.y);
    printf("p2: %d %d\n", p2.x, p2.y);

    printf("static_local_var: %d %d\n", static_local_var.a, static_local_var.b);

    printf("size of struct data = %zu\n", sizeof(struct data));
    printf("size of point = %zu\n", sizeof(point));
}

/*
 11. Memory Layout of Structures
Goal
Analyze the internal memory layout of structures, including padding, alignment, and impact on memory optimization.

Activity
Define a structure and use sizeof() to observe unexpected sizes.
Use different data type orderings and compare structure size.
Simulate structure layout for peripheral memory mapping.
Apply structure packing using #pragma and compare memory efficiency.
 */
/* structure 1 */
struct s1
{
    char a;
    int b;
    char c;
};

/* structure 2 (different order) */
struct s2
{
    int b;
    char a;
    char c;
};

/* packed structure */
#pragma pack(1)
struct s3
{
    char a;
    int b;
    char c;
};
void memory_layout()
{
    struct s1 x1;
    struct s2 x2;
    struct s3 x3;

    printf("size of s1 = %zu\n", sizeof(x1));
    printf("size of s2 = %zu\n", sizeof(x2));
    printf("size of s3 (packed) = %zu\n\n", sizeof(x3));

    printf("offsets in s1:\n");
    printf("a = %zu\n", (size_t)((char*)&x1.a - (char*)&x1));
    printf("b = %zu\n", (size_t)((char*)&x1.b - (char*)&x1));
    printf("c = %zu\n\n", (size_t)((char*)&x1.c - (char*)&x1));

    printf("offsets in s2:\n");
    printf("b = %zu\n",(size_t)((char*)&x2.b - (char*)&x2));
    printf("a = %zu\n",(size_t)((char*)&x2.a - (char*)&x2));
    printf("c = %zu\n",(size_t)((char*)&x2.c - (char*)&x2));
}

int main()
{
	struct_union();
	bitfield();
	struct_padding_alignment();
	driver_interface();
	dynamic_memory();	
	pointer();
	structure_function();
	struct_union();
	struct_init();
	memory_layout();
	return 0;
}
