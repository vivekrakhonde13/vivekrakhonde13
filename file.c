- 👋 Hi, I’m @vivekrakhonde13
- 👀 I’m interested in ...
- 🌱 I’m currently learning ...
- 💞️ I’m looking to collaborate on ...
- 📫 How to reach me ...

<!---
vivekrakhonde13/vivekrakhonde13 is a ✨ special ✨ repository because its `README.md` (this file) appears on your GitHub profile.
You can click the Preview link to take a look at your changes.
--->

#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int rno;
    char name[20];
    struct subject
    {
        int scode;
        char sname[20];
        int mark;
    }sub[5];
    int total;
    float per;
}student;

void create ( ) {
     student *s;
     FILE *fp;
     int n , i , j;
     printf("enter how many students you want : ");
     scanf("%d",&n);

     s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt","w");

     for(i=0;i<n;i++)
     {
        s[i].total = 0;
        s[i].per = 0;
        printf("Enter RollNo:  ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%s",&s[i].name);
        for(j=0;j<5;j++)
        {
            printf("Enter Marks of Subject%d: ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total +=s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 5.0;
        fwrite(&s[i],sizeof(student),1,fp);
     }
     fclose(fp) ;

}
void display ( ) {
      student s1;
      int j;
      FILE *fp;
      fp= fopen("mystudents.txt","r");
      while(fread(&s1,sizeof(student),1,fp))
      {
          printf("\n%-5d%-20s",s1.rno,s1.name);
          for(j=0;j<5;j++)
          {
              printf("%4d",s1.sub[j].mark);

          }
          printf("%5d%7.2f",s1.total,s1.per);

      }

      fclose(fp);

}
void append ( )
{
student *s;
     FILE *fp;
     int n , i , j;
     printf("enter how many students you want : ");
     scanf("%d",&n);

     s = (student*)calloc(n, sizeof(student));
    fp = fopen("mystudents.txt","a");

     for(i=0;i<n;i++)
     {
        s[i].total = 0;
        s[i].per = 0;
        printf("Enter RollNo:  ");
        scanf("%d",&s[i]);
        fflush(stdin);
        printf("Enter Name : ");
        scanf("%s",s[i].name);
        for(j=0;j<5;j++)
        {
            printf("Enter Marks of Subject%d : ",j+1);
            scanf("%d",&s[i].sub[j].mark);
            s[i].total +=s[i].sub[j].mark;
        }
        s[i].per = s[i].total / 5.0;
        fwrite(&s[i],sizeof(student),1,fp);
     }
     fclose(fp) ;
     }

void noofrec()
{
     student s1;
     FILE *fp;
     fp = fopen("mystudents.txt","r");
     fseek(fp,0,SEEK_END);
     int n = ftell(fp)/sizeof(student);
     printf("\n\nNO OF RECORDS = %d",n);
     fclose(fp);
}
void search ()
 {
 student s1;
      int j,rno,found=0;
      FILE *fp;
      fp= fopen("mystudents.txt","r");
      printf("Enter rollno to search : ");
      scanf("%d",&rno);
      while(fread(&s1,sizeof(student),1,fp))
      {
          if(s1.rno == rno){
                found=1;
          printf("\n%-5d%-20s",s1.rno,s1.name);
          for(j=0;j<5;j++)
          {
              printf("%4d",s1.sub[j].mark);

          }
          printf("%5d%7.2f",s1.total,s1.per);
          }

      }
     if(!found)
        printf("\nRecord Not Found\n");
      fclose(fp);

 }
 void update ()
 {
 student s1;
      int j,rno,found=0;
      FILE *fp, *fp1;
      fp= fopen("mystudents.txt","r");
      fp1=fopen("temp.txt","w");
      printf("Enter rollno to update : ");
      scanf("%d",&rno);
      while(fread(&s1,sizeof(student),1,fp))
      {
          if(s1.rno == rno){
                s1.total = 0;
                s1.per = 0;
                found=1;
                   fflush(stdin);
        printf("Enter New Name : ");
        scanf("%[^\n]s",s1.name);
        for(j=0;j<5;j++)
        {
            printf("Enter New Marks of Subjects : ",j+1);
            scanf("%d",&s1.sub[j].mark);
            s1.total +=s1.sub[j].mark;
        }
        s1.per = s1.total / 5.0;
         }
        fwrite(&s1,sizeof(student),1,fp1);
      }
      fclose(fp);
      fclose(fp1);
     if(found)
     {
         fp1= fopen("temp.txt","r");
         fp = fopen("mystudents.txt","w");

         while(fread(&s1,sizeof(student),1,fp1))
         {
             fwrite(&s1,sizeof(student),1,fp);
         }
        fclose(fp);
        fclose(fp1);

     }
     else
        printf("\nRecord Not Found\n");

 }
 void delete_rec ( )
 {
     student s1;
      int j,rno,found=0;
      FILE *fp, *fp1;
      fp= fopen("mystudents.txt","r");
      fp1=fopen("temp.txt","w");
      printf("Enter rollno to delete : ");
      scanf("%d",&rno);
      while(fread(&s1,sizeof(student),1,fp))
      {
          if(s1.rno == rno)
            {

                found=1;

         }
         else
            fwrite(&s1,sizeof(student),1,fp1);
      }
      fclose(fp);
      fclose(fp1);
     if(found)
     {
         fp1= fopen("temp.txt","r");
         fp = fopen("mystudents.txt","w");

         while(fread(&s1,sizeof(student),1,fp1))
         {
             fwrite(&s1,sizeof(student),1,fp);
         }
        fclose(fp);
        fclose(fp1);

     }
     else
        printf("\nRecord Not Found\n");

 }
int main ()
{
  int ch;
  do{
         printf("\n\n 1. create");
         printf("\n 2.display");
         printf("\n 3.add");
         printf("\n 4.No Of Records");
         printf("\n 5.search");
         
         printf("\n 6.delete");
         printf("\n 7.stop");

         printf("\n Enter your choice : ");
         scanf("%d",&ch);

         switch(ch)
         {

         case 1:
              create ();
         break;
         case 2:
            display ();
         break;
         case 3:
            append();
          break;
            case 4:
            noofrec();
          break;
           case 5:
            search();
         
          break;
           case 6:
            delete_rec( );
          break;
    }
  }while(ch!=7);

  return 0;
}
