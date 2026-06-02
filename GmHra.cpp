#include <iostream>
#include <conio.h>
#include <thread>
#include <cstdlib>

using namespace std;

struct {
int dmgStat;
int accStat;
int rngStat;
int hpStat;
int hp;
} player;

struct enemy {
int dmgStat;
int hp;
}enemy1, enemy2, enemy3;

struct {
int acc;
int dmg;
string name;
} zbran;

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
    cin.ignore(1000, '\n');
}

int playerDmg(){
    return player.dmgStat + zbran.dmg;
}

int playerAcc(){
    return player.accStat + zbran.acc;
}

int getAn() {
    char an;
    do{
        cin >> an;
            if(an != 'a' && an != 'n'){
            cout << "Zadejte a/n (malým).\n";
        }
    }while(an != 'a' && an != 'n');
    cin.ignore(1000, '\n');
    return an;

}

int hpP() {
    int x = (100*player.hp)/(10*player.hpStat);
    return x;
}

void hitEnemy(enemy& en, int i) {
    int x = rand()%11 + 20 + (player.dmgStat*10);
    en.hp -= x;
    if(en.hp <= 0) {
        cout << i << ". nepřítel umřel\n";
    }else{
    cout << i << ". nepřítel -" << x << "hp\n";
}
}

void hipEnemy(enemy& en, int i) {
    if(rand()%100 + playerAcc()*5 < 30) {
        int x = rand()%16 + 15 + (playerDmg()*10)*1.2;
    en.hp -= x;
    if(en.hp <= 0) {
        cout << i << ". nepřítel umřel\n";
    }else{
    cout << i << ". nepřítel -" << x << "hp\n";
        }
    }else {
        cout << "Vedle!\n";
    }
}

void enemyHit(enemy& en, int i) {
    int x =  rand()%11 + 20 + (en.dmgStat*10);
    player.hp -= x;
    cout << i << ". nepŕítel zaůtočil.\n";
    cout <<"               -" << x <<" hp \n";
    if(player.hp <= 0) {
        cout << "-----------\n";
        cout << "Umřel si!\n";
        cout << "-----------\n";
        exit(0);
    } else {
        cout << "máš " << player.hp << " hp.";
    }
}

void enemyHip(enemy& en , int i) {
    if(rand()%100 < 40) {
        int x = rand()%16 + 15 + (en.dmgStat*10)*1.2;
        player.hp -= x;
        cout << i << ". nepŕítel zaůtočil hipfirem!!\n";
    cout << i << "              -" << x <<" hp \n";
            if(player.hp <= 0) {
        cout << "-----------\n";
        cout << "Umřel si!\n";
        cout << "-----------\n";
        exit(0);
    } else {
        cout << "máš " << player.hp << " hp.";
    }
    }else {
        cout << i << ". nepŕítel zaůtočil hipfirem!!\n";
        cout <<"                ale netrefilse!\n";
    }
    cout << "---------------\n";
}

