/*
SYITA145
Department IT has a student's club named 'Pinnacle Club'. The first node for president and the last node for secretary. To maintain club member’s information using a SLL. a) Add and delete b) Compute the total c) Display
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ABC* create();
void AddM(int m , struct ABC *head);
void Display(struct ABC *);
struct ABC* DeleteP(struct ABC*);
void Add_Secretary(struct ABC * head);
void Delete_Member(int r,struct ABC *head);
void Delete_Sec(struct ABC *head);
struct ABC* Reverse(struct ABC* head);

struct ABC{
    int PRN , Roll;
    char Name[15];
    struct ABC *next;
};

int main(){
    int choice,roll_no;
    char ch;
    struct ABC *head, *del;
do{
    printf("\n1) Add President \n2) Add members \n3) Remove President \n4) Add Secretary \n5) Dislplay \n6) Delete member \n7) Reverse \n8) Exit \n\nEnter your choice : ");
    scanf("%d",&choice);

    switch(choice){
        case 1 : head = create();
                break;

        case 2 : printf("\n ENter number of Members : ");
                int m;
                scanf("%d",&m);
                AddM(m,head); 
                break;
        
        case 3 : del=DeleteP(head);
                 head = del;
                 break;
        
        case 4 : Add_Secretary(head);
                break;

        case 5 : Display(head);
                 break;

        case 6 : printf("\n Enter Roll number which you want to delete : ");
                scanf("%d",&roll_no);
                Delete_Member(roll_no,head);
                break;
        
        case 7 : head=Reverse(head);
                break;

        default : printf("\n Invalid choice");
    }

    printf("\n Do you want to continue (Y/N) : ");
    scanf("%c",&ch);

}while(ch=='Y');

return 0;
}

struct ABC* create(){
    struct ABC *node;
    char N[15];
    node = (struct ABC*)malloc(sizeof(struct ABC));
    printf("Enter the PRN , Roll_NO , Name : ");
    scanf("%d%d%s",&node->PRN,&node->Roll,N);

    strcpy(node->Name,N);

    return node;
}

void AddM(int m , struct ABC *head){
    struct ABC *temp;
    char n[15];

    for(int i=0; i<m ; i++){
        temp = (struct ABC*)malloc(sizeof(struct ABC));
        printf("\n Enter PRN , Roll_No , Name : ");
          scanf("%d %d %s", &temp->PRN, &temp->Roll, n);
        strcpy(temp->Name,n);
        temp->next=NULL;
        head->next = temp;
        head = head->next;
    }
}

void Display(struct ABC *head){
    printf("\nPRN \t Roll \t Name");

    while(head!=NULL){
        printf("\n%d\t%d\t%s",head->PRN,head->Roll,head->Name);
        head = head->next;
    }
}

struct ABC* DeleteP(struct ABC *head){
    struct ABC* p;
    p=head;
    head = head->next;
    free(p);
    return head;
}

void Add_Secretary(struct ABC * head){
        struct ABC *temp;

    temp = (struct ABC *)malloc(sizeof(struct ABC));

    char n[15];
    printf("\n Enter PRN , Roll_No , Name : ");
    scanf("%d %d %s", &temp->PRN, &temp->Roll, n);
    strcpy(temp->Name,n);

    while (head != NULL && head->next != NULL)
    {
        head = head->next;
    }
    head->next = temp;
}

void Delete_Member(int r,struct ABC *head){
    struct ABC *q;

    while(head->Roll != r){
        q = head;
        head = head->next;
    }
    q->next = head->next;
} 

void Delete_Sec(struct ABC *head){
    struct ABC *p , *q;

    while(p->next!=NULL){
        q = p;
        p = p->next;
    }
    free(p);
    q->next=NULL;
}

struct ABC* Reverse(struct ABC* head){
    struct ABC *p,*q;

    p=head;
    q=head;
    head=head->next;
    q=head;
    p->next=NULL;

    while(head!=NULL){
        head = head->next;
        q->next = p;
        p=q;
        q=head;
    }

return p;
}