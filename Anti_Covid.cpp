#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
#include <time.h>
#pragma warning(disable:4996)

FILE* user;
FILE* tradesman;
FILE* managment;
FILE* hospital;

char str[50];
char ch1;
int i, j;
int num_user = 0;
int num_tradesman = 0;
int num_hospital = 0;
int x;
time_t now;
struct tm tm;
double second;

void grafic(void);
void safhe1(void);
void login(void);
void login_managment(void);
void login_user(void);
void login_tradesman(void);
void creat_acount(void);
void creat_acount_user(void);
void creat_acount_tradesman(void);
void forget_password(void);
void forget_password_managment(void);
void forget_password_user(void);
void forget_password_tradesman(void);
void menum(void);
void edit_pro_modir(void);
void Enter_the_hospital(void);
void See_patient(void);
void Enter_improved_people(void);
void View_all_people(void);
void View_the_deads_list(void);
void View_registered_jobs(void);
void View_registered_hospitals(void);
void menuu(void);
void edit_pro_user(void);
void Health_situation_record(void);
void View_health_entry_history(void);
void record_meeting_with_other_people();
void View_meeting_history(void);
void Add_places_has_gone(void);
void view_the_history_of_places_that_have_gone(void);
void View_corona_statistics(void);
void View_nearby_hospitalsand_treatment_centers(void);
void menusb(void);
void edit_pro_sahebin(void);
void Moshahede_vaziat_makan(void);
void Zede_ofooni_kardan_maghaze(void);
void View_the_number_of_infected_people(void);

struct managment {
    char fnamem[50];
    char lnamem[50];
    char unamem[50];
    char passm[50];
    char passam[50];
    char ncodem[50];
    char emailm[50];
};
struct managment managmentst = { "aref","habibi","ah","1234","1234","123456789","haref460@gmail.com" };

struct user {
    char fnameu[50];
    char lnameu[50];
    char ncodeu[50];
    char unameu[50];
    char passu[50];
    char passau[50];
    char emailu[50];
    char btypeu[50];
    char ageu[50];
    char heightu[50];
    char weightu[50];

    bool haiat;

    int tvsalamati;
    int vsalamati[10];
    time_t sabt_vsalamati[10];
    int max_vsalamati;
    time_t sabt_max_vsalamati;

    int tmolaghat;
    char molaghat[10][50];
    int molaghat_code[10];
    char molaghat_codemeli[10][50];
    time_t sabt_molaghat[10];

    int tmolaghat_makan;
    char molaghat_makan[10][50];
    char molaghat_makan_vaziat[10][50];
    time_t sabt_molaghat_makan[10];
};
struct user userst[100];

struct tradesman {
    char fnamesb[50];
    char lnamesb[50];
    char ncodesb[50];
    char unamesb[50];
    char passsb[50];
    char passasb[50];
    char emailsb[50];
    char nshopsb[50];
    char cshopsb[50];
    char ashopsb[50];

    bool vaziat;
    time_t zaman_vaziat;

    int code2;
    int code3;
    int code4;
};
struct tradesman tradesmanst[100];

struct hospital {
    char name_area[50];
    char name_hospital[50];
};
struct hospital hospitalst[100];

int main() {
    for (i = 0; i < 100; i++) {
        userst[i].tvsalamati = 0;
        userst[i].max_vsalamati = 1;
        userst[i].tmolaghat = 0;
        userst[i].tmolaghat_makan = 0;
        userst[i].haiat = true;
        tradesmanst[i].vaziat = false;
        tradesmanst[i].code2 = 0;
        tradesmanst[i].code3 = 0;
        tradesmanst[i].code4 = 0;
    }
    safhe1();
    return 0;
}
void grafic(void) {
    system("color 4e");
    printf("\n\n\n            __    _  _  ____  ____     ___  _____  _  _  ____  ____  \n");
    printf("           /__\\  ( \\( )(_  _)(_  _)   / __)(  _  )( \\/ )(_  _)(  _ \\ \n");
    printf("          /(__)\\  )  (   )(   _)(_   ( (__  )(_)(  \\  /  _)(_  )(_) )  \n");
    printf("         (__)(__)(_)\\_) (__) (____)   \\___)(_____)  \\/  (____)(____/  \n\n\n");
    printf("         ANTI COVID\n");
    printf("         MADE BY : AREF HABIBI");
}

void safhe1(void) {

    managment = fopen("managment.txt", "r");
    if (managment == NULL) {
        managment = fopen("managment.txt", "w");
        fclose(managment);
    }
    else {
        fread(&managmentst, sizeof(struct managment), 1, managment);
        fclose(managment);
    }

    user = fopen("user.txt", "r");
    if (user == NULL) {
        user = fopen("user.txt", "w");
        fclose(user);
    }
    else {
        fread(&num_user, sizeof(int), 1, user);
        for (i = 0; i < num_user; i++) {
            fread(&userst[i], sizeof(struct user), 1, user);
        }
        fclose(user);
    }

    tradesman = fopen("tradesman.txt", "r");
    if (tradesman == NULL) {
        tradesman = fopen("tradesman.txt", "w");
        fclose(tradesman);
    }
    else {
        fread(&num_tradesman, sizeof(int), 1, tradesman);
        for (i = 0; i < num_tradesman; i++) {
            fread(&tradesmanst[i], sizeof(struct tradesman), 1, tradesman);
        }
        fclose(tradesman);
    }

    hospital = fopen("hospital.txt", "r");
    if (hospital == NULL) {
        hospital = fopen("hospital.txt", "w");
        fclose(hospital);
    }
    else {
        fread(&num_hospital, sizeof(int), 1, hospital);
        for (i = 0; i < num_hospital; i++) {
            fread(&hospitalst[i], sizeof(struct hospital), 1, hospital);
        }
        fclose(hospital);
    }
    grafic();
    printf("\n\n\n\t\t\t\t1 : Login\n");
    printf("\t\t\t\t2 : Creat acount\n");
    printf("\t\t\t\t3 : Forget password\n\n\n\n");

    printf("\t\t\t\tEnter your choice : ");
    str[0] = '\0';
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Login") == 0 || str[0] == '1') login();
    if (strcmpi(str, "Creat acount") == 0 || str[0] == '2') creat_acount();
    if (strcmpi(str, "Forget password") == 0 || str[0] == '3') forget_password();
}

