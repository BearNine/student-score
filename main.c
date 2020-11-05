#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max1 30
#define Max2 6

typedef struct student
    {
        unsigned long int studentID;
        char name[12];
        int score[Max2];
        int stuscoretotal;
        float stuscoreaver;
        int rank;
        int namerank;
    }STUDENT;


void Inputrecord(int number,STUDENT stu[],int clanum);
void NameRise(int number,STUDENT stu[]);
void StuTotal(int number,STUDENT stu[],int clanum);
void StuAver(int number,STUDENT stu[],int clanum);
void Total(int number,STUDENT stu[],int clanum,int total[]);
void Average(int number,int total[],float scoreaver[],int clanum);
void Hight(int number,STUDENT stu[]);
void Low(int number,STUDENT stu[]);
void StuIDrise(int number,STUDENT stu[]);
int IDFind(int number,STUDENT stu[],unsigned long int want);
int NameFind(int number,STUDENT stu[],char namewant[]);
void nextPage();
void NextPage();



int main()
{
    char continue1;
    STUDENT stu[Max1];
    int a,b,clanum,ichoice,number,total[Max2];
    float scoreaver[Max2];
    flag:nextPage();
    printf("       |-----------------------------------------------------------------|\n");
    printf("       |* 1. Input record                                               *|\n");
    printf("       |* 2. Calculate total and average score of every course          *|\n");
    printf("       |* 3. Calculate total and average score of every student         *|\n");
    printf("       |* 4. Sort in descending order by total score of every student   *|\n");
    printf("       |* 5. Sort in ascending order by total score of every student    *|\n");
    printf("       |* 6. Sort in ascending order by number                          *|\n");
    printf("       |* 7. Sort in dictionary order by name                           *|\n");
    printf("       |* 8. Search by number                                           *|\n");
    printf("       |* 9. Search by name                                             *|\n");
    printf("       |*10. Statistic analysis for every course                        *|\n");
    printf("       |*11. List record                                                *|\n");
    printf("       |* 0. Exit                                                       *|\n");
    printf("       |-----------------------------------------------------------------|\n");
    printf("Please enter your choice:");
    scanf("%d",&ichoice);
    nextPage();
    if (ichoice==1)
    {
        printf("The number of student is:");
        scanf("%d",&number);
        printf("The number of class is:");
        scanf("%d",&clanum);
        while(getchar()!='\n');
        Inputrecord(number,stu,clanum);
        a=1;
        StuTotal(number,stu,clanum);
        StuAver(number,stu,clanum);
        Hight(number,stu);
        printf("\n\n\n");
        do
        {
            b=0;
            printf("Please input 1 to continue:");
            scanf("%d",&b);
            while(getchar()!='\n');
        }while(b!=1);
        goto flag;
    }
    if (ichoice==2)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            Total(number,stu,clanum,total);
            Average(number,total,scoreaver,clanum);
            for (int counter=1;counter<=clanum;counter++)
            {
                printf("The %d class total is %d and the average is %f\n",counter,total[counter-1],scoreaver[counter-1]);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==3)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            StuTotal(number,stu,clanum);
            StuAver(number,stu,clanum);
            for (int counter=1;counter<=number;counter++)
            {
                printf("The %s's allscore is %d and the average is %f\n",stu[counter-1].name,stu[counter-1].stuscoretotal,stu[counter-1].stuscoreaver);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==4)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            int counter;
            Hight(number,stu);
            for (counter=1;counter<=number;counter++)
            {
                printf("%s's rank is %d total score is %d\n",stu[counter-1].name,counter,stu[counter-1].stuscoretotal);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==5)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            int counter;
            Low(number,stu);
            for (counter=1;counter<=number;counter++)
            {
                printf("%s's rank is %d total score is %d\n",stu[counter-1].name,number+1-counter,stu[counter-1].stuscoretotal);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==6)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            Hight(number,stu);
            StuIDrise(number,stu);
            for (int counter=1;counter<=number;counter++)
            {
                printf("%s's ID is %ld and allscore is:%d and rank is:%d\n",stu[counter-1].name,stu[counter-1].studentID,stu[counter-1].stuscoretotal,stu[counter-1].rank);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==7)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            NameRise(number,stu);
            for (int counter=1;counter<=number;counter++)
            {
                printf("%s's allsocre is %d and rank is %d\n",stu[counter-1].name,stu[counter-1].stuscoretotal,stu[counter-1].rank);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==8)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            unsigned long int IDwant;
            int want1=-1;
            printf("Please input the studentID you want to chack:");
            scanf("%ld",&IDwant);
            getchar();
            want1=IDFind(number,stu,IDwant);
            if (want1==-1)
            {
                printf("Don't have the student!");
            }
            else
            {
                printf("Name\tRank\tClass1\tClass2\tClass3\tClass4\tClass5\tClass6\t\n");
                printf("%s\t%d\t",stu[want1].name,stu[want1].rank);
                for (int counter=1;counter<=clanum;counter++)
                {
                    printf("%d\t",stu[want1].score[counter-1]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==9)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            int want2=-1;
            char namewant[12];
            while(getchar()!='\n');
            printf("Please input the name you want to chack:");
            fgets(namewant,12,stdin);
            namewant[strlen(namewant)-1]='\0';
            want2=NameFind(number,stu,namewant);
            if (want2==-1)
            {
                printf("Don't have the student!");
            }
            else
            {
                printf("Name\tRank\tClass1\tClass2\tClass3\tClass4\tClass5\tClass6\t\n");
                printf("%s\t%d\t",stu[want2].name,stu[want2].rank);
                for (int counter=1;counter<=clanum;counter++)
                {
                    printf("%d\t",stu[want2].score[counter-1]);
                }
                printf("\n");
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==10)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            int excll,good,mid,pass,faile;
            for (int counter1=1;counter1<=clanum;counter1++)
            {
                excll=0;
                good=0;
                mid=0;
                pass=0;
                faile=0;
                for (int counter2=1;counter2<=number;counter2++)
                {
                    if (stu[counter2-1].score[counter1-1]<=100&&stu[counter2-1].score[counter1-1]>=90)
                    {
                        excll++;
                    }
                    else if (stu[counter2-1].score[counter1-1]<=89&&stu[counter2-1].score[counter1-1]>=80)
                    {
                        good++;
                    }
                    else if (stu[counter2-1].score[counter1-1]<=79&&stu[counter2-1].score[counter1-1]>=70)
                    {
                        mid++;
                    }
                    else if (stu[counter2-1].score[counter1-1]<=69&&stu[counter2-1].score[counter1-1]>=60)
                    {
                        pass++;
                    }
                    else
                    {
                        faile++;
                    }
                }
                printf("The class%d:\nExcllent:%d  %f%%\nGood:%d  %f%%\nMid:%d  %f%%\nPass:%d  %f\nFaile:%d  %f\n\n\n",counter1,excll,(float)excll*100/number,good,(float)good*100/number,mid,(float)mid*100/number,pass,(float)pass*100/number,faile,(float)faile*100/number);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==11)
    {
        if (a!=1)
        {
            printf("Please input record\n");
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
        if (a==1)
        {
            Total(number,stu,clanum,total);
            Average(number,total,scoreaver,clanum);
            printf("Name\tRank\tClass1\tClass2\tClass3\tClass4\tClass5\tClass6\tAllScore\tAverageScore\t\n");
            for (int counter1=1;counter1<=number;counter1++)
            {
                printf("%s\t%d\t",stu[counter1-1].name,stu[counter1-1].rank);
                for (int counter2=1;counter2<=clanum;counter2++)
                {
                    printf("%d\t",stu[counter1-1].score[counter2-1]);
                }
                for(int counter3=1;counter3<=6-clanum;counter3++)
                {
                    printf("\t");
                }
                printf("%d       \t%f\t\n",stu[counter1-1].stuscoretotal,stu[counter1-1].stuscoreaver);
            }
            for (int counter4=1;counter4<=clanum;counter4++)
            {
                printf("Class%d AllSocre is %d and AverageScore is %f\n",counter4,total[counter4-1],scoreaver[counter4-1]);
            }
            printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            goto flag;
        }
    }
    if (ichoice==0)
        return 0;


}


void Inputrecord(int number,STUDENT stu[],int clanum)
{
    int counter;
    switch (clanum)
    {
        case 1:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d",&stu[counter-1].studentID,&stu[counter-1].score[0]);
                while(getchar()!='\n');
            }
            break;
        case 2:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d %d",&stu[counter-1].studentID,&stu[counter-1].score[0],&stu[counter-1].score[1]);
                while(getchar()!='\n');
            }
            break;
        case 3:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d %d %d",&stu[counter-1].studentID,&stu[counter-1].score[0],&stu[counter-1].score[1],&stu[counter-1].score[2]);
                while(getchar()!='\n');
            }
            break;
        case 4:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d %d %d %d",&stu[counter-1].studentID,&stu[counter-1].score[0],&stu[counter-1].score[1],&stu[counter-1].score[2],&stu[counter-1].score[3]);
                while(getchar()!='\n');
            }
            break;
        case 5:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d %d %d %d %d",&stu[counter-1].studentID,&stu[counter-1].score[0],&stu[counter-1].score[1],&stu[counter-1].score[2],&stu[counter-1].score[3],&stu[counter-1].score[4]);
                while(getchar()!='\n');
            }
            break;
        case 6:
            for (counter=1;counter<=number;counter++)
            {
                printf("Pleas input student's name:");
                fgets(stu[counter-1].name,12,stdin);
                stu[counter-1].name[strlen(stu[counter-1].name)-1]='\0';
                printf("Please input studentID and student's score��such as:ID score score score......��:");
                scanf("%d %d %d %d %d %d %d",&stu[counter-1].studentID,&stu[counter-1].score[0],&stu[counter-1].score[1],&stu[counter-1].score[2],&stu[counter-1].score[3],&stu[counter-1].score[4],&stu[counter-1].score[5]);
                while(getchar()!='\n');
            }
            break;
    }
}

