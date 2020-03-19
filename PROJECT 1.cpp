/**********header files**********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/************structure***********/
struct engineer_db{
    char engineer_name[100];
    char engineer_id[100];
    int engineer_age;
    char engineer_gender[100];
    char engineer_hometown[100];
    char engineer_address[100];
    char engineer_category[100];
    int engineer_level;
    float engineer_salary;
    char engineer_blood[100];
    char engineer_contact[100];
    char engineer_email[100];
    char engineer_maritalstatus[100];
};
/*************main function**************/
int main()
{
    char str1[100],str2[100];
    puts("User:");
    gets(str1);
    puts("Password:");
    gets(str2);
    if((strcmp(str1,"Project")==0)&&(strcmp(str2,"224466")==0))
    {
    /*************task 1*************/
    //loading the file in the structure
    engineer_db s[50]; //number of engineer is 50
    FILE *fp;
    fp=fopen("engineer_db.txt","r");
    /**************number of student count*************/
     int counter=0;
    char str[200];
    while(fgets(str,200,fp)!=NULL)
    {
        counter++;
    }
    printf("number of student is = %d\n",counter);
    rewind(fp);
    char newline;
    for(int i=0;i<counter;i++)
    {
    fscanf(fp,"%[^:]:%[^:]:%d:%[^:]:%[^:]:%[^:]:%[^:]:%d:%f:%[^:]:%[^:]:%[^:]:%s",s[i].engineer_name,s[i].engineer_id,&s[i].engineer_age,s[i].engineer_gender,s[i].engineer_hometown,s[i].engineer_address,s[i].engineer_category,&s[i].engineer_level,&s[i].engineer_salary,s[i].engineer_blood,s[i].engineer_contact,s[i].engineer_email,s[i].engineer_maritalstatus);
    }
/*************testing*************/
    for(int i=0;i<counter;i++)
    {
        puts("Name:");
        puts(s[i].engineer_name);
        puts("ID:");
        puts(s[i].engineer_id);
        puts("Age:");
        printf("%d\n",s[i].engineer_age);
        puts("Gender:");
        puts(s[i].engineer_gender);
        puts("Hometown:");
        puts(s[i].engineer_hometown);
        puts("Address:");
        puts(s[i].engineer_address);
        puts("Category:");
        puts(s[i].engineer_category);
        puts("Level:");
        printf("%d\n",s[i].engineer_level);
        puts("Salary:");
        printf("%f\n",s[i].engineer_salary);
        puts("Blood Group:");
        puts(s[i].engineer_blood);
        puts("Contact:");
        puts(s[i].engineer_contact);
        puts("Email:");
        puts(s[i].engineer_email);
        puts("Marital Status:");
        printf("%s\n",s[i].engineer_maritalstatus);
    }
    /*int n;
    while(1)
    {
        printf("Press 1 to see the number of male engineers in the company\n");
        printf("Press 2 to see the engineer name and id whose age between 25-35\n");
        printf("Press 3 to see the number of CSE engineers\n");
        printf("Press 4 to see the name and contact of engineers whose level are not below 3\n");
        printf("Press 5 to see the engineer name and address whose blood group is AB-\n");
        printf("Press 6 to see the youngest engineer name and blood group\n");
        printf("Press 7 to see the engineer name and hometown of lowest salary\n");
        printf("Press 8 to see the oldest EEE engineer name and id\n");
        printf("press 9 to see the male engineer name and id of highest salary\n");
        printf("Press 10 to see the unmarried engineer name and age whose blood group B+\n");
        printf("Press 11 to see the number of female engineers\n");
        printf("Press 12 to see the engineer name and id whose address length between 8-12\n");
        printf("Press 13 to see the number of engineers whose home town is comilla\n");
        printf("Press 14 to see the name and email of engineer whose salary are not over 40000 tk\n");
        printf("Press 15 to see the engineer name and contact whose blood group is O+\n");
        printf("Press 16 to see the engineer name and blood group whose get highest salary\n");
        printf("Press 17 to see the oldest engineer name and hometown\n");
        printf("Press 18 to see the female engineer name and id of lowest salary\n");
        printf("Press 19 to see the youngest CSE engineer name and id\n");
        printf("Press 20 to see the married engineer whose home town rajshahi\n");
        printf("Press 21 to see the age of a engineer by his ID\n");
        printf("Press 22 to see the name & id of a engineer by his contact\n");
        printf("Press 23 to see the CSE/EEE engineer name whose are using banglalink sim\n");
        printf("Press 24 to see the Male/Female engineer id whose are using teletalk sim\n");
        printf("Press 25 to see which has the maximum receiver in the sim company\n");
        printf("Press 26 to see which has the minimum receiver in the sim company\n");
        printf("Press 0 to exit\n");
        scanf("%d",&n);
        fflush(stdin);
        if(n==1)
        {
            int male_count=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_gender,"Male")==0)
                {
                    male_count++;
                }
            }
            printf("Number of male engineers is = %d\n",male_count);
        }
        else if(n==2)
        {
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_age>=25) && (s[i].engineer_age<=35))
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_id);
                }
            }
        }
        else if(n==3)
        {
            int cse_count=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_category,"CSE")==0)
                {
                    cse_count++;
                }
            }
            printf("Number of CSE engineers is = %d\n",cse_count);
        }
        else if(n==4)
        {
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_level>=3)
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_contact);
                }
            }
        }
        else if(n==5)
        {
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_blood,"AB-")==0)
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_address);
                }
            }

        }
        else if(n==6)
        {
            int min_age=s[0].engineer_age;
            int min_index=0;
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_age<min_age)
                {
                    min_age=s[i].engineer_age;
                    min_index=i;
                }
            }
            puts(s[min_index].engineer_name);
            puts(s[min_index].engineer_blood);
        }
        else if(n==7)
        {
            float min_salary=s[0].engineer_salary;
            int min_index=0;
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_salary<min_salary)
                {
                    min_salary=s[i].engineer_salary;
                    min_index=i;
                }
            }
            puts(s[min_index].engineer_name);
            puts(s[min_index].engineer_hometown);
        }
        else if(n==8)
        {
            int max_age=s[0].engineer_age;
            int max_index=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_category,"EEE")==0)
                {
                    max_age=s[i].engineer_age;
                    max_index=i;
                    break;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_age>max_age)&&(strcmp(s[i].engineer_category,"EEE")==0))
                {
                    max_age=s[i].engineer_age;
                    max_index=i;
                }
            }
            puts(s[max_index].engineer_name);
            puts(s[max_index].engineer_id);
        }
        else if(n==9)
        {
            float max_salary=s[0].engineer_salary;
            int max_index=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_gender,"Male")==0)
                {
                    max_salary=s[i].engineer_salary;
                    max_index=i;
                    break;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_salary>max_salary)&&(strcmp(s[i].engineer_gender,"Male")==0))
                {
                    max_salary=s[i].engineer_salary;
                    max_index=i;
                }
            }
            puts(s[max_index].engineer_name);
            puts(s[max_index].engineer_id);
        }
        else if(n==10)
        {
            for(int i=0;i<counter;i++)
            {
                if((strcmp(s[i].engineer_maritalstatus,"Unmarried")==0)&&(strcmp(s[i].engineer_blood,"B+")==0))
                {
                    puts(s[i].engineer_name);
                    printf("%d\n",s[i].engineer_age);
                }
            }
        }
        else if(n==11)
        {
            int female_count=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_gender,"Female")==0)
                {
                    female_count++;
                }
            }
            printf("Number of female engineers is =%d\n",female_count);
        }
        else if(n==12)
        {
            for(int i=0;i<counter;i++)
            {
                if((strlen(s[i].engineer_address)>=8)&&(strlen(s[i].engineer_address)<=12))
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_id);
                }
            }
        }
        else if(n==13)
        {
            int home_count=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_hometown,"Comilla")==0)
                {
                    home_count++;
                }
            }
            printf("Number of engineers whose hometown comilla is =%d\n",home_count);
        }
        else if(n==14)
        {
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_salary<=40000)
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_email);
                }
            }
        }
        else if(n==15)
        {
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_blood,"O+")==0)
                {
                    puts(s[i].engineer_name);
                    puts(s[i].engineer_contact);
                }
            }
        }
        else if(n==16)
        {
            float max_salary=s[0].engineer_salary;
            int max_index=0;
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_salary>max_salary)
                {
                    max_salary=s[i].engineer_salary;
                    max_index=i;
                }
            }
            puts(s[max_index].engineer_name);
            puts(s[max_index].engineer_blood);
        }
        else if(n==17)
        {
            int max_age=s[0].engineer_age;
            int max_index=0;
            for(int i=0;i<counter;i++)
            {
                if(s[i].engineer_age>max_age)
                {
                    max_age=s[i].engineer_age;
                    max_index=i;
                }
            }
            puts(s[max_index].engineer_name);
            puts(s[max_index].engineer_hometown);
        }
        else if(n==18)
        {
            float min_salary=s[0].engineer_salary;
            int min_index=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_gender,"Female")==0)
                {
                    min_salary=s[i].engineer_salary;
                    min_index=i;
                    break;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_salary<min_salary)&&(strcmp(s[i].engineer_gender,"Female")==0))
                {
                    min_salary=s[i].engineer_salary;
                    min_index=i;
                }
            }
            puts(s[min_index].engineer_name);
            puts(s[min_index].engineer_id);
        }
        else if(n==19)
        {
            int min_age=s[0].engineer_age;
            int min_index=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_category,"CSE")==0)
                {
                    min_age=s[i].engineer_age;
                    min_index=i;
                    break;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_age<min_age)&&(strcmp(s[i].engineer_category,"CSE")==0))
                {
                    min_age=s[i].engineer_age;
                    min_index=i;
                }
            }
            puts(s[min_index].engineer_name);
            puts(s[min_index].engineer_id);
        }
        else if(n==20)
        {
            for(int i=0;i<counter;i++)
            {
                if((strcmp(s[i].engineer_maritalstatus,"Married")==0)&&(strcmp(s[i].engineer_hometown,"Rajshahi")==0))
                {
                    printf("%s\n",s[i].engineer_name);
                    printf("%d\n",s[i].engineer_age);
                }
            }
        }
        else if(n==21)
        {
            printf("Please enter engineer id:");
            gets(str);
            int flag=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_id,str)==0)
                {
                    flag=1;
                    printf("Age is = %d\n",s[i].engineer_age);
                    break;
                }
            }
             if(flag==0)
                {
                    puts("Wrong input");
                }
        }
        else if(n==22)
        {
            printf("Please enter engineer contact:");
            gets(str);
            int flag=0;
            for(int i=0;i<counter;i++)
            {
                if(strcmp(s[i].engineer_contact,str)==0)
                {
                    flag=1;
                    printf("Name is = %s\n",s[i].engineer_name);
                    printf("ID is = %s\n",s[i].engineer_id);
                    break;
                }
            }
             if(flag==0)
                {
                    puts("Wrong input");
                }
        }
        else if(n==23)
        {
            printf("Please enter engineer category CSE/EEE:");
            gets(str);
            int flag=0;
            for(int i=0;i<counter;i++)
            {
                if(((s[i].engineer_contact[2])=='9')&&(strcmp(s[i].engineer_category,str)==0))
                {
                    flag=1;
                    puts(s[i].engineer_name);
                }
            }
            if(flag==0)
            {
                puts("Wrong input");
            }
        }
        else if(n==24)
        {
            printf("Please enter engineer gender Male/Female:");
            gets(str);
            int flag=0;
            for(int i=0;i<counter;i++)
            {
                if(((s[i].engineer_contact[2])=='5')&&(strcmp(s[i].engineer_gender,str)==0))
                {
                    flag=1;
                    puts(s[i].engineer_id);
                }
            }
            if(flag==0)
            {
                puts("Wrong input");
            }
        }
        else if(n==25)
        {
            int tel_count=0,air_count=0,gp_count=0,robi_count=0,ban_count=0;
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='5')
                {
                    tel_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='6')
                {
                    air_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='7')
                {
                    gp_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='8')
                {
                    robi_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='9')
                {
                    ban_count++;
                }
            }
            if((tel_count>air_count)&&(tel_count>gp_count)&&(tel_count>robi_count)&&(tel_count>ban_count))
            {
                printf("Teletalk has the maximum receiver.User is = %d\n",tel_count);
            }
            if((air_count>tel_count)&&(air_count>gp_count)&&(air_count>robi_count)&&(air_count>ban_count))
            {
                printf("Airtel has the maximum receiver.User is = %d\n",air_count);
            }
            if((gp_count>air_count)&&(gp_count>tel_count)&&(gp_count>robi_count)&&(gp_count>ban_count))
            {
                printf("Grameenphone has the maximum receiver.User is = %d\n",gp_count);
            }
            if((robi_count>air_count)&&(robi_count>gp_count)&&(robi_count>tel_count)&&(robi_count>ban_count))
            {
                printf("Robi has the maximum receiver.User is = %d\n",robi_count);
            }
            if((ban_count>air_count)&&(ban_count>gp_count)&&(ban_count>robi_count)&&(ban_count>tel_count))
            {
                printf("Banglalink has the maximum receiver.User is = %d\n",ban_count);
            }
        }
        else if(n==26)
        {
            int tel_count=0,air_count=0,gp_count=0,robi_count=0,ban_count=0;
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='5')
                {
                    tel_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='6')
                {
                    air_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='7')
                {
                    gp_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='8')
                {
                    robi_count++;
                }
            }
            for(int i=0;i<counter;i++)
            {
                if((s[i].engineer_contact[2])=='9')
                {
                    ban_count++;
                }
            }
            if((tel_count<air_count)&&(tel_count<gp_count)&&(tel_count<robi_count)&&(tel_count<ban_count))
            {
                printf("Teletalk has the mimimum receiver.User is = %d\n",tel_count);
            }
            if((air_count<tel_count)&&(air_count<gp_count)&&(air_count<robi_count)&&(air_count<ban_count))
            {
                printf("Airtel has the minimum receiver.User is = %d\n",air_count);
            }
            if((gp_count<air_count)&&(gp_count<tel_count)&&(gp_count<robi_count)&&(gp_count<ban_count))
            {
                printf("Grameenphone has the minimum receiver.User is = %d\n",gp_count);
            }
            if((robi_count<air_count)&&(robi_count<gp_count)&&(robi_count<tel_count)&&(robi_count<ban_count))
            {
                printf("Robi has the minimum receiver.User is = %d\n",robi_count);
            }
            if((ban_count<air_count)&&(ban_count<gp_count)&&(ban_count<robi_count)&&(ban_count<tel_count))
            {
                printf("Banglalink has the minimum receiver.User is = %d\n",ban_count);
            }
        }
        else if(n==0)
        {
            exit(0);
        }

    }*/
    fclose(fp);
    }
    else
    {
        puts("Try again");
    }




    return 0;
}
