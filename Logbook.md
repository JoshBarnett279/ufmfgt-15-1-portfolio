TEMPLATE:

### Week X – [Topic]

**Overview:**  
Brief description of what was covered this week.

**What I learned:**  
- Bullet points of new concepts or skills

**Challenges and solutions:**  
- Describe a problem you encountered  
- Explain how you fixed or understood it

**Reflection:**  
Short paragraph on how this week helped your understanding or confidence.

Week 1 – Introduction to C Programming

Overview:
In Week 1, I focused on getting used to CLion and understanding the basics of C programming. I completed some design tasks first, such as writing pseudocode and creating a traffic light flowchart, before moving on to writing my first C programs including a hello program and a speed converter.

What I learned:

How a C program runs from "main()"

How to use "printf()" to display output

How to use "scanf()" to read user input

How to declare variables and carry out simple calculations

Why planning with pseudocode makes coding easier

How to build and run programs in CLion

Challenges and solutions:
At the beginning, I had a few issues with small syntax mistakes like missing semicolons and incorrect "scanf()" usage. I also had some problems getting the correct run configuration in CLion. By carefully reading the compiler errors and checking my code step by step, I was able to fix these problems and understand what went wrong.

Reflection:
Week 1 helped me feel more comfortable with both C and the development environment. The speed converter especially helped me understand how input, processing, and output fit together in a program.

Week 2 – Selection Statements

Overview:
This week introduced conditional statements and decision-making in C. I worked with "if", "else if", "else", and "switch" statements to control how programs respond to user input.

What I learned:

How conditions are checked in order

Why the placement of conditions matters

How to use logical operators such as "&&" and "||"

How to validate user input properly

How to build simple menu-based programs

Challenges and solutions:
Sometimes my conditions were not in the correct order, which led to incorrect outputs. I fixed this by reorganising the structure and testing different input values to make sure each case worked properly.

Reflection:
This week improved my logical thinking. I feel more confident writing programs that make decisions and handle different situations correctly.

Week 3 – Nested Logic and Validation

Overview:
In Week 3, I developed more complex decision structures, including nested "if" statements and validation systems such as mark classification and age verification programs.

What I learned:

How nested "if" statements work

How to validate value ranges correctly

The importance of checking invalid input first

How logical structure affects the overall behaviour of a program

Challenges and solutions:
One challenge was making sure invalid values were handled before other conditions. I improved this by testing boundary cases and reviewing the order of my logic carefully.

Reflection:
Week 3 made me more aware of how small logic mistakes can change the outcome of a program. I now feel more confident structuring more detailed conditional systems.

Week 4 – Arrays and Loops

Overview:
This week focused on arrays and loops to handle multiple pieces of data. I created programs that calculated totals, averages, and identified the highest and lowest values from a set of inputs.

What I learned:

How to declare and use arrays

How "for" and "while" loops operate

How array indexing starts from 0

How to calculate averages and track minimum and maximum values

Challenges and solutions:
At first, I found array indexing and loop limits slightly confusing. I solved this by carefully tracing through the loop logic and checking that my loop conditions were correct.

Reflection:
Week 4 was a big improvement in my understanding. Working with arrays made my programs feel more complete and structured, and I am now more confident handling larger sets of data.

Week 5 – Functions and Modular Programming

Overview:
In Week 5, I learned how to use functions to organise programs more effectively. Instead of placing all logic inside "main()", I created separate functions for tasks such as addition, circle calculations, validation, exponentiation, and swapping values.

What I learned:

How to declare and define functions

The purpose of function prototypes

How parameters and return values work

The meaning of pass-by-value

How modular design improves program structure

Challenges and solutions:
The broken swap exercise helped me understand pass-by-value. Although the values were swapped inside the function, they did not change in "main()" because only copies were passed. I also corrected small issues such as using "%lf" correctly when working with "double".

Reflection:
This week improved my understanding of how larger programs should be structured. Using functions made the code clearer and more organised, and I now feel more prepared to move on to pointers.

Week 6 – Pointers and Memory Management

Overview:
This week focused on pointers and how functions can access or modify variables directly in memory. I explored stack memory, passing arrays to functions, and returning multiple values via pointers.

What I learned:

How to declare and use pointers
The difference between pass-by-value and pass-by-address
Why returning local variable addresses is unsafe
How arrays decay to pointers when passed to functions
Using pointers to return multiple values
Applying pointers to engineering calculations like RLC circuits, time split, and dot product

Challenges and solutions:
Understanding why the broken swap didn’t work helped me see how memory is passed. I also fixed double format specifiers and linked the math library for calculations, reinforcing safe memory use.

Reflection:
Week 6 improved my confidence with memory management in C. I now understand pointers, arrays, and multiple return values, which prepares me to combine modules into larger, more complex programs.

Week 07 – Structs and File I/O

Overview: In Week 07, I learned how to use structs to organise data effectively. Instead of keeping separate variables for related data, I grouped them into structures. I also combined structs with arrays, functions, and file input/output to build practical programs like age calculators, student databases, and waveform analysis helpers.

What I learned:

- How to declare and define structs, including nested structs  
- How to create arrays of structs for multiple data entries  
- Using pointers to modify structs in functions  
- How to read from and write to files using `fopen`, `fscanf`, and `fprintf`  
- How to combine loops, arithmetic, and boolean flags with structs for calculations and checks  
- Handling paths and directories for file input/output in C  

Challenges and solutions:

- `fopen` errors taught me the importance of folder existence and working directories. Using `_mkdir()` or absolute paths solved these issues.  
- Nested structs initially caused syntax confusion — I learned to correctly use `.` for normal access and `->` for pointers.  
- Calculating age accurately with months and days required creating a `getDaysInMonth` function and handling borrow logic.  
- Detecting clipping in waveform data required careful use of loops and boolean flags to stop checking once a clipped sample was found.  

---

Reflection:
This week improved my understanding of structured programming and modular design in C. Using structs, arrays, and functions made the code cleaner and more maintainable. I also learned practical lessons in file management and folder organization, which are crucial for larger projects. I now feel confident applying these techniques in Week 08 for waveform analysis and more complex programs.
