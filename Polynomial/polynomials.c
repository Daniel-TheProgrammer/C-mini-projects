#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int option;

struct Poly_Node{ 
  int coef;
  int exp;
  struct Poly_Node *link;  
};

//functions
void insertTerms(struct Poly_Node **,int,int);
void traverse(struct Poly_Node *);

int main(){
    //Do until input is zero
    printf("\n\t IMPLEMENTATION OF POLYNOMIAL WITH Linked List IN C \t\n");
    printf("\n Create your two polynomials i.e P(x) and Q(x): \t");
    //creating polynomials structures
    struct Poly_Node *start_p=NULL,*start_q=NULL,*start_r=NULL;
    //vars
    int i,n,c,e;

    //Getting polynomial coef and exp
    printf("\n\tEnter P(X)!\n");
    printf("\tEnter Number of terms:");
    scanf("%d",&n);

    for(i=0;i<n;i++){ 
    
      printf("Enter coefficient %d: ", i+1);
      scanf("%d",&c);
      printf("Enter exponent %d: ", i+1);
      scanf("%d",&e);
      insertTerms(&start_p,c,e);

    }

    printf("\n\tEnter second polynomial!\n");
    printf("\tEnter Number of terms:");
    scanf("%d",&n);

    for(i=0;i<n;i++){ 
    
    printf("Enter coefficient %d: ", i+1);
    scanf("%d",&c);
    printf("Enter exponent %d: ", i+1);
    scanf("%d",&e);
    insertTerms(&start_q,c,e);

  }


    do{

        printf("\n\t Choose an option: \t\n");
        printf("\n\t 1.DISPLAY Polynomials \n\t 2.DEQUEUE \n\t 3.traverse queue Elements \n\t 4.Size of queue \n\t 5.Head of queue \n\t 6.End of queue \n\t 0.Exit Program \t");
        printf("\n\n\t");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");

                  printf("\nP(x) = ");
                  traverse(start_p);

                  printf("\nQ(x) = ");
                  traverse(start_q);

                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 2:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //dequeue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 3:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //traverse_queue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            case 4:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //queue_size();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 5:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //headOfQueue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
                case 6:
                {
                  system("cls");
                  printf("\n\t__________________________________________________\t\t\n");
                  //endOfQueue();
                  printf("\n\t__________________________________________________\t\t\n");
                  break;
                }
            default:
                {
                    system("cls");
                    printf("\n\t__________________________________________________\t\t\n");
                    printf("\n Invalid option or program is exiting: \n");
                    printf("\n\t__________________________________________________\t\t\n");
                }
        }

    }while(option != 0);
    getch();
}

void insertTerms(struct Poly_Node **start,int c,int e){
  struct Poly_Node *temp,*temp1,*prev;

  if (*start==NULL){
    temp=(struct Poly_Node*)malloc(sizeof(struct Poly_Node));
    if (temp==NULL){
      printf("Poly_Node is not created, Term cannot be inserted\n");
    }
    else{ 
      temp->coef=c;
      temp->exp=e;
      temp->link=NULL;
      *start=temp;
    }
  }
  else{
    temp1=*start;
    while (temp1!=NULL && temp1->exp>e){
      prev=temp1;
      temp1=temp1->link;
    }

    if(temp1==NULL){
      temp=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));
      if (temp==NULL){
      printf("Poly_Node is not created, Term cannot be inserted\n");
      }
      else{ 
        temp->coef=c;
        temp->exp=e;
        temp->link=NULL;
        prev->link=temp;
      }
    }//ENDIF
    else
    {
      if(temp1->exp==e){
        temp1->coef=temp1->coef+c;
      }
      else
      {
        if(temp1==*start){
          temp=(struct Poly_Node *)malloc (sizeof (struct Poly_Node));

            if(temp==NULL){
              printf("Poly_Node is not created\n");
            }
            else
            { 
              temp->coef=c;
              temp->exp=e;
              temp->link=*start;
              *start=temp;

            }
        }//end if
        else
        {
          temp=(struct Poly_Node *)malloc(sizeof(struct Poly_Node));

          if (temp==NULL){
            printf("Poly_Node is not created\n");
          }
          else
          { 
            temp->coef=c;
            temp->exp=e;
            temp->link=temp1;
            prev->link=temp;

          }//endesle
        }
        
      }
      
    }
    
  }
}//end funct


void traverse(struct Poly_Node *start){
  struct Poly_Node *temp;
  temp=start;

  if (temp==NULL){
    printf("Empty polynomial\n");
  }
  else
  {
    while(temp!=NULL){
      printf("%d x^%d",temp->coef,temp->exp);
      temp=temp->link;
      if(temp!=NULL)
        printf(" + ");
      else
        printf("\n");
      
    }
  }
  
}//End Traverse
