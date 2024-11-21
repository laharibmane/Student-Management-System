#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    int roll_no;
    char name[50];
    int age;
    float marks;
};

// Function declarations
void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(students, &count);
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a student
void addStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Maximum student limit reached.\n");
        return;
    }

    struct Student newStudent;
    printf("Enter Roll Number: ");
    scanf("%d", &newStudent.roll_no);
    printf("Enter Name: ");
    getchar();  // To consume the newline character left by previous scanf
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';  // Remove the trailing newline
    printf("Enter Age: ");
    scanf("%d", &newStudent.age);
    printf("Enter Marks: ");
    scanf("%f", &newStudent.marks);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully.\n");
}

// Function to display all students
void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d\n", students[i].roll_no);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
        printf("---------------------------\n");
    }
}

// Function to search for a student by roll number
void searchStudent(struct Student students[], int count) {
    int roll_no;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].roll_no);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student with Roll Number %d not found.\n", roll_no);
}

// Function to delete a student by roll number
void deleteStudent(struct Student students[], int *count) {
    int roll_no;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll_no);

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (students[i].roll_no == roll_no) {
            found = 1;
            // Shift the remaining students left
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;  // Decrease the student count
            printf("Student with Roll Number %d deleted successfully.\n", roll_no);
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", roll_no);
    }
}
