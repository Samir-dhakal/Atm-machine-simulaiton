#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *current_time();
int isFileEmpty(FILE *file);
char *detail;
int main()
{
    char name1[100];
    char line1[1000];

    struct mentals
    {
        int id;
        char name[100];
        long phone_no;
        char gender[10];
        int age;
        char time[40];
    };
    struct doctors
    {
        int idd;
        char named[100];
        long phone_nod;
        char specalization;
    };
    int numb_of_patients, index;

    printf("0:TO exit the program \n1:To store the data of he new patients.\n2:To see the patients record.\n3:To enter  the doctor record.\n4:TO see the record of the doctor\n5:To find the specific patients in the hospital\n Enter the specific index to perform the particular task:");
    scanf("%d", &index);
    switch (index)
    {
    case (0):
    {
        exit(0);
    }
    case (1):
    {
        printf("Enter the number of patients:");
        scanf("%d", &numb_of_patients);

        struct mentals ment[numb_of_patients];

        for (int i = 0; i < numb_of_patients; i++)
        {
            printf("Enter the id of the %d patient  ", i + 1);
            scanf("%d", &ment[i].id);
            printf("Enter the phone no  of the %d patient's parent  ", i + 1);

            scanf("%ld", &ment[i].phone_no);
            getchar();
            printf("Enter the name of the %d patient  ", i + 1);
            scanf("%[^\n]", &ment[i].name);

            printf("Enter the age of the %d patient  ", i + 1);
            scanf("%d", &ment[i].age);

            printf("Enter the gender of the %d patient  ", i + 1);

            printf("Press '0'for male and '1' for female");
            scanf("%d", &ment[i].gender);
        }
        FILE *vale = fopen("patan.txt", "a");

        if (vale == NULL)
        {
            printf("The file cannot be created ");
            exit(1);
        }

        if (isFileEmpty(vale))
        {
            fprintf(vale, "%-5s%-20s%-12s%-5s%-20s\n", "ID", "NAME", "CONTACT NO", "AGE", "TIME OF ADMISSION");
        }

        for (int i = 0; i < numb_of_patients; i++)
        {
            char gender[10];
            if (ment[i].gender == 1)
                strcpy(ment[i].gender, "female");
            if (ment[i].gender == 0)
                strcpy(ment[i].gender, "male");

            strcpy(ment[i].time, current_time());
            fprintf(vale, "%-5d%-20s%-12ld%-5d%-6s%-20s\n", ment[i].id, ment[i].name, ment[i].phone_no, ment[i].age, ment[i].gender, ment[i].time);
        }
        fclose(vale);
        printf("Data saved successfully to 'patan.txt'.\n");

        break;
    }
    case (2):
    {

        FILE *vale = fopen("patan.txt", "r");

        char line[10];

        while (fgets(line, sizeof(line), vale))
            printf("%s", line);
        ;

        fclose(vale);
        break;
    }
    case (3):
    {

        int no_of_doctors;
        printf("enter the number of doctors to store records ");
        scanf("%d", &no_of_doctors);
        struct doctors doct[no_of_doctors];

        for (int i = 1; i <= no_of_doctors; i++)
        {
            printf("Enter the id of the %d doctor ", i);
            scanf("%d", &doct[i].idd);
            printf("Enter the phone no  of the %d doctor ", i);

            scanf("%ld", &doct[i].phone_nod);
            getchar();
            printf("Enter the name of the %ddoctor  ", i);
            scanf("%[^\n]", &doct[i].named);
            // specialization
            printf("Enter the field in which the doctor is specialized in:");

            scanf("%[^\n]s", &doct[i].specalization);
        }
        FILE *vale = fopen("doctor.txt", "w");
        if (vale == NULL)
        {
            printf("The file cannot be created ");
        }
        for (int i = 1; i <= no_of_doctors; i++)

        {
            fprintf(vale, "%3d%11ld%20s\n", doct[i].idd, doct[i].phone_nod, doct[i].named);
        }
        fclose(vale);
        break;
    }
    case (4):
    {
        FILE *vale = fopen("doctor.txt", "r");

        char line[10];

        while (fgets(line, sizeof(line), vale))
            printf("%s", line);

        fclose(vale);
        break;
    }

    case (5):
    {
        // char name1[100];
        // char line1[100];
        getchar();
        {
            printf("Enter the name of the user you want to search :");
            scanf("%[^\n]s", &name1);

            // if the user want to search the specific patients
            FILE *vale = fopen("patan.txt", "r");
            int found = 0;
            while (fgets(line1, sizeof(line1), vale))
            {
                if (strstr(line1, name1) != NULL)
                {
                    // detail = strstr(line1, name1);
                    // printf("The patient is in our hospital");
                    found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                printf("The paient is in our hospital\n");
                printf("The detail of the patient is :\n");
                printf("%-5s%-20s%-12s%-5s%-20s\n", "ID",
                       "NAME",
                       "CONTACT NO", "AGE", "TIME OF ADMISSION");
                printf("%s", line1);
            }
            else
                printf("the patient is not in out hospital");
        }

        break;
    }
    default:
        printf("The input is invalid");
    }

    return 0;
}

int isFileEmpty(FILE *file)
{
    // Save the current file pointer position
    long currentPos = ftell(file);

    // Move to the end of the file
    fseek(file, 0, SEEK_END);

    // Check if the current position is at the end of the file
    long fileSize = ftell(file);

    // Restore the file pointer to the original position
    fseek(file, currentPos, SEEK_SET);

    // If the file size is 0, it is empty
    return fileSize == 0;
}
char *current_time()
{
    // Create a variable to store the current time
    time_t currentTime;

    // Get the current time
    time(&currentTime);

    // Convert the time to a human-readable format
    char *timeString = ctime(&currentTime);

    // Print the current time
    // printf("Current Time: %s", timeString);
    return timeString;
}
