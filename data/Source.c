#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int Number;

struct tm* mytime;

struct Points {
    int artistry;
    int technique;
};
typedef struct Points points;

struct brigade_referee {
    points ref1;
    points ref2;
    points ref3;
    points ref4;
    points ref5;
};

typedef struct brigade_referee br;

struct name {
    int ID;
    char Surnames[100];
    char Name[100];
    br ref1;
    br ref2;
};

typedef struct name nm;

nm UserList[20];

nm CreatePoint(nm User) {
    User.ref1.ref1.artistry = (rand() % 9) + 1;
    User.ref1.ref1.technique = (rand() % 9) + 1;
    User.ref1.ref2.artistry = (rand() % 9) + 1;
    User.ref1.ref2.technique = (rand() % 9) + 1;
    User.ref1.ref3.artistry = (rand() % 9) + 1;
    User.ref1.ref3.technique = (rand() % 9) + 1;
    User.ref1.ref4.artistry = (rand() % 9) + 1;
    User.ref1.ref4.technique = (rand() % 9) + 1;
    User.ref1.ref5.artistry = (rand() % 9) + 1;
    User.ref1.ref5.technique = (rand() % 9) + 1;

    User.ref2.ref1.artistry = (rand() % 9) + 1;
    User.ref2.ref1.technique = (rand() % 9) + 1;
    User.ref2.ref2.artistry = (rand() % 9) + 1;
    User.ref2.ref2.technique = (rand() % 9) + 1;
    User.ref2.ref3.artistry = (rand() % 9) + 1;
    User.ref2.ref3.technique = (rand() % 9) + 1;
    User.ref2.ref4.artistry = (rand() % 9) + 1;
    User.ref2.ref4.technique = (rand() % 9) + 1;
    User.ref2.ref5.artistry = (rand() % 9) + 1;
    User.ref2.ref5.technique = (rand() % 9) + 1;

    return User;
}


void tabl() {
    puts("\t\t\t\t\tТаблица результатов по фехтованию");
    puts("\t\t\t\tСудьи\t\t\t\t\t\t");
    puts("\t Бригада судей А\t\t\t Бригада судей В\t\t\t\t\t");
    puts(" 1\t2\t3\t4\t5\t1\t2\t3\t4\t5\t");
    puts(" а т \tа т \tа т \tа т \tа т \tа т \tа т \tа т \tа т \tа т     ID     Участники");
}


void print_user(nm User)
{
    printf("|%i %i|  |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i %i|   |%i| %s %s\n", User.ref1.ref1.artistry, User.ref1.ref1.technique, User.ref1.ref2.artistry, User.ref1.ref2.technique, User.ref1.ref3.artistry, User.ref1.ref3.technique, User.ref1.ref4.artistry, User.ref1.ref4.technique, User.ref1.ref5.artistry, User.ref1.ref5.technique, User.ref2.ref1.artistry, User.ref2.ref1.technique, User.ref2.ref2.artistry, User.ref2.ref2.technique, User.ref2.ref3.artistry, User.ref2.ref3.technique, User.ref2.ref4.artistry, User.ref2.ref4.technique, User.ref2.ref5.artistry, User.ref2.ref5.technique, User.ID, User.Name, User.Surnames);
}

void writefile()
{
    FILE* F;

    if ((F = fopen("fail.txt", "w")) == NULL)
    {
        fprintf(stderr, "Невозможно открыть для чтения файл 'fail.dta'\n");
        return;
    }

    fprintf(F, "%d\n", Number);

    for (int i = 0; i < Number; i++) {
        fprintf(F, "%s %s\n", UserList[i].Surnames, UserList[i].Name);
    }
    fclose(F);
}

