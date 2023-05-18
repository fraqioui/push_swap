# push_swap

### Summary
This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. 
To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

**To understand the project in details read the subject between repository files.**

### The rules

• You have 2 stacks named a and b.

• At the beginning:
    ◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
    ◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:

__sa (swap a)__: Swap the first 2 elements at the top of stack a.
             Do nothing if there is only one or no elements.

__sb (swap b)__: Swap the first 2 elements at the top of stack b.
             Do nothing if there is only one or no elements.
             
__ss__ : sa and sb at the same time.

__pa (push a)__: Take the first element at the top of b and put it at the top of a.
              Do nothing if b is empty.
              
__pb (push b)__: Take the first element at the top of a and put it at the top of b.
              Do nothing if a is empty.
              
__ra (rotate a)__: Shift up all elements of stack a by 1.
                The first element becomes the last one.
                
__rb (rotate b)__: Shift up all elements of stack b by 1.
                The first element becomes the last one.
                
__rr__ : ra and rb at the same time.

__rra (reverse rotate a)__: Shift down all elements of stack a by 1.
                        The last element becomes the first one.
                        
__rrb (reverse rotate b)__: Shift down all elements of stack b by 1.
                        The last element becomes the first one.
                        
__rrr__ : rra and rrb at the same time.

### Example:

```
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>
```
To run the program:
1. Clone the repository
2. In the directory of the repository
```
$> make
```
3. Finally, run the program using any random numbers
```
$>./push_swap 56 -100 67 2 99 0 78 30 55
```


## Resources

1. Links I relied on to develop the function that finds the largest increasing subsequence:
 
 - [geeksforgeeks](https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/).
 - [Algorithms for Competitive Programming](https://cp-algorithms.com/sequences/longest_increasing_subsequence.html).
 - [LIS](https://www.youtube.com/watch?v=mouCn3CFpgg).
 - [Dynamic Programming, Part 2: LCS, LIS, Coins](https://www.youtube.com/watch?v=KLBCUx1is2c).
 
 2. I am grateful to the person who developed the algo that inspired me the most (largest increasing list algo) and it was the base of my push swap project. (look for it between repository files)
  
  3. You can use Neso Academy as a reference to understand linked list:
    [Neso Academy](https://www.youtube.com/@nesoacademy).
    