void getZbran(int x) {
    switch (x) {
        case 1:
            zbran.name="Schofield Revolver";
            zbran.dmg=0;
            zbran.acc=1;
        break;
        case 2:
            zbran.name="Double Barrel";
            zbran.dmg=1;
            zbran.acc=0;
        break;
        case 3:
            zbran.name="Litchfield Repeater";
            zbran.dmg=2;
            zbran.acc=1;
        break;
        case 4:
            zbran.name="Winchester Repeater";
            zbran.dmg=2;
            zbran.acc=2;
        break;
        case 5:
            zbran.name="Carabine";
            zbran.dmg=3;
            zbran.acc=1;
        break;
        case 6:
            zbran.name="Winchester Shotgun";
            zbran.dmg=1;
            zbran.acc=0;
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

int hpMax() {
     return player.hpStat*10;
 }

void doHeal(int x) {
    player.hp += (player.hpStat * 10) * x/100;
    if(player.hp > player.hpStat) {
        player.hp = player.hpStat;
    }
    cout << "(+" << x << " hp)\n";
} 

void getObleceni(int x, string* clothes) {
    switch (x) {
        case 1:
            clothes[x]="Vesta";
            player.hpStat += 1;
        break;
        case 2:
            clothes[x]="Kovbojské Kalhoty";
            player.hpStat += 1;
        break;
        case 3:
            clothes[x]="Čepice";
            player.hpStat += 1;
        break;
        case 4:
            clothes[x]="Trench Coat";
            player.hpStat += 1;
        break;
        case 5:
            clothes[x]="Kovový Plát";
            player.hpStat += 2;
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
    cout << "                                    $   $$     $ $$    $        $  $$ $$ $$     $$ $     $$  $$                                 " << endl;
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

int cash;
int heal[2] = {0, 0};
string clothes[5];
int clas = 1;
string classs;
int randNum = (rand());
char opakovat = 'n';
int vyber = 0;
zbran.dmg = 0;
zbran.acc = 0;
zbran.name = "err";

cout << "[    ACC=přesnost   ]" << endl ;
cout << "[    DMG=poškození  ]" << endl ;
cout << "[     HP=životy     ]" << endl ;
cout << "[     RNG=štěstí    ]" << endl ;
cout << " $|ACC|DMG|HP|RNG|" << endl;
cout << "Vyberte si postavu:" << endl;
cout << "1.       Gunslinger" << endl;
cout << "      300$|3|2|4|1|" << endl;
cout << "2.           Outlaw" << endl;
cout << "      400$|2|3|4|1|" << endl;
cout << "3.           Sherif" << endl;
cout << "      350$|2|2|5|1|" << endl;
/*cout << "4.      Gold Digger" << endl;
cout << "      550$|1|1|3|4|" << endl;*/
cout << "-------------------" << endl;
do{
clas=getVyber(1,4);
switch (clas) {
    case 1:
        classs = "Gunslinger";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 3;
        player.dmgStat = 2;
        player.hpStat = 4;
        player.rngStat = 1;
        cash = 360;
        break;
    case 2:
        classs = "Outlaw";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 2;
        player.dmgStat = 3;
        player.hpStat = 4;
        player.rngStat = 1;
        cash = 420;
        break;
    case 3:
        classs = "Sherif";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 2;
        player.dmgStat = 2;
        player.hpStat = 5;
        player.rngStat = 1;
        cash = 350;
        break;
   /* case 4:
        classs = "Gold Digger";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 1;
        player.dmgStat = 1;
        player.hpStat = 3;
        player.rngStat = 4;
        cash = 550;
        break;*/
    case 4:
        classs = "Test";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 999;
        player.dmgStat = 999;
        player.hpStat = 999;
        player.rngStat = 999;
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
 player.hp = hpMax();
 cout << "máš:" << endl;
 cout << "přesnost " << player.accStat << endl;
 cout << "poškození " << player.dmgStat << endl;
 cout << "životy " << player.hpStat << " ("<< hpMax() <<"hp)" << endl;
 cout << "štěsti " << player.rngStat << endl;
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
                getZbran(1);
                cout << "+Schofield\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=400){
                cash-=400;
                getZbran(2);
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
                getObleceni(2, clothes);
                cout << "+Kovbojske Kalohty\n";
                cout<<"Máš $" << cash << " a " << player.hpStat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
        if(checkObleceni(3, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(3, clothes);
                cout << "+Čepice\n";
                cout<<"Máš $" << cash << " a " << player.hpStat << "hp levl.\n";
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
cout << "Při cestě zpátky domů na tebe v málé uličce vyběhl\nmaskovaný chlap, s nepřívětivým pohledem.";
enter();
cout << "Zamířil na tebe svím revolverem a řekl:";
enter();
cout << "DEŠ SE MNOU!!";
enter();
cout << "Co uděláš?:\n";
cout << "1. Budeś bojovat proti němu. (Tutoriál)\n";
cout << "2. Utečeš mu.\n";
vyber=getVyber(1,2);
if(vyber==1){
enemy1.hp = 70;
enemy1.dmgStat = 1;
cout << "Začínáš.";
enter();
while(enemy1.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS (standartní přesnost a dmg)\n";
cout << "2. Střelit Hip-Firem (míň přesnějśí ale více dmg)\n";
cout << "3. Menší heal (+25% hp)\n";
cout << "4. Větší heal (+100% hp)\n";
cout << "[Nepŕítel má: " << enemy1.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
        hitEnemy(enemy1, 1);
    break;
    case 2:
        hipEnemy(enemy1, 1);
    break;
    case 3:
        heal[1]-=1;
        doHeal(25);
    break;
    case 4:
        heal[2]-=2;
        doHeal(100);
    break;
}

if(enemy1.hp > 0){
cout << "1. Nepŕítel je na tahu.\n\n";
if(rand()%10 < 2){
    cout << "1. nepřítel zaůtočil hipfirem!!\n";
    if(rand()%100 < 40) {
    vyber = rand()%16 + 15 + (enemy1.dmgStat*10)*1.2;
        player.hp -= vyber;
    }else {
        cout <<"                ale netrefilse!\n";
    }
}   else {
    vyber =  rand()%11 + (enemy1.dmgStat*10);
    player.hp -= vyber;
    cout << "1. nepřítel zaůtočil.\n";
    }

    cout <<"              -" << vyber <<" hp \n";
    cout << "---------------\n";    
}
            if(player.hp <= 0) {
        player.hp = player.hpStat * 10;
        cout << "byl si poražen...\n";
        enter();
        cout << "ale neumřel si..";
            }
            if(enemy1.hp <= 0) {
        doHeal(100);
        cout << "maskovaný muž zemŕel...";
        enter();
        cout << "ale vyskoćili na tebe maskovaní chlápci kteří tě unesly..";
        enter();
        }
    }
} else if (randNum >= 50){
cout << "Neznámý muž tě střelil do zad když si utíkal a ty si v bolesti spadl na zem.";
player.hp-=10;
enter();
} else {
cout << "z uličky na tebe vyběhli další dva maskovaní chlápci a unesli tě.";
enter();
}

cout << "Si teď v nějáké chatce řeťezem přivázaný ke zdi.";
enter();
cout << "Pouta ale nejseou správně utažená,\n takže se dá z nich jednoduše dostat ven.";
enter();
cout << "Svojí zbraň máš stále u sebe, takže si vyrazil ven,\n kde ti dva co tě unesly, sedí u ohně.";
enter();
cout << "Ale najednou tě zahlídly, musíš s němi bojovat.";
enter();
enemy1.dmgStat = 5;
enemy1.hp = 20;
enemy2.dmgStat = 5;
enemy2.hp = 20;
cout << "Začínáš.";
enter();
while(enemy1.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal (+25% hp)\n";
cout << "4. Větší heal (+100% hp)\n";
cout << "[Nepřátelé mají: " << enemy1.hp << "a " << enemy2.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
    if(enemy1.hp > 0 && enemy2.hp >0){
    cout << "Střelíš:\n";
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    vyber=getVyber(1, 2);
        if(vyber == 1){
            hitEnemy(enemy1, 1);
        } else {
            hitEnemy(enemy2, 2);
        }
    } else if (enemy1.hp > 0) {
        hitEnemy(enemy1, 1);
    } else {
        hitEnemy(enemy2, 2);
    }
    break;
    case 2:
    if(enemy1.hp > 0 && enemy2.hp >0){
    cout << "Střelíš:\n";
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    vyber=getVyber(1, 2);
        if(vyber == 1){
            hipEnemy(enemy1, 1);
        } else {
            hipEnemy(enemy2, 2);
        }
    } else if (enemy1.hp > 0) {
        hipEnemy(enemy1, 1);
    } else {
        hipEnemy(enemy2, 2);
    }
    break;
    case 3:
        heal[1]-=1;
        doHeal(25);
    break;
    case 4:
        heal[2]-=2;
        doHeal(100);
    break;
}
if(enemy1.hp > 0) {
    cout << "1. nepřítel na řadě";
    if (rand()%10<7) {
        enemyHit(enemy1, 1);
    } else {
        enemyHip(enemy1, 1);
    }
}
if(enemy2.hp > 0) {
    cout << "2. nepřítel na řadě";
    if (rand()%10<7) {
        enemyHit(enemy2, 2);
    } else {
        enemyHip(enemy2, 2);
    }
}
}
}