#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    char description[100];
    int iscompleted;
};

void addtask(struct task tasks[], int* taskcount, const char* description)
{
    if (*taskcount < 100)
    {
        struct task newtask;
        strcpy(newtask.description, description);
        newtask.iscompleted = 0;
        tasks[*taskcount] = newtask;
        (*taskcount)++;
    }
    else
    {
        printf("Task list is full. Cannot add more tasks.\n");
    }
}

void markcomplete(struct task tasks[], int taskcount, int taskindex)
{
    if (taskindex >= 0 && taskindex < taskcount)
    {
        tasks[taskindex].iscompleted = 1;
        printf("Task is completed.\n");
    }
    else
    {
        printf("Invalid.\n");
    }
}

void deletetask(struct task tasks[], int* taskcount, int taskindex)
{
    if (taskindex >= 0 && taskindex < *taskcount)
    {
        for (int i=taskindex; i < *taskcount-1; i++)
        {
            tasks[i] = tasks[i + 1];
        }
        (*taskcount)--;
        printf("Task deleted.\n");
    }
    else
    {
        printf("Invalid.\n");
    }
}

void displaytasks(struct task tasks[], int taskcount, int showcompleted)
{
    printf("\nTo-Do List\n");
    for (int i=0; i<taskcount; i++)
    {
        if (showcompleted || !tasks[i].iscompleted)
        {
            printf("%d. %s [%s]\n", i + 1, tasks[i].description, tasks[i].iscompleted ? "Completed" : "Not Completed");
        }
    }
}

int main()
{
    struct task tasks[100];
    int taskcount = 0;

    while (1)
    {
        printf("1. Add Task\n");
        printf("2. Mark Completed\n");
        printf("3. Delete Completed Task\n");
        printf("4. Show All\n");
        printf("5. Show Pending\n");
        printf("6. Show Completed\n");
        printf("7. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter task description: ");
                char description[100];
                scanf(" %[^\n]", description);
                addtask(tasks, &taskcount, description);
                break;
            case 2:
                printf("Enter task index to mark as completed: ");
                int markindex;
                scanf("%d", &markindex);
                markcomplete(tasks, taskcount, markindex - 1);
                break;
            case 3:
                printf("Enter task index to delete: ");
                int deleteindex;
                scanf("%d", &deleteindex);
                deletetask(tasks, &taskcount, deleteindex - 1);
                break;
            case 4:
                displaytasks(tasks, taskcount, 1);
                break;
            case 5:
                displaytasks(tasks, taskcount, 0);
                break;
            case 6:
                displaytasks(tasks, taskcount, 1);
                break;
            case 7:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid\n");
        }
    }

    return 0;
}