#include <unistd.h>
#include <stdlib.h>

/*
    TODO : CONTROL THE SIZE OF THE SECONDARY INTERVAL
    TODO : DECOUPLE LOCATIONS
*/
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

char *f_itoa (int n) {
    int tmp;
    int degree;
    int power;
    char *s;


    tmp = n;
    degree = 0; 
    while (tmp) {
        tmp /= 10;
        degree++;
    }
    
    s = (char*)malloc(sizeof(char) * degree + 1);
    s[degree] = '\0';

    power = 1;
    tmp = degree;
    while (tmp) {
        power *= 10;
        tmp--;
    }

    while (degree) {
        s[degree] = n % power + 48;
        n /= 10;
        power /= 10;
        degree--;
    }
    return (s);
}

void format_time (int t, int interval) {
    int time;
    
    time = t / interval;
    
    if (time < 10) {
        f_putchar('0');
    }

    f_putnbr ( time );
    f_putchar ( ':');

    if (t % interval < 10) {
        f_putchar('0');
    }

    f_putnbr ( t % interval );

    f_putstr ( f_itoa(t / interval) );
}

int main (int argc, char **argv) {
    
    if (argc < 2) {
        f_putstr(argv[0]);
        return (0);
    }

    int i;
    int n;
    int interval;
    int hour;
    char *labels[5] = { "AC", "FM", "LB", "MS"};

    interval = 60;
    i = 0;
    n = 12 * interval;
    
    while (i < n) 
    {
        format_time(i, interval);
        // ()
        // (:= () ('(/ ([1] (p| (m|()) ) ) ([2] (p| (m| ()))) )) )

        //carrier languages vs non-carrier languages

        //{\displaystyle \{P\}C\{Q\}}
        // (=> P (=> (m (M C)) Q))
        // (=> P (= (m (M C_0)) Q))

        // proposal for naming convention of recursive.c using hoar logic
        // (=> P (= (m (M () )) Q))
        // (:=
        //      (=> P (= (m (M () )) Q))
        //      (=> P (= (m (M (=> P (= (m (M () )) Q)) )) Q))
        // )
        // (:= 
        //      (=> P (= (m (M (=> P (= (m (M () )) Q)) )) Q))
        //      (=> P (= (m (M (=> P (= (m (M (=> P (= (m (M (=> P (= (m (M () )) Q)) )) Q)) )) Q)) )) Q))
        // )
        
        // this requires every namable instruction to be testable.

        // what of variables?

        // (=> (= () 1) (= (m (M (+ 2 ()))) 3) )
        // Here, with P as (= () 1), Q as 3, and C as (+ 2 ()) 
        //      We have named, not C in it's entirety, but an abstraction involved by C.

        // The formula may be expanded by one recurrence as follows:
        // (=> (= (=> (= () 1) (= (m (M (+ 2 ()))) 3) ) 1) (= (m (M (+ 2 (=> (= () 1) (= (m (M (+ 2 ()))) 3) )))) 3) )
        
        // This may be informally translated as: That which when added to 2 and executed by the machine, M, returns 3.
        // 
        // This formulation neglects the definition of Q from the Hoar logic using it as an output of a finite state machine instead of an assertion

        // There are two ways to re-accomodate the definition of Q from the Hoar logic:
        // 0. Use the equality involving the succession of M as the definition of Q such that: (= Q "(= (m (M C)) a)").
        //      Now Q has taken the form of an assertion describing the sucession of the state of the Machine, M, given the input, C.
        //      
        //      That means the entire name/formula takes the form: (=> P Q) Where Q abstracts the statement of equality involving C.
        //      Although this form only uses the *precondition* and *postcondition*, the *command* is referenced within the post-condition.                    
        
        // 1. Re-Structure our formula: 
        //      I've forgotten the second
        
        hour = i / interval;

        f_putchar('\t');
        if ((hour <= 7) && (hour > 6)) 
        {
            f_putstr(labels[0]);
            f_putchar(' ');
            f_putstr(labels[0]);
        } 
        else if ((hour < 9) && (hour > 7)) 
        {
            f_putstr(labels[0]);
            f_putchar(' ');
            f_putstr(labels[2]);
        } 
        else if (((hour >= 9) && (hour < lb_close))) 
        {
            f_putchar(labels[2]);
            f_putchar(' ');
            f_putstr(labels[])
            i++;
        }
        */
    }

    return (0);
}
