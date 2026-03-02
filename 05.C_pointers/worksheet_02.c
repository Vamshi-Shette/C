#include<stdio.h>
#include<string.h>
#include<stdint.h>
/*
 1. Pointer and Array Behavior
Goal: Analyze how pointers and arrays differ in memory referencing and sizeof operations in embedded systems.
Activity:
Print the values of the array name, the pointer, and the address of the array.
Use sizeof() on the array and pointer and observe differences.
Access the elements via both array indexing and pointer arithmetic, and print them.
 */
void ptr_arrays()
{
	int arr[5] = {10, 20, 30, 40, 50};
	int *ptr=arr;
	printf(" arr:%u\n, ptr:%u\n, &arr:%u\n",arr,ptr,&arr);
	printf("size of arr:%d ptr:%d\n",sizeof(arr),sizeof(ptr));
	for(int i=0;i<5;i++)
	{
		printf("through index:%d, ptr:%d\n",arr[i],*(ptr+i));
	}
	return;
}

/*
 2. Accessing Multi-Dimensional Arrays with Pointers
Goal: Implement pointer arithmetic to traverse a 2D sensor data array efficiently without nested loops.
Use a single loop and pointer arithmetic to iterate over the matrix elements.
Print each sensor value accessed via the pointer.
*/
void multi_dimensional_array()
{
	int sensors[3][3] = {
				  {100, 101, 102},
 			       	 {110, 111, 112},
				  {120, 121, 122}
				};
	int *p = &sensors[0][0];
	size=sizeof(sensors)/sizeof(sensors[0][0]);
	for(int i=0;i<size;i++)
		printf("%d ",*(p+i));
	return;
}

/*
 3. Working with Const and Volatile Pointers
Goal: Demonstrate how const and volatile qualifiers affect pointer behavior in hardware register access.
Define a dummy hardware register address using #define
#define REG_BASE 0x40000000
Declare pointers with different qualifiers
volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;
const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;
Attempt to write to and read from each pointer and note compiler behavior
 */

#define REG_BASE 0x40000000

void const_volatile_ptrs()
{
	volatile uint32_t *reg_modifiable = (uint32_t *)REG_BASE;
	*reg_modifiable=10;
	printf("%d\n",*reg_modifiable);

	const uint32_t *reg_readonly = (const uint32_t *)REG_BASE;
	printf("%d\n",*reg_readonly);
	//*reg_readonly=20; as it points to a readonly section
	
	const volatile uint32_t *reg_const_volatile = (const volatile uint32_t *)REG_BASE;
	printf("%d\n",*reg_const_volatile);
	//*reg_const_volatile=10; as it points to a read only data it might change through externally(hardware)
}

/*
 4. Void Pointers and Memory Copying
Goal: Use void pointers to create a generic memory copying utility function for embedded data types.
Declare a function mem_copy(void *dest, const void *src, size_t n) that copies n bytes from src to dest
void mem_copy(void *dest, const void *src, size_t n);
Within the function, use char * pointers to copy data byte-by-byte.
Test the function by copying an array of integers and an array of floats.
*/
void mem_copy(void *dest, const void *src, size_t n)
{
	const char *sptr=src;
	char *dptr=dest;
	for(i=0;i<n;i++)
	{
		*dptr=*sptr;
	}
	return;
}
void void_ptr_mem_cpy()
{
	int arr1[5]={1,2,3,4,5};
	inr arr2[5];
	mem_copy(arr2,arr1,sizeof(arr1));
	for(int i=0;i<5;i++)
		printf("%d ",arr2[i]);
	return;
}

/*
 5. Structure Padding and Packed Attributes
Goal: Analyze memory layout and size differences of structs with and without packing for peripheral registers.

Activity:
Define a structure containing char, int, and short fields
Print the total size of the structure and the offsets of each member using offsetof().
Redefine the structure with __attribute__((packed)) and compare sizes and offsets.
 */
struct peripheral_regs1 {
  char status;
  int control;
  short error;
};
void structure_padding()
{
	struct peripheral_regs1 s1;
	printf("total size:%zu\n",sizeof(s1));                    //12
	printf("Offset of status  : %zu\n",offsetof(s1,status)); //0
	printf("Offset of status  : %zu\n",offsetof(s1,control));//4
	printf("Offset of status  : %zu\n",offsetof(s1,error));  //8
}
struct __attribute__((packed)) peripheral_regs2 {
    char  status;
    int   control;
    short error;
};
void structure_padding_pragma()
{
        struct peripheral_regs2 s2;
        printf("total size:%zu\n",sizeof(s1));                    //7
        printf("Offset of status  : %zu\n",offsetof(s2,status)); //0
        printf("Offset of status  : %zu\n",offsetof(s2,control));//1
        printf("Offset of status  : %zu\n",offsetof(s2,error));  //5
}
void struct_padding_packed_attributes()
{
	structure_padding_pragma();
	structure_padding();
}

