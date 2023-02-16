#include"function.h"
int hash(block* b)
{
	int res=0;
	//H(B) = (((sum(all transaction money in block B))2 ⊕ link(B)) + link(B)2) % 1000 + 1
	res=b->t[0].val+b->t[1].val;
	res=res*res;
	res=res^b->link;
	res=res+b->link*b->link;
	res=res%1000+1;
	return res;
}

// TODO: create a block with the given information and return its address
block* create_block(int currentTail, transaction t[2])
{
	block* resblock;
	resblock=(block*)malloc(sizeof(block));
	for (int i=0;i<2;i++)
	  resblock->t[i]=t[i];
	resblock->link=currentTail;
	return resblock;
}

// TODO: query someone's balance
int query(block_chain *bc, char name[10], int initial_saving)
{
	int i=0,count,index;
	count=initial_saving;
	i=bc->tail;
	
	while (i!=0)
	 {
	   if (bc->block_data[i]->t[0].to[0]==name[0])
	   	count+=bc->block_data[i]->t[0].val;
	   if (bc->block_data[i]->t[1].to[0]==name[0])
	   	count+=bc->block_data[i]->t[1].val;
	   if (bc->block_data[i]->t[0].from[0]==name[0])
	   	count-=bc->block_data[i]->t[0].val;
	   if (bc->block_data[i]->t[1].from[0]==name[0])
	   	count-=bc->block_data[i]->t[1].val;
	   
	   i=bc->block_data[i]->link;
	 }
	
	return count; 
}

void trace(block_chain *bc)
{
	int i;
	i=bc->tail;
	while (i!=0)
	{
		printf("<-%d",i);
		i=bc->block_data[i]->link;
	}
	printf("\n");
}
