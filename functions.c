//Çåëåíü 27.03.22.
// Çàäàíèå 1 
//Íàéòè è âûâåñòè îñòàòîê îò äåëåíèÿ öåëîãî ÷èñëà íà 4, íå âûïîëíÿÿ äåëåíèÿ
//è íå èñïîëüçóÿ îïåðàöèþ âçÿòèÿ îñòàòêà îò äåëåíèÿ.
//Çàäàíèå 2 
//Ñòðóêòóðà ñîäåðæèò èíôîðìàöèþ î æèâîòíûõ çîîïàðêà : êîëè÷åñòâî îñîáåé
//(÷èñëî), íàçâàíèå(óêàçàòåëü), âëîæåííóþ ñòðóêòóðó – äàòó ïîñòóïëåíèÿ â
//çîîïàðê(ñòðîêà ôèêñèðîâàííîé äëèíû) è ñðåäíþþ ïðîäîëæèòåëüíîñòü
//æèçíè.Íàéòè æèâîòíûõ ñ çàäàííûì íàçâàíèåì.Óäàëèòü æèâîòíûõ ñ
//çàäàííûì êîëè÷åñòâîì îñîáåé.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct {
    unsigned int division : 2;
}remainder;

void findRemainderBy4(int num) {
    printf("Введите число: ");
    while (scanf_s("%d", &num) != 1 && getchar() != '\n') {
        printf("Ошибка! Введите число: ");
        rewind(stdin);
    }
    remainder.division = num & 3;
    printf("Остаток от деления %d на 4: %d\n", num, remainder.division);
}

#define DATE_SIZE 11   // Ôîðìàò äàòû "DD.MM.YYYY"
#define NAME_SIZE 50   // Ìàêñèìàëüíàÿ äëèíà íàçâàíèÿ æèâîòíîãî

// Ñòðóêòóðà äëÿ õðàíåíèÿ èíôîðìàöèè î æèâîòíûõ
typedef struct {
    int count;                    // Êîëè÷åñòâî îñîáåé
    char name[NAME_SIZE];         // Íàçâàíèå æèâîòíîãî
    char date[DATE_SIZE];         // Äàòà ïîñòóïëåíèÿ
    double lifespan;               // Ñðåäíÿÿ ïðîäîëæèòåëüíîñòü æèçíè
} Animal;

// Ôóíêöèÿ ââîäà ñòðîêè âðó÷íóþ
void input_string(char* str, int size) {
    char c;
    int i = 0;
    while ((c = getchar()) != '\n' && c != EOF); // Î÷èñòêà áóôåðà ââîäà
    while (i < size - 1) {
        c = getchar();
        if (c == '\n' || c == EOF) {
            break;
        }
        str[i++] = c;
    }
    str[i] = '\0'; // Çàâåðøàþùèé ñèìâîë
}

void checkDates(char* str, int size) {
    int day=0, month=0, year=0;
    char answer=0;
  
    while (1) {
        printf("\n");
        printf("Ââåäèòå äåíü: ");
        while (scanf_s("%d", &day) != 1 || day < 0 || day > 31) {
            printf("Îøèáêà! Ââåäèòå äåíü (÷èñëî)(31 ìàêñ.): ");
            rewind(stdin);
        }

        printf("Ââåäèòå ìåñÿö: ");
        while (scanf_s("%d", &month) != 1 || month < 0 || month > 12) {
            printf("Îøèáêà! Ââåäèòå ìåñÿö (÷èñëî)(12 ìàêñ.): ");
            rewind(stdin);
        }
        

        printf("Ââåäèòå ãîä: ");
        while (scanf_s("%d", &year) != 1 || year < 0 || year > 2025) {
            printf("Îøèáêà! Ââåäèòå ãîä (÷èñëî)(2025 ìàêñ.): ");
            rewind(stdin);
        }
      

        // Ïðîâåðêà âèñîêîñíîãî ãîäà
        int isLeap = 0;
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            isLeap = 1;
        }

        // Îïðåäåëåíèå êîëè÷åñòâà äíåé â ìåñÿöå
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

        // Ïðîâåðêà êîððåêòíîñòè äàòû
        if (year >= 1 && year <= 9999 &&
            month >= 1 && month <= 12 &&
            day >= 1 && day <= daysInMonth) {
            printf("Äàòà êîððåêòíà: %02d.%02d.%04d\n", day, month, year);
            sprintf(str, "%02d.%02d.%04d", day, month, year);
            break;
        }
        else {
            printf("Äàòà íåêîððåêòíà.\n");
            printf("Ïîæàëóéñòà, óáåäèòåñü â êîððåêòíîñòè äàííûõ è ïîâòîðèòå ââîä.");
            continue;
        }
    }
}

