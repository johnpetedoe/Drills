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


int main (void) { 
    int i;
    int j;
    int k;
    int sub_unit_j;
    int sub_unit_k;

    // Modularize as function
        // paramatarize variables 
    int hour;
    int base_unit;
    int no_base_unit;
    int interval;
    int start;

    sub_unit_j = 4; 
    sub_unit_k = 1;

    hour = 60;
    base_unit = hour;
    no_base_unit = 24;
    start    = 10;
    interval = base_unit / sub_unit_j;

    i = start; 
    while (i < no_base_unit) {
        j = 0; 
        while (j < base_unit) {
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
            j += interval;
        }
        f_putchar('\n'); // paramatarize this format or seperate format from algo
        i += 1;
    }
    return (0); 
}
