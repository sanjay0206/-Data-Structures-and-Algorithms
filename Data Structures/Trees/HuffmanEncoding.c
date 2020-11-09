#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
        char ch;
        int freq;
        struct node *left,*right;
}node;
node * heap[100];

int heapSize = 0;
void Insert(node * element) {
        heapSize++;
        heap[heapSize] = element;
        int now = heapSize;
        while(heap[now/2] -> freq > element -> freq) {
                heap[now] = heap[now/2];
                now = now / 2;
        }
        heap[now] = element;
}
node * extract_min() {
        node * minElement = heap[1];
        node * lastElement = heap[heapSize--];
        int now, child;
        for(now = 1; now*2 <= heapSize ;now = child)
        {
             child = now*2;
             if(child != heapSize && heap[child+1]->freq < heap[child] -> freq )
                child++;
             if(lastElement -> freq > heap[child] -> freq)
                heap[now] = heap[child];
             else
                break;
        }
        heap[now] = lastElement;
    return minElement;
}
void build_heap(char ch, int freq) {
        node * temp = (node *) malloc(sizeof(node));
        temp -> ch = ch;
        temp -> freq = freq;
        temp -> left = temp -> right = NULL;
        Insert(temp);
}
void Huffman_tree(char ch, int n) {
        if(n == 1)
                printf("char %c code 0\n",ch);
        for(int i=0;i<n-1;i++) {
                node * left =  extract_min();
                node * right = extract_min();
                node * temp = (node *) malloc(sizeof(node));
                temp -> ch = 0;
                temp -> left = left;
                temp -> right = right;
                temp -> freq = left->freq + right -> freq;
                Insert(temp);
        }
}
void encode(node *temp,char *code) {
        if(temp->left == NULL && temp->right == NULL) {
                printf("%c     |  %s\n",temp->ch,code);
                return;
        }
        int length = strlen(code);
        char leftcode[10], rightcode[10];
        strcpy(leftcode,code);
        strcpy(rightcode,code);
        leftcode[length] = '0';
        leftcode[length + 1] = '\0';
        rightcode[length] = '1';
        rightcode[length + 1] = '\0';
        encode(temp->left, leftcode);
        encode(temp->right, rightcode);
}
int main(){
        heap[0] = (node *)malloc(sizeof(node));
        heap[0]->freq = 0;
        int n,  freq;
        printf("Enter the no of characters: ");
        scanf("%d",&n);
        printf("Enter the characters and their frequencies: ");
        char ch;
        for(int i=0;i<n;i++) {
                scanf(" %c",&ch);
                scanf("%d",&freq);
                build_heap(ch, freq);
        }
        Huffman_tree(ch, n);
        node *tree = extract_min();
        char code[10];
        code[0] = '\0';
        printf(" Char | Huffman code ");
        printf("\n--------------------\n");
        encode(tree, code);
}

