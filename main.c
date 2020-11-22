
//..............................................................................................................................................................................................................

#include<stdio.h>                                                                                        //Header Files
#include<unistd.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


//..............................................................................................................................................................................................................                                                                                        //User Defined Function

                                                                                                        //User defined functions

void Main_Menu();                                                                                       //Main Menu
void Student_Panel();                                                                                   //Student Login
void Admin_Panel();                                                                                     //Admin panel { Accessible after login only }
void print_file(FILE *in);                                                                              //Printing File data on screen by accepting file name
void New_Registration();                                                                                // New registration of students after student login
void Store();                                                                                           //Retrieval of data from text file to Linked List
void userlogin();                                                                                       //Admin login
void Print_data();                                                                                      //Printing data from file
void search();                                                                                          //searching operation using PRN { Admin Access Only }
void keyword();                                                                                         //searching operation using keyword { Admin Access Only }
void Removing();                                                                                        //Removing last ASCII value from each variable of node


//..............................................................................................................................................................................................................

                                                                                                        //For preventing Buffer flow
char temp;


//..............................................................................................................................................................................................................


struct Student_data                                                                                     //Student Data
{
    int PRN;
    char Data[21][100];
    char Marks[4][100];
    struct Student_data *Next;
    // Data[0]=Student Name
    // Data[1]=Father Name
    // Data[2]=Mother Name
    // Data[3]=Student Phone Number
    // Data[4]=Father phone Number
    // Data[5]=Mother Phone number
    // Data[6]=Male/Female
    // Data[7]=Student Email ID
    // Data[8]=Alternative Email ID
    // Data[9]=Plot No./House No.
    // Data[10]=Colony/Society
    // Data[11]=Area
    // Data[12]=City
    // Data[13]=District
    // Data[14]=State
    // Data[15]=Date of Birth
    // Data[16]=Caste
    // Data[17]=Adhara Card Number
    // Data[18]=Blood Group
    // Data[19]=Identification Mark
    // Data[20]=Branch
    // Marks[0]=HSC
    // Marks[1]=SSC
    // Marks[2]=CET
    // Marks[3]=JEE
};


struct Student_data *start ,*current , *Temp;


//..............................................................................................................................................................................................................


struct user                                                                                         //admin Login
{
    char username[10];
    char password[10];
}*pUser;


//..............................................................................................................................................................................................................


int main()                                                                                             //Main funtion
{
    FILE *File;
    File=fopen("Welcome.txt","r");

    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**      Welcome to Project Based Learning       **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Move To Next Window________________________________");
    scanf("%c",&temp);
    system("cls");

    print_file(File);
    fclose(File);
    printf("\n\n\n_______________________________Press Enter To Move To Next Window________________________________");
    scanf("%c",&temp);
    system("cls");
    Store();
    Removing();
    Main_Menu();

    return 0;

}


//..............................................................................................................................................................................................................


void Main_Menu()                                                                                        //Main Menu
{
    int choice;

    system("cls");
    printf("\n 1. Student Panel \n 2. Admin Panel \n 3. Help\n 4. Exit\n\n Enter Your Choice : - ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        Student_Panel();
        break;
    case 2:
        system("cls");
        userlogin();
        break;
    case 3:
        system("cls");
        printf("\n\n\n\n");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**                                              **");
        printf("\n\t\t\t\t**            Welcome to Help Portal            **");
        printf("\n\t\t\t\t**                                              **");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**************************************************\n\n\n");
        sleep(5);
        system("cls");
        FILE *File;
        File=fopen("Help.txt","r");
        if(File!=NULL)
        {
            print_file(File);
        }
        sleep(20);
        fclose(File);

        break;
    case 4:
        system("cls");
        return;
        break;
    default:
        printf("\nWrong Choice !!!!\n'''TRY AGAIN'''");
        Main_Menu();
    }

}


//..............................................................................................................................................................................................................


