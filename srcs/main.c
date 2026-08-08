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
    
    time = t / interval % 24;
    
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
    int lb_close;
    int hour;
    char *labels[5] = { "AC", "FM", "LB", "MS"};

    interval = 60;
    lb_close = 18;
    i = 0;
    n = 48 * interval;

    
    while (i < n) 
    {
        format_time(i, interval);
        hour = i / interval % 24;

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
            f_putstr(labels[2]);
            f_putchar(' ');
            f_putstr(labels[2]);
        }
        f_putchar('\n');
        i++;
        
    }

    return (0);
}
