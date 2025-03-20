### **C Variable Grouper**
This program:
- Reads a C file
- Extracts variable names
- Groups them based on their **first N characters**
- Ignores comments and strings

#### **Compilation & Execution**
```bash
gcc c_variable_grouper.c -o c_variable_grouper
./c_variable_grouper my_code.c 3
```
(Where `my_code.c` is the input file, and `3` is the grouping length)

#### **Example Output**
```bash
abc
  abc_var
  abc_count

int
  integer1
  int_max

str
  string_var
  str_length
```
