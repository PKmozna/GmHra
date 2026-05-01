#include <iostream>
#include <conio.h>
#include <thread>
#include <cstdlib>

using namespace std;

void enter() {
    cout << "\n-";
    while (_getch() != 13) {}
    cout << endl;
}

void getZbran(int x, string &zbran, int &zbranDmg, int &zbranAcc) {
    switch (x) {
        case 1://schofield
            zbran="Schofield Revolver";
            zbranDmg=0;
            zbranAcc=1;
        break;
        case 2://double barrel
            zbran="Double Barrel";
            zbranDmg=1;
            zbranAcc=0;
        break;
        case 3://Lichtfield
            zbran="Litchfield Repeater";
            zbranDmg=2;
            zbranAcc=1;
        break;
        case 4://Winchester
            zbran="Winchester Repeater";
            zbranDmg=2;
            zbranAcc=2;
        break;
        case 5://schofield
            zbran="Carabine";
            zbranDmg=3;
            zbranAcc=1;
        break;
        case 6://Winchester Shotgun
            zbran="Winchester Shotgun";
            zbranDmg=1;
            zbranAcc=0;
        break;
        default:
    cout << "----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Spatny Input: RESTARTUJ HRU!" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------" << endl;
    break;
    }
}

bool checkObleceni(int x, string* clothes){
switch (x){
    case 1:
        if(clothes[x]=="Vesta"){
            return true;
        }else{
            return false;
        }
    break;
    case 2:
        if(clothes[x]=="Kovbojské kalhoty"){
            return true;
        }else{
            return false;
        }
    break;
    case 3:
        if(clothes[x]=="Čepice"){
            return true;
        }else{
            return false;
        }
    break;
    case 4:
        if(clothes[x]=="Trench Coat"){
            return true;
        }else{
            return false;
        }
    break;
    case 5:
        if(clothes[x]=="Kovový Plát"){
            return true;
        }else{
            return false;
        }
    break;
    default:
    cout << "----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Spatny Kod: RESTARTUJ HRU!" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------" << endl;
    return false;
    break;
    }
}

void getObleceni(int x, string* clothes, int &hp_stat) {
    switch (x) {
        case 1:
            clothes[x]="Vesta";
            hp_stat +=1;
        break;
        case 2:
            clothes[x]="Kovbojské kalhoty";
            hp_stat+=1;
        break;
        case 3:
            clothes[x]="Čepice";
            hp_stat+=1;
        break;
        case 4:
            clothes[x]="Trench Coat";
            hp_stat+=1;
        break;
        case 5:
            clothes[x]="Kovový Plát";
            hp_stat+=2;
        break;
        default:
    cout << "----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Spatny Input: RESTARTUJ HRU!" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------" << endl;
    break;
    }
}

