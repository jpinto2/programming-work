#include "schedule.h"
#include <stdlib.h>
#include <stdio.h>

struct node {
	PCB *value;
	struct node *next;
};

struct node *root[3];
/**
 * Function to initialize any global variables for the scheduler.
 */
void init(){
	int i =0;
	for(; i<3; i++) root[i] = NULL;
}

/**
 * Function called every simulated time period to provide a mechanism
 * to age the scheduled processes and trigger feedback if needed.
 */
void age(){
	if (root[1] != NULL || root[2] != NULL) {
		struct node *temp;
		struct node *cur;
		PCB *tmp;
		int i=1;

		for(; i<3; i++) {
			if (root[i] != NULL) {

				while (root[i] != NULL) {
					if (root[i]->value->age > 999) {
						temp = root[i];
						tmp = temp->value;
						root[i] = root[i]->next;
						free(temp);
						--tmp->priority;
						tmp->age = 0;
						addProcess(tmp); 
					}
					else {
						++root[i]->value->age;
						break;
					}

				}


				if (root[i] != NULL && root[i]->next != NULL) {
					cur = root[i];
					while (cur->next != NULL) {
						if (cur->next->value->age > 999) {
							temp = cur->next;
							tmp = temp->value;
							cur->next = cur->next->next;
							free(temp);
							--tmp->priority;
							tmp->age = 0;
							addProcess(tmp);
						}
						else {
							++cur->next->value->age;
							cur = cur->next;
						}
					}
				}

			}
		}
	}
}

/**
 * Function to add a process to the scheduler
 * @Param process - Pointer to the process control block for the process that
 * 			needs to be scheduled. PCB is defined in the header.
 * @return true/false response for if the addition was successful
 */
int addProcess(PCB* process){
	if (process != NULL) {
		struct node *tmp;
		tmp = (struct node*) malloc( sizeof(struct node));
		tmp->value = process;
		int i=process->priority;
		if (root[i] == NULL) {
			tmp->next = root[i];
			root[i] = tmp;
		}
		else {
			struct node *cur;
			cur = root[i];
			while (cur->next != NULL) cur = cur->next;
			tmp->next = cur->next;
			cur->next = tmp;
		}

		return 1;
	}
	return 0;
}

/**
 * Function to get the next process from the scheduler
 * @Param time - pass by reference variable to store the quanta of time
 * 		the scheduled process should run for
 * @Return returns pointer to process control block that needs to be executed
 * 		returns NULL if there is no process to be scheduled.
 */
PCB* nextProcess(int *time){
	if (!hasProcess()) return NULL;
	struct node *cur;
	PCB *tmp;
	int pr;

	if (root[0] != NULL) pr=0;
	else if (root[1] != NULL) pr=1;
	else pr=2;

	cur = root[pr];
	tmp = cur->value;
	if (pr==0) *time = 0;
	else if (pr==1) *time=4;
	else if (pr==2) *time=1;
	root[pr] = root[pr]->next;
	free(cur);

	return tmp;
}

/**
 * Function that returns a boolean 1 True/0 False based on if there are any
 * processes still scheduled
 * @Return 1 if there are processes still scheduled 0 if there are no more
 *		scheduled processes
 */
int hasProcess(){
	int i=0;
	for(; i<3; i++) if (root[i] != NULL) return 1;
	return 0;
}