void Student_Panel()                                                                                   //Student Login
{
    int choice,i;

    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**          Welcome to Student Panel            **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Move To Next Window________________________________");

    scanf("%c",&temp);
    scanf("%c",&temp);
    system("cls");

    Again:
    printf("\n 1. New Registration\n 2. Help\n\n Enter Your Choice : - ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        system("cls");
        New_Registration();
        break;
    case 2:
        system("cls");
        printf("\n\n\n\n");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**                                              **");
        printf("\n\t\t\t\t**            Welcome to Help Portal            **");
        printf("\n\t\t\t\t**                                              **");
        printf("\n\t\t\t\t**************************************************");
        printf("\n\t\t\t\t**************************************************\n\n\n");
        sleep(5);
        system("cls");
        FILE *File;
        File=fopen("Help.txt","r");
        if(File!=NULL)
        {
            print_file(File);
        }
        fclose(File);
        break;
    default:
        system("cls");
        printf("\nWrong Choice !!!!\n'''TRY AGAIN'''\n");
        goto Again;
    }
    system("cls");
    printf("\nReturning To Main Menu ");
    for(i=0;i<4;i++)
    {
        sleep(1.5);
        printf("@");
    }
    Main_Menu();


}


//..............................................................................................................................................................................................................


void Admin_Panel()                                                                                     //Admin panel { Accessible after login only }
{
    int a,i;
    system("cls");
    printf("\n\n\n\n");;
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**            Welcome to Admin Panel            **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Move To Next Window ________________________________\n");

    Again:
    printf("\n1.All Student Data\n2.Search\n3.Back to Menu\n4.Exit\nEnter Your Choice : ");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        Print_data();
        break;
    case 2:
        search();
        break;
    case 4:
        return;
        break;
    case 3:
        system("cls");
        printf("\nReturning To Main Menu ");
        for(i=0;i<4;i++)
        {
            sleep(1.5);
            printf("@");
        }
        Main_Menu();
    default:
        printf("\nWrong Choice!!!!!!!!!!!!TRY AGAIN");
        goto Again;
    }
}


//..............................................................................................................................................................................................................


void print_file(FILE *in)                                                                               //Printing File data on screen by accepting file name
{
    char ch=0;
    while(!feof(in))
    {
        ch = (char) getc(in);
        if (ferror(in))
        {
            fputs ("File error - Reading Operation",stderr);
            exit (EXIT_FAILURE);
        }
        if (!feof(in))
        {
            putchar(ch);
        }
    }
    return;
}


//..............................................................................................................................................................................................................


