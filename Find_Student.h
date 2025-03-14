#ifndef _FIND_STUDENT_H
#define _FIND_STUDENT_H

#include "structure.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define NAME "stud.dat"

void Find_Student();

#endif
=======
void Find_Student() {
    FILE *file = fopen(NAME, "rb");
    if (!file) {
        perror("File opening error");
        return;
    }
    char request[50];
    printf("Enter the searching field (name/faculty/group/GPA) with enter: ");
    scanf("%49s", request);
    
    Student s;
    int found = 0;
    char gpa_str[10];
    
    while (fread(&s, sizeof(Student), 1, file)) {
        snprintf(gpa_str, sizeof(gpa_str), "%.2f", s.GPA);
        if (strstr(s.name, request) || strstr(s.faculty, request) || strstr(s.group, request) || strstr(gpa_str, request)) {
            printf("\nResults of searching: %s | %s | %s | %.2f\n", s.name, s.faculty, s.group, s.GPA);
            found = 1;
        }
    }
    if (!found) {
        printf("No results found\n");
    }
    fclose(file);
}