void Load(void)
{
    FILE* F;
    int i;

    if ((F = fopen("fail.txt", "rt")) == NULL)
    {
        fprintf(stderr, "Невозможно открыть для чтения файл 'fail.dta'\n");
        return;
    }
    int id = 0;
    fscanf(F, "%i", &Number);
    for (i = 0; i < Number; i++) {
        fscanf(F, "%s%s", &UserList[i].Surnames, &UserList[i].Name);
        UserList[i].ID = id;
        id += 1;
        UserList[i] = CreatePoint(UserList[i]);
    }
    fclose(F);
}

void sumA(answercaseA) {
    int userID = 0, A;
    switch (answercaseA) {
    case 1:
        printf("Введите ID пользователя");
        scanf("%d", &userID);
        A = UserList[userID].ref1.ref1.artistry + UserList[userID].ref1.ref2.artistry + UserList[userID].ref1.ref3.artistry + UserList[userID].ref1.ref4.artistry + UserList[userID].ref1.ref5.artistry + UserList[userID].ref2.ref1.artistry + UserList[userID].ref2.ref2.artistry + UserList[userID].ref2.ref3.artistry + UserList[userID].ref2.ref4.artistry + UserList[userID].ref2.ref5.artistry;
        printf("Сумма за A=%i|%s %s|\n", A, UserList[userID].Name, UserList[userID].Surnames);
        break;
    case 2:
        for (int i = 0; i < Number; i++) {
            A = UserList[i].ref1.ref1.artistry + UserList[i].ref1.ref2.artistry + UserList[i].ref1.ref3.artistry + UserList[i].ref1.ref4.artistry + UserList[i].ref1.ref5.artistry + UserList[i].ref2.ref1.artistry + UserList[i].ref2.ref2.artistry + UserList[i].ref2.ref3.artistry + UserList[i].ref2.ref4.artistry + UserList[i].ref2.ref5.artistry;
            printf("Сумма за A=%i|%s %s|\n", A, UserList[i].Name, UserList[i].Surnames);
        }
        break;
    default:
        break;
    }
}


void sumT(answercaseT) {
    int userID = 0, T;
    switch (answercaseT) {
    case 1:
        printf("Введите ID пользователя");
        scanf("%d", &userID);
        T = UserList[userID].ref1.ref1.technique + UserList[userID].ref1.ref2.technique + UserList[userID].ref1.ref3.technique + UserList[userID].ref1.ref4.technique + UserList[userID].ref1.ref5.technique + UserList[userID].ref2.ref1.technique + UserList[userID].ref2.ref2.technique + UserList[userID].ref2.ref3.technique + UserList[userID].ref2.ref4.technique + UserList[userID].ref2.ref5.technique;
        printf("Сумма за T=%i|%s %s|\n", T, UserList[userID].Name, UserList[userID].Surnames);
        break;
    case 2:
        for (int i = 0; i < Number; i++) {
            T = UserList[i].ref1.ref1.technique + UserList[i].ref1.ref2.technique + UserList[i].ref1.ref3.technique + UserList[i].ref1.ref4.technique + UserList[i].ref1.ref5.technique + UserList[i].ref2.ref1.artistry + UserList[i].ref2.ref2.technique + UserList[i].ref2.ref3.technique + UserList[i].ref2.ref4.technique + UserList[i].ref2.ref5.technique;
            printf("Сумма за T=%i|%s %s|\n", T, UserList[i].Name, UserList[i].Surnames);
        }
        break;
    default:
        break;
    }
}

