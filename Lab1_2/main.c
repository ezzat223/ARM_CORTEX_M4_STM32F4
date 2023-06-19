#include <stdio.h>
#include <stdlib.h>

    /* Lab 1 */
void get_u_v(void);
void get_stats(void);
void get_time(void);

    /* Lab 2 */
void rotate(void);
void draw_diamond(void);
void get_fibonacci(void);

    /* HW */
void get_taylor_expo(void);

int main()
{
    int option;

    while(1)
    {
        printf("\nPlease enter question number: ");
        scanf("%i", &option);
        switch(option)
        {
            case 1:
               get_u_v();
               break;
            case 2:
                get_stats();
                break;
            case 3:
                get_time();
                break;
            case 4:
                rotate();
                break;
            case 5:
                draw_diamond();
                break;
            case 6:
                get_fibonacci();
                break;
            case 7:
                get_taylor_expo();
                break;
            default:
                exit(1);
        }
    }

    return 0;
}

void get_u_v(void)
{
    unsigned int u,a,t,v,s;
    printf("Enter Initial Velocity, acceleration, time elapsed: ");
    scanf("%i %i %i",&u, &a, &t);
    v = u + a*t;
    s = u*t + (0.5*a*t*t);
    printf("v = %i\ns = %i", v, s);
}
void get_stats(void)
{
    unsigned int num1, num2, num3;
    printf("Enter 3 Numbers: ");
    scanf("%i %i %i",&num1, &num2, &num3);
    printf("Sum is %i\n", num1+num2+num3);
    printf("Average is %0.2f\n", (num1+num2+num3)/3.0);
    printf("Product is %i\n", num1*num2*num3);
    int smallest = (num1<=num2 ? (num1<=num3 ? num1 : num3) : (num2<=num3 ? num2 : num3));
    int largest = (num1>=num2 ? (num1>=num3 ? num1 : num3) : (num2>=num3 ? num2 : num3));
    printf("Smallest is %i\n", smallest);
    printf("Largest is %i\n", largest);

}

void get_time(void)
{
    unsigned int total, hours, minutes, seconds;
    printf("Enter Total time in seconds: ");
    scanf("%i",&total);

    hours = total / 3600;
    total = total % 3600;

    minutes = total / 60;
    seconds = total % 60;

    printf("Time is %i:%i:%i\n", hours, minutes, seconds);
}

/////////////////////* LAB 2 *////////////////////////////////

void rotate(void)
{
    signed char x, rotated;
    unsigned char n;
    char o;
    printf("Enter n-rotate cycles: ");
    scanf("%i", &n);
    printf("Enter 8bit-number: ");
    scanf("%i", &x);
    printf("Enter L or R for rotation: ");
    fflush(stdin);
    o = getchar();
    if((o != 'L') && (o != 'l') && (o != 'R') && (o != 'r'))
    {
        printf("Please Enter a valid option for Rotation!\n");
        rotate();
    }
    switch (o)
    {
        case 'L':
        case 'l':
            for(int i=1; i<=n ; i++)
            {
                rotated = (x<<i)|(x>>(8-i));
                printf("%i\n", rotated);
            }
            break;
        case 'R':
        case 'r':
            for(int i=1; i<=n ; i++)
            {
                rotated = (x>>i) | (x<<(8-i));
                printf("%i\n", rotated);
            }
            break;
    }
}


void draw_diamond(void)
{
    /* You can print space or asterisk ONLY */
    int rows = 9, i, space, stars;

    ////////////* Upper half and middle line */////////////////////
    for(i = 1 ; i <= ((rows / 2) + 1) ; i++)
    {
                ////////* spaces *//////////
        for(space = 1; space <= ((rows / 2) + (1-i)) ; space++)
        {
            printf(" ");
        }
        		////////* asterisks *//////////
        for(stars = 1; stars <= ((2*i) - 1) ; stars++)
        {
            printf("*");
        }
        printf("\n");
    }

    //////////////* lower half *//////////////////
    for(i = (rows / 2) ; i >= 1 ; i--)
    {
               ////////* spaces *//////////
        for(space = 1; space <= rows / 2 + 1 - i; space++)
        {
            printf(" ");
        }
        		////////* asterisks *//////////
        for(stars = 1; stars <= 2 * i - 1; stars++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void get_fibonacci(void)
{
    int n, first=0, second=1, element;
    printf("Enter number of series terms: ");
    scanf("%i", &n);
    if(n < 0)
    {
        printf("Please enter a non negative number!\n");
        get_fibonacci();
    }
    else if(n == 0)
    {
        printf("Series terms are: %i\n", n);
    }
    else if(n == 1)
    {
        printf("Series terms are: %i, %i\n", 0, n);
    }
    else
    {
       printf("Series terms are : ");
        printf("%i, ", first);
        printf("%i, ", second);
        for(int i =2; i <= n ; i++)
        {
            element = first+second;
            first = second;
            second = element;
            printf("%i, ", element);
        }
        printf("\n");
    }
}

//////////////////////* HW *///////////////////////
void get_taylor_expo(void)
{
    int x, n, fact = 1;
    float result = 1;
    printf("Enter the number, n-iterations: ");
    scanf("%i %i", &x, &n);

    if(n <= 0)
    {
        printf("Please enter a positive n-iterations!\n");
        get_taylor_expo();
    }
    else if(n == 1)
    {
        printf("Result = %i\n", 1);
    }
    else
    {
        for(int i =1; i< n ; i++)
        {
            fact *= i;
            result += ((float)x/i);
            x *= x;
        }
        printf("Result = %0.2f\n", result);
    }

}


