TERMINAL COMMANDS:
    g++ rpn.cpp
    ./a.out


TESTING:
The program will prompt you line by line for what to input. First n (the length of your string array), then the string array one string at a time, then -l if desired.

-l prints out the tree, indenting each successive child. 

EXAMPLE:
To input n = 9 for test[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*"}
Input in the terminal when prompeted the value of n (string array size):
> 9

Input into termal each value of the array one by one, program will only let you enter N values:
> 2
> 12
> 6
> -
> /
> 5
> 3
> +
> *

Input into terminal 'y' or 'n' if you want -l to be displayed:
> y

NOTE: there is minimal error checking for the input portion, so if there is an unintended mis-type you must control-C and rereun ./a.out
(There is, however, error checking for the array of strings to make sure everything is a valid number/operator/in the correct order before final calculations).
After you input y, the program will execute -l and then print the result. 
If you input n, the program will only print the result. 