int main(){
    cout << "                                 $$$$$$ $$$$$ $$  $ $$$$$$      $$$$   $$   $$$$$$ $$$$$ $$$$$                                  " << endl;
    cout << "                                    $   $$     $ $     $        $  $   $$$  $$   $ $      $  $$                                 " << endl;
    cout << "                                    $   $$$$    $$     $        $$$$   $ $    $    $$$$  $$  $$                                 " << endl;
    cout << "                                    $   $$     $$$     $        $  $$ $$ $$     $$ $     $$  $$                                 " << endl;
    cout << "                                    $   $$     $ $$    $        $   $ $$$$$ $$  $$ $     $$  $$                                 " << endl;
    cout << "                                    $   $$$$$ $@  $$   $        $$$$$ $   $ $$$$$$ $$$$$ $$$$$                                 " << endl;
    cout << "                                                                                                                                " << endl;
    cout << "                       $$$$$$$$$ $$$$$$$$    $$$$$$$$$                                          $$$$$$$$$                       " << endl;
    cout << "           $$$$$$$$$$  $$$$$$$$$ $$$$$$$$$$  $$$$$$$$$  $$$   $$$   $$$$$$$$$ $$$$$$$$$$$ $$$$  $$$$$$$$$  $$$$   $$$           " << endl;
    cout << "           $$$    $$$  $$@         $$$   $$$  $$        $$$$ $$$$$  $$$    $$$     $$$     $$$   $$    $$$  $$$$   $$$           " << endl;
    cout << "           $$$$$$$$$$  $$          $$$  $$$$  $$        $$$$$$$$$$  $$$$@  $$$     $$$     $$$   $$@   $$$  $$$$$  $$$           " << endl;
    cout << "           $$$  $$$    $$$$$       $$$  $$$$  $$$$$     $$$$$$$$$$  $$$$$$$$$$     $$$     $$$$  $$$   $$$  $$$$$$ $$$           " << endl;
    cout << "           $$$  $$$    $$$$$$$     $$$  $$$$  $$$$$$    $$$$$$$$$$  $$$$           $$$     $$$$  $$$   $$$  $$$ $$$$$$           " << endl;
    cout << "           $$$  $$$$   $$          $$$  $$$$  $$        $$$ $$ $$$  $$$$           $$$     $$$$  $$$   $$$  $$$  $$@$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$        $$$ $$ $$$  $$$$           $$$     $$$$  $$$    $$  $$$  $$$$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$      @ $$$    $$$  $$$$           $$$     $$$$  $$$    $$  $$$   $$$$           " << endl;
    cout << "           $$$    $$$  $$$$$$$$$  $$$$$$$$$$  $$$$$$$$$ $$$    $$$  $$$$           $$$     $$$$  $$$$$$$$$  $$$    $$$           " << endl;
    cout << "           $$$    @$$            @$$$$$$$$              $$$    $$   $$$$           $$$     $$$   $$$$$$$$$   $$    $$$           " << endl;
int dmg_stat = 0;
int acc_stat = 0;
int hp_stat = 0;
int rng_stat = 0;
int cash;
int clas = 1;
char opakovat = 'n';
int vyber = 0;
int zbranDmg = 0;
int zbranAcc = 0;
string clothes[5];
string zbran = "err";
string classs;
cout << "[    ACC=přesnost   ]" << endl ;
cout << "[    DMG=poškození  ]" << endl ;
cout << "[     HP=životy     ]" << endl ;
cout << "[     RNG=štěstí    ]" << endl ;
cout << " $|ACC|DMG|HP|RNG|" << endl;
cout << "Vyberte si postavu:" << endl;
cout << "1.       Gunslinger" << endl;
cout << "      300$|3|2|2|1|" << endl;
cout << "2.           Outlaw" << endl;
cout << "      400$|2|3|2|1|" << endl;
cout << "3.           Sherif" << endl;
cout << "      350$|2|2|3|1|" << endl;
cout << "4.      Gold Digger" << endl;
cout << "      550$|1|1|1|4|" << endl;
cout << "-------------------" << endl;
do{
do{
    if(clas<1||clas>5){
    cout << "Zadejte čísla 1,2,3 nebo 4." << endl;
    }
cout << "Výběr:";
cin>> clas;

}while(clas<1||clas>5);
switch (clas) {
    case 1:
        classs = "Gunslinger";
        cout << "Vybral si postavu " << classs << "." << endl;
        acc_stat = 3;
        dmg_stat = 2;
        hp_stat = 2;
        rng_stat = 1;
        cash = 360;
        break;
    case 2:
        classs = "Outlaw";
        cout << "Vybral si postavu " << classs << "." << endl;
        acc_stat = 2;
        dmg_stat = 3;
        hp_stat = 1;
        rng_stat = 1;
        cash = 420;
        break;
    case 3:
        classs = "Sherif";
        cout << "Vybral si postavu " << classs << "." << endl;
        acc_stat = 2;
        dmg_stat = 2;
        hp_stat = 3;
        rng_stat = 1;
        cash = 350;
        break;
    case 4:
        classs = "Gold Digger";
        cout << "Vybral si postavu " << classs << "." << endl;
        acc_stat = 1;
        dmg_stat = 1;
        hp_stat = 1;
        rng_stat = 4;
        cash = 550;
        break;
    case 5:
        classs = "Test";
        cout << "Vybral si postavu " << classs << "." << endl;
        acc_stat = 999;
        dmg_stat = 999;
        hp_stat = 999;
        rng_stat = 999;
        cash = 6742021;
        break;
        default :
    cout << "----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Spatny Input: RESTARTUJ HRU!" << endl;
    cout << endl;
    cout << endl;
    cout << "----------------------------" << endl;
 }
 cout << "máš:" << endl;
 cout << "přesnost " << acc_stat << endl;
 cout << "poškození " << dmg_stat << endl;
 cout << "životy " << hp_stat << endl;
 cout << "štěsti " << rng_stat << endl;
 cout << "note: to že máš životy na 3ce neznamená to že máš 4 životy." << endl;
 cout << "chceš pokračovat s tvojí postavou? (a/n):";
 do{
    if(opakovat!='a' && opakovat!='n'){
        cout << endl << "zadejte a nebo n (malým)" << endl;
    }
cin >> opakovat;
}while(opakovat!='a' && opakovat!='n');
}while(opakovat=='n');
cout << "Je rok 1908 (Enter)";
enter();
cout << "Jsi majitelem maleho pozemku s domkem pobliíš" << endl << "Duboisu v Americkém Wayomingu.";
enter();
cout << "Za opaskem ti cinká cattleman revolver (0 acc, 0 dmg) po tvém tátovi.";
enter();
cout << "Přesně tak, jak to otcové zakladatelé zamýšleli...";
enter();
cout << "Deš do Duboisu. Už si zapoměl proč, ale je to vlastné jedno.";
enter();
                                                                                        //Vesnice
cout << "Chceš jít do nějákého obchodu?" << endl;
cout << "   1-Obchod se zbraněmi" << endl;
cout << "   2-Obchod s oblblečením" << endl;
cout << "   3-Drugstore" << endl;
cout << "   4-Jít dál" << endl;

do{
    vyber=0;
    if(vyber<0||vyber>4){
    cout << "Zadejte cisla 1,2,3 nebo 4." << endl;
    }
cout << "Vyber:";
cin>> vyber;
        }while(vyber<0||vyber>4);

switch (vyber) {                                                                        // zbrane
    case 1 :
    do{
        cout << "Dnešní nabídka:\n";
        cout << "(Note: Když is koupíš zbraň, zahodíš předchozí)\n";
        cout << "1. $350 Schofield (1 dmg)\n";
        cout << "2. $400 Doublebarrel (1 acc)\n";

    do{
    vyber=0;
    if(vyber<0||vyber>3){
    cout << "Zadejte cisla 1,2 nebo 3." << endl;
    }
cout << "Vyber:";
cin>> vyber;
        }while(vyber<0||vyber>3);
        
    switch (vyber) {
        case 1:
            if (cash>=350){
                cash-=350;
                getZbran(1, zbran, zbranDmg, zbranAcc);
                cout << "+Schofield\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=400){
                cash-=400;
                getZbran(2, zbran, zbranDmg, zbranAcc);
                cout << "+Doublebarrel\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;

        default : 
            cout << "----------------------------\n\n\n";
            cout << "Spatny Input: RESTARTUJ HRU!\n\n\n";
            cout << "----------------------------\n";
        break;
}
    cout << "chceš pokračovat? (a/n):";
 do{
    if(opakovat!='a' && opakovat!='n'){
        cout << endl << "zadejte a nebo n (malým)" << endl;
    }
cin >> opakovat;
}while(opakovat!='a' && opakovat!='n');
}while(opakovat=='n');
break;

case 2 :                                                             //Obleceni
    do{
        cout << "Dnešní nabídka:\n";
        cout << "(Note: Když is koupíš nové oblećení, přidává se k tomu starému)\n";
        cout << "1. $350 Kovbojske Kalohty (+1 Hp)\n";
        cout << "2. $350 Čepice (+1 Hp)\n";

    do{
    vyber=0;
    if(vyber<0||vyber>3){
    cout << "Zadejte cisla 1,2 nebo 3." << endl;
    }
cout << "Vyber:";
cin>> vyber;
        }while(vyber<0||vyber>3);
        
    switch (vyber) {
        case 1:
                if(checkObleceni(2, clothes)){
            cout << "Už máš tenhle kus oblečeni\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(2, clothes, hp_stat);
                cout << "+Kovbojske Kalohty\n";
                cout<<"Máš $" << cash << " a " << hp_stat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
        if(checkObleceni(3, clothes)){
            cout << "Už máš tenhle kus oblečeni\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(3, clothes, hp_stat);
                cout << "+Čepice\n";
                cout<<"Máš $" << cash << " a " << hp_stat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;

        default : 
            cout << "----------------------------\n\n\n";
            cout << "Spatny Input: RESTARTUJ HRU!\n\n\n";
            cout << "----------------------------\n";
        break;
}
    cout << "chceš pokračovat? (a/n):";
 do{
    if(opakovat!='a' && opakovat!='n'){
        cout << endl << "zadejte a nebo n (malým)" << endl;
    }
cin >> opakovat;
}while(opakovat!='a' && opakovat!='n');
}while(opakovat=='n');
break;


    default : 
        cout << "----------------------------\n\n\n";
        cout << "Spatny Input: RESTARTUJ HRU!\n\n\n";
        cout << "----------------------------\n";
    break;
}
vyber=0;
}