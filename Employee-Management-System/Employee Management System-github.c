
void modify(FILE * fp)
{
    printHead();
    printf("\n\t\t\t\Modify Employee");
    Employee e;
    int i,flag=0,tempid,siz=sizeof(e);
    char linebuf[256];

    printf("\n\n\tEnter ID Number of Employee to Modify the Record : ");
    if (fgets(linebuf, sizeof(linebuf), stdin) == NULL) return; /* handle EOF */
    tempid = (int)strtol(linebuf, NULL, 10);

    rewind(fp);

    while((fread(&e,siz,1,fp))==1)
    {
        if(e.id==tempid)
        {
            flag=1; //sohanuzzaman_soad
            break;
        }
    }

    if(flag==1)
    {
        if (fseek(fp,-siz,SEEK_CUR) != 0) {
            printf("\n\n\tFailed to position file for update.");
            return;
        }
        printf("\n\n\t\tRecord Found");
        printf("\n\n\t\tEnter New Data for the Record");

        /* Read ID number safely */
        printf("\n\n\t\tEnter ID number: ");
        if (fgets(linebuf, sizeof(linebuf), stdin) == NULL) return; /* PRECOGS_FIX: avoid scanf; use fgets+strtol to robustly parse */
        e.id = (int)strtol(linebuf, NULL, 10);

        /* Helper: read into e.* with bounds checking and safe newline strip */
        /* Full Name */
        printf("\n\n\t\tEnter Full Name of Employee: ");
        if (fgets(e.name, sizeof(e.name), stdin) != NULL) {
            size_t L = strlen(e.name);
            if (L > 0 && e.name[L-1] == '\n') e.name[L-1] = '\0';
            else e.name[sizeof(e.name)-1] = '\0';
        } else {
            e.name[0] = '\0';
        }

        /* Designation */
        printf("\n\n\t\tEnter Designation: ");
        if (fgets(e.desgn, sizeof(e.desgn), stdin) != NULL) {
            size_t L = strlen(e.desgn);
            if (L > 0 && e.desgn[L-1] == '\n') e.desgn[L-1] = '\0';
            else e.desgn[sizeof(e.desgn)-1] = '\0';
        } else {
            e.desgn[0] = '\0';
        }

        /* Gender */
        printf("\n\n\t\tEnter Gender: ");
        if (fgets(e.gender, sizeof(e.gender), stdin) != NULL) {
            size_t L = strlen(e.gender);
            if (L > 0 && e.gender[L-1] == '\n') e.gender[L-1] = '\0';
            else e.gender[sizeof(e.gender)-1] = '\0';
        } else {
            e.gender[0] = '\0';
        }

        /* Branch */
        printf("\n\n\t\tEnter Branch: ");
        if (fgets(e.branch, sizeof(e.branch), stdin) != NULL) {
            size_t L = strlen(e.branch);
            if (L > 0 && e.branch[L-1] == '\n') e.branch[L-1] = '\0';
            else e.branch[sizeof(e.branch)-1] = '\0';
        } else {
            e.branch[0] = '\0';
        }

        /* Salary - parse via fgets to validate */
        printf("\n\n\t\tEnter Salary: ");
        if (fgets(linebuf, sizeof(linebuf), stdin) != NULL) {
            char *endptr = NULL;
            e.sal = strtof(linebuf, &endptr);
            if (endptr == linebuf) e.sal = 0.0f; /* fallback on parse failure */
        } else {
            e.sal = 0.0f;
        }

        /* Present Address */
        printf("\n\n\t\tEnter Present Address: ");
        if (fgets(e.psaddr, sizeof(e.psaddr), stdin) != NULL) {
            size_t L = strlen(e.psaddr);
            if (L > 0 && e.psaddr[L-1] == '\n') e.psaddr[L-1] = '\0';
            else e.psaddr[sizeof(e.psaddr)-1] = '\0';
        } else {
            e.psaddr[0] = '\0';
        }

        /* Permanant Address */
        printf("\n\n\t\tEnter Permanant Address: ");
        if (fgets(e.prtaddr, sizeof(e.prtaddr), stdin) != NULL) {
            size_t L = strlen(e.prtaddr);
            if (L > 0 && e.prtaddr[L-1] == '\n') e.prtaddr[L-1] = '\0';
            else e.prtaddr[sizeof(e.prtaddr)-1] = '\0';
        } else {
            e.prtaddr[0] = '\0';
        }

        /* Phone */
        printf("\n\n\t\tEnter Phone: ");
        if (fgets(e.phone, sizeof(e.phone), stdin) != NULL) {
            size_t L = strlen(e.phone);
            if (L > 0 && e.phone[L-1] == '\n') e.phone[L-1] = '\0';
            else e.phone[sizeof(e.phone)-1] = '\0';
        } else {
            e.phone[0] = '\0';
        }

        /* E-mail */
        printf("\n\n\t\tEnter E-mail: ");
        if (fgets(e.mail, sizeof(e.mail), stdin) != NULL) {
            size_t L = strlen(e.mail);
            if (L > 0 && e.mail[L-1] == '\n') e.mail[L-1] = '\0';
            else e.mail[sizeof(e.mail)-1] = '\0';
        } else {
            e.mail[0] = '\0';
        }

        if (fwrite(&e,sizeof(e),1,fp) != 1) {
            printf("\n\n\tFailed to write updated record to file.");
        }
    }
    else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

    printf("\n\n\t");
    system("pause");
}