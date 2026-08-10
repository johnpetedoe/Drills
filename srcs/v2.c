# include <unistd.h>
# include <stdlib.h>

int f_strlen (char *s) {
    int i;

    i = 0;
    while (s[i]) {
        i++ ;
    }
    return (i);
}

void f_putchar (char c) {
    write(1, &c, 1);
}

void f_putstr (char *s) {
    int i;
    int n;
    
    n = f_strlen(s);
    i = 0;
    while (i < n) {
        f_putchar(s[i]);
        i++;
    }
}

void f_putnbr (long long n) {
    long long tmp;

    tmp = n;
    if (tmp < 0) 
    {
        tmp = -tmp;
        f_putchar('-');
    }
    if ( tmp >= 10 ) 
    {
        f_putnbr(tmp / 10);
        f_putnbr(tmp % 10);
    } 
    else 
    {
        f_putchar(tmp + '0');
    } 
}

/*
0. Main func
1. Alloc Tickets, recruitment
    0. Update prototypes
        0. Knights
        1. Engineers
        2. Other stem
        3. non-stem
        4. hypocrites
        5. future hypocrites
        6. polymorphic abstractions
    
    1. Selection/containment of demon pocesses:
        1. I vs ~I, 
        2. P vs ~P,
    */

    /*
        00. user executes logistic algorithm
        01. change in environmental variables may necessitate change in path
        02. user may not have access to device to compute change in path
        03. this program is meant to enumerate a number of possible schedules depending on conditions. 
        04. the user may have access to limited cognitive resources
        05. If the user is forced to make a decision, they may select from one of the pre-computed possibilities. 
    */

// This program's code is sloppy and not at all dry because something else is using my engineer, I'm currently translating the work of my logician into C without regard for SWE best practices I've observed for most of my education and my career.

int main (void) { 
    int i;
    int j;
    int k;
    //int n;
    //int arr;
    int sub_unit_j;
    int sub_unit_k;

    //arr = (char*)malloc(sizeof(char*) * n + 1);
    //arr[n] = NULL;

    sub_unit_j = 4; 
    sub_unit_k = 1;

    i = 0; 
    while (i < 24) {
        j = 0; 
        while ((j / sub_unit_j) < 60) {
            k = 0;
            while (k < 1) {
                f_putchar((( i < 10 ) ? '0' : '\0'));
                f_putnbr(i);
                f_putchar(':');
                f_putchar((( j < 10 ) ? '0' : '\0'));
                f_putnbr(j);
                f_putchar('\n');
                
                k += sub_unit_k;
            }
        }
        f_putnbr( 60 / sub_unit_j );
        f_putchar('\n');
        j += 60 / sub_unit_j;
        
    }
    i += 1;
    return (0); 
}