void sumAT(answercaseAT) {
    int userID = 0, T, A;
    switch (answercaseAT) {
    case 1:
        printf("Введите ID пользователя");
        scanf("%d", &userID);
        A = UserList[userID].ref1.ref1.artistry + UserList[userID].ref1.ref2.artistry + UserList[userID].ref1.ref3.artistry + UserList[userID].ref1.ref4.artistry + UserList[userID].ref1.ref5.artistry + UserList[userID].ref2.ref1.artistry + UserList[userID].ref2.ref2.artistry + UserList[userID].ref2.ref3.artistry + UserList[userID].ref2.ref4.artistry + UserList[userID].ref2.ref5.artistry;

        T = UserList[userID].ref1.ref1.technique + UserList[userID].ref1.ref2.technique + UserList[userID].ref1.ref3.technique + UserList[userID].ref1.ref4.technique + UserList[userID].ref1.ref5.technique + UserList[userID].ref2.ref1.technique + UserList[userID].ref2.ref2.technique + UserList[userID].ref2.ref3.technique + UserList[userID].ref2.ref4.technique + UserList[userID].ref2.ref5.technique;
        printf("Сумма за A и T=%i|%s %s|\n", A + T, UserList[userID].Name, UserList[userID].Surnames);
        break;
    case 2:
        for (int i = 0; i < Number; i++) {
            A = UserList[userID].ref1.ref1.artistry + UserList[userID].ref1.ref2.artistry + UserList[userID].ref1.ref3.artistry + UserList[userID].ref1.ref4.artistry + UserList[userID].ref1.ref5.artistry + UserList[userID].ref2.ref1.artistry + UserList[userID].ref2.ref2.artistry + UserList[userID].ref2.ref3.artistry + UserList[userID].ref2.ref4.artistry + UserList[userID].ref2.ref5.artistry;

            T = UserList[i].ref1.ref1.technique + UserList[i].ref1.ref2.technique + UserList[i].ref1.ref3.technique + UserList[i].ref1.ref4.technique + UserList[i].ref1.ref5.technique + UserList[i].ref2.ref1.artistry + UserList[i].ref2.ref2.technique + UserList[i].ref2.ref3.technique + UserList[i].ref2.ref4.technique + UserList[i].ref2.ref5.technique;
            printf("Сумма за A и T=%i|%s %s|\n", A + T, UserList[i].Name, UserList[i].Surnames);
        }
        break;
    default:
        break;
    }
}

void create_new() {
    FILE* fp;
    fp = fopen("fail.txt", "a");
    fprintf(fp, "%s\n%s\n%s\n");
    fclose(fp);
}

nm* sort_artistry(nm* array) {
    for (int i = 0; i < Number - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < Number - i - 1; j++) {
            int one = UserList[j].ref1.ref1.artistry + UserList[j].ref1.ref2.artistry + UserList[j].ref1.ref3.artistry + UserList[j].ref1.ref4.artistry + UserList[j].ref1.ref5.artistry + UserList[j].ref2.ref1.artistry + UserList[j].ref2.ref2.artistry + UserList[j].ref2.ref3.artistry + UserList[j].ref2.ref4.artistry + UserList[j].ref2.ref5.artistry;
            int two = UserList[j + 1].ref1.ref1.artistry + UserList[j + 1].ref1.ref2.artistry + UserList[j + 1].ref1.ref3.artistry + UserList[j + 1].ref1.ref4.artistry + UserList[j + 1].ref1.ref5.artistry + UserList[j + 1].ref2.ref1.artistry + UserList[j + 1].ref2.ref2.artistry + UserList[j + 1].ref2.ref3.artistry + UserList[j + 1].ref2.ref4.artistry + UserList[j + 1].ref2.ref5.artistry;
            if (one < two) {
                // если они идут в неправильном порядке, то  
                //  меняем их местами. 
                nm tmp = UserList[j];
                UserList[j] = UserList[j + 1];
                UserList[j + 1] = tmp;
            }
        }
    }
    return array;
}

