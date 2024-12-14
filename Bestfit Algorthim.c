#include <stdio.h>
#define MAX_BLOCKS 100  // Define a constant for the maximum number of memory blocks

// Define a structure to represent a memory block
struct MemoryBlock {
    int block_id;       // ID of the memory block (1-based index)
    int size;           // Size of the memory block
    int allocated;      // Allocation status: 0 means not allocated, 1 means allocated
};

// Function to implement the Best Fit memory allocation strategy
void bestFit(struct MemoryBlock blocks[], int m, int processSize) {
    int bestIdx = -1;  // Initialize the index of the best fit block as -1 (not found)

    // Iterate through all memory blocks to find the best fit
    for (int i = 0; i < m; i++) {
        // Check if the block is not allocated and has enough space for the process
        if (blocks[i].allocated == 0 && blocks[i].size >= processSize) {
            // If no best block found yet or current block is a better fit (smaller size but enough space)
            if (bestIdx == -1 || blocks[i].size < blocks[bestIdx].size) {
                bestIdx = i;  // Update the best fit index
            }
        }
    }

    // After checking all blocks, allocate the best fit block if one was found
    if (bestIdx != -1) {
        blocks[bestIdx].allocated = 1;  // Mark the block as allocated
        printf("Process with size %d allocated to block %d\n", processSize, bestIdx + 1);  // Output allocation info
    } else {
        printf("Cannot allocate the process with size %d\n", processSize);  // Output if no suitable block is found
    }
}

// Main function to drive the memory allocation process
int main() {
    int m;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);  // Input number of memory blocks

    struct MemoryBlock blocks[MAX_BLOCKS];  // Declare an array to hold the memory blocks

    // Input the size of each memory block
    for (int i = 0; i < m; i++) {
        blocks[i].block_id = i + 1;  // Assign a unique block ID (1-based)
        printf("Enter the size of memory block %d: ", i + 1);
        scanf("%d", &blocks[i].size);  // Input size of each block
        blocks[i].allocated = 0;  // Initially, all blocks are not allocated
    }

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);  // Input the number of processes to allocate

    // Allocate memory for each process
    for (int i = 0; i < n; i++) {
        int processSize;
        printf("Enter the size of process %d: ", i + 1);
        scanf("%d", &processSize);  // Input the size of each process
        bestFit(blocks, m, processSize);  // Try to allocate the process using the best-fit strategy
    }

    return 0;  // End of the program
}