void New_Registration()                                                                                 // New registration of students after student login
{

    char a[100];
    float m;
    FILE *fp;
    fp=fopen("Student.txt","a+");                //Opening student data file

    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**       Welcome to Regestration Portal         **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Move To Next Window ________________________________");
    scanf("%c",&temp);
    scanf("%c",&temp);
    system("cls");
    if(fp==NULL)
    {
        printf("\nSorry");
    }

//__________________________________________________________________________________________Entering Student DATA

    printf("\n****************************Welcome to New Student Registration********************************\n\n");


    printf("\nYour Personal identification number is %d",current->PRN+1);
    fprintf(fp,"\n%d\n",current->PRN+1);

    printf("\n------------------Personal Details------------------");

    printf("\nStudent Name : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nFather Name: ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nMother Name: ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nStudent Phone Number: ");
    gets(a);
    fprintf(fp," %s\n",a);

    printf("\nFather Phone Number: ");
    gets(a);
    fprintf(fp," %s\n",a);

    printf("\nMother Phone Number: ");
    gets(a);
    fprintf(fp," %s\n",a);

    printf("\nGender [Male/Female/Prefer Not to Say] : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nEmail ID: ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nAlternative Email ID: ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nAddresses - ");

    printf("\nPlot No./House No. : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nColony/Society : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nArea : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nCity : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nDistrict : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nState : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));


    printf("\n\n------------------Extra Details------------------");

    printf("\nDate of Birth (DD/MM/YYYY) : ");
    gets(a);
    fprintf(fp," %s\n",a);

    printf("\nCaste : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nAadhar Number: ");
    gets(a);
    fprintf(fp," %s\n",a);

    printf("\nBlood Group(e.g.A+): ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nIdentification Mark: ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\nBranch : ");
    gets(a);
    fprintf(fp," %s\n",strupr(a));

    printf("\n\n------------------Educational Details------------------");

    printf("\nHSC Marks: ");
    scanf("%f",&m);
    fprintf(fp,"%f\n",m);

    printf("\nSSC Marks: ");
    scanf("%f",&m);
    fprintf(fp,"%f\n",m);

    printf("\nCET Percentile (If not then type NO ): ");
    scanf("%f",&m);
    fprintf(fp,"%f\n",m);

    printf("\nJEE Percentile (If not then type NO ): ");
    scanf("%f",&m);
    fprintf(fp,"%f",m);

    fclose(fp);
    printf("\n****************************Thank You********************************");


}


//..............................................................................................................................................................................................................


void Store()                                                                                           //Retrieval of data from text file to Linked List
{
    char z[100];
    int i;
    FILE *fp;
    fp=fopen("Tempp.txt","w+");

    FILE *Sdata;
    Sdata=fopen("Student.txt","r+");
    start = malloc(sizeof(struct Student_data));

    printf("\n\n\nRestoring Data From File");
    for(i=0;i<6;i++)
    {
        sleep(1);
        printf(".");
    }
    printf("\n\nData Restoring Process Completed");
    sleep(3);

    if(Sdata==NULL)
    {
        printf("\nUnable to read the data file\nPlease contact with admin\n...Thank You\n");
    }
    else
    {
        fscanf(Sdata,"%d",&start->PRN);
        fgets(z,100,Sdata);
        fprintf(fp,"%d\n",start->PRN);

        for(i=0;i<21;i++)
        {
            fgets(start->Data[i],100,Sdata);
            fprintf(fp,"%s\n",start->Data[i]);
        }
        for(i=0;i<4;i++)
        {
            fgets(start->Marks[i],100,Sdata);
            fprintf(fp,"%s\n",start->Marks[i]);
        }

        start->Next=NULL;
        Temp=start;
        while(!feof(Sdata))
        {
            current=malloc(sizeof(struct Student_data));
            fscanf(Sdata,"%d",&current->PRN);
            fprintf(fp,"%d\n",current->PRN);
            fgets(z,100,Sdata);
            for(i=0;i<21;i++)
            {
                fgets(current->Data[i],100,Sdata);
                fprintf(fp,"%s\n",current->Data[i]);
            }
            for(i=0;i<4;i++)
            {
                fgets(current->Marks[i],100,Sdata);
                fprintf(fp,"%s\n",current->Marks[i]);
            }
            current->Next=NULL;
            Temp->Next=current;
            Temp=current;
        }
    }
    fclose(Sdata);

}


//..............................................................................................................................................................................................................


void Store1()                                                                                           //Tempp.txt
{
    char z[100];
    int i;

    FILE *Sdata;
    Sdata=fopen("Tempp.txt","r+");
    start = malloc(sizeof(struct Student_data));
    if(Sdata==NULL)
    {
        printf("\nUnable to read the data file\nPlease contact with admin\n...Thank You\n");
    }
    else
    {
        fscanf(Sdata,"%d",&start->PRN);
        fgets(z,100,Sdata);


        for(i=0;i<21;i++)
        {
            fgets(start->Data[i],100,Sdata);
        }
        for(i=0;i<4;i++)
        {
            fgets(start->Marks[i],100,Sdata);
        }

        start->Next=NULL;
        Temp=start;
        while(!feof(Sdata))
        {
            current=malloc(sizeof(struct Student_data));
            fscanf(Sdata,"%d",&current->PRN);
            fgets(z,100,Sdata);
            for(i=0;i<21;i++)
            {
                fgets(current->Data[i],100,Sdata);
            }
            for(i=0;i<4;i++)
            {
                fgets(current->Marks[i],100,Sdata);
            }
            current->Next=NULL;
            Temp->Next=current;
            Temp=current;
        }
    }
    fclose(Sdata);
}


//..............................................................................................................................................................................................................


void userlogin()                                                                                         //Admin login
{
    FILE *fp;
    char uName[10], pwd[10];
    int i,login=0;
    char c;

    pUser=(struct user *)malloc(sizeof(struct user));

    system("cls");
    Login:
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**           Welcome to Login Portal            **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Login ________________________________\n");
    scanf("%c",&temp);
    scanf("%c",&temp);


    printf("\n\n Login Through Your Credential\nPress 1 For Login : ");
    scanf("%d",& i);
    //system("cls");
    switch(i){
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL)
            {
                if ( ( fp=fopen("user.dat", "w+")) == NULL)
                {
                    printf ("Could not open file\n");
                    exit(1);
                }
            }
            printf("\nUsername: ");
            scanf("%9s",uName);
            printf("\nPassword: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1)
            {
                if( strcmp ( pUser->username, uName) == 0)
                {

                    system("cls");
                    printf ("\n\n!!!!!!!!!!Checking Crediential");
                    sleep(3);
                    printf("\n\nRegistered Username Found\n");
                    sleep(3);

                    if( strcmp ( pUser->password, pwd) == 0)
                    {
                        free(pUser);                                                                                          //free allocated memory
                        printf ("\nCredential Match Succefully\n*****LOGIN SUCCESFULL*****\n     ^^^^^^^^^^^^^^^^\n");
                        Admin_Panel();
                        return;
                    }
                    else
                    {
                        printf("\nUnathorized Access Detected [ Password Not Match ] !!!! Automated System Logout Performing \n\n");
                        sleep(2);
                        return;
                    }
                }
            }
            if(login==0)
            {
                system("cls");
                printf("\n\n\n\n\t\t!!!!!!!!!!!!!!!!! W A R N I N G !!!!!!!!!!!!!!!!!\n\nUnathorized Access Detected !!!! Automated System Logout Performing \n\n");
                sleep(2);
            }
            break;

        case 6268:
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL)
                {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL)
                    {
                        printf ("Could not open file\n");
                        exit(1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
                printf("Add another account? (Y/N): ");
                scanf(" %c",&c);                                                                        //skip leading whitespace
            }while(c=='Y'||c=='y');
            break;
        default:
            system("cls");
            printf("\nWrong Choice!!!\nTRY AGAIN\n");
            goto Login;
    }

    free ( pUser);                                                                                      //free allocated memory
    fclose(fp);
}


//..............................................................................................................................................................................................................


void Print_data()                                                                                        //Printing data from file
{
    int i=0,a;
    struct Student_data *p=start;
    if(start==NULL)
    {
        printf("\nEmpty List");
        return;
    }
    else
    {
        system("cls");
        printf("------------------------------------------------------------------------");
        while(p!=NULL)
        {
            i++;
            printf("\nSr_No. : %d\n\nPRN : %d\n\nName :%s\nEmail : %s\nPhone No. : %s\n",i,p->PRN,p->Data[0],p->Data[7],p->Data[3]);
            printf("------------------------------------------------------------------------");
            p=p->Next;
        }
        printf("\n\nEnter Sr No. For More Information : ");
        scanf("%d",&a);
        p=start;
        for(i=1;i<a;i++)
        {
            p=p->Next;
        }
        system("cls");
        printf("\n____________________________________________________________________________________________________________\n\n");
        printf("\nPRN : %d",p->PRN);
        sleep(0.5);
        printf("\nStudent Name : %s",p->Data[0]);
        sleep(0.5);
        printf("\nFather Name: %s",p->Data[1]);
        sleep(0.5);
        printf("\nMother Name: %s",p->Data[2]);
        sleep(0.5);
        printf("\nStudent Phone Number: %s",p->Data[3]);
        sleep(0.5);
        printf("\nFather Phone Number: %s",p->Data[4]);
        sleep(0.5);
        printf("\nMother Phone Number: %s",p->Data[5]);
        sleep(0.5);
        printf("\nGender : %s",p->Data[6]);
        sleep(0.5);
        printf("\nEmail ID: %s",p->Data[7]);
        sleep(0.5);
        printf("\nAlternative Email ID: %s",p->Data[8]);
        sleep(0.5);
        printf("\n\nAddresses - ");
        sleep(0.5);
        printf("\nPlot No./House No. : %s",p->Data[9]);
        sleep(0.5);
        printf("\nColony/Society : %s",p->Data[10]);
        sleep(0.5);
        printf("\nArea : %s",p->Data[11]);
        sleep(0.5);
        printf("\nCity : %s",p->Data[12]);
        sleep(0.5);
        printf("\nDistrict : %s",p->Data[13]);
        sleep(0.5);
        printf("\nState : %s",p->Data[14]);
        sleep(0.5);
        printf("\n\n------------------Extra Details------------------");
        printf("\nDate of Birth : %s",p->Data[15]);
        sleep(0.5);
        printf("\nCaste : %s",p->Data[16]);
        sleep(0.5);
        printf("\nAadhar Number: %s",p->Data[17]);
        sleep(0.5);
        printf("\nBlood Group : %s",p->Data[18]);
        sleep(0.5);
        printf("\nIdentification Mark: %s",p->Data[19]);
        sleep(0.5);
        printf("\nBranch : %s",p->Data[20]);
        printf("\n\n------------------Educational Details------------------");
        printf("\nHSC Marks: %s",p->Marks[0]);
        sleep(0.5);
        printf("\nSSC Marks: %s",p->Marks[1]);
        printf("\nCET Percentile : %s",p->Marks[2]);
        sleep(0.5);
        printf("\nJEE Percentile : %s\n",p->Marks[3]);
         printf("____________________________________________________________________________________________________________\n\n");

    }

}


//..............................................................................................................................................................................................................


void search()                                                                                           //searching operation using PRN { Admin Access Only }
{
    int a,Prn,i;
    struct Student_data *p=NULL;
    p=start;

    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**          Welcome to Search Portal            **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\nPress Enter To Login ________________________________");
    scanf("%c",&temp);


    Again:
    printf("\nSearch Using 1.PRN 2.Keyword\nEnter Your Choice : ");
    scanf("%d",&a);
    if(a==1)
    {
        system("cls");
        printf("\nSearch Using PRN : ");
        scanf("%d",&Prn);
        if(p==NULL)
        {
            printf("\nSorry Unable to search!!!!!!!!!!");
        }
        else
        {
            while(p!=NULL)
            {
                if(p->PRN==Prn)
                {
                    printf("\n____________________________________________________________________________________________________________\n\n");
                    printf("\nPRN : %d",p->PRN);
                    printf("Student Name : %s",p->Data[0]);
                    printf("\nFather Name: %s",p->Data[1]);
                    printf("\nMother Name: %s",p->Data[2]);
                    printf("\nStudent Phone Number: %s",p->Data[3]);
                    printf("\nFather Phone Number: %s",p->Data[4]);
                    printf("\nMother Phone Number: %s",p->Data[5]);
                    printf("\nGender : %s",p->Data[6]);
                    printf("\nEmail ID: %s",p->Data[7]);
                    printf("\nAlternative Email ID: %s",p->Data[8]);
                    printf("\n\nAddresses - ");
                    printf("\nPlot No./House No. : %s",p->Data[9]);
                    printf("\nColony/Society : %s",p->Data[10]);
                    printf("\nArea : %s",p->Data[11]);
                    printf("\nCity : %s",p->Data[12]);
                    printf("\nDistrict : %s",p->Data[13]);
                    printf("\nState : %s",p->Data[14]);
                    printf("\n\n------------------Extra Details------------------");
                    printf("\nDate of Birth : %s",p->Data[15]);
                    printf("\nCaste : %s",p->Data[16]);
                    printf("\nAadhar Number: %s",p->Data[17]);
                    printf("\nBlood Group : %s",p->Data[18]);
                    printf("\nIdentification Mark: %s",p->Data[19]);
                    printf("\nBranch : %s",p->Data[20]);
                    printf("\n\n------------------Educational Details------------------");
                    printf("\nHSC Marks: %s",p->Marks[0]);
                    printf("\nSSC Marks: %s",p->Marks[1]);
                    printf("\nCET Percentile : %s",p->Marks[2]);
                    printf("\nJEE Percentile : %s\n",p->Marks[3]);
                    printf("\n____________________________________________________________________________________________________________\n\n");
                    break;
                }
                p=p->Next;
            }
        }
    }
    else if(a==2)
    {
        keyword();
    }
    else
    {
        goto Again;
    }
    sleep(10);
    system("cls");
    printf("\nReturning To Main Menu ");
    for(i=0;i<4;i++)
    {
        sleep(1.5);
        printf("@");
    }
    Main_Menu();
}


//..............................................................................................................................................................................................................


void keyword()                                                                                         //searching operation using keyword { Admin Access Only }
{
    char key[50];
    int n = 0,m = 1,i,sr=0,sr_no,result[50];
    int len;                        // contains the length of search string

    struct Student_data *p=NULL;
    p=start;
    system("cls");
    printf("\n\n\n\n");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**          Welcome to Search Portal            **");
    printf("\n\t\t\t\t**                                              **");
    printf("\n\t\t\t\t**************************************************");
    printf("\n\t\t\t\t**************************************************");


    printf("\n\n\n\t\tEnter Keyword For Search : ");
    scanf("%c",&temp);
    gets(key);
    strcpy(key,strupr(key));
    len=strlen(key);

    if(p==NULL)
    {
        printf("\nSometing is wrong");
    }
    while(p!=NULL)
    {
        for(i=0;i<21;i++)
        {
            n = 0;
            m = 1;

            while(p->Data[i][n]!='\0')
            {
                if(p->Data[i][n] == key[m])
                {                                       // if first character of search string matches
                                                        // keep on searching
                    while(p->Data[i][n] == key[m]  && p->Data[i][n] !='\0')
                    {
                        n++;
                        m++;
                    }
                                                            // if we sequence of characters matching with the length of searched string
                    if(m == len && (p->Data[i][n] == ' ' || p->Data[i][n] == '\0'))
                    {
                        result[sr]=p->PRN;
                        sr++;
                        printf("\nSr_No. : %d\n\nPRN : %d\nName :%s\nEmail : %s\nPhone No. : %s\n",sr,p->PRN,p->Data[0],p->Data[7],p->Data[3]);
                        printf("------------------------------------------------------------------------");
                        goto Next;
                    }
                }
                else
                {                                                            // if first character of search string DOES NOT match
                    while(p->Data[i][n] != ' ')
                    {                                                        // Skip to next word
                        n++;
                        if(p->Data[i][n] == '\0')
                        {
                            break;
                        }
                    }
                }
                n++;
                m=0;                                                       // reset the counter to start from first character of the search string.
           }
        }
        Next:
        p=p->Next;
    }
    if(sr==0)
    {
        printf("'%s' does not appear in the sentence.\n", key);
    }
    else
    {
        printf("\nEnter Sr No. for more information : ");
        scanf("%d",&sr_no);
        system("cls");
        p=start;
        while(p!=NULL)
            {
                if(p->PRN==result[sr_no-1])
                {
                    printf("\n____________________________________________________________________________________________________________\n\n");
                    printf("\nPRN : %d",p->PRN);
                    printf("\nStudent Name : %s",p->Data[0]);
                    printf("\nFather Name: %s",p->Data[1]);
                    printf("\nMother Name: %s",p->Data[2]);
                    printf("\nStudent Phone Number: %s",p->Data[3]);
                    printf("\nFather Phone Number: %s",p->Data[4]);
                    printf("\nMother Phone Number: %s",p->Data[5]);
                    printf("\nGender : %s",p->Data[6]);
                    printf("\nEmail ID: %s",p->Data[7]);
                    printf("\nAlternative Email ID: %s",p->Data[8]);
                    printf("\n\nAddresses - ");
                    printf("\nPlot No./House No. : %s",p->Data[9]);
                    printf("\nColony/Society : %s",p->Data[10]);
                    printf("\nArea : %s",p->Data[11]);
                    printf("\nCity : %s",p->Data[12]);
                    printf("\nDistrict : %s",p->Data[13]);
                    printf("\nState : %s",p->Data[14]);
                    printf("\n\n------------------Extra Details------------------");
                    printf("\nDate of Birth : %s",p->Data[15]);
                    printf("\nCaste : %s",p->Data[16]);
                    printf("\nAadhar Number: %s",p->Data[17]);
                    printf("\nBlood Group : %s",p->Data[18]);
                    printf("\nIdentification Mark: %s",p->Data[19]);
                    printf("\nBranch : %s",p->Data[20]);
                    printf("\n\n------------------Educational Details------------------");
                    printf("\nHSC Marks: %s",p->Marks[0]);
                    printf("\nSSC Marks: %s",p->Marks[1]);
                    printf("\nCET Percentile : %s",p->Marks[2]);
                    printf("\nJEE Percentile : %s\n",p->Marks[3]);
                    printf("\n____________________________________________________________________________________________________________\n\n");
                    break;
                }
                p=p->Next;
            }
    }

}


//..............................................................................................................................................................................................................


void Removing()                                                                                        //Removing last ASCII value from each variable of node
{
    int i,a;
    struct Student_data *p=NULL;
    p=start;
    system("cls");
    while(p!=NULL){
    for(i=0;i<21;i++)
    {
        a=strlen(p->Data[i]);
        p->Data[i][a-1]=' ';
    }
    p=p->Next;
    }
}


//..............................................................................................................................................................................................................
