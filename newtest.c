#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"



int PScheduler(void) {
 int pid, ret_pid, exit_status;
  int i,j,k;
  int pri;
    printf(1, "\n  Step 2: testing the priority scheduler and setpriority(int priority)) systema call:\n");
    printf(1, "\n  Step 2: Assuming that the priorities range between range between 1 to 63\n");
    printf(1, "\n  Step 2: 1 is the highest priority. All processes have a default priority of 20\n");
    printf(1, "\n  Step 2: The parent processes will switch to priority 0\n");
    setpriority(0);
    for (i = 0; i <  3; i++) {
	pid = fork();
	if (pid > 0 ) {
		continue;}
	else if ( pid == 0) {
                setpriority(60-20*i);	
		for (j=0;j<50000;j++) {
			for(k=0;k<10000;k++) {
				asm("nop"); }}
		printf(1, "\n child# %d with priority %d has finished! \n",getpid(),60-20*i);		
		exit(0);
        }
        else {
			printf(2," \n Error \n");
			exit(-1);
        }
	}

	if(pid > 0) {
		for (i = 0; i <  3; i++) {
			ret_pid = wait(&exit_status);
		}
                     printf(1,"\n if processes with highest priority finished first then its correct \n");
	}	
			
	return 0;


}

int main(int argc, char *argv[])
{
	int PScheduler(void);

  printf(1, "\n This program tests the correctness of your lab#1\n");
  
  if (atoi(argv[1]) == 1)
	printf(1, "already tested");
  else if (atoi(argv[1]) == 2)
	printf(1, "already tested");
  else if (atoi(argv[1]) == 3)
	PScheduler();
  else 
   printf(1, "\ntype \"lab1 1\" to test exit and wait, \"lab1 2\" to test waitpid and \"lab1 3\" to test the priority scheduler \n");

exit(0);

}
