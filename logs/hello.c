#include <unistd.h>
int main(void){write(1,"Hello World !",13);char c=10;write(1,&c,1);return(0);}
