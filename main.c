#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Inputrecord(int number,float score[],int student_number[],char name[][40]);
float Total(float score[],int number);
float Average(float ftotal,int number);
void Hight(float score[],int student_number[],int number,char name[][40]);
void Low (float score[],int student_number[],int number,char name[][40]);
void StuNumSortRise(int student_number[],float score[],int number,char name[][40]);
int Find (int student_number[],float score[],int number,int want);
void NameRise (char name[][40],int number,float score[],int student_number[]);
int NameFind (char name[][40],int number,char namewant[]);

int main()
{
    int ichoice,a,number;
    char name[30][40];
    float score[30];
    int student_number[30];
    int name_number[30];
    flag:printf("       |------------------------------------------------------|\n");
    printf("       |* 1. Input record                                    *|\n");
    printf("       |* 2. Calculate total and average score of course     *|\n");
    printf("       |* 3. Sort in descending order by score               *|\n");
    printf("       |* 4. Sort in ascending order by score                *|\n");
    printf("       |* 5. Sort in ascending order by number               *|\n");
    printf("       |* 6. Sort in dictionary order by name                *|\n");
    printf("       |* 7. Search by number                                *|\n");
    printf("       |* 8. Search by name                                  *|\n");
    printf("       |* 9. Statistic analysis!                             *|\n");
    printf("       |*10. List record                                     *|\n");
    printf("       |* 0. Exit                                            *|\n");
    printf("       |------------------------------------------------------|\n");
    printf("Please enter your choice:");
    scanf("%d",&ichoice);
    if (ichoice==1)
    {
        printf("The number of student is:");
        scanf("%d",&number);
        while(getchar()!='\n');
        Inputrecord(number,score,student_number,name);
        a=1;
        goto flag;
    }
    if (ichoice==2)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            float ftotal,faverage;
            ftotal=Total(score,number);
            faverage=Average(ftotal,number);
            printf("The total is %f and the average is %f\n\n\n",ftotal,faverage);
            goto flag;
        }

    }
    if (ichoice==3)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
          int counter;
            Hight(score,student_number,number,name);
            for (counter=1;counter<=number;counter++)
            {
                printf("%s's score is %f    studentnumber is %d\n",name[counter-1],score[counter-1],student_number[counter-1]);
            }
            goto flag;
        }
    }
    if (ichoice==4)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            int counter;
            Low(score,student_number,number,name);
            for (counter=1;counter<=number;counter++)
            {
                printf("%s's score is %f    studentnumber is %d\n",name[counter-1],score[counter-1],student_number[counter-1]);
            }
            goto flag;
        }
    }
    if (ichoice==5)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            int counter;
            StuNumSortRise(student_number,score,number,name);
            for (counter=1;counter<=number;counter++)
            {
                printf("%s's score is %f\n",name[counter-1],score[counter-1]);
            }
            goto flag;
        }
    }
    if (ichoice==6)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            NameRise(name,number,score,student_number);
            for (int counter=1;counter<=number;counter++)
            {
                printf("%s's score is %f\n",name[counter-1],score[counter-1]);
            }
            goto flag;
        }
    }
    if (ichoice==7)
    {
        int want;
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            int irank=-1;
            printf("Input the student_number's number you want to chack:");
            scanf("%d",&want);
            Hight(score,student_number,number,name);
            irank=Find(student_number,score,number,want);
            if (irank==-1)
            {
                printf("Don't have the person\n");
            }
            else
            {
                printf("The student's score is %f and rank is %d\n",score[irank],irank+1);
            }
            goto flag;
        }
    }
    if (ichoice==8)
    {
        int want2;
        char namewant[40];
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            getchar();
            printf("Input the name you want to find:");
            fgets(namewant,10,stdin);
            namewant[strlen(namewant)-1]='\0';
            Hight(score,student_number,number,name);
            want2=NameFind(name,number,namewant);
            printf("%s's rank is %d and score is %f\n",name[want2],want2+1,score[want2]);
            goto flag;
        }
    }
    if (ichoice==9)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            int excll,good,mid,pass,faile;
            excll=0;
            good=0;
            mid=0;
            pass=0;
            faile=0;
            for (int counter=1;counter<=number;counter++)
            {
                if (score[counter-1]<=100&&score[counter-1]>=90)
                {
                    excll++;
                }
                else if (score[counter-1]<=89&&score[counter-1]>=80)
                {
                    good++;
                }
                else if (score[counter-1]<=79&&score[counter-1]>=70)
                {
                    mid++;
                }
                else if (score[counter-1]<=69&&score[counter-1]>=60)
                {
                    pass++;
                }
                else
                {
                    faile++;
                }
            }
            printf("Excllent:%d  %f%%\nGood:%d  %f%%\nMid:%d  %f%%\nPass:%d  %f\nFaile:%d  %f\n",excll,(float)excll*100/number,good,(float)good*100/number,mid,(float)mid*100/number,pass,(float)pass*100/number,faile,(float)faile*100/number);
            goto flag;
        }
    }
    if (ichoice==10)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            goto flag;
        }
        if (a==1)
        {
            float ftotal,faverage;
            int counter;
            for (counter=1;counter<=number;counter++)
            {
                printf("%-5f   %-10d\n",score[counter-1],student_number[counter-1]);
            }
            ftotal=Total(score,number);
            faverage=Average(ftotal,number);
            printf("The total is %f and the average is %f\n\n\n",ftotal,faverage);
            goto flag;
        }
    }
    if (ichoice==0)
    {
        return 0;
    }
}




