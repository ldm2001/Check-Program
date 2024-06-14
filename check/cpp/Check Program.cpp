#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PEOPLE 5

typedef struct {
    char name[MAX_NAME_LENGTH];
    int late_count;
} AttendanceRecord;

void add_person(AttendanceRecord records[], int* num_people);
void check_late(AttendanceRecord records[], int num_people);
void undo_check(AttendanceRecord records[], int num_people);
void edit_name(AttendanceRecord records[], int num_people);
void display_records(AttendanceRecord records[], int num_people);
void clear_screen();

int main() {
    AttendanceRecord attendance_records[MAX_PEOPLE];
    int num_people = 0;
    int choice;

    do {
        clear_screen();
        printf("===== 지각 체크 프로그램 =====\n");
        printf("1. 이름 추가\n");
        printf("2. 지각 체크\n");
        printf("3. 되돌리기\n");
        printf("4. 이름 수정\n");
        printf("5. 지각 기록 보기\n");
        printf("6. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_person(attendance_records, &num_people);
            break;
        case 2:
            check_late(attendance_records, num_people);
            break;
        case 3:
            undo_check(attendance_records, num_people);
            break;
        case 4:
            edit_name(attendance_records, num_people);
            break;
        case 5:
            display_records(attendance_records, num_people);
            break;
        case 6:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            break;
        }
        getchar();
        printf("\n계속하려면 엔터 키를 누르세요...");
        getchar();
    } while (choice != 6);

    return 0;
}

void add_person(AttendanceRecord records[], int* num_people) {
    clear_screen();
    if (*num_people < MAX_PEOPLE) {
        printf("추가할 사람의 이름을 입력하세요: ");
        scanf("%s", records[*num_people].name);
        records[*num_people].late_count = 0;
        (*num_people)++;
        printf("\n사람이 추가되었습니다.\n");
    } else {
        printf("\n더 이상 추가할 수 없습니다. 최대 인원은 %d명입니다.\n", MAX_PEOPLE);
    }
}

void check_late(AttendanceRecord records[], int num_people) {
    char name[MAX_NAME_LENGTH];
    clear_screen();
    printf("지각을 체크할 사람의 이름을 입력하세요: ");
    scanf("%s", name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, name) == 0) {
            records[i].late_count++;
            printf("\n%s님의 지각 횟수가 기록되었습니다.\n", name);
            return;
        }
    }
    printf("\n%s님을 찾을 수 없습니다.\n", name);
}

void undo_check(AttendanceRecord records[], int num_people) {
    char name[MAX_NAME_LENGTH];
    clear_screen();
    printf("지각 체크를 되돌릴 사람의 이름을 입력하세요: ");
    scanf("%s", name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, name) == 0) {
            if (records[i].late_count > 0) {
                records[i].late_count--;
                printf("\n%s님의 지각 체크가 되돌려졌습니다.\n", name);
            } else {
                printf("\n%s님의 지각 체크 기록이 없습니다.\n", name);
            }
            return;
        }
    }
    printf("\n%s님을 찾을 수 없습니다.\n", name);
}

void edit_name(AttendanceRecord records[], int num_people) {
    char old_name[MAX_NAME_LENGTH], new_name[MAX_NAME_LENGTH];
    clear_screen();
    printf("수정할 사람의 이름을 입력하세요: ");
    scanf("%s", old_name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, old_name) == 0) {
            printf("새로운 이름을 입력하세요: ");
            scanf("%s", new_name);
            strcpy(records[i].name, new_name);
            printf("\n%s님의 이름이 수정되었습니다.\n", old_name);
            return;
        }
    }
    printf("\n%s님을 찾을 수 없습니다.\n", old_name);
}

void display_records(AttendanceRecord records[], int num_people) {
    clear_screen();
    printf("===== 지각 기록 보기 =====\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s: %d회\n", records[i].name, records[i].late_count);
    }
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}