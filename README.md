# Push Swap
Because Swap Push doesn’t feel as natural

In this project, a data in a stack is sorted using a limited set of instructions, aiming
to achieve the lowest possible number of actions. To succeed, the Turck sorting algorithm was choose to apropriated data sorting.

## Install
To install just do the steps below:
```
git clone https://github.com/mcmaquine/42_Push_Swap.git push_swap
cd ./push_swap
git clone https://github.com/mcmaquine/42_Libft_2_0.git libft
make
```
## Running
After properly install just call the executable with a set of unsorted integers as parameter:
```
./push_swap 36125 32860 47059 6484 28187 30968 1302 9204
```
The printed result is a list of all commands to properly sort the sequence inserted in the parameter.

## Bonus
Bonus is a program to check if sequence is properly sorted, its accept a sequence as parameter and user must input the steps whichs must sort the sequence. If the  input properly sorts the sequence it prints OK, otherwise KO.

To run bonus, first compile it (only works if Install was done successfully):
```
make bonus
```
A checker executable will be made, and run like example below:
```
arg="30000 5356 38385 19699 41196 46717 17922 20931"
./push_swap $arg | ./checker $arg
```

