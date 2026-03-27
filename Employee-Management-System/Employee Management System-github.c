
FILE * del(FILE * fp)
{
 printHead();
printf("\n\t\t\t\\Delete Employee");
Employee e;
int flag=0,tempid,siz=sizeof(e);
FILE *ft;

/* PRECOGS_FIX: use mkstemp to create a unique, secure temporary file */
#include <unistd.h>
#include <fcntl.h>
char tmp_template[] = "tempXXXXXX";
int tmp_fd = mkstemp(tmp_template);
if(tmp_fd == -1) {
    printf("\n\n\t\t\t\\t!!! ERROR creating temp file !!!\n\t\t");
    system("pause");
    return fp;
}

ft = fdopen(tmp_fd, "wb+");
if(!ft) {
    close(tmp_fd);
    unlink(tmp_template);
    printf("\n\n\t\t\t\\t!!! ERROR opening temp stream !!!\n\t\t");
    system("pause");
    return fp;
}

printf("\n\n\tEnter ID number of Employee to Delete the Record");
printf("\n\n\t\t\tID No. : ");
if(scanf("%d",&tempid)!=1) { while(getchar()!='\n'); printf("Invalid ID\n"); fclose(ft); unlink(tmp_template); return fp; }

rewind(fp);

while((fread(&e,siz,1,fp))==1)
{
    if(e.id==tempid)
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",e.name,e.branch,e.id);
    continue;
    }

    fwrite(&e,siz,1,ft);
}

fclose(fp);
fflush(ft);
fsync(fileno(ft));
fclose(ft);

/* atomically replace original file with the secure temporary file */
if(rename(tmp_template, "employeeInfo.txt") != 0) {
    /* rename failed: cleanup and restore state */
    unlink(tmp_template);
    printf("ERROR replacing data file\n");
    return NULL;
}

if((fp=fopen("employeeInfo.txt","rb+"))==NULL)//sohanuzzaman_soad
{
    printf("ERROR");
    return  NULL;
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65);
printf("\n\t");
system("pause");
return fp;
}