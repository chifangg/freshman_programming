typedef long long ll;
ll* matrix_pow(ll *A, ll b, ll m)
{
 ll* t= (ll*)malloc(4 *sizeof(ll));
 ll* t1= (ll*)malloc(4 *sizeof(ll));
 ll* t2= (ll*)malloc(4 *sizeof(ll));

    if (b==0)
    {
        t[0] = 1;
        t[1] = 0;
        t[2] = 0;
        t[3] = 1;
        return t;
    }
    t = matrix_pow(A, b/2, m);
    if (b%2 == 0)
          {
           t1[0]=(t[0]*t[0]+t[1]*t[2])%m;
           t1[1]=(t[0]*t[1]+t[1]*t[3])%m;
           t1[2]=(t[2]*t[0]+t[3]*t[2])%m;
           t1[3]=(t[2]*t[1]+t[3]*t[3])%m;
           return t1;
    }
    else
    {
     t1[0]=(t[0]*t[0]+t[1]*t[2])%m;
           t1[1]=(t[0]*t[1]+t[1]*t[3])%m;
           t1[2]=(t[2]*t[0]+t[3]*t[2])%m;
           t1[3]=(t[2]*t[1]+t[3]*t[3])%m;
           t2[0]=(t1[0]*A[0]+t1[1]*A[2])%m;
           t2[1]=(t1[0]*A[1]+t1[1]*A[3])%m;
           t2[2]=(t1[2]*A[0]+t1[3]*A[2])%m;
           t2[3]=(t1[2]*A[1]+t1[3]*A[3])%m;
           return t2;
    }


}
