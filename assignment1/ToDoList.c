/**************************************************************************************************/
/* Programmer: Mike diBenedetto                                                                   */
/*                                                                                                */
/* Program assignment01pe01: ToDo list                                                            */
/*                                                                                                */
/* Approximate completion time: ... minutes                                                       */
/**************************************************************************************************/

/*Headers provided by C*/
/* Example: #inlcude <stdio.h> */
#include <stdio.h>
#include <stdlib.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */

#define LENGTHOFTASK 100

char** loadFile(FILE *fp, char *Strings[], int *numberoftasks);
void saveFile(FILE *fp, char *Strings[], int numberoftasks);
char** addTask(char *Strings[], int *numberoftasks, int endloaction, char *theTask);
char** removeTask(char *Strings[], int *numberoftasks, int tasknumber);
char** shiftTask(char *Strings[], int tasknumber, int shift, int numberoftasks);
void displaySpecificTask(char *Strings[], int task);
void displayTasks(char *Strings[], int numberoftasks);

int main(int argc, char *argv[]){
	int cont = 0;
	FILE *fp = fopen("original_list.txt", "r");
    char **Strings = NULL;
	char *ts;
	int numberoftasks = 0, temp1, temp2;

    Strings = loadFile(fp, Strings, &numberoftasks);
    fclose(fp);
    
	while(cont != 7){
		printf("1. Display an item at a specific location\n");
		printf("2. Display all items\n");
		printf("3. Replace a task\n");
		printf("4. Remove a task\n");
		printf("5. Add a new task\n");
		printf("6. Move a task to another location\n");
		printf("7. Quit\n");
		printf("Enter a number between 1 and 7: ");
		scanf("%d", &cont);

		switch(cont){
			case 1:
				temp1 = 0;
				while(temp1 > numberoftasks || temp1 < 1){
					printf("Enter the task number: ");
					scanf("%d", &temp1);
					if(temp1 > numberoftasks || temp1 < 1){
						printf("You need to enter a number between 1 and %d!\n", numberoftasks);
                    }
				}
				displaySpecificTask(Strings, temp1);
				break;
			case 2:
				displayTasks(Strings, numberoftasks);
				break;
			case 3:
				temp1 = 0;
                ts = (char *)malloc(sizeof(char) * LENGTHOFTASK);
				while(temp1 > numberoftasks || temp1 < 1){
					printf("Enter the number of the task you want to replace: ");
					scanf("%d", &temp1);
					if(temp1 > numberoftasks || temp1 < 1){
						printf("You need to enter a number between 1 and %d!\n", numberoftasks);
                    } else {
                        printf("Enter the task you want to replace it with: ");
                        scanf("%100s", ts);
                        Strings[temp1-1] = ts;
                    }
				}
				break;
			case 4:
				temp1 = 0;
                temp2 = -1;
                if(numberoftasks > 0){
                    while(temp1 > numberoftasks || temp1 < 1){
                        printf("Enter the number of the task you want to delete: ");
                        scanf("%d", &temp1);
                        if(temp1 > numberoftasks || temp1 < 1){
                            printf("You need to enter a number between 1 and %d!\n", numberoftasks);
                        } else {
                            while(temp2 > 1 || temp2 < 0){
                                printf("Are you sure you want to delete this task? 1 = Yes 0 = No: ");
                                scanf("%d", &temp2);
                            }
                            if(temp2 == 1){
                                Strings = removeTask(Strings, &numberoftasks, temp1-1);
                                break;
                            }
                        }
                    }
                } else {
                    printf("There are no tasks to delete.");
                }
				break;
			case 5:
				temp1 = 0;
                ts = (char *)malloc(sizeof(char) * LENGTHOFTASK);
				while(temp1 == 0){
					printf("Enter the task you want to add: ");
					scanf("%s", ts);
					printf("Are you sure that is the task you want to add? 1 = yes 0 = no: ");
					scanf("%d", &temp1);
					if(temp1 == 1){
						temp2 = 0;
						while(temp2 > (numberoftasks+1) || temp2 < 1){
							printf("Where do you want to place the task: ");
							scanf("%d", &temp2);
							if(temp2 > (numberoftasks+1) || temp2 < 1){
								printf("You need to enter a number between 1 and %d!\n", (numberoftasks+1));
							} else {
                                Strings = addTask(Strings, &numberoftasks, temp2, ts);
							}
						}
					}
				}
				break;
			case 6:
				temp1 = 0;
				while(temp1 > numberoftasks || temp1 < 1){
					printf("Enter the number of the task you want to move: ");
					scanf("%d", &temp1);
					if(temp1 > numberoftasks || temp1 < 1){
						printf("You need to enter a number between 1 and %d", numberoftasks);
					}
				}
				temp2 = 0;
				while(temp2 > numberoftasks || temp2 < 1){
					printf("Enter the number of the position you want to move the task to: ");
					scanf("%d", &temp2);
					shiftTask(Strings, temp1-1, temp2-temp1, numberoftasks);
				}
				break;
			case 7:
                temp1 = 0;
                fp = fopen("final_list.txt", "w");
                do{
                    printf("Are you sure that you want to quit? 1 = yes 0 = no: ");
                    scanf("%d", &temp1);
                    if(temp1 == 1){
                        saveFile(fp, Strings, numberoftasks);
                        free(Strings);
                        return 0;
                    }
                    
                }while(temp1 < 0 || temp1 > 1);
                fclose(fp);
				break;
			default:
				printf("You need to enter a number between 1 and 7!\n");
				break;
		}
        cont = 0;
	}
	return 0;
}

