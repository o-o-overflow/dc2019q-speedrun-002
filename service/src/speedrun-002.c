#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 

   Compilation:
   gcc -o speedrun-002 -no-pie -fno-stack-protector speedrun-002.c && strip speedrun-002

   Also need to take the glibc version to give to folks.

 */

int test()
{
   return 0xc35a;
}

void say_hello()
{
   printf("We meet again on these pwning streets.\n");
}

void more_info(char* buf)
{
   printf("What an interesting thing to say.\nTell me more.\n");
   read(0, buf, 2010);
   write(1, "Fascinating.\n", strlen("Fascinating.\n"));
}

void what_do_they_say()
{
   char buf[1024];
   char line[400];
   printf("What say you now?\n");

   read(0, line, 300);
   if (strncmp(line, "Everything intelligent is so boring.", strlen("Everything intelligent is so boring.")) == 0)
   {
	  more_info(buf);
   }
   else
   {
	  printf("What a ho-hum thing to say.\n");
   }
}

void say_goodbye()
{
   printf("Fare thee well.\n");
}

int main(int argc, char** argv)
{
   setvbuf(stdout, NULL, _IONBF, 0);

   if (getenv("DEBUG") == NULL)
   {
	  alarm(5);
   }


   say_hello();
   what_do_they_say();
   say_goodbye();
}
