// ===========================Part 1===========================
#include <stdio.h>  // Standard Input Output functions (printf, scanf)
#include <stdlib.h> // Standard library functions
#include <string.h> // String handling functions
#include <ctype.h>  // Character handling functions like isalpha()

// Maximum number of students that can be stored
#define MAX 100

// Structure to store details of one student
struct Student
{
    int rollNo;       // Student Roll Number
    char name[50];    // Student Name
    int marks[5];     // Marks of 5 subjects
    int total;        // Total Marks
    float percentage; // Percentage
    char grade;       // Grade (A, B, C, D, F)
};

// Global array to store student records
struct Student s[MAX];

// Array storing names of subjects
char subject[5][20] =
    {
        "English",
        "Mathematics",
        "Science",
        "Computer",
        "Social Science"};

// Global variable to count total students
int n = 0;

// Loop variables declared globally
int i, j;

//---------------------- Function Prototypes ----------------------//

// Checks whether entered name contains only letters and spaces
int isValidName(char name[]);

// Calculates total, percentage and grade
void calculateResult(struct Student *st);

// Adds a new student
void addStudent();

// Searches a student by roll number
void searchStudent();

// Displays all students
void displayStudents();

// Updates student details
void updateStudent();

// Deletes a student record
void deleteStudent();

// Displays complete result of one student
void calculateStudentResult();

// Saves all records into a file
void saveToFile();

//---------------------------------------------------------------//
// Function to validate student's name
//---------------------------------------------------------------//
int isValidName(char name[])
{
    int i; // Loop variable

    // Traverse every character of the name
    for (i = 0; name[i] != '\0'; i++)
    {
        // Check whether character is alphabet or space
        if (!(isalpha(name[i]) || name[i] == ' '))
        {
            return 0; // Invalid name
        }
    }

    return 1; // Valid name
}

//---------------------------------------------------------------//
// Function to calculate Total, Percentage and Grade
//---------------------------------------------------------------//
void calculateResult(struct Student *st)
{
    int k; // Loop variable

    // Initialize total marks to zero
    st->total = 0;

    // Calculate total marks of all five subjects
    for (k = 0; k < 5; k++)
    {
        st->total += st->marks[k];
    }

    // Calculate percentage
    st->percentage = st->total / 5.0;

    // Assign grade according to percentage
    if (st->percentage >= 90)
        st->grade = 'A';

    else if (st->percentage >= 75)
        st->grade = 'B';

    else if (st->percentage >= 60)
        st->grade = 'C';

    else if (st->percentage >= 40)
        st->grade = 'D';

    else
        st->grade = 'F';
}

//---------------------------------------------------------------//
// Main Function
//---------------------------------------------------------------//
int main()
{
    int choice; // Variable to store user's menu choice

    // Repeat menu until user selects Exit
    do
    {
        // Display program heading
        printf("\n==========================================");
        printf("\n STUDENT RESULT MANAGEMENT SYSTEM");
        printf("\n==========================================");

        // Display menu options
        printf("\n1. Add Student");
        printf("\n2. Search Student");
        printf("\n3. Display All Students");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Calculate Student Result");
        printf("\n7. Save Records To File");
        printf("\n8. Exit");

        // Ask user to enter menu choice
        printf("\n\nEnter Your Choice : ");

        // Validate numeric input
        while (scanf("%d", &choice) != 1)
        {
            // Display error message
            printf("Invalid Choice. Enter Numeric Value : ");

            // Clear invalid input from buffer
            while (getchar() != '\n')
                ;
        }

        // Execute selected option
        switch (choice)
        {
        case 1:
            addStudent(); // Call Add Student function
            break;

        case 2:
            searchStudent(); // Call Search Student function
            break;

        case 3:
            displayStudents(); // Call Display function
            break;

        case 4:
            updateStudent(); // Call Update function
            break;

        case 5:
            deleteStudent(); // Call Delete function
            break;

        case 6:
            calculateStudentResult(); // Display result of one student
            break;

        case 7:
            saveToFile(); // Save all student records into file
            break;

        case 8:
            printf("\nThank You...\n"); // Exit message
            break;

        default:
            printf("\nInvalid Choice."); // Invalid menu option
        }

    } while (choice != 8); // Continue until Exit is selected

    return 0; // Program ends successfully
}

