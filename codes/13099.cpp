#include"function.h"
void AddItem( Item* L, int idx, char* name, int price, int discount, int quality )
{
    L[idx].name = (char*)malloc(sizeof(char)*(strlen(name)+1));
    strcpy(L[idx].name, name);
    L[idx].price = price;
    L[idx].discount = discount;
    L[idx].quality = quality;
}
void DeleteList(Item* L, int N)
{
    for(int i = 0; i < N; i++)
    {
        free(L[i].name);
    }
    free(L);
}

int price_cmp( const void* lhs, const void* rhs )
{
    const Item* l = (const Item*) lhs;
    const Item* r = (const Item*) rhs;
    if((l->price)-(l->discount) < (r->price)-(r->discount))
        return -1;
    else if((l->price)-(l->discount) == (r->price)-(r->discount))
        return 0;
    else return 1;
}
int discount_cmp( const void* lhs, const void* rhs )
{
    const Item* l = (const Item*) lhs;
    const Item* r = (const Item*) rhs;
    if(l->discount < r->discount) return 1;
    else if(l->discount == r->discount) return 0;
    else return -1;
}
int quality_cmp( const void* lhs, const void* rhs )
{
    const Item* l = (const Item*) lhs;
    const Item* r = (const Item*) rhs;
    if(l->quality < r->quality) return 1;
    else if(l->quality == r->quality) return 0;
    else return -1;
}

Item* CreateList(int N)
{
    return (Item*)malloc(sizeof(Item)*N);
}










