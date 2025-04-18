//������ 27.03.22.
// ������� 1 
//����� � ������� ������� �� ������� ������ ����� �� 4, �� �������� �������
//� �� ��������� �������� ������ ������� �� �������.
//������� 2 
//��������� �������� ���������� � �������� �������� : ���������� ������
//(�����), ��������(���������), ��������� ��������� � ���� ����������� �
//�������(������ ������������� �����) � ������� �����������������
//�����.����� �������� � �������� ���������.������� �������� �
//�������� ����������� ������.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int remainder_by_4(int n) {
    return n & 3; // ��������� � � 3 (0b11) ��� ������� �� ������� �� 4
}

void findRemainderBy4(int num) {
    printf("������� �����: ");
    while (scanf_s("%d", &num) != 1 && getchar() != '\n') {
        printf("������! ������� �����: ");
        rewind(stdin);
    }
    printf("������� �� ������� %d �� 4: %d\n", num, remainder_by_4(num));
}

#define DATE_SIZE 11   // ������ ���� "DD.MM.YYYY"
#define NAME_SIZE 50   // ������������ ����� �������� ���������

// ��������� ��� �������� ���������� � ��������
typedef struct {
    int count;                    // ���������� ������
    char name[NAME_SIZE];         // �������� ���������
    char date[DATE_SIZE];         // ���� �����������
    double lifespan;               // ������� ����������������� �����
} Animal;

// ������� ����� ������ �������
void input_string(char* str, int size) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF); // ������� ������ �����
    while (i < size - 1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        str[i++] = c;
    }
    str[i] = '\0'; // ����������� ������
}

void checkDates(char* str, int size) {
    int day=0, month=0, year=0;
    char answer=0;
  
    while (1) {
        printf("\n");
        printf("������� ����: ");
        while (scanf_s("%d", &day) != 1 || day < 0 || day > 31) {
            printf("������! ������� ���� (�����)(31 ����.): ");
            rewind(stdin);
        }

        printf("������� �����: ");
        while (scanf_s("%d", &month) != 1 || month < 0 || month > 12) {
            printf("������! ������� ����� (�����)(12 ����.): ");
            rewind(stdin);
        }
        

        printf("������� ���: ");
        while (scanf_s("%d", &year) != 1 || year < 0 || year > 2025) {
            printf("������! ������� ��� (�����)(2025 ����.): ");
            rewind(stdin);
        }
      

        // �������� ����������� ����
        int isLeap = 0;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeap = 1;
        }

        // ����������� ���������� ���� � ������
        int daysInMonth = 0;
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12) {
            daysInMonth = 31;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            daysInMonth = 30;
        }
        else if (month == 2) {
            daysInMonth = isLeap ? 29 : 28;
        }

        // �������� ������������ ����
        if (year >= 1 && year <= 9999 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= daysInMonth) {
            printf("���� ���������: %02d.%02d.%04d\n", day, month, year);
            sprintf(str, "%02d.%02d.%04d", day, month, year);
            break;
        }
        else {
            printf("���� �����������.\n");
            printf("����������, ��������� � ������������ ������ � ��������� ����.");
            continue;
        }
    }
}

// ������� ��� ����� ������ � ��������
void input_animal(Animal* a) {
    printf("������� �������� ���������: ");
    input_string(a->name, NAME_SIZE);

    printf("������� ���������� ������: ");
    while (scanf_s("%d", &a->count) != 1 && getchar() != '\n') {       
        printf("������! ������� ���������� ������: ");
        rewind(stdin);
    }

    printf("������� ���� ����������� (DD.MM.YYYY): ");
    checkDates(a->date, DATE_SIZE);

    printf("������� ������� ����������������� �����: ");
    while (scanf_s("%lf", &a->lifespan) != 1 && getchar() != '\n') {
        printf("\n");
        printf("������! ������� ������� ����������������� �����: ");
        rewind(stdin);
    }
}

// ������� ��� ������ ������ � ��������
void print_animal(const Animal* a) {
    printf("\n��������: %s\n", a->name);
    printf("���������� ������: %d\n", a->count);
    printf("���� �����������: %s\n", a->date);
    printf("������� ����������������� �����: %.2lf ���\n", a->lifespan);
}

// ������� ��������� �����
int my_strcmp(const char* a, const char* b) {
    if (a == NULL || b == NULL) return -1;

    while (*a && (*a == *b)) {
        a++;
        b++;
    }

    return *(unsigned char*)a - *(unsigned char*)b;
}

// ������� ������ �������� �� ��������
void find_by_name(Animal* animals, int size, const char* target_name, int found) {
    
    for (int i = 0; i < size; i++) {
        if (my_strcmp(animals[i].name, target_name) == 0) {
            print_animal(&animals[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("�������� � ��������� '%s' �� �������.\n", target_name);
    }
}

// ������� �������� �������� � �������� ����������� ������
int delete_by_count(Animal* animals, int size, int target_count) {
    int new_size = 0;
    for (int i = 0; i < size; i++) {
        if (animals[i].count != target_count) {
            animals[new_size++] = animals[i]; 
        }
    }
    return new_size;
}

int ZooStructure(num_animals) {
    
    printf("������� ���������� �������� � ��������: ");
    while (scanf_s("%d", &num_animals) != 1 && getchar() != '\n') {
        printf("������! ������� ���������� �������� � ��������: ");
        rewind(stdin);
    }
  
    Animal* zoo = (Animal*)malloc(num_animals * sizeof(Animal));
    if (!zoo) {
        printf("������ ��������� ������!\n");
        return -1;
    }
    
    // ���� ������ � ��������
    for (int i = 0; i < num_animals; i++) {
        printf("������� ������ ��� ��������� %d:\n", i + 1);       
        input_animal(&zoo[i]);
    }

    // ����� ���� ������
    printf("\n������ ���� ��������:\n");
    for (int i = 0; i < num_animals; i++) {
        print_animal(&zoo[i]);
    }
    int choice1 = 1;
    while (choice1 != 0) {
        int found = 0;     
        char search_name[NAME_SIZE];
        printf("\n������� �������� ��������� ��� ������: ");
        input_string(search_name, NAME_SIZE);
        find_by_name(zoo, num_animals, search_name, found);       
        printf("\n���� ������� ���������� ����� ������� ����� ����� ����� '0': ");
        scanf_s("%d", &choice1);       
    } 
    printf("\n");
    // �������� �������� � �������� ����������� ������
    int delete_count = 0;
    
    printf("������� ���������� ������ ��� �������� ���������: ");
    while (scanf_s("%d", &delete_count) != 1 || getchar() != '\n') {
        printf("O�����! ������� ���������� ������ ��� �������� ���������: ");
        rewind(stdin);
    }
    num_animals = delete_by_count(zoo, num_animals, delete_count);

    // ����� ������ ����� ��������
    printf("\n������ ����� ��������:\n");
    for (int i = 0; i < num_animals; i++) {
        print_animal(&zoo[i]);
    }

    // ������������ ������
    free(zoo);
    printf("\n������ �����������. ��������� ���������.\n\n");
    return 1;
}


