#include <iostream>
#include <vector>
using namespace std;

//exercice 1
struct node
{
  int element;
  struct node *next;
};
typedef node *stack;

//push function
void push (int x, stack * L)
{
  node *C = (node *) malloc (sizeof (node));
  if (L == NULL)
    {

      C->element = x;
      C->next = NULL;
      *L = C;
    }
  else
    {
      C->element = x;
      C->next = *L;
      *L = C;

    }
}

//pop function
void pop (stack * L)
{
  if (*L != NULL)
    {
      (*L) = (*L)->next;
      return;

    }
  else
    cout << "stack is empty " << L ;
}

//display function
void display (stack L)
{
  stack temp = L;
  while (temp != NULL)
    {
      cout << temp->element << " ";
      temp = temp->next;
    }
  cout << endl;
}



//exercice 3 
int search(stack L, int x){
    stack temp = L;
    while(temp!=NULL){
        //cout<<"element of temp: "<<temp->element<<endl;
        if(temp->element == x)
            return 0;
        temp=temp->next;
    }
    return 1;
}

//eliminate function
stack eliminate(stack L){
    stack temp, R;
    temp = L;
    R = NULL;
    while(temp!=NULL){
        if(search(R, temp->element)==1){
            push(temp->element,&R);
        }
        temp=temp->next;
    }
    return R;
}



int main ()
{
  stack L = NULL, P = NULL;
  push (4, &L);
  push (6, &L);
  push (78, &L);
  push (6, &L);
  display(L);
  stack M = eliminate(L);
  display(M);
 
  
  

  return 0;
}