void Inputrecord(int number,float score[],int student_number[],char name[][40])
{
    int counter;
    for (counter=1;counter<=number;counter++)
    {
        printf("Please input student's name:");
        fgets(name[counter-1],8,stdin);
        name[counter-1][strlen(name[counter-1])-1]='\0';
        printf("Please input student's score and student_number:");
        scanf("%f %d",&score[counter-1],&student_number[counter-1]);
        while(getchar()!='\n');
    }
}

float Total(float score[],int number)
{
    float ftotal=0;
    int counter;
    for (counter=1;counter<=number;counter++)
    {
        ftotal=ftotal+score[counter-1];
    }
    return ftotal;
}

float Average(float ftotal,int number)
{
    float faverage;
    faverage=ftotal/number;
    return faverage;
}

void Hight(float score[],int student_number[],int number,char name[][40])
{
    char temp_name[40];
    int i,j,k,tem2;
    float tem1;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (score[j]>score[k])
            {
                k=j;
            }
        }
        if (k!=i)
            {
                tem1=score[i];
                score[i]=score[k];
                score[k]=tem1;
                strcpy(temp_name,name[k]);
                strcpy(name[k],name[i]);
                strcpy(name[i],temp_name);
                tem2=student_number[i];
                student_number[i]=student_number[k];
                student_number[k]=tem2;
            }
    }
}

void Low (float score[],int student_number[],int number,char name[][40])
{
    char temp_name[40];
    int i,j,k,tem2;
    float tem1;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (score[j]<score[k])
            {
                k=j;
            }

        }
        if (k!=i)
            {
                tem1=score[i];
                score[i]=score[k];
                score[k]=tem1;
                strcpy(temp_name,name[k]);
                strcpy(name[k],name[i]);
                strcpy(name[i],temp_name);
                tem2=student_number[i];
                student_number[i]=student_number[k];
                student_number[k]=tem2;
            }
    }
}

void StuNumSortRise(int student_number[],float score[],int number,char name[][40])
{
    char temp_name[40];
    int i,j,k,tem2;
    float tem1;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (student_number[j]<student_number[k])
            {
                k=j;
            }
        }
        if (k!=i)
        {
            tem1=score[i];
            score[i]=score[k];
            score[k]=tem1;
            strcpy(temp_name,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp_name);
            tem2=student_number[i];
            student_number[i]=student_number[k];
            student_number[k]=tem2;
        }
    }
}

int Find (int student_number[],float score[],int number,int want)
{
    for (int counter=1;counter<=number;counter++)
    {
        if (want==student_number[counter-1])
        {
            return (counter-1);
        }
    }
    return -1;
}

void NameRise (char name[][40],int number,float score[],int student_number[])
{
    char temp_name[40];
    int k,j,tem2;
    float temp;
    for (int i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (strcmp(name[j],name[k])<0)
            {
                k=j;
            }
        }
        if (k!=i)
        {
            strcpy(temp_name,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp_name);
            temp=score[i];
            score[i]=score[k];
            score[k]=temp;
            tem2=student_number[i];
            student_number[i]=student_number[k];
            student_number[k]=tem2;
        }
    }
}

int NameFind (char name[][40],int number,char namewant[])
{
    for (int counter=1;counter<=number;counter++)
    {
        if (strcmp(namewant,name[counter-1])==0)
            return (counter-1);
    }
    return -1;
}