/*
 6. Function Pointer Arrays for Command Execution
Goal: Log Session an embedded command interface using an array of function pointers.
Activity:
Declare three functions representing device operations:
void init(void);
void start(void);
void stop(void);
Log Session an array of function pointers referencing these functions:
void (*cmd_table[])(void) = {init, start, stop};
Use an index or enum value to invoke the appropriate function via the array.
 */
void init(void)
{
    printf("Device Initialized\n");
}

void start(void)
{
    printf("Device Started\n");
}

void stop(void)
{
    printf("Device Stopped\n");
}
void function_ptr()
{
	void (*cmd_table[])(void)={init,start,stop};
	cmd_table[0];
	cmd_table[1];
	cmd_table[2];
	return;
}
/*
 7. Dangling Pointer Scenario
Goal: Identify potential risks and behavior of dangling pointers in embedded dynamic memory management.
Write a function that allocates a block of memory dynamically using malloc() and returns the pointer
int *allocate_buffer(void) 
{
  int *buf = (int *)malloc(10 * sizeof(int));
  return buf;
}
In the calling context, free the memory pointed to and then try to access it via the original pointer.
Use debug prints or debugger to observe system behavior.
 */
int *allocate_buffer(void)
{
    int *buf=(int *)malloc(10*sizeof(int));
    return buf;
}
void dangling_pointer()
{
    int *ptr=allocate_buffer();
    if (ptr==NULL)
    {
        printf("Allocation failed\n");
        return;
    }
    // Initialize memory
    for (int i=0;i<10;i++)
        ptr[i]=i;
    printf("Before free: ptr[0] = %d\n",ptr[0]);
    free(ptr);  // Memory released
    printf("After free: ptr[0] = %d\n",ptr[0]);   // Undefined behavior
    return;
}

/*
 8. Dynamic Allocation of 2D Register Block
Goal: Dynamically allocate and manage a two-dimensional register map for peripheral configuration.
Allocate memory for a 4x4 matrix of 32-bit registers using double pointers
uint32_t **reg_block;
reg_block = malloc(rows * sizeof(uint32_t *));
for (int i = 0; i < rows; i++)
  reg_block[i] = malloc(cols * sizeof(uint32_t));
  Initialize the matrix elements with example register values.
Print the matrix values via pointer dereferencing.
Free all allocated memory properly after use.
 */
/*
 9. Function Returning Pointer to Fixed-Size Array
Goal: Implement a function that returns a pointer to a fixed-size calibration data array.
Use typedef to declare a pointer to an array of 10 integers
typedef int (*CalibArrayPtr)[10];
Log Session a function that returns a pointer to a static array of calibration values
CalibArrayPtr get_calibration_data(void);
from the calling function, access calibration data via the returned pointer
 */
typedef int (*CalibArrayPtr)[10];
CalibArrayPtr get_calibration_data(void)
{
    static int calibration[10] =
    {
        100, 105, 110, 115, 120,
        125, 130, 135, 140, 145
    };
    return &calibration;   // return pointer to entire array
}
void dynamic_allocation()
{
	CalibArrayPtr ptr = get_calibration_data();
    printf("Calibration values:\n");
    for (int i=0;i<10;i++)
    {
        printf("%d ",(*ptr)[i]);
    }
	return;
}
/*
 10. Pointer Arithmetic on Struct Arrays
Goal: Access and modify an array of peripheral register structs using pointer arithmetic.
Define a struct representing peripheral registers
struct Peripheral {
  uint8_t status;
  uint8_t control;
  uint16_t data;
};
Declare an array of 5 such structs.
Use a pointer to traverse and modify the array elements using pointer arithmetic.
 */
struct Peripheral {
    uint8_t  status;
    uint8_t  control;
    uint16_t data;
};
void ptr_struct()
{
	 struct Peripheral devices[5];
    struct Peripheral *ptr = devices;  // points to first element
    // Initialize using pointer arithmetic
    for(int i=0;i<5;i++)
    {
        (ptr+i)->status=i;
        (ptr+i)->control=i+10;
        (ptr+i)->data=i*100;
    }

    // Print values
    for(int i=0;i<5;i++)
    {
        printf("Device %d:\n", i);
        printf("  Status  = %u\n",(ptr+i)->status);
        printf("  Control = %u\n",(ptr+i)->control);
        printf("  Data    = %u\n",(ptr+i)->data);
    }
    return;
}
int main()
{
	ptr_arrays();
	multi_dimensional_array();
	void_ptr_mem_cpy();
	const_volatile_ptrs();
	struct_padding_packed_attributes();
	function_ptr();
	dangling_pointer();
	dynamic_allocation();
	ptr_struct();
	return 0;
}
