# atoi (to fix the 9999999999999999999999999999999999999999 (long overflow) issue):

> check if past the limit after every change
```c
while(str[i])
{
        nbr = nbr * 10 + (str[i] - '0');
        if (nbr * sign > INT_MAX || nbr * sign < 2147483648) // Check if > INT_MAX or < INT_MIN
        {
            free_stack();
            exit(1);
        }
}
```
- fdsafa
- fdsad
- fsda\
- ggfds