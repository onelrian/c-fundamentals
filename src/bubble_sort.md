
# Bubble Sort with Dynamic Input Handling

## Description
This C program reads a series of numbers from the user, stopping when `-1` is entered. It then sorts the numbers using **Bubble Sort** and displays the sorted output.

## Features
- Supports up to **100 numbers**.
- Dynamically allocates memory (`malloc`).
- Stops reading numbers when `-1` is entered.
- Optimized **Bubble Sort** (stops early if already sorted).
- Prevents invalid input (e.g., `n > 100` or `n <= 0`).
- Frees allocated memory (`free()`).

## How to Compile and Run
### **Compile**
```sh
gcc -o bubble_sort bubble_sort.c
```

### **Run**
```sh
./bubble_sort
```

### **Example Run**
```sh
Enter the number of elements (max 100): 5
Enter numbers (Enter -1 to stop early):
7 3 9 2 5
```
#### **Output**
```sh
Your series of numbers:
7 3 9 2 5 

Sorted numbers:
2 3 5 7 9 
```

## Notes
- **If `-1` is entered**, the program stops input early.
- **If input exceeds 100 numbers**, the program **prevents overflow**.
- **Bubble Sort is optimized** to avoid unnecessary passes.