void login(void) {
    printf("\n*********************************** LOGIN **************************************");
    printf("\n\n\n\n\n\n\t\t\t     1_ Managment");
    printf("\n\n\t\t\t     2_ User");
    printf("\n\n\t\t\t     3_ Tradesman");
    printf("\n\n\n\t\t\t     Who are you, Enter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    system("cls");
    if (strcmpi(str, "Managment") == 0 || str[0] == '1') login_managment();
    else if (strcmpi(str, "User") == 0 || str[0] == '2') login_user();
    else if (strcmpi(str, "Tradesman") == 0 || str[0] == '3') login_tradesman();
}

void login_managment(void) {
    char username[50];
    char password[50];

    printf("\n*********************************** LOGIN **************************************");
    printf("\n\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(username, 50, stdin);
    username[strlen(username) - 1] = '\0';
    printf("\n\n\t\t\t\tPassword : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        password[i] = ch1;
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    password[i] = '\0';

    system("cls");

    if (strcmpi(username, managmentst.unamem) == 0 && strcmpi(password, managmentst.passm) == 0) menum();
    else {
        printf("\n\n\n\t\t\tUsername or password is incorrect");
        printf("\n\n\n\n\n\n\t\t\t1_ Home");
        printf("\n\n\n\t\t\t2_ Exit");
        printf("\n\n\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
        if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    }
}

void login_user(void) {
    char username[50];
    char password[50];

    printf("\n*********************************** LOGIN **************************************");
    printf("\n\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(username, 50, stdin);
    username[strlen(username) - 1] = '\0';
    printf("\n\n\t\t\t\tPassword : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();

        password[i] = ch1;
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    password[i] = '\0';

    system("cls");

    for (x = 0; x < num_user; x++) {
        if (strcmpi(username, userst[x].unameu) == 0 && strcmpi(password, userst[x].passu) == 0) menuu();
    }
    if (x == num_user) {
        printf("\n\n\n\t\t\tUsername or password is incorrect");
        printf("\n\n\n\n\n\n\t\t\t1_ Home");
        printf("\n\n\n\t\t\t2_ Exit");
        printf("\n\n\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
        if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    }
}

void login_tradesman(void) {
    char username[50];
    char password[50];

    printf("\n*********************************** LOGIN **************************************");
    printf("\n\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(username, 50, stdin);
    username[strlen(username) - 1] = '\0';
    printf("\n\n\t\t\t\tPassword : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        password[i] = ch1;
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    password[i] = '\0';

    system("cls");

    for (x = 0; x < num_user; x++) {
        if (strcmpi(username, tradesmanst[x].unamesb) == 0 && strcmpi(password, tradesmanst[x].passsb) == 0) menusb();
    }
    if (x == num_user) {
        printf("\n\n\n\t\t\tUsername or password is incorrect");
        printf("\n\n\n\n\n\n\t\t\t1_ Home");
        printf("\n\n\n\t\t\t2_ Exit");
        printf("\n\n\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
        if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    }
}

void creat_acount(void) {
    printf("\n******************************* CREAT ACOUNT ***********************************");
    printf("\n\n\n\n\n\t\t\tWhat type of acount do you want?\n\n\n\n\n\n");
    printf("\t\t\t1 : Ordinary user\n");
    printf("\t\t\t2 : Tradesman\n\n\n\n");
    printf("\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Ordinary user") == 0 || str[0] == '1') creat_acount_user();
    if (strcmpi(str, "Tradesman") == 0 || str[0] == '2') creat_acount_tradesman();
}

void creat_acount_user(void) {
    printf("\n******************************* CREAT ACOUNT ***********************************");
    printf("\n\t\t\tFirst name : ");
    fgets(userst[num_user].fnameu, 50, stdin);
    while (userst[num_user].fnameu[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your first name again : ");
        fgets(userst[num_user].fnameu, 50, stdin);
    }
    userst[num_user].fnameu[strlen(userst[num_user].fnameu) - 1] = '\0';

    printf("\n\t\t\tLast name : ");
    fgets(userst[num_user].lnameu, 50, stdin);
    while (userst[num_user].lnameu[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your last name again : ");
        fgets(userst[num_user].lnameu, 50, stdin);
    }
    userst[num_user].lnameu[strlen(userst[num_user].lnameu) - 1] = '\0';

    printf("\n\t\t\tNational code : ");
    fgets(userst[num_user].ncodeu, 50, stdin);
    while (userst[num_user].ncodeu[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your national code again : ");
        fgets(userst[num_user].ncodeu, 50, stdin);
    }
    userst[num_user].ncodeu[strlen(userst[num_user].ncodeu) - 1] = '\0';

    printf("\n\t\t\tUser name : ");
    fgets(userst[num_user].unameu, 50, stdin);
    while (userst[num_user].unameu[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your user[num_user] name again : ");
        fgets(userst[num_user].unameu, 50, stdin);
    }
    userst[num_user].unameu[strlen(userst[num_user].unameu) - 1] = '\0';

    printf("\n\t\t\tPassword : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        userst[num_user].passu[i] = ch1;
        if (userst[num_user].passu[0] == 13) {
            printf("\n\t\t\tNot corrected , Enter your password again : ");
            i--;
            continue;
        }
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    userst[num_user].passu[i] = '\0';

    printf("\n\n\t\t\tRepeat password : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        userst[num_user].passau[i] = ch1;
        if (userst[num_user].passau[0] == 13) {
            printf("\n\t\t\tNot corrected , Enter your repeat password again : ");
            i--;
            continue;
        }
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    userst[num_user].passau[i] = '\0';

    printf("\n\n\t\t\tEmail : ");
    fgets(userst[num_user].emailu, 50, stdin);
    while (userst[num_user].emailu[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your user[num_user] email again : ");
        fgets(userst[num_user].emailu, 50, stdin);
    }
    userst[num_user].emailu[strlen(userst[num_user].emailu) - 1] = '\0';

    printf("\n\t\t\tBlood type : ");
    fgets(userst[num_user].btypeu, 50, stdin);
    userst[num_user].btypeu[strlen(userst[num_user].btypeu) - 1] = '\0';

    printf("\n\t\t\tAge : ");
    fgets(userst[num_user].ageu, 50, stdin);
    userst[num_user].ageu[strlen(userst[num_user].ageu) - 1] = '\0';

    printf("\n\t\t\tHeight : ");
    fgets(userst[num_user].heightu, 50, stdin);
    userst[num_user].heightu[strlen(userst[num_user].heightu) - 1] = '\0';

    printf("\n\t\t\tWeight : ");
    fgets(userst[num_user].weightu, 50, stdin);
    userst[num_user].weightu[strlen(userst[num_user].weightu) - 1] = '\0';

    system("cls");
    if (strcmp(userst[num_user].passu, userst[num_user].passau) == 0) {
        if (strcmp(userst[num_user].unameu, managmentst.unamem) == 0 || strcmp(userst[num_user].ncodeu, managmentst.ncodem) == 0) {
            printf("\n\n\n\t\t\tThis username or national code already exists");
            printf("\n\n\n\n\n\n\t\t\t1_ Home");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
        for (j = 0; j < num_user; j++) {
            if (strcmp(userst[num_user].unameu, userst[j].unameu) == 0 || strcmp(userst[num_user].ncodeu, userst[j].ncodeu) == 0) {
                printf("\n\n\n\t\t\tThis username or national code already exists");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
        }
        for (j = 0; j < num_tradesman; j++) {
            if (strcmp(userst[num_user].unameu, tradesmanst[j].unamesb) == 0 || strcmp(userst[num_user].ncodeu, tradesmanst[j].ncodesb) == 0) {
                printf("\n\n\n\t\t\tThis username or national code already exists");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
        }

        user = fopen("user.txt", "w");
        num_user++;
        fwrite(&num_user, sizeof(int), 1, user);
        for (i = 0; i < num_user; i++) {
            fwrite(&userst[i], sizeof(struct user), 1, user);
        }
        fclose(user);
        safhe1();
    }
    else {
        printf("\n\n\n\t\t\tPassword and repeat password are not the same");
        printf("\n\n\n\n\n\n\t\t\t1_ Home");
        printf("\n\n\n\t\t\t2_ Exit");
        printf("\n\n\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
        if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    }
}

void creat_acount_tradesman(void) {
    printf("\n******************************* CREAT ACOUNT ***********************************");
    printf("\n\t\t\tFirst name : ");
    fgets(tradesmanst[num_tradesman].fnamesb, 50, stdin);
    while (tradesmanst[num_tradesman].fnamesb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your first name again : ");
        fgets(tradesmanst[num_tradesman].fnamesb, 50, stdin);
    }
    tradesmanst[num_tradesman].fnamesb[strlen(tradesmanst[num_tradesman].fnamesb) - 1] = '\0';

    printf("\n\t\t\tLast name : ");
    fgets(tradesmanst[num_tradesman].lnamesb, 50, stdin);
    while (tradesmanst[num_tradesman].lnamesb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your last name again : ");
        fgets(tradesmanst[num_tradesman].lnamesb, 50, stdin);
    }
    tradesmanst[num_tradesman].lnamesb[strlen(tradesmanst[num_tradesman].lnamesb) - 1] = '\0';

    printf("\n\t\t\tNational code : ");
    fgets(tradesmanst[num_tradesman].ncodesb, 50, stdin);
    while (tradesmanst[num_tradesman].ncodesb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your national code again : ");
        fgets(tradesmanst[num_tradesman].ncodesb, 50, stdin);
    }
    tradesmanst[num_tradesman].ncodesb[strlen(tradesmanst[num_tradesman].ncodesb) - 1] = '\0';

    printf("\n\t\t\tUser name : ");
    fgets(tradesmanst[num_tradesman].unamesb, 50, stdin);
    while (tradesmanst[num_tradesman].unamesb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your user name again : ");
        fgets(tradesmanst[num_tradesman].unamesb, 50, stdin);
    }
    tradesmanst[num_tradesman].unamesb[strlen(tradesmanst[num_tradesman].unamesb) - 1] = '\0';

    printf("\n\t\t\tPassword : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        tradesmanst[num_tradesman].passsb[i] = ch1;
        if (tradesmanst[num_tradesman].passsb[0] == 13) {
            printf("\n\t\t\tNot corrected , Enter your password again : ");
            i--;
            continue;
        }
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    tradesmanst[num_tradesman].passsb[i] = '\0';

    printf("\n\n\t\t\tRepeat password : ");
    for (i = 0; i < 50; i++) {
        ch1 = _getch();
        tradesmanst[num_tradesman].passasb[i] = ch1;
        if (tradesmanst[num_tradesman].passasb[0] == 13) {
            printf("\n\t\t\tNot corrected , Enter your repeat password again : ");
            i--;
            continue;
        }
        if (ch1 == 8 && i >= 1) {
            printf("\b \b");
            i -= 2;
            continue;
        }
        else if (ch1 != 13)
            printf("*");
        else if (ch1 == 13)
            break;
    }
    tradesmanst[num_tradesman].passasb[i] = '\0';

    printf("\n\n\t\t\tEmail : ");
    fgets(tradesmanst[num_tradesman].emailsb, 50, stdin);
    while (tradesmanst[num_tradesman].emailsb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your email again : ");
        fgets(tradesmanst[num_tradesman].emailsb, 50, stdin);
    }
    tradesmanst[num_tradesman].emailsb[strlen(tradesmanst[num_tradesman].emailsb) - 1] = '\0';

    printf("\n\t\t\tShop name : ");
    fgets(tradesmanst[num_tradesman].nshopsb, 50, stdin);
    while (tradesmanst[num_tradesman].nshopsb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your shop name again : ");
        fgets(tradesmanst[num_tradesman].nshopsb, 50, stdin);
    }
    tradesmanst[num_tradesman].nshopsb[strlen(tradesmanst[num_tradesman].nshopsb) - 1] = '\0';

    printf("\n\t\t\tShop city : ");
    fgets(tradesmanst[num_tradesman].cshopsb, 50, stdin);
    while (tradesmanst[num_tradesman].cshopsb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your shop city again : ");
        fgets(tradesmanst[num_tradesman].cshopsb, 50, stdin);
    }
    tradesmanst[num_tradesman].cshopsb[strlen(tradesmanst[num_tradesman].cshopsb) - 1] = '\0';

    printf("\n\t\t\tShop area : ");
    fgets(tradesmanst[num_tradesman].ashopsb, 50, stdin);
    while (tradesmanst[num_tradesman].ashopsb[0] == '\n') {
        printf("\t\t\tNot corrected , Enter your shop area again : ");
        fgets(tradesmanst[num_tradesman].ashopsb, 50, stdin);
    }
    tradesmanst[num_tradesman].ashopsb[strlen(tradesmanst[num_tradesman].ashopsb) - 1] = '\0';

    system("cls");
    if (strcmp(tradesmanst[num_tradesman].passsb, tradesmanst[num_tradesman].passasb) == 0) {
        if (strcmp(tradesmanst[num_tradesman].unamesb, managmentst.unamem) == 0 || strcmp(tradesmanst[num_tradesman].ncodesb, managmentst.ncodem) == 0) {
            printf("\n\n\n\t\t\tThis username or password already exists");
            printf("\n\n\n\n\n\n\t\t\t1_ Home");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
        for (j = 0; j < num_user; j++) {
            if (strcmp(tradesmanst[num_tradesman].unamesb, userst[j].unameu) == 0 || strcmp(tradesmanst[num_tradesman].ncodesb, userst[j].ncodeu) == 0) {
                printf("\n\n\n\t\t\tThis username or password already exists");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
        }
        for (j = 0; j < num_tradesman; j++) {
            if (strcmp(tradesmanst[num_tradesman].unamesb, tradesmanst[j].unamesb) == 0 || strcmp(tradesmanst[num_tradesman].ncodesb, tradesmanst[j].ncodesb) == 0) {
                printf("\n\n\n\t\t\tThis username or password already exists");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
        }

        tradesman = fopen("tradesman.txt", "w");
        num_tradesman++;
        fwrite(&num_tradesman, sizeof(int), 1, tradesman);
        for (i = 0; i < num_tradesman; i++) {
            fwrite(&tradesmanst[i], sizeof(struct tradesman), 1, tradesman);
        }
        fclose(tradesman);
        safhe1();
    }
    else {
        printf("\n\n\n\t\t\tPassword and repeat password are not the same");
        printf("\n\n\n\n\n\n\t\t\t1_ Home");
        printf("\n\n\n\t\t\t2_ Exit");
        printf("\n\n\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
        if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    }
}

void forget_password(void) {
    printf("\n****************************** FORGET PASSWORD *********************************");
    printf("\n\n\n\n\n\n\t\t\t     1_ Managment");
    printf("\n\n\t\t\t     2_ User");
    printf("\n\n\t\t\t     3_ Tradesman");
    printf("\n\n\n\t\t\t     Who are you, Enter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    system("cls");

    if (strcmpi(str, "Managment") == 0 || str[0] == '1') forget_password_managment();
    else if (strcmpi(str, "User") == 0 || str[0] == '2') forget_password_user();
    else if (strcmpi(str, "Tradesman") == 0 || str[0] == '3') forget_password_tradesman();
}

void forget_password_managment(void) {
    char fuser[50];
    char fcod[50];
    char femail[50];

    printf("\n****************************** FORGET PASSWORD *********************************");
    printf("\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(fuser, 50, stdin);
    fuser[strlen(fuser) - 1] = '\0';

    printf("\n\n\n\t\t\t\tNational code : ");
    fgets(fcod, 50, stdin);
    fcod[strlen(fcod) - 1] = '\0';

    printf("\n\n\n\t\t\t\tEmail : ");
    fgets(femail, 50, stdin);
    femail[strlen(femail) - 1] = '\0';

    system("cls");

    if (strcmpi(fuser, managmentst.unamem) == 0 && strcmpi(fcod, managmentst.ncodem) == 0 && strcmpi(femail, managmentst.emailm) == 0) {
        printf("\n\n\n\n\n\n\t\t\tEnter your password : ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            managmentst.passm[i] = ch1;
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        managmentst.passm[i] = '\0';

        printf("\n\n\n\n\n\t\t\tEnter your password again: ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            managmentst.passam[i] = ch1;
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        managmentst.passam[i] = '\0';
        system("cls");
        if (strcmpi(managmentst.passm, managmentst.passam) == 0) {
            managment = fopen("managment.txt", "w");
            fwrite(&managmentst, sizeof(struct managment), 1, managment);
            fclose(managment);
            system("cls");
            safhe1();
        }
        else {
            printf("\n\n\n\t\t\tPassword and repeat password are not the same");
            printf("\n\n\n\n\n\n\t\t\t1_ Home");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
    }
    else {
        printf("\n\n\n\n\t\t\tNot corrected ,Enter 0 to get back to menu : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        system("cls");

        if (strcmpi(str, "0") == 0) safhe1();
    }
}

void forget_password_user(void) {
    char fuser[50];
    char fcod[50];
    char femail[50];

    printf("\n****************************** FORGET PASSWORD *********************************");
    printf("\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(fuser, 50, stdin);
    fuser[strlen(fuser) - 1] = '\0';

    printf("\n\n\n\t\t\t\tNational code : ");
    fgets(fcod, 50, stdin);
    fcod[strlen(fcod) - 1] = '\0';

    printf("\n\n\n\t\t\t\tEmail : ");
    fgets(femail, 50, stdin);
    femail[strlen(femail) - 1] = '\0';

    system("cls");
    for (j = 0; j < num_user; j++) {
        if (strcmpi(fuser, userst[j].unameu) == 0 && strcmpi(fcod, userst[j].ncodeu) == 0 && strcmpi(femail, userst[j].emailu) == 0) {
            printf("\n\n\n\n\n\n\t\t\tEnter your password : ");
            for (i = 0; i < 50; i++) {
                ch1 = _getch();
                userst[j].passu[i] = ch1;
                if (ch1 == 8 && i >= 1) {
                    printf("\b \b");
                    i -= 2;
                    continue;
                }
                else if (ch1 != 13)
                    printf("*");
                else if (ch1 == 13)
                    break;
            }
            userst[j].passu[i] = '\0';

            printf("\n\n\n\n\n\t\t\tEnter your password again: ");
            for (i = 0; i < 50; i++) {
                ch1 = _getch();
                userst[j].passau[i] = ch1;
                if (ch1 == 8 && i >= 1) {
                    printf("\b \b");
                    i -= 2;
                    continue;
                }
                else if (ch1 != 13)
                    printf("*");
                else if (ch1 == 13)
                    break;
            }
            userst[j].passau[i] = '\0';
            system("cls");
            if (strcmpi(userst[j].passu, userst[j].passau) == 0) {
                user = fopen("user.txt", "w");
                fwrite(&num_user, sizeof(int), 1, user);
                for (i = 0; i < num_user; i++) {
                    fwrite(&userst[i], sizeof(struct user), 1, user);
                }
                fclose(user);
                system("cls");
                safhe1();
            }
            else {
                printf("\n\n\n\t\t\tPassword and repeat password are not the same");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
            break;
        }
        else {
            printf("\n\n\n\n\t\t\tNot corrected ,Enter 0 to get back to menu : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "0") == 0) safhe1();
        }
    }
}

void forget_password_tradesman(void) {
    char fuser[50];
    char fcod[50];
    char femail[50];

    printf("\n****************************** FORGET PASSWORD *********************************");
    printf("\n\n\n\n\n\n\t\t\t\tUser name : ");
    fgets(fuser, 50, stdin);
    fuser[strlen(fuser) - 1] = '\0';

    printf("\n\n\n\t\t\t\tNational code : ");
    fgets(fcod, 50, stdin);
    fcod[strlen(fcod) - 1] = '\0';

    printf("\n\n\n\t\t\t\tEmail : ");
    fgets(femail, 50, stdin);
    femail[strlen(femail) - 1] = '\0';

    system("cls");
    for (j = 0; j < num_user; j++) {
        if (strcmpi(fuser, tradesmanst[j].unamesb) == 0 && strcmpi(fcod, tradesmanst[j].ncodesb) == 0 && strcmpi(femail, tradesmanst[j].emailsb) == 0) {
            printf("\n\n\n\n\n\n\t\t\tEnter your password : ");
            for (i = 0; i < 50; i++) {
                ch1 = _getch();
                tradesmanst[j].passsb[i] = ch1;
                if (ch1 == 8 && i >= 1) {
                    printf("\b \b");
                    i -= 2;
                    continue;
                }
                else if (ch1 != 13)
                    printf("*");
                else if (ch1 == 13)
                    break;
            }
            tradesmanst[j].passsb[i] = '\0';

            printf("\n\n\n\n\n\t\t\tEnter your password again: ");
            for (i = 0; i < 50; i++) {
                ch1 = _getch();
                tradesmanst[j].passasb[i] = ch1;
                if (ch1 == 8 && i >= 1) {
                    printf("\b \b");
                    i -= 2;
                    continue;
                }
                else if (ch1 != 13)
                    printf("*");
                else if (ch1 == 13)
                    break;
            }
            tradesmanst[j].passasb[i] = '\0';
            system("cls");
            if (strcmpi(tradesmanst[j].passsb, tradesmanst[j].passasb) == 0) {
                tradesman = fopen("tradesman.txt", "w");
                fwrite(&num_tradesman, sizeof(int), 1, user);
                for (i = 0; i < num_tradesman; i++) {
                    fwrite(&tradesmanst[i], sizeof(struct tradesman), 1, user);
                }
                fclose(tradesman);
                system("cls");
                safhe1();
            }
            else {
                printf("\n\n\n\t\t\tPassword and repeat password are not the same");
                printf("\n\n\n\n\n\n\t\t\t1_ Home");
                printf("\n\n\n\t\t\t2_ Exit");
                printf("\n\n\n\n\t\t\tEnter your choice : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
                if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
            }
            break;
        }
        else {
            printf("\n\n\n\n\t\t\tNot corrected ,Enter 0 to get back to menu : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "0") == 0) safhe1();
        }
    }
}

void menum(void) {
    printf("\n**************************** MANAGEMENT MENU ***********************************");
    printf("\n\t\t\t1_ Home");
    printf("\n\n\t\t\t2_ Exit");
    printf("\n\n\t\t\t3_ Edit profile");
    printf("\n\n\t\t\t4_ Enter the hospital");
    printf("\n\n\t\t\t5_ See patient");
    printf("\n\n\t\t\t6_ Enter improved people");
    printf("\n\n\t\t\t7_ View all people");
    printf("\n\n\t\t\t8_ View the deads list");
    printf("\n\n\t\t\t9_ View registered jobs");
    printf("\n\n\t\t\t10_View registered hospitals");
    printf("\n\n\t\t\tEnter your choice : ");

    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Home") == 0 || strcmpi(str, "1") == 0) safhe1();
    if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    if (strcmpi(str, "Edit profile") == 0 || str[0] == '3') edit_pro_modir();
    if (strcmpi(str, "Enter the hospital") == 0 || str[0] == '4') Enter_the_hospital();
    if (strcmpi(str, "See patient") == 0 || str[0] == '5') See_patient();
    if (strcmpi(str, "Enter improved people") == 0 || str[0] == '6') Enter_improved_people();
    if (strcmpi(str, "View all people") == 0 || str[0] == '7') View_all_people();
    if (strcmpi(str, "View the deads list") == 0 || str[0] == '8') View_the_deads_list();
    if (strcmpi(str, "View registered jobs") == 0 || str[0] == '9') View_registered_jobs();
    if (strcmpi(str, "View registered hospitals") == 0 || strcmpi(str, "10") == 0) View_registered_hospitals();
}

void edit_pro_modir(void) {
    printf("\n******************************* EDIT PROFIE ***********************************");
    printf("\n\n\t\t\tWhich one do yo want to change?");
    printf("\n\n\n\t\t\t1_ First name");
    printf("\n\n\n\t\t\t2_ Last name");
    printf("\n\n\n\t\t\t3_ User name");
    printf("\n\n\n\t\t\t4_ Email");
    printf("\n\n\n\t\t\t5_ Password");
    printf("\n\n\n\t\t\t6_ None , back to menu");
    printf("\n\n\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "first name") == 0 || str[0] == '1') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your first name : ");
        fgets(managmentst.fnamem, 50, stdin);
        while (managmentst.fnamem[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your first name again : ");
            fgets(managmentst.fnamem, 50, stdin);
        }
        managmentst.fnamem[strlen(managmentst.fnamem) - 1] = '\0';
        system("cls");
        edit_pro_modir();
    }
    else if (strcmpi(str, "last name") == 0 || str[0] == '2') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your last name : ");
        fgets(managmentst.lnamem, 50, stdin);
        while (managmentst.lnamem[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your last name again : ");
            fgets(managmentst.lnamem, 50, stdin);
        }
        managmentst.lnamem[strlen(managmentst.lnamem) - 1] = '\0';
        system("cls");
        edit_pro_modir();
    }
    else if (strcmpi(str, "user name") == 0 || str[0] == '3') {
        char username[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your user name : ");
        fgets(username, 50, stdin);
        while (username[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your user name again : ");
            fgets(username, 50, stdin);
        }
        username[strlen(username) - 1] = '\0';

        for (j = 0; j < num_user; j++) {
            if (strcmp(username, userst[j].unameu) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_modir();
            }
        }
        for (j = 0; j < num_tradesman; j++) {
            if (strcmp(username, tradesmanst[j].unamesb) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_modir();
            }
        }
        strcpy(managmentst.unamem, username);
        system("cls");
        edit_pro_modir();
    }
    /*else if (strcmpi(str, "national code") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your national code : ");
        fgets(managmentst.ncodem, 50, stdin);
        while (managmentst.ncodem[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your national code again : ");
            fgets(managmentst.ncodem, 50, stdin);
        }
        managmentst.ncodem[strlen(managmentst.ncodem) - 1] = '\0';
        system("cls");
        edit_pro_modir();
    }*/
    else if (strcmpi(str, "email") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your email : ");
        fgets(managmentst.ncodem, 50, stdin);
        while (managmentst.ncodem[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your email again : ");
            fgets(managmentst.ncodem, 50, stdin);
        }
        managmentst.ncodem[strlen(managmentst.ncodem) - 1] = '\0';
        system("cls");
        edit_pro_modir();
    }
    else if (strcmpi(str, "password") == 0 || str[0] == '5') {
        char password[50];
        char passworda[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\t\t\tChange your password : ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            password[i] = ch1;
            if (password[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        password[i] = '\0';

        printf("\n\n\n\n\n\t\t\tEnter password again: ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            passworda[i] = ch1;
            if (passworda[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your repeat password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        passworda[i] = '\0';
        system("cls");
        if (strcmp(password, passworda) != 0) {
            printf("\n\n\n\t\tPassword and repeat password are not the same");
            printf("\n\n\n\n\n\n\t\t\t1_ Edit profile");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') edit_pro_modir();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
        strcpy(managmentst.passm, password);
        strcpy(managmentst.passam, passworda);
        system("cls");
        edit_pro_modir();
    }
    else if (strcmpi(str, "None , back to menu") == 0 || str[0] == '6') {
        managment = fopen("managment.txt", "w");
        fwrite(&managmentst, sizeof(struct managment), 1, managment);
        fclose(managment);
        system("cls");
        menum();
    }
}

void Enter_the_hospital(void) {
    printf("\n*************************** ENTER THE HOSPITAL *********************************");
    printf("\n\n\n\t\t\tEnter a new hospital");
    printf("\n\n\n\t\t\tWhere is area of the hospital : ");
    fgets(hospitalst[num_hospital].name_area, 50, stdin);
    hospitalst[num_hospital].name_area[strlen(hospitalst[num_hospital].name_area) - 1] = '\0';

    printf("\n\n\n\t\t\tWhat is the hospitals name : ");
    fgets(hospitalst[num_hospital].name_hospital, 50, stdin);
    hospitalst[num_hospital].name_hospital[strlen(hospitalst[num_hospital].name_hospital) - 1] = '\0';

    num_hospital++;

    hospital = fopen("hospital.txt", "w");
    fwrite(&num_hospital, sizeof(int), 1, hospital);
    for (i = 0; i < num_hospital; i++) {
        fwrite(&hospitalst[i], sizeof(struct hospital), 1, hospital);
    }
    fclose(hospital);
    system("cls");
    menum();
}

void See_patient(void) {
    printf("\n******************************* See_patient ************************************");
    for (i = 0; i < num_user; i++) {
        if (userst[i].max_vsalamati == 4 && userst[i].haiat == true) {
            printf("\n\n\t\t\t%d_ %s %s  %s  ", i + 1, userst[i].fnameu, userst[i].lnameu, userst[i].ncodeu);
            tm = *localtime(&(userst[i].sabt_max_vsalamati));
            printf("%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
        }
    }
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menum();
}

void Enter_improved_people(void) {
    printf("\n************************** ENTER IMPROVED PEOPLE *******************************");
    char national_code[50];
    printf("\n\n\n\n\n\t\t\tWho is dead or healed : ");
    fgets(national_code, 50, stdin);
    national_code[strlen(national_code) - 1] = '\0';

    for (x = 0; x < num_user; x++) {
        if (strcmpi(userst[x].ncodeu, national_code) == 0) break;
    }
    if (x == num_user) {
        printf("\n\n\n\t\t\tNot founded!!!!");
        printf("\n\t\t\tEnter 0 to back menu : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        if (strcmpi(str, "0") == 0) menum();
    }
    if (userst[x].haiat == false) {
        printf("\n\n\n\t\t\tHe/She is dead :(");
        printf("\n\t\t\tEnter 0 to back menu : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        if (strcmpi(str, "0") == 0) menum();
    }
    if (userst[x].max_vsalamati == 4) {
        printf("\n\n\n\n\t\t\t1_ He/She is dead");
        printf("\n\n\n\n\t\t\t2_ He/She is improved");
        printf("\n\n\t\t\tEnter your choice : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';

        if (strcmpi(str, "He/She is dead") == 0 || str[0] == '1') {
            userst[x].haiat = false;
        }
        if (strcmpi(str, "He/She is improved") == 0 || str[0] == '2') {
            userst[x].max_vsalamati = 2;
            userst[x].sabt_max_vsalamati = time(NULL);
        }
    }
    else {
        printf("\n\n\n\n\t\t\tEror, He/she doesnt have corona virus!!!");
    }
    printf("\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);

    user = fopen("user.txt", "w");
    fwrite(&num_user, sizeof(int), 1, user);
    for (i = 0; i < num_user; i++) {
        fwrite(&userst[i], sizeof(struct user), 1, user);
    }
    fclose(user);

    system("cls");
    if (str[0] == '0') menum();
}

void View_all_people(void) {
    printf("\n**************************** VIEW ALL PEOPLE ***********************************");
    printf("\n\n");
    for (j = 0; j < num_user; j++) {
        if (userst[j].haiat == false) continue;
        printf("\n\n\t\t\t%d_ %s %s  %s  code %d", j + 1, userst[j].fnameu, userst[j].lnameu, userst[j].ncodeu, userst[j].max_vsalamati);
    }
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menum();
}

void View_the_deads_list(void) {
    printf("\n************************** VIEW THE DEADS LIST *********************************");
    int p = 1;
    printf("\n\n\n\n");
    for (j = 0; j < num_user; j++) {
        if (userst[j].haiat == false) {
            printf("\n\n\t\t\t%d_ %s %s  %s", p, userst[j].fnameu, userst[j].lnameu, userst[j].ncodeu);
            p++;
        }
    }
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menum();
}

void View_registered_jobs(void) {
    printf("\n************************** VIEW REGISTERED JOBS ********************************");
    printf("\n\n");
    for (j = 0; j < num_tradesman; j++) {
        printf("\n\n\t\t\t%d_ %s  %s  ", j + 1, tradesmanst[j].nshopsb, tradesmanst[j].ncodesb);
        if (tradesmanst[j].vaziat == true) printf("red condition");
        else printf("white condition");
    }
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menum();
}

void View_registered_hospitals(void) {
    printf("\n*********************** VIEW REGISTERED HOSPITALS ******************************");
    printf("\n\n\n\n");
    for (j = 0; j < num_hospital; j++) {
        printf("\n\n\t\t\t%d_ %s   %s", j + 1, hospitalst[j].name_area, hospitalst[j].name_hospital);
    }
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menum();
}

void menuu(void) {
    now = time(NULL);
    for (j = 0; j < num_user; j++) {
        second = difftime(now, userst[j].sabt_max_vsalamati);
        if (second >= 604800 && userst[j].max_vsalamati == 3) {
            userst[j].sabt_max_vsalamati += 604800;
            userst[j].max_vsalamati--;
        }
        second = difftime(now, userst[j].sabt_max_vsalamati);
        if (second >= 604800 && userst[j].max_vsalamati == 2) {
            userst[j].sabt_max_vsalamati += 604800;
            userst[j].max_vsalamati--;
        }
    }
    now = time(NULL);
    for (j = 0; j < num_tradesman; j++) {
        second = difftime(now, tradesmanst[j].zaman_vaziat);
        if (second >= 1209600) {
            tradesmanst[j].vaziat = false;
        }
    }
    printf("****************************** USERNAME MENU ***********************************");
    printf("\n\t\t\t1 : Home");
    printf("\n\n\t\t\t2 : Exit");
    printf("\n\n\t\t\t3 : Editing profile");
    printf("\n\n\t\t\t4 : Health situation record");
    printf("\n\n\t\t\t5 : View health entry history");
    printf("\n\n\t\t\t6 : Record meeting with other people");
    printf("\n\n\t\t\t7 : View meeting history");
    printf("\n\n\t\t\t8 : Add places has gone");
    printf("\n\n\t\t\t9 : View the history of places that have gone");
    printf("\n\n\t\t\t10: View corona statistics");
    printf("\n\n\t\t\t11: View nearby hospitals and treatment centers");

    printf("\n\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Home") == 0 || strcmpi(str, "1") == 0) safhe1();
    if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    if (strcmpi(str, "Editing profile") == 0 || str[0] == '3') edit_pro_user();
    if (strcmpi(str, "Health situation record") == 0 || str[0] == '4') Health_situation_record();
    if (strcmpi(str, "View health entry history") == 0 || str[0] == '5') View_health_entry_history();
    if (strcmpi(str, "Record meeting with other people") == 0 || str[0] == '6') record_meeting_with_other_people();
    if (strcmpi(str, "View meeting history") == 0 || str[0] == '7') View_meeting_history();
    if (strcmpi(str, "Add places has gone") == 0 || str[0] == '8') Add_places_has_gone();
    if (strcmpi(str, "view the history of places that have gone") == 0 || str[0] == '9') view_the_history_of_places_that_have_gone();
    if (strcmpi(str, "View corona statistics") == 0 || strcmpi(str, "10") == 0) View_corona_statistics();
    if (strcmpi(str, "View nearby hospitals and treatment centers") == 0 || strcmpi(str, "11") == 0) View_nearby_hospitalsand_treatment_centers();

}

void edit_pro_user(void) {
    printf("******************************* EDIT PROFIE ***********************************");
    printf("\n\n\t\t\t1_ First name");
    printf("\n\n\t\t\t2_ Last name");
    printf("\n\n\t\t\t3_ User name");
    printf("\n\n\t\t\t4_ Email");
    printf("\n\n\t\t\t5_ Password");
    printf("\n\n\t\t\t6_ Blood type");
    printf("\n\n\t\t\t7_ Age");
    printf("\n\n\t\t\t8_ Height");
    printf("\n\n\t\t\t9_ Weight");
    printf("\n\n\t\t\t10_None , back to menu");

    printf("\n\n\t\t\tWhich one do yo want to change : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "first name") == 0 || strcmpi(str, "1") == 0) {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your first name : ");
        fgets(userst[x].fnameu, 50, stdin);
        while (userst[x].fnameu[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your first name again : ");
            fgets(userst[x].fnameu, 50, stdin);
        }
        userst[x].fnameu[strlen(userst[x].fnameu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "last name") == 0 || str[0] == '2') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your last name : ");
        fgets(userst[x].lnameu, 50, stdin);
        while (userst[x].lnameu[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your last name again : ");
            fgets(userst[x].lnameu, 50, stdin);
        }
        userst[x].lnameu[strlen(userst[x].lnameu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "user name") == 0 || str[0] == '3') {
        char username[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your user name : ");
        fgets(username, 50, stdin);
        while (username[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your user name again : ");
            fgets(username, 50, stdin);
        }
        username[strlen(username) - 1] = '\0';
        if (strcmp(username, managmentst.unamem) == 0) {
            printf("\n\n\n\t\t\tThis username already exists");
            printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "0") == 0) edit_pro_user();
        }
        for (j = 0; j < num_user; j++) {
            if (strcmp(username, userst[j].unameu) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_user();
            }
        }
        for (j = 0; j < num_tradesman; j++) {
            if (strcmp(username, tradesmanst[j].unamesb) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_user();
            }
        }
        strcpy(userst[x].unameu, username);
        system("cls");
        edit_pro_user();
    }
    /*else if (strcmpi(str, "national code") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your national code : ");
        fgets(userst[x].ncodeu, 50, stdin);
        while (userst[x].ncodeu[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your national code again : ");
            fgets(userst[x].ncodeu, 50, stdin);
        }
        userst[x].ncodeu[strlen(userst[x].ncodeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }*/
    else if (strcmpi(str, "email") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your email : ");
        fgets(userst[x].ncodeu, 50, stdin);
        while (userst[x].ncodeu[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your email again : ");
            fgets(userst[x].ncodeu, 50, stdin);
        }
        userst[x].ncodeu[strlen(userst[x].ncodeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "password") == 0 || str[0] == '5') {
        char password[50];
        char passworda[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\n\t\t\tChange your password : ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            password[i] = ch1;
            if (password[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        password[i] = '\0';

        printf("\n\n\n\n\n\t\t\tEnter password again: ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            passworda[i] = ch1;
            if (passworda[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your repeat password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        passworda[i] = '\0';
        system("cls");
        if (strcmp(password, passworda) != 0) {
            printf("\n\n\n\t\t\tPassword and repeat password are not the same");
            printf("\n\n\n\n\n\n\t\t\t1_ Edit profile");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') edit_pro_user();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
        strcpy(userst[x].passu, password);
        strcpy(userst[x].passau, passworda);

        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "blood type") == 0 || str[0] == '6') {
        printf("\n\t\t\tChange your blood type : ");
        fgets(userst[x].btypeu, 50, stdin);
        userst[x].btypeu[strlen(userst[x].btypeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "age") == 0 || str[0] == '7') {
        printf("\n\t\t\tChange your age : ");
        fgets(userst[x].btypeu, 50, stdin);
        userst[x].btypeu[strlen(userst[x].btypeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "height") == 0 || str[0] == '8') {
        printf("\n\t\t\tChange your height : ");
        fgets(userst[x].btypeu, 50, stdin);
        userst[x].btypeu[strlen(userst[x].btypeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "weight") == 0 || strcmpi(str, "9") == 0) {
        printf("\n\t\t\tChange your weight : ");
        fgets(userst[x].btypeu, 50, stdin);
        userst[x].btypeu[strlen(userst[x].btypeu) - 1] = '\0';
        system("cls");
        edit_pro_user();
    }
    else if (strcmpi(str, "None , back to menu") == 0 || strcmpi(str, "10") == 0) {
        user = fopen("user.txt", "w");
        fwrite(&num_user, sizeof(int), 1, user);
        for (i = 0; i < num_user; i++) {
            fwrite(&userst[i], sizeof(struct user), 1, user);
        }
        fclose(user);
        system("cls");
        menuu();
    }
}

void Health_situation_record(void) {
    int sum = 0;
    printf("\n************************* HEALTH SITUATION RECORD ******************************");
    printf("\n\n\n\n\t\tAya shoma ... darid?(Enter bale or na)");
    printf("\n\n\n\t\tSorfe haye khoshk ba tedad ziyad : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmpi(str, "bale") == 0) sum += 30;

    printf("\n\n\t\tTab balaye 37 daraje : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmpi(str, "bale") == 0) sum += 20;

    printf("\n\n\t\tTangi nafas : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmpi(str, "bale") == 0) sum += 20;

    printf("\n\n\t\tDard va kooftegi : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmpi(str, "bale") == 0) sum += 15;

    printf("\n\n\t\tGeloo dard : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    if (strcmpi(str, "bale") == 0) sum += 15;

    system("cls");
    if (userst[x].tvsalamati == 10) {
        for (j = 8; j >= 0; j--) {
            userst[x].vsalamati[j] = userst[x].vsalamati[j + 1];
            userst[x].sabt_vsalamati[j] = userst[x].sabt_vsalamati[j + 1];
        }
        userst[x].tvsalamati--;
    }

    if (sum >= 75) userst[x].vsalamati[userst[x].tvsalamati] = 4;
    else if (sum >= 50) userst[x].vsalamati[userst[x].tvsalamati] = 3;
    else if (sum >= 25) userst[x].vsalamati[userst[x].tvsalamati] = 2;
    else if (sum >= 0) userst[x].vsalamati[userst[x].tvsalamati] = 1;

    userst[x].sabt_vsalamati[userst[x].tvsalamati] = time(NULL);
    printf("\n\n\n\n\n\n\n\n\t\t\tCode %d", userst[x].vsalamati[userst[x].tvsalamati]);
    if (userst[x].vsalamati[userst[x].tvsalamati] > userst[x].max_vsalamati) {
        userst[x].max_vsalamati = userst[x].vsalamati[userst[x].tvsalamati];
        userst[x].sabt_max_vsalamati = time(NULL);
        if (userst[x].max_vsalamati == 3) {
            for (j = 0; j < userst[x].tmolaghat; j++) {
                for (i = 0; i < num_user; i++) {
                    now = time(NULL);
                    if (strcmp(userst[x].molaghat_codemeli[j], userst[i].ncodeu) == 0) {
                        if (userst[i].max_vsalamati == 1 && difftime(now, userst[x].sabt_molaghat[j]) < 604800) {
                            userst[i].max_vsalamati = 2;
                            userst[i].sabt_max_vsalamati = time(NULL);
                        }
                        break;
                    }
                }
            }
        }
        if (userst[x].max_vsalamati == 4) {
            for (j = 0; j < userst[x].tmolaghat; j++) {
                for (i = 0; i < num_user; i++) {
                    if (strcmp(userst[x].molaghat_codemeli[j], userst[i].ncodeu) == 0) {
                        if (userst[i].max_vsalamati < 3 && difftime(now, userst[x].sabt_molaghat[j]) < 604800) {
                            userst[i].max_vsalamati = 3;
                            userst[i].sabt_max_vsalamati = time(NULL);

                            if (userst[i].max_vsalamati == 3) {
                                for (int p = 0; p < userst[i].tmolaghat; p++) {
                                    for (int q = 0; q < num_user; q++) {
                                        if (strcmp(userst[i].molaghat_codemeli[p], userst[q].ncodeu) == 0) {
                                            if (userst[q].max_vsalamati == 1 && difftime(now, userst[i].sabt_molaghat[p]) < 604800) {
                                                userst[q].max_vsalamati = 2;
                                                userst[q].sabt_max_vsalamati = time(NULL);
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
            for (j = 0; j < userst[x].tmolaghat_makan; j++) {
                for (i = 0; i < num_tradesman; i++) {
                    if (strcmp(userst[x].molaghat_makan[j], tradesmanst[i].nshopsb) == 0) {
                        now = time(NULL);
                        if (difftime(now, userst[x].sabt_molaghat_makan[j]) < 604800) {
                            tradesmanst[i].vaziat = true;
                            tradesmanst[i].zaman_vaziat = time(NULL);
                            tradesmanst[i].code4++;
                        }
                        break;
                    }
                }
            }
        }
    }
    userst[x].tvsalamati++;

    user = fopen("user.txt", "w");
    fwrite(&num_user, sizeof(int), 1, user);
    for (j = 0; j < num_user; j++) {
        fwrite(&userst[j], sizeof(struct user), 1, user);
    }
    fclose(user);

    tradesman = fopen("tradesman.txt", "w");
    fwrite(&num_tradesman, sizeof(int), 1, tradesman);
    for (j = 0; j < num_user; j++) {
        fwrite(&tradesmanst[j], sizeof(struct tradesman), 1, tradesman);
    }
    fclose(tradesman);

    printf("\n\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();

}

void View_health_entry_history(void) {
    printf("\n*********************** VIEW HEALTH ENTRY HISTORY ******************************");
    printf("\n\n\t\t\tHealthy code : %d", userst[x].max_vsalamati);
    for (j = 0; j < userst[x].tvsalamati; j++) {
        printf("\n\n\t\t\t%d_ Code %d  ", j + 1, userst[x].vsalamati[j]);
        tm = *localtime(&(userst[x].sabt_vsalamati[j]));
        printf("%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }

    printf("\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();
}

void record_meeting_with_other_people() {
    char national_code[50];
    printf("\n********************* RECORD MEETING WITH OTHER PEOPLE *************************");
    printf("\n\n\n\n\n\n\tIf you had meet someone in last week enter his national code.\n\n\t\t\t\t");
    fgets(national_code, 50, stdin);
    national_code[strlen(national_code) - 1] = '\0';

    for (i = 0; i < num_user; i++) {
        if (strcmpi(userst[i].ncodeu, national_code) == 0) break;
    }
    if (i == num_user) {
        printf("\n\n\n\t\t\tNot founded!!!!");
        printf("\n\t\t\tEnter 0 to back menu : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        if (strcmpi(str, "0") == 0) menuu();
    }

    if (userst[x].tmolaghat == 10) {
        for (j = 8; j >= 0; j--) {
            strcpy(userst[x].molaghat[j], userst[x].molaghat[j + 1]);
            userst[x].sabt_molaghat[j] = userst[x].sabt_molaghat[j + 1];
            userst[x].molaghat_code[j] = userst[x].molaghat_code[j + 1];
        }
        userst[x].tmolaghat--;
    }

    if (userst[i].tmolaghat == 10) {
        for (j = 8; j >= 0; j--) {
            strcpy(userst[i].molaghat[j], userst[i].molaghat[j + 1]);
            userst[i].sabt_molaghat[j] = userst[i].sabt_molaghat[j + 1];
            userst[i].molaghat_code[j] = userst[i].molaghat_code[j + 1];
        }
        userst[i].tmolaghat--;
    }

    strcpy(userst[x].molaghat[userst[x].tmolaghat], userst[i].fnameu);
    strcpy(userst[i].molaghat[userst[i].tmolaghat], userst[x].fnameu);
    strcpy(userst[x].molaghat_codemeli[userst[x].tmolaghat], userst[i].ncodeu);
    strcpy(userst[i].molaghat_codemeli[userst[i].tmolaghat], userst[x].ncodeu);
    userst[x].molaghat_code[userst[x].tmolaghat] = userst[i].max_vsalamati;
    userst[i].molaghat_code[userst[i].tmolaghat] = userst[x].max_vsalamati;
    userst[x].sabt_molaghat[userst[x].tmolaghat] = time(NULL);
    userst[i].sabt_molaghat[userst[i].tmolaghat] = time(NULL);

    if (userst[x].max_vsalamati > userst[i].max_vsalamati) {
        userst[i].max_vsalamati = userst[x].max_vsalamati - 1;
        userst[i].sabt_max_vsalamati = time(NULL);
    }
    else if (userst[i].max_vsalamati > userst[x].max_vsalamati) {
        userst[x].max_vsalamati = userst[i].max_vsalamati - 1;
        userst[x].sabt_max_vsalamati = time(NULL);
    }
    userst[x].tmolaghat++;
    userst[i].tmolaghat++;

    user = fopen("user.txt", "w");
    fwrite(&num_user, sizeof(int), 1, user);
    for (j = 0; j < num_user; j++) {
        fwrite(&userst[j], sizeof(struct user), 1, user);
    }
    fclose(user);
    system("cls");
    menuu();
}

void View_meeting_history(void) {
    printf("\n************************* VIEW MEETING HISTORY *********************************");
    for (j = 0; j < userst[x].tmolaghat; j++) {
        printf("\n\n\t\t\t%d_ %s  code %d  ", j + 1, userst[x].molaghat[j], userst[x].molaghat_code[j]);
        tm = *localtime(&(userst[x].sabt_molaghat[j]));
        printf("%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
    printf("\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();
}

void Add_places_has_gone(void) {
    char name[50];
    printf("\n*********************** ADD PLACES DO YOU WANT TO GO ***************************");
    printf("\n\n\n\n\n\n\n\n\t\t\tWhere do you want to go :");
    fgets(name, 50, stdin);
    name[strlen(name) - 1] = '\0';

    for (i = 0; i < num_tradesman; i++) {
        if (strcmpi(tradesmanst[i].nshopsb, name) == 0) break;
    }
    if (i == num_tradesman) {
        printf("\n\n\n\t\t\tNot founded!!!!");
        printf("\n\t\t\tEnter 0 to back menu : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        if (strcmpi(str, "0") == 0) menuu();
    }

    if (tradesmanst[i].vaziat == true) {
        printf("\n\n\t\tThis place is red. Do you still want to go there?");
        printf("\n\n\t\t1_ Yes");
        printf("\n\n\t\t2_ No, back to menu");
        printf("\n\n\t\tWhich one do yo want to change : ");
        fgets(str, 50, stdin);
        str[strlen(str) - 1] = '\0';
        system("cls");
        if (strcmpi(str, "yes") == 0 || str[0] == '1');
        if (strcmpi(str, "No, back to menu") == 0 || str[0] == '2') menuu();
    }

    if (userst[x].tmolaghat_makan == 10) {
        for (j = 8; j >= 0; j--) {
            strcpy(userst[x].molaghat_makan[j], userst[x].molaghat_makan[j + 1]);
            userst[x].sabt_molaghat_makan[j] = userst[x].sabt_molaghat_makan[j + 1];
            strcpy(userst[x].molaghat_makan_vaziat[j], userst[x].molaghat_makan_vaziat[j + 1]);
        }
        userst[x].tmolaghat_makan--;
    }
    strcpy(userst[x].molaghat_makan[userst[x].tmolaghat_makan], tradesmanst[i].nshopsb);
    userst[x].sabt_molaghat_makan[userst[x].tmolaghat_makan] = time(NULL);
    if (tradesmanst[i].vaziat == true)
        strcpy(userst[x].molaghat_makan_vaziat[userst[x].tmolaghat_makan], "red");
    else strcpy(userst[x].molaghat_makan_vaziat[userst[x].tmolaghat_makan], "white");

    if (userst[x].max_vsalamati == 4) {
        tradesmanst[i].vaziat = true;
        tradesmanst[i].code4++;
    }
    if (userst[x].max_vsalamati == 3) {
        tradesmanst[i].code3++;
    }
    if (userst[x].max_vsalamati == 2) {
        tradesmanst[i].code2++;
    }

    if (userst[x].max_vsalamati == 1 && tradesmanst[i].vaziat == true) {
        userst[x].max_vsalamati = 2;
        userst[x].sabt_max_vsalamati = time(NULL);
    }

    userst[x].tmolaghat_makan++;

    user = fopen("user.txt", "w");
    fwrite(&num_user, sizeof(int), 1, user);
    for (j = 0; j < num_user; j++) {
        fwrite(&userst[j], sizeof(struct user), 1, user);
    }
    fclose(user);

    tradesman = fopen("tradesman.txt", "w");
    fwrite(&num_tradesman, sizeof(int), 1, tradesman);
    for (j = 0; j < num_user; j++) {
        fwrite(&tradesmanst[j], sizeof(struct tradesman), 1, tradesman);
    }
    fclose(tradesman);

    system("cls");
    menuu();
}

void view_the_history_of_places_that_have_gone(void) {
    printf("\n**************** VIEW THE HISTORY OF PLACES THAT HAVE GONE *********************");
    for (j = 0; j < userst[x].tmolaghat_makan; j++) {
        printf("\n\n\t\t\t%d_ %s  %s  ", j + 1, userst[x].molaghat_makan[j], userst[x].molaghat_makan_vaziat[j]);
        tm = *localtime(&(userst[x].sabt_molaghat_makan[j]));
        printf("%d-%02d-%02d %02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
    }
    printf("\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();
}

void View_corona_statistics(void) {
    printf("\n************************* VIEW CORONA STATISTICS *******************************");
    int rooz = 0;
    int hafte = 0;
    now = time(NULL);
    for (j = 0; j < num_user; j++) {
        if (userst[j].max_vsalamati == 4) {
            second = difftime(now, userst[j].sabt_max_vsalamati);
            if (second < 86400) {
                rooz++;
                hafte++;
                continue;
            }
            if (second < 604800) hafte++;
        }
    }
    printf("\n\n\n\n\n\t\t\tNumber of patients daily : %d", rooz);
    printf("\n\n\n\t\t\tNumber of patients per week : %d", hafte);
    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();
}

void View_nearby_hospitalsand_treatment_centers(void) {
    int p = 1;
    bool find = false;
    printf("\n********************** VIEW NEARBY TREATMENT CENTER ****************************");
    printf("\n\n\t\tWhich city medical centers do you want to see : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';
    for (j = 0; j < num_hospital; j++) {
        if (strcmpi(hospitalst[j].name_area, str) == 0) {
            printf("\n\n\n\t\t\t%d_ %s", p, hospitalst[j].name_hospital);
            p++;
            find = true;
        }
    }
    if (find == false) printf("\n\n\n\n\n\t\t\tNot founded!!!");
    printf("\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menuu();

}

void menusb(void) {
    now = time(NULL);
    for (j = 0; j < num_tradesman; j++) {
        second = difftime(now, tradesmanst[j].zaman_vaziat);
        if (second >= 1209600) {
            tradesmanst[j].vaziat = false;
        }
    }
    printf("\n***************************** TRADESMAN MENU ***********************************");
    printf("\n\n\t\t\t1_ Home");
    printf("\n\n\n\t\t\t2_ Exit");
    printf("\n\n\n\t\t\t3_ Edit profile");
    printf("\n\n\n\t\t\t4_ Moshahede vaziat makan");
    printf("\n\n\n\t\t\t5_ Zede ofooni kardan maghaze");
    printf("\n\n\n\t\t\t6_ View the number of infected people");
    printf("\n\n\n\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Home") == 0 || str[0] == '1') safhe1();
    if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
    if (strcmpi(str, "Edit profile") == 0 || str[0] == '3') edit_pro_sahebin();
    if (strcmpi(str, "Moshahede vaziat makan") == 0 || str[0] == '4') Moshahede_vaziat_makan();
    if (strcmpi(str, "Zede ofooni kardan maghaze") == 0 || str[0] == '5') Zede_ofooni_kardan_maghaze();
    if (strcmpi(str, "View the number of infected people") == 0 || str[0] == '6') View_the_number_of_infected_people();
}

void edit_pro_sahebin(void) {
    printf("\n******************************* EDIT PROFIE ***********************************");
    printf("\n\n\t\t\tWhich one do yo want to change?");
    printf("\n\n\t\t\t1_ First name");
    printf("\n\n\t\t\t2_ Last name");
    printf("\n\n\t\t\t3_ User name");
    printf("\n\n\t\t\t4_ Email");
    printf("\n\n\t\t\t5_ Password");
    printf("\n\n\t\t\t6_ Shop name");
    printf("\n\n\t\t\t7_ Shop city");
    printf("\n\n\t\t\t8_ Shop area");
    printf("\n\n\t\t\t9_ None , back to menu");

    printf("\n\n\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "first name") == 0 || strcmpi(str, "1") == 0) {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your first name : ");
        fgets(tradesmanst[x].fnamesb, 50, stdin);
        while (tradesmanst[x].fnamesb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your first name again : ");
            fgets(tradesmanst[x].fnamesb, 50, stdin);
        }
        tradesmanst[x].fnamesb[strlen(tradesmanst[x].fnamesb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "last name") == 0 || str[0] == '2') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your last name : ");
        fgets(tradesmanst[x].lnamesb, 50, stdin);
        while (tradesmanst[x].lnamesb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your last name again : ");
            fgets(tradesmanst[x].lnamesb, 50, stdin);
        }
        tradesmanst[x].lnamesb[strlen(tradesmanst[x].lnamesb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "user name") == 0 || str[0] == '3') {
        char username[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your user name : ");
        fgets(username, 50, stdin);
        while (username[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your user name again : ");
            fgets(username, 50, stdin);
        }
        username[strlen(username) - 1] = '\0';
        if (strcmp(username, managmentst.unamem) == 0) {
            printf("\n\n\n\t\t\tThis username already exists");
            printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "0") == 0) edit_pro_sahebin();
        }
        for (j = 0; j < num_user; j++) {
            if (strcmp(username, userst[j].unameu) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_sahebin();
            }
        }
        for (j = 0; j < num_tradesman; j++) {
            if (strcmp(username, tradesmanst[j].unamesb) == 0) {
                printf("\n\n\n\t\t\tThis username already exists");
                printf("\n\n\t\t\tEnter 0 to get back to edit profile : ");
                fgets(str, 50, stdin);
                str[strlen(str) - 1] = '\0';

                system("cls");

                if (strcmpi(str, "0") == 0) edit_pro_sahebin();
            }
        }
        strcpy(tradesmanst[x].unamesb, username);
        system("cls");
        edit_pro_sahebin();
    }
    /*else if (strcmpi(str, "national code") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your national code : ");
        fgets(tradesmanst[x].ncodesb, 50, stdin);
        while (tradesmanst[x].ncodesb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your national code again : ");
            fgets(tradesmanst[x].ncodesb, 50, stdin);
        }
        tradesmanst[x].ncodesb[strlen(tradesmanst[x].ncodesb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }*/
    else if (strcmpi(str, "email") == 0 || str[0] == '4') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your email : ");
        fgets(tradesmanst[x].ncodesb, 50, stdin);
        while (tradesmanst[x].ncodesb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your email again : ");
            fgets(tradesmanst[x].ncodesb, 50, stdin);
        }
        tradesmanst[x].ncodesb[strlen(tradesmanst[x].ncodesb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "password") == 0 || str[0] == '5') {
        char password[50];
        char passworda[50];
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\n\t\t\tChange your password : ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            password[i] = ch1;
            if (password[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        password[i] = '\0';

        printf("\n\n\n\n\n\n\t\t\tEnter again : ");
        for (i = 0; i < 50; i++) {
            ch1 = _getch();
            passworda[i] = ch1;
            if (passworda[0] == 13) {
                printf("\n\t\t\tNot corrected , Enter your repeat password again : ");
                i--;
                continue;
            }
            if (ch1 == 8 && i >= 1) {
                printf("\b \b");
                i -= 2;
                continue;
            }
            else if (ch1 != 13)
                printf("*");
            else if (ch1 == 13)
                break;
        }
        passworda[i] = '\0';
        if (strcmp(password, passworda) != 0) {
            printf("\n\n\n\t\t\tPassword and repeat password are not the same");
            printf("\n\n\n\n\n\n\t\t\t1_ Edit profile");
            printf("\n\n\n\t\t\t2_ Exit");
            printf("\n\n\n\n\t\t\tEnter your choice : ");
            fgets(str, 50, stdin);
            str[strlen(str) - 1] = '\0';

            system("cls");

            if (strcmpi(str, "Home") == 0 || str[0] == '1') edit_pro_sahebin();
            if (strcmpi(str, "Exit") == 0 || str[0] == '2') exit(0);
        }
        strcpy(tradesmanst[x].passsb, password);
        strcpy(tradesmanst[x].passasb, passworda);

        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "shop name") == 0 || str[0] == '6') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your shop name : ");
        fgets(tradesmanst[x].nshopsb, 50, stdin);
        while (tradesmanst[x].nshopsb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your shop name again : ");
            fgets(tradesmanst[x].nshopsb, 50, stdin);
        }
        tradesmanst[x].nshopsb[strlen(tradesmanst[x].nshopsb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "shop city") == 0 || str[0] == '7') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your shop city : ");
        fgets(tradesmanst[x].cshopsb, 50, stdin);
        while (tradesmanst[x].cshopsb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your shop city again : ");
            fgets(tradesmanst[x].cshopsb, 50, stdin);
        }
        tradesmanst[x].cshopsb[strlen(tradesmanst[x].cshopsb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "shop area") == 0 || str[0] == '8') {
        printf("\n******************************* EDIT PROFIE ***********************************");
        printf("\n\n\n\n\n\t\t\tChange your shop area : ");
        fgets(tradesmanst[x].ashopsb, 50, stdin);
        while (tradesmanst[x].ashopsb[0] == '\n') {
            printf("\t\t\tNot corrected , Enter your shop area again : ");
            fgets(tradesmanst[x].ashopsb, 50, stdin);
        }
        tradesmanst[x].ashopsb[strlen(tradesmanst[x].ashopsb) - 1] = '\0';
        system("cls");
        edit_pro_sahebin();
    }
    else if (strcmpi(str, "None , back to menu") == 0 || strcmpi(str, "9") == 0) {
        tradesman = fopen("tradesman.txt", "w");
        fwrite(&num_tradesman, sizeof(int), 1, tradesman);
        for (i = 0; i < num_user; i++) {
            fwrite(&tradesmanst[i], sizeof(struct tradesman), 1, tradesman);
        }
        fclose(tradesman);
        system("cls");
        menusb();
    }
}

void Moshahede_vaziat_makan(void) {
    printf("\n************************* MOSHAHEDE VAZIAT MAKAN *******************************");
    if (tradesmanst[x].vaziat == false) printf("\n\n\n\n\n\t\t\tvaziat sefid :)))");
    else printf("\n\n\n\n\n\t\t\tvaziat ghermez :(((");

    printf("\n\n\n\t\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menusb();
}

void Zede_ofooni_kardan_maghaze(void) {
    printf("\n************************** ZEDE OFOONI MAGHAZE *********************************");
    printf("\n\n\n\n\n\n\t\t\tAya maghaze khod ra zed ofooni kardid?");
    printf("\n\n\n\n\t\t\t1_ Yes");
    printf("\n\n\t\t\t2_ No");
    printf("\n\n\n\n\t\t\tEnter your choice : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "Yes") == 0 || str[0] == '1') tradesmanst[x].vaziat = false;

    tradesman = fopen("tradesman.txt", "w");
    fwrite(&num_tradesman, sizeof(int), 1, tradesman);
    for (i = 0; i < num_user; i++) {
        fwrite(&tradesmanst[i], sizeof(struct tradesman), 1, tradesman);
    }
    fclose(tradesman);

    menusb();
}

void View_the_number_of_infected_people(void) {
    printf("\n******************** VIEW THE NUMBER OF INFECTED PEOPLE ************************");
    printf("\n\n\n\n\n\n\t\tTo date, these types of people have entered your shop");
    printf("\n\n\n\t\tCode 2   :   %d", tradesmanst[x].code2);
    printf("\n\n\n\t\tCode 3   :   %d", tradesmanst[x].code3);
    printf("\n\n\n\t\tCode 4   :   %d", tradesmanst[x].code4);
    printf("\n\n\n\t\tEnter 0 to get back to menu : ");
    fgets(str, 50, stdin);
    str[strlen(str) - 1] = '\0';

    system("cls");

    if (strcmpi(str, "0") == 0) menusb();
}