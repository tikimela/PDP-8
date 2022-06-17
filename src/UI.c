#include "PDP-8.h"
#include"string.h"

void UIStart(){
    Intro();
    Meni();
}

void Start(char *input){
    LoadProgram(input);
    Intro();
    printf("----------------------------------\n");
    printf("Ucitali ste: %s \n",input);
    printf("----------------------------------\n");
    Meni();
}
 /* -----------------------------------------------------------------------------------------
 | Operacija      | Opis operacije                                                 | Sifra |
 | --------------------------------------------------------------------------------| ----- |
 | START PROGRAM  | Pokretanje programa                                            |   1   |
 | --------------------------------------------------------------------------------| ----- |
 | LOAD PROGRAM   | Ucitava file sa instrukcijama koje zelite da program izvrsi.   |   2   |
 | --------------------------------------------------------------------------------| ----- |
 | DUMP MEMORY    | Stampanje memorijske slike.                                    |   3   |
 | --------------------------------------------------------------------------------| ----- |
 | CLEAR MEMORY   | Ciscenje memorije.                                             |   4   |
 | --------------------------------------------------------------------------------- ----- |
 | READ ME        | Otvara READ ME file.                                           |   5   |
  ---------------------------------------------------------------------------------- -----*/

  void Meni(){
     printf("Izaberite iz tabele operaciju koju zelite pokrenuti, i upisite njen kod ispod.\n\n");
     printf("  --------------------------------------------------------------------------------- ----- \n");
     printf("| Operacija      | Opis operacije                                                 |  Kod  |\n");
     printf("| --------------------------------------------------------------------------------| ----- |\n");
     printf("| START PROGRAM  | Pokretanje programa                                            |   1   |\n");
     printf("| --------------------------------------------------------------------------------| ----- |\n");
     printf("| LOAD PROGRAM   | Ucitava file sa instrukcijama koje zelite da program izvrsi.   |   2   |\n");
     printf("| --------------------------------------------------------------------------------| ----- |\n");
     printf("| DUMP MEMORY    | Stampanje memorijske slike.                                    |   3   |\n");
     printf("| --------------------------------------------------------------------------------| ----- |\n");
     printf("| CLEAR MEMORY   | Ciscenje memorije.                                             |   4   |\n");
     printf("| --------------------------------------------------------------------------------- ----- |\n");
     printf("| EXIT           | Izlaz                                                          |   5   |\n");
     printf(" ---------------------------------------------------------------------------------- -----\n\n");

     CodePicker();
  }

void CodePicker(){
    int n = 0;
    printf("----------------------------------\n");
    printf("Kod:");
    scanf("%d",&n);
    printf("\n");

    char f;
    while((f=getchar())!=EOF && f!='\n');

    if(n == 1){
        printf("\n");
        if(isThereFile == true){
            boot(1);
            printf("----------------------------------\n");
            printf("Uspjesno je zavrsen program ~\n");
            printf("----------------------------------\n\n");
            printf("\n\n");

            BackToMenu();
        }
        else{
            printf("\n");
            printf("----------------------------------------\n");
            printf("Niste ucitali file! Pokusajte opet.\n");
            printf("----------------------------------------\n");
            Meni();
            CodePicker();
        }

    }
    else if(n == 2){
        printf("\n");
        printf("Upisite adresu vaseg file-a:\n");
        printf("----------------------------------\n");
        printf("Adresa:");

        char path[256];
        fgets(path, 255, stdin);

        if ((strlen(path) > 0) && (path[strlen (path) - 1] == '\n'))
            path[strlen (path) - 1] = '\0';

        LoadProgram(path);
        printf("\n\n");

        printf("----------------------------------\n");
        printf("Uspjesno je ucitan file ~\n");
        printf("----------------------------------\n");
        printf("\n\n");
        BackToMenu();


    }
    else if(n == 3){
        printf("\n");
        printf("Upisite adresu file-a u kom zelite ostampati memorijsku sliku:\n");
        printf("-------------------------------------------------------------\n");
        printf("Adresa:");

        char path[256];
        fgets(path, 255, stdin);

        if ((strlen(path) > 0) && (path[strlen (path) - 1] == '\n'))
            path[strlen (path) - 1] = '\0';

        DumpMemory();
        printf("\n\n");

        printf("----------------------------------------\n");
        printf("Uspjesno je ostampana memorijska slika ~\n");
        printf("----------------------------------------\n");
        printf("\n\n");

        BackToMenu();

    }
    else if(n == 4){
        printf("\n");
        ClearMem();
        printf("----------------------------------\n");
        printf("Uspjesno je ociscena memorija ~\n");
        printf("----------------------------------\n");
        printf("\n\n");
        BackToMenu();
    }
    else if(n == 5){
        printf("\n");
        printf("\n");
        printf("Hvala Vam sto ste koristili moj program!\n");

    }
    else{
        printf("\n");
        printf("----------------------------------------\n");
        printf("Upisali ste neodgovarajuci kod! Probajte opet.\n");
        printf("----------------------------------------\n");

        CodePicker();
    }
}

/* _____  _____  _____              ___
|  __ \|  __ \|  __ \            / _ \
| |__) | |  | | |__) |  ______  | (_) |
|  ___/| |  | |  ___/  |______|  > _ <
| |    | |__| | |               | (_) |
|_|    |_____/|_|                \___/*/

void Intro(){
    printf("\n");
    printf("\n");
    printf(" _____    _____    _____                ___\n");
      printf("|  __  | |  __  | |  __  |            |     | \n");
      printf("| |__) | | |  | | | |__) |   ______  |  (_)  |\n");
      printf("|  ___/  | |  | | |  ___/   |______|   > _ <\n");
      printf("| |      | |__| | | |                |  (_)  |\n");
      printf("|_|      |_____/  |_|                 |_____|\n\n");

      printf("Mirela Abazovic 43/21, C - smjer \n\n");
}


void BackToMenu(){
    int m = 0;
    printf("\n----------------------------------------\n");
    printf("Hocete li nazad na tabelu? (1/0): ");
    scanf("%d",&m);

    if(m == 1){
        Meni();
    }
    else{
        printf("\n");
        printf("Hvala Vam sto ste koristili moj program!\n");
    }
}