// ======================================Part 2=====================================

//=============================================================//
// Function Name : addStudent()
// Purpose       : Adds a new student record into the system.
//                 It accepts Roll Number, Name, Subject Marks,
//                 calculates Total, Percentage, Grade and stores
//                 the record in the student array.
//=============================================================//
void addStudent()
{
    // Variable used to check whether Roll Number already exists
    int found = 0;

    // Check whether the student array has reached its maximum size
    if (n >= MAX)
    {
        // Display message if no more records can be stored
        printf("\nStudent Record is Full.\n");

        // Exit from the function
        return;
    }

    // Display heading for Add Student section
    printf("\n====================================");
    printf("\n      ADD STUDENT RECORD");
    printf("\n====================================\n");

    //=========================================================
    //              Enter Roll Number
    //=========================================================

    // Repeat until a valid and unique Roll Number is entered
    while (1)
    {
        // Assume Roll Number is not duplicate
        found = 0;

        // Ask user to enter Roll Number
        printf("Enter Roll Number : ");

        // Check whether input is numeric
        if (scanf("%d", &s[n].rollNo) != 1)
        {
            // Display error message
            printf("Invalid! Roll Number must contain only numbers.\n");

            // Remove invalid characters from input buffer
            while (getchar() != '\n')
                ;

            // Restart the loop
            continue;
        }

        // Compare entered Roll Number with all existing students
        for (i = 0; i < n; i++)
        {
            // Check if Roll Number already exists
            if (s[i].rollNo == s[n].rollNo)
            {
                // Duplicate Roll Number found
                found = 1;

                // Stop searching
                break;
            }
        }

        // If duplicate Roll Number is found
        if (found)
        {
            // Ask user to enter another Roll Number
            printf("Roll Number already exists. Enter another Roll Number.\n");
        }
        else
        {
            // Roll Number is valid and unique
            break;
        }
    }

    // Remove leftover newline character from keyboard buffer
    while (getchar() != '\n')
        ;

    //=========================================================
    //              Enter Student Name
    //=========================================================

    // Repeat until a valid name is entered
    while (1)
    {
        // Ask user to enter student's name
        printf("Enter Student Name : ");

        // Read complete name including spaces
        fgets(s[n].name, sizeof(s[n].name), stdin);

        // Remove newline character added by fgets()
        s[n].name[strcspn(s[n].name, "\n")] = '\0';

        // Check whether name is empty
        if (strlen(s[n].name) == 0)
        {
            // Display error message
            printf("Name cannot be empty.\n");

            // Ask again
            continue;
        }

        // Check whether name contains only alphabets and spaces
        if (isValidName(s[n].name))
        {
            // Name is valid
            break;
        }

        // Display error message if invalid characters are entered
        printf("Invalid! Name should contain only alphabets and spaces.\n");
    }

    //=========================================================
    //          Enter Marks of Five Subjects
    //=========================================================

    // Display heading
    printf("\nEnter Marks of the Following Subjects\n");

    // Loop for all five subjects
    for (j = 0; j < 5; j++)
    {
        // Repeat until valid marks are entered
        while (1)
        {
            // Display subject name
            printf("%s : ", subject[j]);

            // Accept marks and validate range (0–100)
            if (scanf("%d", &s[n].marks[j]) == 1 &&
                s[n].marks[j] >= 0 &&
                s[n].marks[j] <= 100)
            {
                // Valid marks entered
                break;
            }

            // Display error message
            printf("Invalid! Enter marks between 0 and 100.\n");

            // Remove invalid input from keyboard buffer
            while (getchar() != '\n')
                ;
        }
    }

    //=========================================================
    //      Calculate Total, Percentage and Grade
    //=========================================================

    // Call function to calculate result of the student
    calculateResult(&s[n]);

    //=========================================================
    //          Display Student Record
    //=========================================================

    // Display success message
    printf("\n====================================");
    printf("\nStudent Record Added Successfully");
    printf("\n====================================");

    // Display Roll Number
    printf("\nRoll Number : %d", s[n].rollNo);

    // Display Student Name
    printf("\nStudent Name: %s", s[n].name);

    // Display heading for marks
    printf("\n\nMarks Obtained\n");

    // Display subject-wise marks
    for (j = 0; j < 5; j++)
    {
        printf("%-20s : %d\n", subject[j], s[n].marks[j]);
    }

    // Display Total Marks
    printf("\nTotal Marks : %d / 500", s[n].total);

    // Display Percentage
    printf("\nPercentage  : %.2f%%", s[n].percentage);

    // Display Grade
    printf("\nGrade       : %c\n", s[n].grade);

    // Increase total student count so next record is stored
    // at the next position in the array
    n++;
}
// ===================================Part 3=====================================

