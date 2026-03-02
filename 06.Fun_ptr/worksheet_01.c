#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
/*
 Mathematical Operations with Function Pointers
Log Session four simple mathematical functions (add, subtract, multiply, divide) that accept two integer arguments and return an integer.
Use a single function pointer to dynamically select and execute one of these operations based on user input.
 */
int add(int a,int b)
{
    return a+b;
}

int subtract(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

int divide(int a,int b)
{
    if (b==0)
    {
        printf("Error: Division by zero!\n");
        return 0;
    }
    return a/b;
}
void mathematic_operations()
{
	 int a,b,choice;
    int (*operation)(int,int);   // function pointer
    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);
    printf("Choose operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("4. Divide\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            operation=add;
            break;
        case 2:
            operation=subtract;
            break;
        case 3:
            operation=multiply;
            break;
        case 4:
            operation=divide;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    int result=operation(a,b);   // Call selected function
    printf("Result = %d\n",result);
	return;
}

/*
 Callback Function Array Processing
Define a function processArray that accepts an integer array, its size, and a callback function as arguments.
Implement callback functions (increment, doubleValue) that modify array elements in different ways.
Demonstrate invoking processArray with different callback functions.
 */

void processArray(int *arr,size_t size,void (*callback)(int *))
{
    for (size_t i=0;i<size;i++)
    {
        callback(&arr[i]);
    }
}

void increment(int *value)
{
    (*value)++;
}

void doubleValue(int *value)
{
    (*value)*=2;
}
void callback_function()
{
    int data1[]={1,2,3,4,5};
    int data2[]={10,20,30,40,50};
    processArray(data1,5,increment);
    processArray(data2,5,doubleValue);
}

/*
 Menu-driven Calculator Using Function Pointers
Implement mathematical operations (power, modulo, squareRoot) as separate functions.
Store these operation functions in a function pointer array.
Provide a user-interactive menu to select and execute the chosen operation on input values.
 */
int power(int a,int b)
{
    int result=1;
    for (int i=0;i<b;i++)
        result *=a;
    return result;
}

int modulo(int a,int b)
{
    if (b==0)
    {
        printf("Error: Division by zero\n");
        return 0;
    }
    return a%b;
}

int squareRoot(int a,int unused)
{
    if (a<0)
    {
        printf("Error: Negative input\n");
        return 0;
    }
    return (int)sqrt(a);
}
void menu_driven_calculator()
{
    int choice;
    int a,b;
    int (*operations[])(int,int) = {power,modulo,squareRoot};
    printf("Menu:\n");
    printf("1. Power (a^b)\n");
    printf("2. Modulo (a %% b)\n");
    printf("3. Square Root (sqrt(a))\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    if (choice==1 || choice==2)
    {
        printf("Enter two integers: ");
        scanf("%d %d",&a,&b);
    }
    else if (choice==3)
    {
        printf("Enter one integer: ");
        scanf("%d",&a);
        b=0;
    }
    else
    {
        printf("Invalid choice\n");
        return;
    }
    int result=operations[choice-1](a,b);
    printf("Result=%d\n",result);
}

/*
 State Machine Implementation
Implement a basic state machine (initState, runState, stopState, errorState) with each state represented by a separate function.
Use function pointers to transition between states based on user input or internal conditions.
Demonstrate state transitions clearly in your program’s output.
 */

typedef void (*StateFunc)(void);
void initState();
void runState();
void stopState();
void errorState();

static StateFunc currentState;

void initState()
{
    int input;
    printf("\n--- INIT STATE ---\n");
    printf("1 -> Run\n");
    printf("2 -> Error\n");
    printf("Enter choice: ");
    scanf("%d",&input);
    if (input==1)
        currentState=runState;
    else if (input==2)
        currentState=errorState;
    else
        currentState=initState;
}

void runState()
{
    int input;
    printf("\n--- RUN STATE ---\n");
    printf("1 -> Stop\n");
    printf("2 -> Error\n");
    printf("Enter choice: ");
    scanf("%d",&input);
    if (input==1)
        currentState=stopState;
    else if (input==2)
        currentState=errorState;
    else
        currentState=runState;
}

void stopState()
{
    int input;
    printf("\n--- STOP STATE ---\n");
    printf("1 -> Init\n");
    printf("2 -> Error\n");
    printf("Enter choice: ");
    scanf("%d",&input);
    if (input==1)
        currentState=initState;
    else if (input==2)
        currentState=errorState;
    else
        currentState=stopState;
    return;
}
void errorState()
{
    int input;
    printf("\n--- ERROR STATE ---\n");
    printf("1 -> Init (Reset)\n");
    printf("Enter choice: ");
    scanf("%d",&input);
    if (input==1)
        currentState=initState;
    else
        currentState=errorState;
    return;
}
void state_machine()
{
    currentState=initState;
    while (1)
    {
        currentState();
    }
    return;
}

/*
 Generic Find Function
Implement a generic function find that takes an integer array, its size, and a function pointer as a condition.
Log Session condition functions (e.g., isEven, isPositive, isPrime).
Use find to identify and print the first element matching the provided condition.
 */

int isEven(int value)
{
    return value%2==0;
}

int isPositive(int value)
{
    return value>0;
}

int isPrime(int value)
{
    if (value<=1)
        return 0;

    for (int i=2;i*i<=value;i++)
    {
        if (value%i==0)
            return 0;
    }
    return 1;
}

int find(int *arr,int size,int (*condition)(int))
{
    for (int i=0;i<size;i++)
    {
        if(condition(arr[i]))
            return arr[i];
    }
    return -1;  
}
void generic_find()
{
    int data[]={-3,-1,4,9,11,15};
    int size=sizeof(data)/sizeof(data[0]);
    int result;
    result=find(data,size,isEven);
    if (result!=-1)
        printf("First Even:%d\n",result);

    result=find(data,size,isPositive);
    if (result!=-1)
        printf("First Positive: %d\n",result);

    result=find(data,size,isPrime);
    if (result!=-1)
        printf("First Prime: %d\n",result);
}
/*
 Event Handling System
Define events such as buttonPressEvent, sensorTriggerEvent.
Implement handler functions for these events.
Log Session an array of function pointers mapping each event to its corresponding handler function.
Simulate event triggers, calling the appropriate handler through function pointers.
 */
typedef enum
{
    BUTTON_PRESS_EVENT,
    SENSOR_TRIGGER_EVENT,
    EVENT_COUNT
} EventType;

void handleButtonPress(void)
{
    printf("Button Press Event Handled\n");
}

void handleSensorTrigger(void)
{
    printf("Sensor Trigger Event Handled\n");
}

void (*eventHandlers[EVENT_COUNT])(void) =
{
    handleButtonPress,
    handleSensorTrigger
};

void trigger_event(EventType event)
{
    if(event>=0 && event<EVENT_COUNT)
        eventHandlers[event]();
    else
        printf("Invalid Event\n");
}
void event_handling()
{
    trigger_event(BUTTON_PRESS_EVENT);
    trigger_event(SENSOR_TRIGGER_EVENT);
}

/*
 Function Pointer as Return Value
Implement multiple arithmetic functions (add, subtract, multiply).
Write a function getOperation(char *name) that takes a string (like "add" or "subtract") and returns a pointer to the corresponding function.
Use this return value to perform the selected operation on user-provided numbers.
 */
int add(int a,int b)
{
    return a+b;
}

int subtract(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

int (*getOperation(const char *name))(int, int)
{
    if (strcmp(name, "add") == 0)
        return add;
    else if (strcmp(name, "subtract")==0)
        return subtract;
    else if (strcmp(name, "multiply")==0)
        return multiply;
    else
        return NULL;
}

void run_operation()
{
    char opName[20];
    int a,b;

    printf("Enter operation (add, subtract, multiply): ");
    scanf("%19s",opName);

    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);

    int (*operation)(int, int)=getOperation(opName);

    if (operation!=NULL)
    {
        int result=operation(a,b);
        printf("Result = %d\n",result);
    }
    else
    {
        printf("Invalid operation\n");
    }
}

/*
 Function Pointer Array for String Operations
Implement several string manipulation functions (reverseString, toUpperCase, countVowels), each accepting a string argument.
Store these functions in an array of function pointers.
Prompt the user to choose an operation and apply it to their input string using the selected function pointer.
 */

void reverseString(char *str)
{
    int len=strlen(str);
    for (int i=0;i<len/2;i++)
    {
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
    printf("Reversed String: %s\n",str);
}

void toUpperCase(char *str)
{
    for (int i=0;str[i]!='\0';i++)
        str[i]=toupper((unsigned char)str[i]);

    printf("Uppercase String: %s\n", str);
}

void countVowels(char *str)
{
    int count=0;
    for (int i=0;str[i]!='\0';i++)
    {
        char ch=tolower((unsigned char)str[i]);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            count++;
    }
    printf("Vowel Count:%d\n",count);
}

void string_operations()
{
    char input[100];
    int choice;

    void (*operations[])(char *) = {
        reverseString,
        toUpperCase,
        countVowels
    };

    printf("Enter a string: ");
    scanf(" %[^\n]s",input);

    printf("Choose operation:\n");
    printf("1. Reverse String\n");
    printf("2. Convert to Uppercase\n");
    printf("3. Count Vowels\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    if (choice>=1 && choice<=3)
        operations[choice-1](input);
    else
        printf("Invalid choice\n");
}

/*
 Interrupt Handler Simulation
Log Session several interrupt handler functions (e.g., timerInterrupt, keyboardInterrupt, errorInterrupt).
Map these interrupt handlers using an array of function pointers.
Simulate interrupts by invoking appropriate interrupt handlers using their pointers based on interrupt numbers entered by the user.
 */
typedef void (*InterruptHandler)(void);

void timerInterrupt(void)
{
    printf("Timer Interrupt Handled\n");
}

void keyboardInterrupt(void)
{
    printf("Keyboard Interrupt Handled\n");
}

void errorInterrupt(void)
{
    printf("Error Interrupt Handled\n");
}

#define INTERRUPT_COUNT 3

InterruptHandler interruptTable[INTERRUPT_COUNT] =
{
    timerInterrupt,
    keyboardInterrupt,
    errorInterrupt
};

void triggerInterrupt(int interruptNumber)
{
    if (interruptNumber>=0 && interruptNumber<INTERRUPT_COUNT)
        interruptTable[interruptNumber]();
    else
        printf("Invalid Interrupt Number\n");
}

void interrupt_handler()
{
    int irq;
    printf("Enter interrupt number (0:Timer, 1:Keyboard, 2:Error): ");
    scanf("%d",&irq);
    triggerInterrupt(irq);
}
/*
 Recursive Function Pointer
Implement a recursive function (such as factorial or fibonacci) using a function pointer variable instead of directly calling the function by name.
Show that the recursion works correctly using only the pointer.
 */
int (*factPtr)(int);

int factorial(int n)
{
    if (n<=1)
        return 1;

    return n*factPtr(n-1);
}

void recursive_fn_ptr()
{
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    factPtr=factorial;
    int result=factPtr(n);
    printf("Factorial of %d = %d\n",n,result);
}
/*
 Array of Function Pointers in a Structure
Define a structure (e.g., Calculator) that contains an array of function pointers for operations (add, subtract, multiply).
Instantiate the structure and use it to call the various operations on input values, demonstrating how the structure can perform different calculations.
 */
typedef int (*Operation)(int,int);

int add(int a,int b)
{
    return a+b;
}

int subtract(int a,int b)
{
    return a-b;
}

int multiply(int a,int b)
{
    return a*b;
}

typedef struct
{
    Operation ops[3];
} Calculator;

void fn_ptr_structure()
{
    Calculator calc={{ add,subtract,multiply}};
    int a,b,choice;
    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);
    printf("Choose operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("Enter choice: ");
    scanf("%d",&choice);
    if (choice>=1 && choice<=3)
    {
        int result=calc.ops[choice - 1](a, b);
        printf("Result = %d\n",result);
    }
    else
    {
        printf("Invalid choice\n");
    }
}
/*
 Chained Function Pointer Calls
Write several functions that transform an integer (e.g., doubleValue, increment, square).
Log Session an array of function pointers representing a pipeline of operations.
Pass a number through the pipeline by applying each function in sequence, using the array of pointers.
 */
int double_value(int x)
{
    return x*2;
}

int increment(int x)
{
    return x+1;
}

int square(int x)
{
    return x*x;
}

typedef int (*transform_fn)(int);

transform_fn pipeline[]={
    double_value,
    increment,
    square
};

#define PIPELINE_SIZE (sizeof(pipeline)/sizeof(pipeline[0]))

void chained_fun_ptr()
{
    int value;

    printf("enter an integer: ");
    scanf("%d",&value);

    for (int i=0;i<PIPELINE_SIZE;i++)
    {
        value=pipeline[i](value);
    }

    printf("final result = %d\n",value);
}

/*
 Passing Function Pointers to Standard Algorithms
Define a structure representing a record (e.g., struct Person { char name[30]; int age; }).
Implement multiple comparison functions for sorting (e.g., by name, by age).
Use the C standard library function qsort, passing these comparison functions as function pointers to sort an array of records in different ways.
 */

/*
 Multi-dimensional Function Pointer Array
Define arithmetic functions for both int and float types (e.g., intAdd, floatAdd).
Organize the function pointers in a two-dimensional array:
First dimension: operation type (arithmetic, bitwise)
Second dimension: data type (int, float)
Demonstrate calling the correct function based on selected type and operation.
 */
int int_add(int a,int b)
{
    return a+b;
}

int int_sub(int a,int b)
{
    return a-b;
}

float float_add(float a,float b)
{
    return a+b;
}

float float_sub(float a,float b)
{
    return a-b;
}

int int_and(int a,int b)
{
    return a&b;
}

int int_or(int a,int b)
{
    return a|b;
}

float float_and(float a,float b)
{
    return 0.0f;
}

float float_or(float a,float b)
{
    return 0.0f;
}

typedef int (*int_op)(int, int);
typedef float (*float_op)(float, float);

/* Two-dimensional function pointer arrays 
 [operation][type]
 operation: 0 = arithmetic, 1 = bitwise 
 type:      0 = int,        1 = float   */

int_op int_operations[2][2] = {
    { int_add,int_sub },   /* arithmetic */
    { int_and,int_or }     /* bitwise    */
};
float_op float_operations[2][2] = {
    { float_add,float_sub }, /* arithmetic */
    { float_and,float_or }   /* bitwise    */
};
void multi_dim_fp()
{
    int op_type,data_type,op_choice;

    printf("Select operation type (0: arithmetic, 1: bitwise): ");
    scanf("%d",&op_type);

    printf("Select data type (0: int, 1: float): ");
    scanf("%d",&data_type);

    printf("Select operation (0: first op, 1: second op): ");
    scanf("%d",&op_choice);

    if (data_type==0)
    {
        int a,b;
        printf("Enter two integers: ");
        scanf("%d %d",&a,&b);

        int result = int_operations[op_type][op_choice](a, b);
        printf("Result = %d\n",result);
    }
    else
    {
        float a,b;
        printf("Enter two floats: ");
        scanf("%f %f", &a, &b);

        float result=float_operations[op_type][op_choice](a, b);
        printf("Result = %.2f\n",result);
    }
}

/*
 Replace Switch-Case with Function Pointer Table
Simulate a command-based application where each command is represented by a number.
Instead of using a large switch-case block to handle commands, create a function pointer table.
Use the input command number as an index to call the corresponding handler function via the function pointer table.
 */
void cmd_init(void)
{
    printf("init command executed\n");
}

void cmd_start(void)
{
    printf("start command executed\n");
}

void cmd_stop(void)
{
    printf("stop command executed\n");
}

void cmd_status(void)
{
    printf("status command executed\n");
}

typedef void (*cmd_handler)(void);

#define CMD_COUNT 4

cmd_handler cmd_table[CMD_COUNT]={
    cmd_init,
    cmd_start,
    cmd_stop,
    cmd_status
};

void fun_ptr_table()
{
    int cmd;

    printf("enter command number (0:init, 1:start, 2:stop, 3:status): ");
    scanf("%d",&cmd);

    if (cmd>=0 && cmd<CMD_COUNT)
        cmd_table[cmd]();
    else
        printf("invalid command\n");
}

int main()
{
	mathematic_operations();
	callback_function();
	menu_driven_calculator();
	event_handling();
	state_machine();
	string_operations();
	run_operation();
	generic_find();
	interrupt_handler();
	recursive_fn_ptr();
	fn_ptr_structure();
	chained_fun_ptr();
	multi_dim_fp();
	fun_ptr_table();
	return 0;
}
