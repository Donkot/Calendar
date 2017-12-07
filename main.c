#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[42];
    int data,q,w,e,r,y,d,m,dayname;
    int i = -1;
    int error=0;
    w=1;
    e=1;
    q=0;
    printf("enter date in following format: day.month.year\n>> ");
    gets(a);
    int len = strlen(a);
    while (++i != len)
        if (!isdigit(a[i]) && a[i]!=46)
        {
            int j = i--;
            --len;
            while (++j != len+1)
                a[j-1] = a[j];
        }
    a[len] = '\0';
    printf("%s\n",a);
    for (i=len-1; i>-1; i--) {
        if (a[i]!=46){
             q=q+(a[i]-48)*w;
             w=w*10;
        }
        else{
            if (e==1){
                y=q;
                ++e;
            }
            else{
                m=q;
            }
            q=0;
            w=1;
        }
    }
    d=q;
    if (m>12){
        printf("A month can not be more 12");
        error=1;
    }
    else{
            if (m==1 && m==3 && m==5 && m==7 && m==8 && m==10 && m==12){
                if (d>31 && d<1){
                    printf("This month a total of 31 days");
                    error=1;
                }
                else{
                    if (d>30 && m!=2 && d<1){
                    printf("This month a total of 30 days");
                    error=1;
                }
                }
            }
    }
     if (m==2 && d>29 && d<1){
         if (y%4==0 && y%100!=0 || y%400==0){
            printf("This month a total of 29 days");
            error=1;
         }
         else{
            if (d>28 && d<1){
               printf("This month a total of 28 days");
               error=1;
         }
     }
     }
     if (error!=1){
    q = (14 - m) / 12;
    w = y - q;
    e = m + 12 * q - 2;
    dayname=(7000 + (d + w + w / 4 - w / 100 + w / 400 + (31 * e) / 12)) % 7;
     switch(dayname) {
        case 0:  printf("sunday"); break;
        case 1:  printf("monday"); break;
        case 2:  printf("tuesday"); break;
        case 3:  printf("wednesday"); break;
        case 4:  printf("thursday"); break;
        case 5:  printf("friday"); break;
        case 6:  printf("saturday"); break;
}
     }
}