nm* sort_technique(nm* array) {
    for (int i = 0; i < Number - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < Number - i - 1; j++) {
            int one = UserList[j].ref1.ref1.technique + UserList[j].ref1.ref2.technique + UserList[j].ref1.ref3.technique + UserList[j].ref1.ref4.technique + UserList[j].ref1.ref5.technique + UserList[j].ref2.ref1.technique + UserList[j].ref2.ref2.technique + UserList[j].ref2.ref3.technique + UserList[j].ref2.ref4.technique + UserList[j].ref2.ref5.technique;
            int two = UserList[j + 1].ref1.ref1.technique + UserList[j + 1].ref1.ref2.technique + UserList[j + 1].ref1.ref3.technique + UserList[j + 1].ref1.ref4.technique + UserList[j + 1].ref1.ref5.technique + UserList[j + 1].ref2.ref1.technique + UserList[j + 1].ref2.ref2.technique + UserList[j + 1].ref2.ref3.technique + UserList[j + 1].ref2.ref4.technique + UserList[j + 1].ref2.ref5.technique;
            if (one < two) {
                // если они идут в неправильном порядке, то  
                //  меняем их местами. 
                nm tmp = UserList[j];
                UserList[j] = UserList[j + 1];
                UserList[j + 1] = tmp;
            }
        }
    }
    return array;
}

nm* rating(nm* array) {
    for (int i = 0; i < Number - 1; i++) {
        // сравниваем два соседних элемента.
        for (int j = 0; j < Number - i - 1; j++) {
            int oneA = UserList[j].ref1.ref1.artistry + UserList[j].ref1.ref2.artistry + UserList[j].ref1.ref3.artistry + UserList[j].ref1.ref4.artistry + UserList[j].ref1.ref5.artistry + UserList[j].ref2.ref1.artistry + UserList[j].ref2.ref2.artistry + UserList[j].ref2.ref3.artistry + UserList[j].ref2.ref4.artistry + UserList[j].ref2.ref5.artistry + UserList[j].ref1.ref1.technique + UserList[j].ref1.ref2.technique + UserList[j].ref1.ref3.technique + UserList[j].ref1.ref4.technique + UserList[j].ref1.ref5.technique + UserList[j].ref2.ref1.technique + UserList[j].ref2.ref2.technique + UserList[j].ref2.ref3.technique + UserList[j].ref2.ref4.technique + UserList[j].ref2.ref5.technique;
            int twoA = UserList[j + 1].ref1.ref1.artistry + UserList[j + 1].ref1.ref2.artistry + UserList[j + 1].ref1.ref3.artistry + UserList[j + 1].ref1.ref4.artistry + UserList[j + 1].ref1.ref5.artistry + UserList[j + 1].ref2.ref1.artistry + UserList[j + 1].ref2.ref2.artistry + UserList[j + 1].ref2.ref3.artistry + UserList[j + 1].ref2.ref4.artistry + UserList[j + 1].ref2.ref5.artistry + UserList[j + 1].ref1.ref1.technique + UserList[j + 1].ref1.ref2.technique + UserList[j + 1].ref1.ref3.technique + UserList[j + 1].ref1.ref4.technique + UserList[j + 1].ref1.ref5.technique + UserList[j + 1].ref2.ref1.technique + UserList[j + 1].ref2.ref2.technique + UserList[j + 1].ref2.ref3.technique + UserList[j + 1].ref2.ref4.technique + UserList[j + 1].ref2.ref5.technique;
            int oneT = UserList[j].ref1.ref1.technique + UserList[j].ref1.ref2.technique + UserList[j].ref1.ref3.technique + UserList[j].ref1.ref4.technique + UserList[j].ref1.ref5.technique + UserList[j].ref2.ref1.technique + UserList[j].ref2.ref2.technique + UserList[j].ref2.ref3.technique + UserList[j].ref2.ref4.technique + UserList[j].ref2.ref5.technique;
            int twoT = UserList[j + 1].ref1.ref1.technique + UserList[j + 1].ref1.ref2.technique + UserList[j + 1].ref1.ref3.technique + UserList[j + 1].ref1.ref4.technique + UserList[j + 1].ref1.ref5.technique + UserList[j + 1].ref2.ref1.technique + UserList[j + 1].ref2.ref2.technique + UserList[j + 1].ref2.ref3.technique + UserList[j + 1].ref2.ref4.technique + UserList[j + 1].ref2.ref5.technique;
            if (oneA + oneT < twoA + twoT) {
                // если они идут в неправильном порядке, то  
                //  меняем их местами. 
                nm tmp = UserList[j];
                UserList[j] = UserList[j + 1];
                UserList[j + 1] = tmp;
            }
        }
    }
    return array;
}

