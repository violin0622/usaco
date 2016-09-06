#include <stdlib.h>
#include <stdio.h>

typedef struct NODE{
	int color;
	int count;
	struct NODE *pre;
	struct NODE *next;
}node;

node *createHead(char color){
	node *head = (node*)malloc(sizeof(node));
	if(head){
		head->color = color;
		head->count = 1;
		head->pre = head;
		head->next = head;
		return head;
	}else{
		printf("init head node error !\n");
		return NULL;
	}
}

node *newBead(char color, node *head){
	node *p = (node*)malloc(sizeof(node));
	if(p){
		p->color = color;
		p->count = 1;
		p->next = head;
		p->pre = head->pre;
		head->pre->next = p;
		head->pre = p;
		return head;
	}else{
		printf("append beads error !\n");
		return NULL;
	}
}

node *constructBeadsArray(){
	FILE *fin = fopen("beads.in","r");
	FILE *fout = fopen("beads.out", "w");
	int color;
	//get in and ignore the first two numbers including '\n';
	fscanf(fin, "%d", &color);
	fscanf(fin, "%d", &color);

	color = fgetc(fin);
	node *head = createHead(color);
	while((color = fgetc(fin))!='\n'){
		if(color == head->pre->color){
			head->pre->count++;
		}else{
			head = newBead(color, head);
		}
	}
	return head;
}

//if there are white beads enclosured by same color beads,
//change the white beads to that color
//and merge three array of beads
void inverseColor(node *head){
	node *p = head, *temp;
	do{
		if(p->pre->color == p->next->color){
			p->color = p->next->color;
			p->pre->count += p->count + p->next->count;
			temp = p->pre;
			temp->pre->next = p;
			p->pre = temp->pre;
			free(temp);
			temp = p->next;
			temp->next->pre = p;
			p->next = temp->next;
			free(temp);
		}
	}while((p = p->next) != head->next);
}

int main(){
	return 0;
} 
