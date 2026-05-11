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

int getVyber(int min, int max) {
    int vyber;
    do{
        cout << "vyber: ";
        cin >> vyber;
            if(vyber < min || vyber > max){
            cout << "zadejte čísla " << min << " až " << max << ".\n";
        }
    }while(vyber < min || vyber > max);
    return vyber;
}

int getAn() {
    char an;
    do{
        cin >> an;
            if(an != 'a' && an != 'n'){
            cout << "Zadejte a/n (malým).\n";
        }
    }while(an != 'a' && an != 'n');
    return an;
}

void getZbran(int x, string &zbran, int &zbranDmg, int &zbranAcc) {
    switch (x) {
        case 1:
            zbran="Schofield Revolver";
            zbranDmg=0;
            zbranAcc=1;
        break;
        case 2:
            zbran="Double Barrel";
            zbranDmg=1;
            zbranAcc=0;
        break;
        case 3:
            zbran="Litchfield Repeater";
            zbranDmg=2;
            zbranAcc=1;
        break;
        case 4:
            zbran="Winchester Repeater";
            zbranDmg=2;
            zbranAcc=2;
        break;
        case 5:
            zbran="Carabine";
            zbranDmg=3;
            zbranAcc=1;
        break;
        case 6:
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
        if(clothes[x]=="Kovbojské Kalhoty"){
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

int hpMax(int &hpStat) {
     return hpStat*10;
 }

void doHeal(int x, int &hp, int &hpStat) {
    hp += hpMax(hpStat)*x/100;
} 

void getObleceni(int x, string* clothes, int &hpStat) {
    switch (x) {
        case 1:
            clothes[x]="Vesta";
            hpStat +=1;
        break;
        case 2:
            clothes[x]="Kovbojské Kalhoty";
            hpStat+=1;
        break;
        case 3:
            clothes[x]="Čepice";
            hpStat+=1;
        break;
        case 4:
            clothes[x]="Trench Coat";
            hpStat+=1;
        break;
        case 5:
            clothes[x]="Kovový Plát";
            hpStat+=2;
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
    cout << "           $$$$$$$$$$  $$$$$$$$$ $$$$$$$$$$  $$$$$$$$$  $$$   $$$   $$$$$$$$$  $$$$$$$$$$$ $$$$  $$$$$$$$$  $$$$   $$$           " << endl;
    cout << "           $$$    $$$  $$@         $$$   $$$  $$        $$$$ $$$$$  $$$    $$$     $$$     $$$   $$    $$$  $$$$   $$$           " << endl;
    cout << "           $$$$$$$$$$  $$          $$$  $$$$  $$        $$$$$$$$$$  $$$$@  $$$     $$$     $$$   $$@   $$$  $$$$$  $$$           " << endl;
    cout << "           $$$  $$$    $$$$$       $$$  $$$$  $$$$$     $$$$$$$$$$  $$$$$$$$$$     $$$     $$$$  $$$   $$$  $$$$$$ $$$           " << endl;
    cout << "           $$$  $$$    $$$$$$$     $$$  $$$$  $$$$$$    $$$$$$$$$$  $$$$           $$$     $$$$  $$$   $$$  $$$ $$$$$$           " << endl;
    cout << "           $$$  $$$$   $$          $$$  $$$$  $$        $$$ $$ $$$  $$$$           $$$     $$$$  $$$   $$$  $$$  $$@$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$        $$$ $$ $$$  $$$$           $$$     $$$$  $$$    $$  $$$  $$$$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$      @ $$$    $$$  $$$$           $$$     $$$$  $$$    $$  $$$   $$$$           " << endl;
    cout << "           $$$    $$$  $$$$$$$$$  $$$$$$$$$$  $$$$$$$$$ $$$    $$$  $$$$           $$$     $$$$  $$$$$$$$$  $$$    $$$           " << endl;
    cout << "           $$$    @$$            @$$$$$$$$              $$$    $$   $$$$           $$$     $$$   $$$$$$$$$   $$    $$$           " << endl;
srand(time(0));
int dmgStat = 0;
int accStat = 0;
int rngStat = 0;
int hpStat = 0;
int hp;
int cash;
int clas = 1;
char opakovat = 'n';
int vyber = 0;
int zbranDmg = 0;
int zbranAcc = 0;
int heal[2] = {0, 0};
int randNum = (rand());
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
clas=getVyber(1,5);
switch (clas) {
    case 1:
        classs = "Gunslinger";
        cout << "Vybral si postavu " << classs << "." << endl;
        accStat = 3;
        dmgStat = 2;
        hpStat = 2;
        rngStat = 1;
        cash = 360;
        break;
    case 2:
        classs = "Outlaw";
        cout << "Vybral si postavu " << classs << "." << endl;
        accStat = 2;
        dmgStat = 3;
        hpStat = 1;
        rngStat = 1;
        cash = 420;
        break;
    case 3:
        classs = "Sherif";
        cout << "Vybral si postavu " << classs << "." << endl;
        accStat = 2;
        dmgStat = 2;
        hpStat = 3;
        rngStat = 1;
        cash = 350;
        break;
    case 4:
        classs = "Gold Digger";
        cout << "Vybral si postavu " << classs << "." << endl;
        accStat = 1;
        dmgStat = 1;
        hpStat = 1;
        rngStat = 4;
        cash = 550;
        break;
    case 5:
        classs = "Test";
        cout << "Vybral si postavu " << classs << "." << endl;
        accStat = 999;
        dmgStat = 999;
        hpStat = 999;
        rngStat = 999;
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
 cout << "přesnost " << accStat << endl;
 cout << "poškození " << dmgStat << endl;
 cout << "životy " << hpStat << " ("<< hpMax(hpStat) <<"hp)" << endl;
 cout << "štěsti " << rngStat << endl;
 cout << "note: to že máš životy na 3ce neznamená to že máš 4 životy." << endl;
 cout << "chceš pokračovat s tvojí postavou? (a/n):";
opakovat=getAn();
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
do{
cout << "Chceš jít do nějákého obchodu?" << endl;
cout << "   1-Obchod se zbraněmi" << endl;
cout << "   2-Obchod s oblblečením" << endl;
cout << "   3-Řezník" << endl;
cout << "   4-Jít dál" << endl;

vyber=getVyber(1,4);

if(vyber!=4){
switch (vyber) {                                                                        // zbrane
    case 1 :
    do{
        cout << "Dnešní nabídka:\n";
        cout << "Tady si můžeš koupit větśí dmg\n";
        cout << "(Note: Když is koupíš zbraň, zahodíš předchozí)\n";
        cout << "1. $350 Schofield (1 dmg)\n";
        cout << "2. $400 Doublebarrel (1 acc)\n";

    vyber=getVyber(1,2);
        
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
    opakovat=getAn();
}while(opakovat=='n');
break;

case 2 :                                                             //Obleceni
    do{
        cout << "Dnešní nabídka:\n";
        cout << "Tady si můžeš zvíśit svoje max hp\n";
        cout << "(Note: Když is koupíš nové oblećení, přidává se k tomu starému)\n";
        cout << "1. $350 Kovbojske Kalohty (+1 Hp)\n";
        cout << "2. $350 Čepice (+1 Hp)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
                if(checkObleceni(2, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(2, clothes, hpStat);
                cout << "+Kovbojske Kalohty\n";
                cout<<"Máš $" << cash << " a " << hpStat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
        if(checkObleceni(3, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(3, clothes, hpStat);
                cout << "+Čepice\n";
                cout<<"Máš $" << cash << " a " << hpStat << "hp levl.\n";
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
    opakovat=getAn();

}while(opakovat=='n');
break;

    case 3 :
    do{
        cout << "Dnešní nabídka:\n";
        cout << "Tady si můžeš koupit healy do fightů.\n";
        cout << "1. $150 Zavaŕovaný Ananas (+25 % max hp)\n";
        cout << "2. $350 Marinované Hovézí (+100 % max hp)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
            if (cash>=150){
                cash-=150;
                ++heal[vyber];
                cout << "+Zavaŕovaný Ananas\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=350){
                cash-=350;
                ++heal[vyber];
                cout << "+Marinované Hovézí\n";
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
    cout << "Chceš pokračovat? (a/n):";
    opakovat=getAn();
}while(opakovat=='n');
break;

case 4:break;

default : 
        cout << "----------------------------\n\n\n";
        cout << "Spatny Input: RESTARTUJ HRU!\n\n\n";
        cout << "----------------------------\n";
    break;
}
}
}while(vyber != 4);
cout << "Při cestě zpátky domů na tebe v málé uličce vyběhl\nmaskovaný chlap, s nepřívětivým pohledem.\n";
enter();
cout << "Zamířil na tebe svím revolverem a řekl:\n";
enter();
cout << "DEŠ SE MNOU!!\n";
enter();
cout << "Co uděláš?:\n";
cout << "1. Budeś bojovat proti němu. (Tutoriál)\n";
cout << "2. Utečeš mu.\n";
vyber=getVyber(1,2);
if(vyber==1){

}else{
if(randNum >= 50){

}else{

}

}
}