void Total(int number,STUDENT stu[],int clanum,int total[])
{
    for (int counter1=1;counter1<=clanum;counter1++)
    {
        total[counter1-1]=0;
       for (int counter2=1;counter2<=number;counter2++)
        {
            total[counter1-1]=total[counter1-1]+stu[counter2-1].score[counter1-1];
        }
    }
}

void StuTotal(int number,STUDENT stu[],int clanum)
{
    for (int counter1=1;counter1<=number;counter1++)
    {
        stu[counter1-1].stuscoretotal=0;
        for (int counter2=1;counter2<=clanum;counter2++)
        {
            stu[counter1-1].stuscoretotal=stu[counter1-1].stuscoretotal+stu[counter1-1].score[counter2-1];
        }
    }
}

void StuAver(int number,STUDENT stu[],int clanum)
{

    for (int counter=1;counter<=number;counter++)
    {
        stu[counter-1].stuscoreaver=(float)stu[counter-1].stuscoretotal/(float)clanum;
    }
}

void Average(int number,int total[],float scoreaver[],int clanum)
{
    for (int counter1=1;counter1<=clanum;counter1++)
    {
        scoreaver[counter1-1]=(float)total[counter1-1]/(float)number;
    }
}

void Hight(int number,STUDENT stu[])
{
    STUDENT temp;
    int i,k,j;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (stu[j].stuscoretotal>stu[k].stuscoretotal)
            {
                k=j;
            }
        }
        if (k!=i)
        {
            temp=stu[k];
            stu[k]=stu[i];
            stu[i]=temp;
        }
    }
    for (int counter=1;counter<=number;counter++)
    {
        stu[counter-1].rank=counter;
    }
}