//=============================================================//
// Function Name : searchStudent()
// Purpose       : Searches a student record using Roll Number.
//                 If the Roll Number exists, it displays the
//                 student's complete information including
//                 marks, total, percentage and grade.
//=============================================================//
void searchStudent()
{
    // Variable to store the Roll Number entered by the user
    int roll;

    // Variable to check whether the student is found or not
    int found = 0;

    // Check whether any student record exists
    if (n == 0)
    {
        // Display message if there are no records
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //          Enter Roll Number to Search
    //=========================================================

    // Repeat until a valid numeric Roll Number is entered
    while (1)
    {
        // Ask user to enter Roll Number
        printf("\nEnter Roll Number to Search : ");

        // Check whether input is numeric
        if (scanf("%d", &roll) == 1)
            // Exit loop if input is valid
            break;

        // Display error message
        printf("Invalid! Roll Number must be numeric.\n");

        // Remove invalid characters from input buffer
        while (getchar() != '\n')
            ;
    }

    //=========================================================
    //              Search Student Record
    //=========================================================

    // Traverse all student records
    for (i = 0; i < n; i++)
    {
        // Compare entered Roll Number with current student's Roll Number
        if (s[i].rollNo == roll)
        {
            // Student record found
            found = 1;

            // Display heading
            printf("\n====================================");
            printf("\n        STUDENT RECORD");
            printf("\n====================================");

            // Display Roll Number
            printf("\nRoll Number : %d", s[i].rollNo);

            // Display Student Name
            printf("\nName        : %s", s[i].name);

            // Display heading for marks
            printf("\nMarks        : ");

            // Display marks of all five subjects
            for (j = 0; j < 5; j++)
            {
                printf("%d ", s[i].marks[j]);
            }

            // Display Total Marks
            printf("\nTotal        : %d", s[i].total);

            // Display Percentage
            printf("\nPercentage   : %.2f%%", s[i].percentage);

            // Display Grade
            printf("\nGrade        : %c", s[i].grade);

            // Display closing line
            printf("\n====================================\n");

            // Exit function after displaying record
            return;
        }
    }

    //=========================================================
    //          Student Not Found
    //=========================================================

    // Check whether no matching Roll Number was found
    if (found == 0)
    {
        // Display message
        printf("\nStudent Record Not Found.\n");
    }
}
//=============================================================//
// Function Name : displayStudents()
// Purpose       : Displays all student records stored in the
//                 system along with subject-wise marks,
//                 total marks, percentage and grade.
//=============================================================//
void displayStudents()
{
    // Check whether any student record exists
    if (n == 0)
    {
        // Display message if no records are available
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    // Display heading
    printf("\n======================================================");
    printf("\n             ALL STUDENT RECORDS");
    printf("\n======================================================");

    //=========================================================
    //          Display Every Student Record
    //=========================================================

    // Traverse all student records one by one
    for (i = 0; i < n; i++)
    {
        // Display student serial number
        printf("\n\nStudent %d", i + 1);

        // Display separator line
        printf("\n------------------------------------------------------");

        // Display Roll Number
        printf("\nRoll Number : %d", s[i].rollNo);

        // Display Student Name
        printf("\nStudent Name: %s\n", s[i].name);

        // Display heading for subject marks
        printf("\nSubject Wise Marks");

        // Display separator
        printf("\n------------------------------------------------------");

        //=====================================================
        //      Display Subject Names and Marks
        //=====================================================

        // Traverse all five subjects
        for (j = 0; j < 5; j++)
        {
            // Display subject name with its corresponding marks
            printf("\n%-20s : %3d", subject[j], s[i].marks[j]);
        }

        // Display separator
        printf("\n------------------------------------------------------");

        // Display Total Marks obtained by the student
        printf("\nTotal Marks : %d / 500", s[i].total);

        // Display Percentage
        printf("\nPercentage  : %.2f%%", s[i].percentage);

        // Display Grade
        printf("\nGrade       : %c", s[i].grade);

        // Display ending line for current student's record
        printf("\n======================================================");
    }
}
// ===============================Part 4=====================================

//=============================================================//
// Function Name : updateStudent()
// Purpose       : Searches a student by Roll Number and updates
//                 the student's Name and Subject Marks.
//                 After updating, it recalculates Total,
//                 Percentage and Grade, then displays the
//                 updated record.
//=============================================================//
void updateStudent()
{
    // Variable to store the Roll Number entered by the user
    int roll;

    // Variable used to check whether the student record is found
    int found = 0;

    //=========================================================
    //      Check Whether Student Records Exist
    //=========================================================

    // If there are no student records
    if (n == 0)
    {
        // Display message
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //          Enter Roll Number to Update
    //=========================================================

    // Repeat until a valid numeric Roll Number is entered
    while (1)
    {
        // Ask user to enter Roll Number
        printf("\nEnter Roll Number to Update : ");

        // Check whether the entered value is numeric
        if (scanf("%d", &roll) == 1)
            // Exit loop if input is valid
            break;

        // Display error message
        printf("Invalid! Roll Number must be numeric.\n");

        // Remove invalid characters from the input buffer
        while (getchar() != '\n')
            ;
    }

    //=========================================================
    //          Search Student Record
    //=========================================================

    // Traverse all student records
    for (i = 0; i < n; i++)
    {
        // Compare entered Roll Number with stored Roll Number
        if (s[i].rollNo == roll)
        {
            // Student record found
            found = 1;

            // Clear leftover newline character from input buffer
            while (getchar() != '\n')
                ;

            // Display heading
            printf("\n========================================");
            printf("\n        UPDATE STUDENT RECORD");
            printf("\n========================================");

            // Display current student name
            printf("\nCurrent Name : %s\n", s[i].name);

            //=================================================
            //          Update Student Name
            //=================================================

            // Repeat until a valid name is entered
            while (1)
            {
                // Ask user to enter the new student name
                printf("Enter New Student Name : ");

                // Read complete name including spaces
                fgets(s[i].name, sizeof(s[i].name), stdin);

                // Remove newline character added by fgets()
                s[i].name[strcspn(s[i].name, "\n")] = '\0';

                // Check whether the entered name contains
                // only alphabets and spaces
                if (isValidName(s[i].name))
                    // Exit loop if name is valid
                    break;

                // Display error message
                printf("Invalid! Name should contain only alphabets and spaces.\n");
            }

            //=================================================
            //          Update Subject-wise Marks
            //=================================================

            // Display heading
            printf("\nEnter New Marks\n");
            printf("----------------------------------------\n");

            // Repeat for all five subjects
            for (j = 0; j < 5; j++)
            {
                // Repeat until valid marks are entered
                while (1)
                {
                    // Display subject name
                    printf("%-20s : ", subject[j]);

                    // Accept marks and check whether they are
                    // between 0 and 100
                    if (scanf("%d", &s[i].marks[j]) == 1 &&
                        s[i].marks[j] >= 0 &&
                        s[i].marks[j] <= 100)
                    {
                        // Valid marks entered
                        break;
                    }

                    // Display error message
                    printf("Invalid! Enter marks between 0 and 100.\n");

                    // Remove invalid input from the keyboard buffer
                    while (getchar() != '\n')
                        ;
                }
            }

            //=================================================
            //      Recalculate Student Result
            //=================================================

            // Calculate Total Marks, Percentage and Grade again
            calculateResult(&s[i]);

            //=================================================
            //      Display Updated Student Record
            //=================================================

            // Display success message
            printf("\n========================================");
            printf("\nStudent Record Updated Successfully");
            printf("\n========================================");

            // Display Roll Number
            printf("\nRoll Number : %d", s[i].rollNo);

            // Display Student Name
            printf("\nStudent Name: %s", s[i].name);

            // Display heading for updated marks
            printf("\n\nUpdated Subject Wise Marks");
            printf("\n----------------------------------------");

            // Display subject-wise updated marks
            for (j = 0; j < 5; j++)
            {
                printf("\n%-20s : %3d", subject[j], s[i].marks[j]);
            }

            // Display separator line
            printf("\n----------------------------------------");

            // Display Total Marks
            printf("\nTotal Marks : %d / 500", s[i].total);

            // Display Percentage
            printf("\nPercentage  : %.2f%%", s[i].percentage);

            // Display Grade
            printf("\nGrade       : %c", s[i].grade);

            // Display closing line
            printf("\n========================================\n");

            // Exit the function after successful update
            return;
        }
    }

    //=========================================================
    //          Student Record Not Found
    //=========================================================

    // If no matching Roll Number exists
    if (found == 0)
    {
        // Display error message
        printf("\nStudent Record Not Found.\n");
    }
}

//=============================================================//
// Function Name : deleteStudent()
// Purpose       : Deletes a student record using Roll Number.
//                 After finding the student, all remaining
//                 records are shifted one position to the left
//                 to maintain the array, and the total number
//                 of students is decreased.
//=============================================================//
void deleteStudent()
{
    // Variable to store the Roll Number entered by the user
    int roll;

    // Variable used to check whether the student record is found
    int found = 0;

    //=========================================================
    //      Check Whether Student Records Exist
    //=========================================================

    // Check if there are no student records
    if (n == 0)
    {
        // Display message
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //          Enter Roll Number to Delete
    //=========================================================

    // Repeat until a valid numeric Roll Number is entered
    while (1)
    {
        // Ask the user to enter Roll Number
        printf("\nEnter Roll Number to Delete : ");

        // Accept Roll Number and check if it is numeric
        if (scanf("%d", &roll) == 1)
            // Exit loop if input is valid
            break;

        // Display error message
        printf("Invalid! Enter Numeric Roll Number.\n");

        // Remove invalid characters from the input buffer
        while (getchar() != '\n')
            ;
    }

    //=========================================================
    //          Search Student Record
    //=========================================================

    // Traverse all student records
    for (i = 0; i < n; i++)
    {
        // Compare entered Roll Number with current record
        if (s[i].rollNo == roll)
        {
            // Student record found
            found = 1;

            //=================================================
            //      Shift Remaining Records
            //=================================================

            // Move every record after the deleted student
            // one position towards the left
            for (j = i; j < n - 1; j++)
            {
                // Copy next record into current position
                s[j] = s[j + 1];
            }

            // Reduce the total number of student records
            n--;

            // Display success message
            printf("\nStudent Record Deleted Successfully.\n");

            // Exit the function
            return;
        }
    }

    //=========================================================
    //          Student Record Not Found
    //=========================================================

    // Check whether no matching Roll Number exists
    if (found == 0)
    {
        // Display error message
        printf("\nStudent Record Not Found.\n");
    }
}

//=============================================================//
// Function Name : calculateStudentResult()
// Purpose       : Searches a student by Roll Number,
//                 calculates the student's result,
//                 and displays subject-wise marks,
//                 total marks, percentage and grade.
//=============================================================//
void calculateStudentResult()
{
    // Variable to store the Roll Number entered by the user
    int roll;

    // Variable used to check whether the student record is found
    int found = 0;

    //=========================================================
    //      Check Whether Student Records Exist
    //=========================================================

    // Check if there are no student records
    if (n == 0)
    {
        // Display message
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //          Enter Roll Number
    //=========================================================

    // Repeat until a valid numeric Roll Number is entered
    while (1)
    {
        // Ask user to enter Roll Number
        printf("\nEnter Roll Number : ");

        // Accept Roll Number and check whether the input is numeric
        if (scanf("%d", &roll) == 1)
            // Exit loop if input is valid
            break;

        // Display error message
        printf("Invalid! Roll Number must be numeric.\n");

        // Remove invalid characters from the keyboard buffer
        while (getchar() != '\n')
            ;
    }

    //=========================================================
    //          Search Student Record
    //=========================================================

    // Traverse all stored student records
    for (i = 0; i < n; i++)
    {
        // Compare entered Roll Number with current student's Roll Number
        if (s[i].rollNo == roll)
        {
            // Student record found
            found = 1;

            //=================================================
            //      Calculate Student Result
            //=================================================

            // Call function to calculate
            // Total Marks, Percentage and Grade
            calculateResult(&s[i]);

            //=================================================
            //      Display Student Result
            //=================================================

            // Display heading
            printf("\n==================================================");
            printf("\n              STUDENT RESULT");
            printf("\n==================================================");

            // Display Roll Number
            printf("\nRoll Number : %d", s[i].rollNo);

            // Display Student Name
            printf("\nStudent Name: %s", s[i].name);

            // Display heading for subject-wise marks
            printf("\n\nSubject Wise Marks");

            // Display separator line
            printf("\n--------------------------------------------------");

            //=================================================
            //      Display Subject-wise Marks
            //=================================================

            // Repeat for all five subjects
            for (j = 0; j < 5; j++)
            {
                // Display subject name along with obtained marks
                printf("\n%-20s : %3d", subject[j], s[i].marks[j]);
            }

            // Display separator line
            printf("\n--------------------------------------------------");

            // Display total marks obtained by the student
            printf("\nTotal Marks : %d / 500", s[i].total);

            // Display percentage
            printf("\nPercentage  : %.2f%%", s[i].percentage);

            // Display grade
            printf("\nGrade       : %c", s[i].grade);

            // Display closing line
            printf("\n==================================================\n");

            // Exit the function after displaying the result
            return;
        }
    }

    //=========================================================
    //          Student Record Not Found
    //=========================================================

    // Check whether no matching Roll Number exists
    if (found == 0)
    {
        // Display error message
        printf("\nStudent Record Not Found.\n");
    }
}

//=============================================================//
// Function Name : saveToFile()
// Purpose       : Saves all student records into a text file.
//                 Each student's Roll Number, Name,
//                 Subject-wise Marks, Total Marks,
//                 Percentage and Grade are written
//                 into "StudentResult.txt".
//=============================================================//
void saveToFile()
{
    // Declare a file pointer
    FILE *fp;

    //=========================================================
    //      Check Whether Student Records Exist
    //=========================================================

    // Check if there are no student records
    if (n == 0)
    {
        // Display message
        printf("\nNo Student Records Available.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //          Open File
    //=========================================================

    // Open the file "StudentResult.txt" in Write Mode ("w")
    // If the file already exists, its previous contents
    // will be erased.
    // If the file does not exist, a new file will be created.
    fp = fopen("StudentResult.txt", "w");

    // Check whether the file was opened successfully
    if (fp == NULL)
    {
        // Display error message
        printf("\nUnable to Open File.\n");

        // Exit the function
        return;
    }

    //=========================================================
    //      Write All Student Records into File
    //=========================================================

    // Traverse all student records one by one
    for (i = 0; i < n; i++)
    {
        // Write heading into the file
        fprintf(fp, "\n==================================================\n");
        fprintf(fp, "              STUDENT RECORD\n");
        fprintf(fp, "==================================================\n");

        // Write Roll Number
        fprintf(fp, "Roll Number : %d\n", s[i].rollNo);

        // Write Student Name
        fprintf(fp, "Student Name: %s\n", s[i].name);

        // Write heading for subject-wise marks
        fprintf(fp, "\nSubject Wise Marks\n");

        // Write separator line
        fprintf(fp, "--------------------------------------------------\n");

        //=====================================================
        //      Write Subject Names and Marks
        //=====================================================

        // Repeat for all five subjects
        for (j = 0; j < 5; j++)
        {
            // Write subject name and corresponding marks
            fprintf(fp, "%-20s : %3d\n", subject[j], s[i].marks[j]);
        }

        // Write separator line
        fprintf(fp, "--------------------------------------------------\n");

        // Write Total Marks
        fprintf(fp, "Total Marks : %d / 500\n", s[i].total);

        // Write Percentage
        fprintf(fp, "Percentage  : %.2f%%\n", s[i].percentage);

        // Write Grade
        fprintf(fp, "Grade       : %c\n", s[i].grade);

        // Write closing line
        fprintf(fp, "==================================================\n");
    }

    //=========================================================
    //          Close the File
    //=========================================================

    // Close the file after all records have been saved.
    // This ensures that all data is written properly and
    // releases the file resource.
    fclose(fp);

    //=========================================================
    //      Display Success Message
    //=========================================================

    // Display confirmation message
    printf("\n====================================");

    // Inform the user that records were saved successfully
    printf("\nRecords Saved Successfully!");

    // Display the file name where records are stored
    printf("\nFile Name : StudentResult.txt");

    // Display closing line
    printf("\n====================================\n");
}