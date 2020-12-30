#include <stdio.h>
struct fushu{
    float shibu;
    float xubu;
};
/* ��ĳ��򽫷������� */
void add(struct fushu &a, struct fushu &b){
	struct fushu retval;
	retval.shibu = a.shibu + b.shibu;
	retval.xubu = a.xubu + b.xubu;
	a = retval;
}
void mul(struct fushu &a, struct fushu &b){
	struct fushu retval;
	retval.shibu = a.shibu * b.shibu - a.xubu * b.xubu;
	retval.xubu = a.shibu * b.xubu + b.shibu * a.xubu;
	a = retval;
}
void sub(struct fushu &a, struct fushu &b){
	struct fushu retval;
	retval.shibu = a.shibu - b.shibu;
	retval.xubu = a.xubu - b.xubu;
	a = retval;
}
int main()
{
    struct fushu a,b,c,d;
    scanf("%f%fi",&a.shibu,&a.xubu);      //�����һ������
    scanf("%f%fi",&b.shibu,&b.xubu);      //����ڶ�������
    add(a,b);                             //����a=a+b
    mul(a,b);                             //����a=a*b
    scanf("%f%fi",&c.shibu,&c.xubu);      //�������������
    sub(a,c);                             //����a=a-c
    if(a.xubu>0)
      printf("%.2f+%.2fi\n",a.shibu,a.xubu);
    else if(a.xubu<0) printf("%.2f%.2fi\n",a.shibu,a.xubu);
    else printf("%.2f\n",a.shibu);
    return 0;
}
