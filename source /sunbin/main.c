#include "ft_printf.h"

int main()
{
    ft_printf("%123dddtem%0-54678.1835gp1111%22% asdnio\n");
    printf("%123dddtem%0-54678.1835gp1111%22% asdnio\n");
    printf("[%3.s]\n","abc");
    printf("[%03.s]\n","abc");

    //ft_printf("temp11111");
}