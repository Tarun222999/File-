#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int r_no;
    char name[80];
    int marks;
}STUDENT;
int main()
{
    printf(" 0.Write the data \n 1.Append the data to the file \n 2.search the data from the file \n 3.Delete the data from the file \n 4.Modify the data \n 5.Read Complete data") ;
    int ch,x;
    ch=0;
    while(ch==0)
    {
        printf("\nEnter the choice {0,1,2,3,4,5} \n");
        printf("Enter -1 to quit \n ");
        scanf("%d",&x);
        if(x==-1)
        {
            ch=-1;
            break;
        }
        switch(x)
        {
        case 0:
            write();break;
        case 1:
            append(); break;
        case 2:
            search();break;
        case 3:
            deletee();break;
        case 4:
            modify();break;
        case 5:read();break;
        default:printf("\n Invalid choice");
        }
    }

}
void write()
{
     FILE *fp;
     int n,i;

        printf("Enter the no of students \n");
        scanf("%d",&n);
        STUDENT stud1[n];
        fp=fopen("File.TXT","w");
        if(fp==NULL)
        {
            printf("\n File opening error ");
            return 0;
        }
        for(i=0;i<n;i++)
        {
            printf("\n Enter the r_no & name & marks of student %d \n ",i+1);
            scanf("%d%s%d",&stud1[i].r_no,&stud1[i].name,&stud1[i].marks);
        }
        for(i=0;i<n;i++)
        {
            fprintf(fp,"\n %d %s %d",stud1[i].r_no,stud1[i].name,stud1[i].marks);
        }
        fprintf(fp, "\n %d",-1);
        fclose(fp);
}
void append()
    {
        FILE *fp;
        STUDENT stud1;
        fp=fopen("File.TXT","a");
        printf("Enter the r_no and name and marks :");
        scanf("%d%s%d",&stud1.r_no,&stud1.name,&stud1.marks);
        fprintf(fp,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);
        fprintf(fp, "\n %d",-1);
        printf("\n Data Appended");
        fclose(fp);
        return 0;
    }

void search()
{
    FILE *fp;
    int found=0,r_no;
    STUDENT stud1;
    fp=fopen("File.TXT","r");
    printf("Enter the r_no of student whose record has to be read : \n");
    scanf("%d",&r_no);
    while(1)
    {

        fscanf(fp,"%d %s %d",&stud1.r_no,stud1.name,&stud1.marks);
        if(stud1.r_no==-1)
            break;
        if(stud1.r_no==r_no)
        {
            found =1;
            printf("The details of the student are");
            printf("\n r_no :%d name :%s marks : %d",stud1.r_no,stud1.name,stud1.marks);
            break;
        }

    }
    if(found==0)
    {
        printf("\n Record not found in the file ");
    }

    fclose(fp);
    return 0;
}
void deletee()
{
    FILE *fp1,*fp2;
    STUDENT stud1;
    int r_no,found=0;
    fp1=fopen("File.TXT","r");
    fp2=fopen("Temp.TXT","w");
    printf("Enter the roll_no to be deleted");
    scanf("%d",&r_no);
    while(1)
    {
        fscanf(fp1,"%d",&stud1.r_no);
        if(stud1.r_no==-1)
            break;
        if(stud1.r_no==r_no)
        {
            found=1;
            fscanf(fp1," %s %d",stud1.name,&stud1.marks);

        }
        else
        {

            fscanf(fp1," %s %d",stud1.name,&stud1.marks);
            fprintf(fp2,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);
        }
    }
    fprintf(fp2,"\n %d",-1);
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        printf("\n The record with role number does not exist");
    }
    else
    {
        fp1=fopen("File.TXT","w");
        fp2=fopen("Temp.TXT","r");
        while(1)
        {
            fscanf(fp2,"%d",&stud1.r_no);
            if(stud1.r_no==-1)
                break;
            fscanf(fp2," %s %d",stud1.name,&stud1.marks);
            fprintf(fp1,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);

        }

    }
    fprintf(fp1,"\n %d",-1);
    fclose(fp1);
    fclose(fp2);
    printf("Record deleted");
    return 0;

}
void read()
{
    STUDENT stud1;
    FILE *fp;
    fp=fopen("File.TXT","r");
    printf("***Complete Data ***");
    while(1)
    {

        fscanf(fp,"%d %s %d",&stud1.r_no,stud1.name,&stud1.marks);
         if(stud1.r_no==-1)
            break;
        printf("\n Roll no :%d Name : %s Marks : %d",stud1.r_no,stud1.name,stud1.marks);

    }
}

void modify()
{
    FILE *fp1,*fp2;
    STUDENT stud1;
    int r_no,found=0;
    fp1=fopen("File.TXT","r");
    fp2=fopen("Temp1.TXT","w");
    printf("Enter the roll_no of the student whose record has to be modified \n ");
    scanf("%d",&r_no);
    while(1)
    {
        fscanf(fp1,"%d",&stud1.r_no);
        if(stud1.r_no==-1)
            break;
        if(stud1.r_no==r_no)
        {
            found=1;
            fscanf(fp1," %s %d",stud1.name,&stud1.marks);
            printf("\n The details of the existing records are :");
            printf("\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);
            printf("\n Enter the modified name of student ");
            scanf("%s",stud1.name);
            printf("\n Enter the modified marks of the student :");
            scanf("%d",&stud1.marks);
            fprintf(fp2,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);
        }
        else
        {
            fscanf(fp1," %s %d",stud1.name,&stud1.marks);
            fprintf(fp2,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);
        }

    }
    fprintf(fp2,"\n %d",-1);
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        printf("\n The record with role number does not exist");
    }
    else
    {
        fp1=fopen("File.TXT","w");
        fp2=fopen("Temp1.TXT","r");
        while(1)
        {
            fscanf(fp2,"%d",&stud1.r_no);
            if(stud1.r_no==-1)
                break;
            fscanf(fp2," %s %d",stud1.name,&stud1.marks);
            fprintf(fp1,"\n %d %s %d",stud1.r_no,stud1.name,stud1.marks);

        }

    }
    fprintf(fp1,"\n %d",-1);
    fclose(fp1);
    fclose(fp2);
    printf("\n Record Updated");
}