void Low(int number,STUDENT stu[])
{
    STUDENT temp;
    int i,k,j;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (stu[j].stuscoretotal<stu[k].stuscoretotal)
            {
                k=j;
            }
        }
        if (k!=i)
        {
            temp=stu[k];
            stu[k]=stu[i];
            stu[i]=temp;
        }
    }
}

void StuIDrise(int number,STUDENT stu[])
{
    STUDENT temp;
    int i,k,j;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (stu[j].studentID<stu[k].studentID)
            {
                k=j;
            }
        }
        if (k!=i)
        {
            temp=stu[i];
            stu[i]=stu[k];
            stu[k]=temp;
        }
    }
}

void NameRise(int number,STUDENT stu[])
{
    STUDENT temp;
    int i,j,k;
    for (i=0;i<number-1;i++)
    {
        k=i;
        for (j=i+1;j<number;j++)
        {
            if (strcmp(stu[j].name,stu[k].name)<0)
            {
                k=j;
            }
        }
        if (k!=i)
        {
            temp=stu[i];
            stu[i]=stu[k];
            stu[k]=temp;
        }
    }
    for (int counter=1;counter<=number;counter++)
    {
        stu[counter-1].namerank=counter;
    }
}

int IDFind(int number,STUDENT stu[],unsigned long int want)
{
    for (int counter=1;counter<=number;counter++)
    {
        if (want==stu[counter-1].studentID)
        {
            return counter-1;
        }
    }
    return -1;
}

int NameFind(int number,STUDENT stu[],char namewant[])
{
    for (int counter=1;counter<=number;counter++)
    {
        if (strcmp(namewant,stu[counter-1].name)==0)
        {
            return counter-1;
        }
    }
    return -1;
}

void nextPage()
{
    system("cls");
}

void NextPage()
{
    int b;
    printf("\n\n\n");
            do
            {
                b=0;
                printf("Please input 1 to continue:");
                scanf("%d",&b);
                while(getchar()!='\n');
            }while(b!=1);
            system("cls");
}