// Ôóíêöèÿ äëÿ ââîäà äàííûõ î æèâîòíîì
void input_animal(Animal* a) {
    printf("Ââåäèòå íàçâàíèå æèâîòíîãî: ");
    input_string(a->name, NAME_SIZE);

    printf("Ââåäèòå êîëè÷åñòâî îñîáåé: ");
    while (scanf_s("%d", &a->count) != 1 && getchar() != '\n') {       
        printf("Îøèáêà! Ââåäèòå êîëè÷åñòâî îñîáåé: ");
        rewind(stdin);
    }

    printf("Ââåäèòå äàòó ïîñòóïëåíèÿ (DD.MM.YYYY): ");
    checkDates(a->date, DATE_SIZE);

    printf("Ââåäèòå ñðåäíþþ ïðîäîëæèòåëüíîñòü æèçíè: ");
    while (scanf_s("%lf", &a->lifespan) != 1 && getchar() != '\n') {
        printf("\n");
        printf("Îøèáêà! Ââåäèòå ñðåäíþþ ïðîäîëæèòåëüíîñòü æèçíè: ");
        rewind(stdin);
    }
}

// Ôóíêöèÿ äëÿ âûâîäà äàííûõ î æèâîòíîì
void print_animal(const Animal* a) {
    printf("\nÍàçâàíèå: %s\n", a->name);
    printf("Êîëè÷åñòâî îñîáåé: %d\n", a->count);
    printf("Äàòà ïîñòóïëåíèÿ: %s\n", a->date);
    printf("Ñðåäíÿÿ ïðîäîëæèòåëüíîñòü æèçíè: %.2lf ëåò\n", a->lifespan);
}

// Ôóíêöèÿ ñðàâíåíèÿ ñòðîê
int my_strcmp(const char* a, const char* b) {
    if (a == NULL || b == NULL) return -1;

    while (*a && (*a == *b)) {
        a++;
        b++;
    }

    return *(unsigned char*)a - *(unsigned char*)b;
}

// Ôóíêöèÿ ïîèñêà æèâîòíûõ ïî íàçâàíèþ
void find_by_name(Animal* animals, int size, const char* target_name, int found) {
    
    for (int i = 0; i < size; i++) {
        if (my_strcmp(animals[i].name, target_name) == 0) {
            print_animal(&animals[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Æèâîòíûå ñ íàçâàíèåì '%s' íå íàéäåíû.\n", target_name);
    }
}

// Ôóíêöèÿ óäàëåíèÿ æèâîòíûõ ñ çàäàííûì êîëè÷åñòâîì îñîáåé
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
    
    printf("Ââåäèòå êîëè÷åñòâî æèâîòíûõ â çîîïàðêå: ");
    while (scanf_s("%d", &num_animals) != 1 && getchar() != '\n') {
        printf("Îøèáêà! Ââåäèòå êîëè÷åñòâî æèâîòíûõ â çîîïàðêå: ");
        rewind(stdin);
    }
  
    Animal* zoo = (Animal*)malloc(num_animals * sizeof(Animal));
    if (!zoo) {
        printf("Îøèáêà âûäåëåíèÿ ïàìÿòè!\n");
        return -1;
    }
    
    // Ââîä äàííûõ î æèâîòíûõ
    for (int i = 0; i < num_animals; i++) {
        printf("Ââåäèòå äàííûå äëÿ æèâîòíîãî %d:\n", i + 1);       
        input_animal(&zoo[i]);
    }

    // Âûâîä âñåõ äàííûõ
    printf("\nÑïèñîê âñåõ æèâîòíûõ:\n");
    for (int i = 0; i < num_animals; i++) {
        print_animal(&zoo[i]);
    }
    int choice1 = 1;
    while (choice1 != 0) {
        int found = 0;     
        char search_name[NAME_SIZE];
        printf("\nÂâåäèòå íàçâàíèå æèâîòíîãî äëÿ ïîèñêà: ");
        input_string(search_name, NAME_SIZE);
        find_by_name(zoo, num_animals, search_name, found);       
        printf("\nÅñëè æåëàåòå ïðîäîëæèòü ïîèñê ââåäèòå ëþáîé òåêñò êðîìå '0': ");
        scanf_s("%d", &choice1);       
    } 
    printf("\n");
    // Óäàëåíèå æèâîòíûõ ñ çàäàííûì êîëè÷åñòâîì îñîáåé
    int delete_count = 0;
    
    printf("Ââåäèòå êîëè÷åñòâî îñîáåé äëÿ óäàëåíèÿ æèâîòíîãî: ");
    while (scanf_s("%d", &delete_count) != 1 || getchar() != '\n') {
        printf("Oøèáêà! Ââåäèòå êîëè÷åñòâî îñîáåé äëÿ óäàëåíèÿ æèâîòíîãî: ");
        rewind(stdin);
    }
    num_animals = delete_by_count(zoo, num_animals, delete_count);

    // Âûâîä ñïèñêà ïîñëå óäàëåíèÿ
    printf("\nÑïèñîê ïîñëå óäàëåíèÿ:\n");
    for (int i = 0; i < num_animals; i++) {
        print_animal(&zoo[i]);
    }

    // Îñâîáîæäåíèå ïàìÿòè
    free(zoo);
    printf("\nÏàìÿòü îñâîáîæäåíà. Ïðîãðàììà çàâåðøåíà.\n\n");
    return 1;
}


