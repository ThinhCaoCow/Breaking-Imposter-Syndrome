// Grade book System
// Started 8/8/2025 -- Temp Ended 14/8/2025
// Create a Student struct with fields: name, studentID, grade.
// Implement functions to add, remove, edit, and display students.
// Use dynamic arrays (via malloc/realloc) to store multiple student records.
// Implement file reading/writing using fopen, fscanf, fprintf.
// Create a main menu loop using a while loop with user options.
// Format command-line input validation and error messages.

// Due to my constant procrastination, i have decided to move on and continue to a C++ finance program instead. Once i have finished the 60 day jounry, i will look back and complete the program to show my detication.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 100  //Defining the max length here is purely for organization purposes.
typedef struct // Data Structure for the Student (struct), featuring the name, ID, and Grade. 
{
    char name[MaxLength]; // The individual letters length
    int studentID; // ID obv
    float grade; // float to allow for point values
} Student;

void addStudent(Student **students, int *count) // when selected, it would obtain the array (**) of students with a pointer (data) to the count of students, to be changed later when adding a student.
{
    Student *temp = realloc(*students, (*count + 1) * sizeof(Student)); // reallocates the memory to fit an additional student based on the count, if the temp returns a null value, it would mean that the memory has failed
    if (temp == NULL)
    {
        printf("failed to reallocate\n");
        exit(1);
    }
    *students = temp; // the temporary pointer is then 

    printf("Enter student name: ");
    getchar(); 
    fgets((*students)[*count].name, MaxLength, stdin); // fgets collects the characters inputed by the user, towards the name struct, dependant in the length by the maxlength in the standard input
    (*students)[*count].name[strcspn((*students)[*count].name, "\n")] = 0; // a bit confusing but the (*students)[*count].name is the content where the command line strcspn((*students)[*count].namefinds the index of the first newline character, to which it is then set to 0 to remove the newline (all of that for cosmetic purposes)
    printf("Enter student ID: ");
    scanf("%d", &(*students)[*count].studentID); // collects studentID through a integer 

    printf("Enter student grade: ");
    scanf("%f", &(*students)[*count].grade); // collects student grade through a float

    (*count)++; // adds up the count to finalise that the student had been added
}

void removeStudent(Student **students, int *count);

void editStudent(Student *students, int count);

void displayStudents(const Student *students, int count);

int main (void) // main function which hosts 
{
    Student *students = NULL; // Pointer to the "future" array of students
    int count = 0; // Define current count of students present
    int choice; // Defining the choice variable so that it exists lol

    
    while (1) //while (1) means when its true. Ty Python
    {
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Edit Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        scanf("%d", &choice); // Scanf to get the next input from the user, which would direct it towards the memory address of "choice"

        switch (choice)
        {
            case 1:
                addStudent(&students, &count);
                break;
            case 2:
                removeStudent(&students, &count);
                break;
            case 3:
                editStudent(students, count);
                break;
            case 4:
                displayStudents(students, count);
                break;
            case 5:
                free(students);
                return 0;
            default:
                printf("Invalid choice. Try again.\n");

        }
    }
}