void printresult(nm* array) {
    rating(array);
    printf("Место\tСчет\t      Участник\n");
    for (int j = 0; j < Number; j++) {
        int oneA = UserList[j].ref1.ref1.artistry + UserList[j].ref1.ref2.artistry + UserList[j].ref1.ref3.artistry + UserList[j].ref1.ref4.artistry + UserList[j].ref1.ref5.artistry + UserList[j].ref2.ref1.artistry + UserList[j].ref2.ref2.artistry + UserList[j].ref2.ref3.artistry + UserList[j].ref2.ref4.artistry + UserList[j].ref2.ref5.artistry + UserList[j].ref1.ref1.technique + UserList[j].ref1.ref2.technique + UserList[j].ref1.ref3.technique + UserList[j].ref1.ref4.technique + UserList[j].ref1.ref5.technique + UserList[j].ref2.ref1.technique + UserList[j].ref2.ref2.technique + UserList[j].ref2.ref3.technique + UserList[j].ref2.ref4.technique + UserList[j].ref2.ref5.technique;
        int oneT = UserList[j].ref1.ref1.technique + UserList[j].ref1.ref2.technique + UserList[j].ref1.ref3.technique + UserList[j].ref1.ref4.technique + UserList[j].ref1.ref5.technique + UserList[j].ref2.ref1.technique + UserList[j].ref2.ref2.technique + UserList[j].ref2.ref3.technique + UserList[j].ref2.ref4.technique + UserList[j].ref2.ref5.technique;

        printf("  %d\t %d\t %s %s\n", j + 1, oneA + oneT, UserList[j].Name, UserList[j].Surnames);
    }
}

int main() {
    setlocale(LC_ALL, "RUS");
    SetConsoleCP(1251);         // !!!
    SetConsoleOutputCP(1251);   // !!!
    Load();


    int stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned)ltime / 2;
    srand(stime);

    int n, d = 1;
    int A, T, AT;
    int userID = 0, answercaseA = 0, answercaseT = 0, answercaseAT = 0;
    nm User;
    char id = Number;
    while (d == 1) {
        printf("База данных\n");
        printf("1)Создать пользователя\n");
        printf("2)Посмотреть таблицу\n");
        printf("3)Сумма за А\n");
        printf("4)Сумма за Т\n");
        printf("5)Сумма за всё\n");
        printf("6)Сортировка по А\n");
        printf("7)Сортировка по T\n");
        printf("8)Рейтинг\n");
        scanf("%i", &n);
        switch (n) {
        case 1:
            printf("Введите имя\n");
            getchar();
            scanf("%s", User.Name);
            printf("Введите фамилию\n");
            getchar();
            scanf("%s", User.Surnames);
            User.ID = id;
            User = CreatePoint(User);
            UserList[id] = User;
            id += 1;
            Number += 1;
            writefile();
            break;
        case 2:
            tabl();
            for (int i = 0; i < Number; i++)
                print_user(UserList[i]);
            break;
        case 3:
            printf("Выбрать пользователя по ID - 1 Посмотреть всех - 2\n");
            scanf("%d", &answercaseA);
            sumA(answercaseA);
            break;
        case 4:
            printf("Выбрать пользователя по ID - 1 Посмотреть всех - 2\n");
            scanf("%d", &answercaseT);
            sumT(answercaseT);
            break;
        case 5:
            printf("Выбрать пользователя по ID - 1 Посмотреть всех - 2\n");
            scanf("%d", &answercaseAT);
            sumAT(answercaseAT);
            break;
        case 6:
            sort_artistry(UserList);
            break;
        case 7:
            sort_technique(UserList);
            break;
        case 8:
            printresult(UserList);
            break;
        default:
            break;
        }
    }
}