char** loadFile(FILE *fp, char *Strings[], int *numberoftasks){
    char temp2;
    char *ptr;
    int i;
    while((temp2 = fgetc(fp)) != EOF){
        if(temp2 == '\n'){
            *numberoftasks += 1;
        }
    }
    rewind(fp);
    Strings = malloc(sizeof(char *) * *numberoftasks);
    for(i = 0; i < *numberoftasks; i++){
        Strings[i] = (char *)malloc(sizeof(char) * LENGTHOFTASK);
    }
    for(i = 0; i < *numberoftasks; i++){
        fgets(Strings[i], LENGTHOFTASK, fp);
        ptr = Strings[i];
        while(*ptr != '\0'){
            if(*ptr == '\n'){
                *ptr = '\0';
            }
            ptr++;
        }
    }
    return Strings;
}

void saveFile(FILE *fp, char *Strings[], int numberoftasks){
	int i;
	for(i = 0; i < numberoftasks; i++){
		fputs(Strings[i], fp);
        fputs("\n", fp);
	}
}

char** addTask(char *Strings[], int *numberoftasks, int endloaction, char* theTask){
    *numberoftasks += 1;
    Strings = realloc(Strings, sizeof(char *) * *numberoftasks);
    Strings[*numberoftasks-1] = theTask;
    Strings = shiftTask(Strings, *numberoftasks-1, endloaction-*numberoftasks, *numberoftasks);
    return Strings;
}

char** removeTask(char *Strings[], int *numberoftasks, int tasknumber){
    Strings = shiftTask(Strings, tasknumber, *numberoftasks-tasknumber, *numberoftasks);
    *numberoftasks -= 1;
    Strings = realloc(Strings, sizeof(char *) * *numberoftasks);
    return Strings;
}

char** shiftTask(char *Strings[], int tasknumber, int shift, int numberoftasks){
    char *temp = malloc(sizeof(char) * LENGTHOFTASK);
    int i, i2;
    if(shift == 0){
        return Strings;
    }
    temp = Strings[tasknumber];
    if(shift > 0){
        for(i = tasknumber, i2 = 0; i2 < shift; i++, i2++){
            Strings[i] = Strings[i+1];
        }
    } else {
        for(i = tasknumber, i2 = 0; i2 < shift*-1; i--, i2++){
            Strings[i] = Strings[i-1];
        }
    }
    Strings[i] = temp;
    free(temp);
    return Strings;
}

void displaySpecificTask(char *String[], int task){
	printf("%d: %s\n", task, String[task-1]);
}

void displayTasks(char *Strings[], int numberoftasks){
	int i;
    printf("\n");
	for(i = 0; i < numberoftasks; i++){
		printf("%d: %s\n", i+1, Strings[i]);
	}
    printf("\n");
}
