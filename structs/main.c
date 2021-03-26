#include "list.h"
#include "zutils.h"
#include <string.h>


bool Terminate() {
    log_warn("All unsaved data will be lost. Exit? y/n");
    printf(":");
    char op;
    fflush(stdin);
    scanf(" %c", &op);
    return !(op == 'y');
}

void AddEmployee(struct Node** head) {
    struct Employee e;
    
    clear();
    printf("# New Employee entry:\n\n");
    printf("Personal information:\n----------------------\n\n");
    printf("  First Name: ");
    scanf("%s", e.first_name);
    printf("  Last Name: ");
    scanf("%s", e.last_name);
    printf("  Gender: ");
    scanf(" %c", &e.gender);
    printf("  Age: ");
    scanf("%hu", &e.age);
    printf("  ID: ");
    scanf("%u", &e.id);
    printf("\nAddress details:\n------------------------\n\n");
    printf("  City: ");
    scanf("%s", e.addr.city);
    printf("  Street: ");
    scanf("%s", e.addr.street);
    printf("  ZIP Code: ");
    scanf("%u", &e.addr.zip_code);

    struct Node* _new = malloc(sizeof(struct Node));
    _new->data = e;
    PushBack(_new, head);
}

void RemoveEmployee(struct Node** head) {}

void ListEmployees(struct Node* head) {
    clear();
    printf("\n\n ++++ EMPLOYEE LIST ++++\n\n\n");
    printf("------------------------------------------\n");
    printf("| ID\t| Name\t\t\t| G, Age |\n");
    printf("==========================================\n");
    struct Node* iter = head;
    while (iter != NULL) {
        printf("| %u\t| %s, %s\t| %c, %hu  |\n", iter->data.id, iter->data.last_name, iter->data.first_name, iter->data.gender, iter->data.age); 
        printf("------------------------------------------\n");
        iter = iter->next;
    }
    printf("\n\n\n");
    printf("Enter any command to close\n\n:");
    char cmd;
    scanf(" %c", &cmd);
    clear();
}

void WriteToDisk(struct Node* head) {
    
}


int main() {
    
    struct Node* head = NULL;
    struct Node* tail = NULL;

    bool running = true;
    while (running) {
        clear();
        printf("---------------------------------\n");
        printf("|      EMPLOYEE MANAGEMENT      |\n");
        printf("---------------------------------\n\n\n");
        printf("Enter any of the available commands:\n");
        printf("------------------------------------\n");
        printf("<add>   : Adds a new entry\n");
        printf("<ls>    : Lists all employees\n");
        printf("<rm>    : Removes an employee\n");
        printf("<d>     : Clears the list\n");
        printf("<w>     : Stores the entries onto disk\n");
        printf("<q>     : Terminates the program\n\n\n");
        printf(":");

        char cmd[10];
        fflush(stdin);
        scanf("%s", cmd);
        if (strcmp(cmd, "add") == 0) {
            AddEmployee(&tail);
            if (head == NULL) head = tail;
            if (tail == NULL) tail = head;
        }
        else if (strcmp(cmd, "ls") == 0) ListEmployees(head);
        else if (strcmp(cmd, "rm") == 0) RemoveEmployee(&head);
        else if (strcmp(cmd, "d") == 0) Clear(&head);
        else if (strcmp(cmd, "w") == 0) WriteToDisk(head);
        else if (strcmp(cmd, "q") == 0) running = Terminate();
        else log_err("Invalid command!", CASUAL);
    }

    Clear(&head);

    return 0;
}
