### **User Information Collector**  

This C program:  
* Collects user details including:  
  - Surname, Firstname  
  - Date of Birth (Year, Month, Day)  
  - Address  
* Displays the collected data in a structured format  
* Compares birthdates to determine the older user  

#### **Download Only `user_info.c`**  
- Using `wget`:  
  ```bash
  wget https://raw.githubusercontent.com/onelrian/c-fundamentals/main/src/user_info.c
  ```
- Using `curl`:  
  ```bash
  curl -O https://raw.githubusercontent.com/onelrian/c-fundamentals/main/src/user_info.c
  ```

#### **Compile & Run**  
```bash
gcc user_info.c -o user_info
./user_info
```