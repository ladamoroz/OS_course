#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
struct node{
  int data;
  struct node* next;
};
struct node *head = NULL;

void print_list(){
  struct node* p = head;
  while (p != NULL){
    printf("%d ",p->data);
    p = p->next;
  }
  printf("\n");
}
void insert_node(int to, int data) {
  struct node *p = (struct node*) malloc(sizeof(struct node));
  p->data = data;
  if (head == NULL){
    printf("List is empty, value will be inserted at the beginning");
    p->next = NULL;
    head = p;
  } else {
      struct node* temp = head;
      while (temp!= NULL){
        if (temp->data == to){
          p->next = temp->next;
          temp->next = p;
          break;
        } else {
          temp = temp->next;
        }
      }
      if (temp == NULL){
        printf("Value cannot be found");
      }
  }
}

void delete_node(int value){
  if (head == NULL){
    printf("List is empty");
  } else {
    struct node* temp = head;
    struct node* prev = NULL;
    while(temp!=NULL){
      if (temp->data == value && temp!=head){
        prev->next = temp->next;
        break;
      } else {
        if (temp->data == value && temp== head){
          head = temp->next;
          break;
        } else {
          prev = temp;
          temp = temp->next;
        }
      }
    }
    if (temp == NULL){
      printf("No such value");
    }
  }
}

int main(){
  insert_node(14, 15);
  print_list();
  insert_node(15, 48);
  print_list();
  insert_node(15, 17);
  print_list();
  delete_node(17);
  print_list();
  delete_node(15);
  print_list();
  delete_node(987);
  return 0;
}