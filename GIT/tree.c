#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
   
struct node{  
    int data;  
    struct node *left;  
    struct node *right;  
};  
   

struct node *root = NULL;  
   
 
struct node* createNode(int data){  
    
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
     
    newNode->data = data;  
    newNode->left = NULL;  
    newNode->right = NULL;  
      
    return newNode;  
}  
   

struct queue  
{  
    int front, rear, size;  
    struct node* *arr;  
};  
   

struct queue* createQueue()  
{  
    struct queue* newQueue = (struct queue*) malloc(sizeof( struct queue ));  
   
    newQueue->front = -1;  
    newQueue->rear = 0;  
    newQueue->size = 0;  
  
    newQueue->arr = (struct node**) malloc(100 * sizeof( struct node* ));  
   
    return newQueue;  
}  
   
void enqueue(struct queue* queue, struct node *temp){  
    queue->arr[queue->rear++] = temp;  
    queue->size++;  
}  
   
 
struct node *dequeue(struct queue* queue){  
    queue->size--;  
    return queue->arr[++queue->front];  
}  
   
   

void insertNode(int data) {  

    struct node *newNode = createNode(data);  
 
    if(root == NULL){  
        root = newNode;  
        return;  
    }  
    else {  
        
        struct queue* queue = createQueue();  
      
        enqueue(queue, root);  
          
        while(true) {  
            struct node *node = dequeue(queue);  
          
            if(node->left != NULL && node->right != NULL) {  
                enqueue(queue, node->left);  
                enqueue(queue, node->right);  
            }  
            else {  
                
                if(node->left == NULL) {  
                    node->left = newNode;  
                    enqueue(queue, node->left);  
                }  
                
                else {  
                    node->right = newNode;  
                    enqueue(queue, node->right);  
                }  
                break;  
            }  
        }  
    }  
}  
   

void inorderTraversal(struct node *node) {  

    if(root == NULL){  
        printf("Tree is empty\n");  
        return;  
    }  
    else {  
            
        if(node->left != NULL)  
            inorderTraversal(node->left);  
        printf("%d ", node->data);  
        if(node->right != NULL)  
            inorderTraversal(node->right);  
                
        }  
    }  
            
int main(){  
      
    insertNode(1);  
    printf("Binary tree after insertion: \n");  

    inorderTraversal(root);  
      
    insertNode(2);  
    insertNode(3);  

    printf("\nBinary tree after insertion: \n");  

    inorderTraversal(root);  
      
    insertNode(4);  
    insertNode(5);  

    printf("\nBinary tree after insertion: \n");  

    inorderTraversal(root);  
      
    insertNode(6);  
    insertNode(7);  

    printf("\nBinary tree after insertion: \n");  
  
    inorderTraversal(root);  
      
    return 0;  
}  
