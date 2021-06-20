#define arrival			0
#define execution 		1
#define deadline		2
#define period			3
#define abs_arrival		4
#define execution_copy  5
#define abs_deadline	6

//stucture of a task
typedef struct
{
	int T[7],instance,alive;

}task;

#define IDLE_TASK_ID 1023   // When there is no process running
#define ALL 1 //Need to change all task.
#define CURRENT 0 //Need to change just one task.

void get_tasks(task *t1,int n);				//Get tasks parameters - Arrival time , Execution time , Deasdline and Period.
int hyperperiod_calc(task *t1,int n);			//Calculate hyperiod period of the task set  .
float cpu_util(task *t1,int n);				//Calculates CPU utilization.
int gcd(int a, int b);					//Find greatest common divisor.
int lcm(int *a, int n);					//Find Least common multiple.
int sp_interrupt(task *t1,int tmr,int n);		//Scheduling point interrupt.
int min(task *t1,int n,int p);				//Find minimum of given task parameter.
void update_abs_arrival(task *t1,int n,int k,int all);	//Update absolute arrival time (absolute arrival time = arrivaltime + instance*period). 
void update_abs_deadline(task *t1,int n,int all);	//Update absolute deadline (absolute deadline = absolute arrival time + deadline ).
void copy_execution_time(task *t1,int n,int all);	//Keep a backup copy of execution time.
