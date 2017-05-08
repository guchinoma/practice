#include <stdio.h>
#include <string.h>
char buf[32];

int main(int argc, char *argv[]){

char local[32];
printf("buf = 0x%x\n", &buf);
fgets(local, 128, stdin);
strcpy(buf, local);
return 0;

}