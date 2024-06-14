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
        printf("===== ���� üũ ���α׷� =====\n");
        printf("1. �̸� �߰�\n");
        printf("2. ���� üũ\n");
        printf("3. �ǵ�����\n");
        printf("4. �̸� ����\n");
        printf("5. ���� ��� ����\n");
        printf("6. ����\n");
        printf("�޴� ����: ");
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
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
            break;
        }
        getchar();
        printf("\n����Ϸ��� ���� Ű�� ��������...");
        getchar();
    } while (choice != 6);

    return 0;
}

void add_person(AttendanceRecord records[], int* num_people) {
    clear_screen();
    if (*num_people < MAX_PEOPLE) {
        printf("�߰��� ����� �̸��� �Է��ϼ���: ");
        scanf("%s", records[*num_people].name);
        records[*num_people].late_count = 0;
        (*num_people)++;
        printf("\n����� �߰��Ǿ����ϴ�.\n");
    } else {
        printf("\n�� �̻� �߰��� �� �����ϴ�. �ִ� �ο��� %d���Դϴ�.\n", MAX_PEOPLE);
    }
}

void check_late(AttendanceRecord records[], int num_people) {
    char name[MAX_NAME_LENGTH];
    clear_screen();
    printf("������ üũ�� ����� �̸��� �Է��ϼ���: ");
    scanf("%s", name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, name) == 0) {
            records[i].late_count++;
            printf("\n%s���� ���� Ƚ���� ��ϵǾ����ϴ�.\n", name);
            return;
        }
    }
    printf("\n%s���� ã�� �� �����ϴ�.\n", name);
}

void undo_check(AttendanceRecord records[], int num_people) {
    char name[MAX_NAME_LENGTH];
    clear_screen();
    printf("���� üũ�� �ǵ��� ����� �̸��� �Է��ϼ���: ");
    scanf("%s", name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, name) == 0) {
            if (records[i].late_count > 0) {
                records[i].late_count--;
                printf("\n%s���� ���� üũ�� �ǵ��������ϴ�.\n", name);
            } else {
                printf("\n%s���� ���� üũ ����� �����ϴ�.\n", name);
            }
            return;
        }
    }
    printf("\n%s���� ã�� �� �����ϴ�.\n", name);
}

void edit_name(AttendanceRecord records[], int num_people) {
    char old_name[MAX_NAME_LENGTH], new_name[MAX_NAME_LENGTH];
    clear_screen();
    printf("������ ����� �̸��� �Է��ϼ���: ");
    scanf("%s", old_name);
    for (int i = 0; i < num_people; i++) {
        if (strcmp(records[i].name, old_name) == 0) {
            printf("���ο� �̸��� �Է��ϼ���: ");
            scanf("%s", new_name);
            strcpy(records[i].name, new_name);
            printf("\n%s���� �̸��� �����Ǿ����ϴ�.\n", old_name);
            return;
        }
    }
    printf("\n%s���� ã�� �� �����ϴ�.\n", old_name);
}

void display_records(AttendanceRecord records[], int num_people) {
    clear_screen();
    printf("===== ���� ��� ���� =====\n");
    for (int i = 0; i < num_people; i++) {
        printf("%s: %dȸ\n", records[i].name, records[i].late_count);
    }
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}