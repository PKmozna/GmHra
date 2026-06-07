#include <iostream>
#include <conio.h>
#include <thread>
#include <cstdlib>

using namespace std;

struct {
int dmgStat;
int accStat;
int hpStat;
int hp;
int xp = 0;
int actt;
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

struct Boss { //1.oheň 2.země 3.vítr 4.voda
int hp;
int hpMax;
int actt;
string act[5] = {"null", "ohně", "země", "větru", "vody"};
} boss;

void enter() {
    cout << "\n-";
    while (_getch() != 13) {}
    cout << endl;
}

void doHeal(int x) {
    player.hp += (player.hpStat * 10) * x/100;
    if(player.hp > player.hpStat*10) {
        player.hp = player.hpStat*10;
    }
    cout << "(+" << x << " hp)\n";
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
    cin.ignore(1000, '\n');    
    return vyber;
}

int playerDmg(){
    return player.dmgStat + zbran.dmg;
}

int playerAcc(){
    return player.accStat + zbran.acc;
}

int hpMax() {
     return player.hpStat*10;
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

void getGold(int& cash) {
    int x = rand()%22 + 80;
    cash += x;
    cout << "(+ $" << x << ")\n";
}

int hpP() {
    int x = (100*player.hp)/(10*player.hpStat);
    return x;
}

void bossAtt(){
    int vyber;
    boss.actt=rand()%4+1;
    cout << "Quadratera utočí pomocí " << boss.act[boss.actt] << ".\n";
    cout << "-1.Použiješ item...\n";
    cout << "-2.Přemístíš se na...\n";
    vyber=getVyber(1, 2);
    cout << "---------------";
    cout << "1.Oheň\n";
    cout << "2.Země\n";
    cout << "3.Vítr\n";
    cout << "4.Voda\n";
    player.actt=getVyber(1, 4);
    if(vyber == 2){
        player.actt+=4;
    }
    switch(player.actt){
        case 1:
            cout << "Škrtnul si křesadlem.\n";
            switch(boss.actt){
                case 1:
                   player.hp-=5;
                   cout << "Spálil ses\n(-5 hp)\n";
                break;
                case 2:
                    cout << "Žádné poškození\n";
                break;
                case 3:
                    boss.hp-=10;
                    cout << "Quadraterra -10 hp\n";
                    player.hp-=10;
                    cout << "(-10 hp)\n";
                break;
                case 4:
                    cout << "Nic se nestalo.";
                break;
            }
        break;
        case 2:
            cout << "Otevřel si sklenici hlíny.\n";
            switch(boss.actt){
                case 1:
                   boss.hp -= 30;
                   cout << "Quadraterra -30 hp\n";
                break;
                case 2:
                    cout << "Nic se nestalo.\n";
                break;
                case 3:
                    player.hp-=5;
                    cout << "(-5 hp)\n";
                break;
                case 4:
                    boss.hp -= 5;
                    cout << "Quadraterra -5 hp\n";
                break;
            }
        break;
        case 3:
            cout << "Máchnul si vějířem.\n";
            switch(boss.actt){
                case 1:
                   player.hp -= 10;
                   cout << "(-10 hp)\n";
                break;
                case 2:
                    cout << "Nic se nestalo.\n";
                break;
                case 3:
                    boss.hp-=10;
                    cout << "Quadraterra -10 hp.\n";
                    player.hp-=10;
                    cout << "(-10 hp)\n";
                break;
                case 4:
                    boss.hp -= 5;
                    cout << "Quadraterra -5 hp.\n";
                break;
            }
        break;
        case 4:
            cout << "Otevřel si lahvičku vody.\n";
            switch(boss.actt){
                case 1:
                   boss.hp -= 40;
                    cout << "Quadraterra -40 hp.\n";
                break;
                case 2:
                    boss.hp -= 10;
                    cout << "Quadraterra -10 hp.\n";
                break;
                case 3:
                    cout << "Nic se nestalo.\n";
                break;
                case 4:
                    cout << "Nic se nestalo.\n";
                break;
            }
        break;
        case 5:
            cout << "Stoupl sis na místo ohně.\n";
            switch(boss.actt){
                case 1:
                   player.hp -= player.hp*0.1;
                    cout << "Zbylo ti 10 % zbylích životů. (" << player.hp << ")\n";
                break;
                case 2:
                    player.hp-=20;
                    cout << "(-20 hp)\n";
                break;
                case 3:
                    doHeal(20);
                    cout << "(+20 %' hp)\n";
                break;
                case 4:
                    cout << "Nic se nestalo.\n";
                break;
            }
        break;
        case 6:
            cout << "Stoupl sis na místo země.\n";
            switch(boss.actt){
                case 1:
                   player.hp-=10;
                    cout << "(-10 hp)\n";
                break;
                case 2:
                    player.hp-=30;
                    cout << "(-30 hp)\n";
                break;
                case 3:
                    cout << "Nic se nestalo.\n";
                break;
                case 4:
                    doHeal(20);
                    cout << "(+20 %' hp)\n";
                break;
            }
        break;
        case 7:
            cout << "Stoupl sis na místo větru.\n";
            switch(boss.actt){
                case 1:
                    cout << "Nic se nestalo.\n";
                break;
                case 2:
                    cout << "Nic se nestalo.\n";
                break;
                case 3:
                    player.hp-=20;
                    cout << "(-20 hp)\n";
                break;
                case 4:
                    player.hp-=5;
                    cout << "(-5 hp)\n";
                break;
            }
        break;
        case 8:
            cout << "Stoupl sis na místo vody.\n";
            switch(boss.actt){
                case 1:
                   player.hp-=20;
                    cout << "(-20 hp)\n";
                break;
                case 2:
                    player.hp-=10;
                    cout << "(-10 hp)\n";
                break;
                case 3:
                    boss.hp -= 50;
                    cout << "Quadraterra -50 hp.\n";
                break;
                case 4:
                    player.hp -= player.hp*0.1;
                    cout << "Zbylo ti 10 % zbylích životů. (" << player.hp << ")\n";
                break;
            }
        break;
    }
    if(player.hp <= 0) {
        cout << "-----------\n";
        cout << "Umřel si!\n";
        cout << "-----------\n";
        exit(0);
    }
}

void hitEnemy(enemy& en, int i) {
    int x = rand()%11 + 10 + (player.dmgStat*6);
    en.hp -= x;
    if(en.hp <= 0) {
        cout << i << ". nepřítel umřel\n";
    }else{
    cout << i << ". nepřítel -" << x << "hp\n";
}
}

void hipEnemy(enemy& en, int i) {
    if(rand()%100 + playerAcc()*5 > 40) {
        int x = rand()%16 + 10 + (playerDmg()*4)*1.2;
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
    int x =  rand()%11 + 5 + (en.dmgStat*3);
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
        int x = rand()%16 + 5 + (en.dmgStat*3)*1.2;
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
            zbran.acc=2;
        break;
        case 6:
            zbran.name="Winchester Shotgun";
            zbran.dmg=4;
            zbran.acc=1;
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

void getXp() {
    int vyber;
    int x = rand()%35 + 40;
    player.xp += x;
    if(player.xp >=100) {
        player.xp -= 100;
        cout << "-LVL upnul si!-\n";
        cout << "Vyber si upgrade:\n";
        cout << "   1. DMG |" << player.dmgStat << " -> " << player.dmgStat+1 << "|\n";
        cout << "   2. ACC |" << player.accStat << " -> " << player.accStat+1 << "|\n";
        cout << "   3. HP  |" << player.hpStat << " -> " << player.hpStat+1 << "|\n";
        cout << "---------------------------\n";
        vyber = getVyber(1, 3);
    switch (vyber){
        case 1:
            player.dmgStat+=1;
            cout << "DMG LVL -> " << player.dmgStat << endl;
            cout << "-------------\n";
        break;
        case 2:
            player.accStat+=1;
            cout << "ACC LVL -> " << player.accStat << endl;
            cout << "-------------\n";
        break;
        case 3:
            player.hpStat+=1;
            cout << "HP LVL -> " << player.hpStat << endl;
            cout << "------------\n";
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
    case 6:
        if(clothes[x]=="Pozlacený Pásek"){
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
        case 6:
            clothes[x]="Pozlacený Pásek";
            player.hpStat += 1;
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
int heal[3] = {0, 0, 0};
string clothes[7];
int clas = 1;
string classs;
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
        cash = 360;
        break;
    case 2:
        classs = "Outlaw";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 2;
        player.dmgStat = 3;
        player.hpStat = 4;
        cash = 420;
        break;
    case 3:
        classs = "Sherif";
        cout << "Vybral si postavu " << classs << "." << endl;
        player.accStat = 2;
        player.dmgStat = 2;
        player.hpStat = 5;
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
cout << "   3-Potraviny" << endl;
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
cout << "3. Menší heal ("<< heal[1] <<")(+25% hp)\n";
cout << "4. Větší heal ("<< heal[2] <<")(+100% hp)\n";
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
        heal[2]-=1;
        doHeal(100);
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
        getGold(cash);
        enter();
        cout << "ale vyskoćili na tebe maskovaní chlápci kteří tě unesly..";
        enter();
        }
    }
} else if (rand() >= 50){
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
cout << "Ale najednou tě zahlídly, jen tak té odejít nenechají.";
enter();
enemy1.dmgStat = 1;
enemy1.hp = 20;
enemy2.dmgStat = 1;
enemy2.hp = 20;
cout << "Začínáš.";
enter();
while(enemy1.hp+enemy2.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
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
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
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
getGold(cash);
getXp();
getGold(cash);
getXp();
cout << "Porzail si oba a našel si nějáké jídlo v jejich kempu.";
doHeal(100);
enter();
cout << "Výstřeli ale asi zaslech jeśtě jeden z bandy, který až teď doběhl na pomoc.";
enter();

enemy1.hp = 50;
enemy1.dmgStat = 4;
while(enemy1.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřítel má: " << enemy1.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
        hitEnemy(enemy1, 1);
    break;
    case 2:
        hipEnemy(enemy1, 1);
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
}
if(enemy1.hp > 0) {
    cout << "Nepřítel na řadě";
    if (rand()%10<7) {
        enemyHit(enemy1, 1);
    } else {
        enemyHip(enemy1, 1);
    }
}
}
getXp();
getGold(cash);
cout << "Všechny si vystřílel.";
enter();
cout << "Po prozkoumání tábořiště si zjistil, že tvoji únosci jsou členy sekty Itaky klanu.";
enter();
cout <<"Našel si mapu, na které byl zakreslená cesta k hlavní osadě klanu,\nkterý je umísténý poblíž vrcholku hory Grand Teton.";
enter();
cout << "Chceś jít a pomstít a zničit celý kult?\n";
opakovat=getAn();
if(opakovat == 'n') {
    cout << "Okay..";
    enter();
    cout << "Odešel si domů a žil spokojený život.";
    enter();
    cout << "Čau";
    exit(0);
}
cout <<"Vydal si se po cestě k nejbližšímu městu a došel si do Colter Bay Village";
doHeal(100);
enter();
do{
cout << "Chceš jít do nějákého obchodu?" << endl;
cout << "   1-Obchod se zbraněmi" << endl;
cout << "   2-Obchod s oblblečením" << endl;
cout << "   3-Potraviny" << endl;
cout << "   4-Jít dál" << endl;
cout << "   [Máš $ " << cash << "]" << endl;
vyber=getVyber(1,4);

if(vyber!=4){
switch (vyber) {                                                                        // zbrane
    case 1 :
    do{
        cout << "Dnešní nabídka:\n";
        cout << "1. $700 Winchester Repeater (2 dmg, 2 acc)\n";
        cout << "2. $500 Litchfield Repeater (2 dmg, 1 acc)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
            if (cash>=700){
                cash-=700;
                getZbran(3);
                cout << "+Winchester Repeater\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=500){
                cash-=500;
                getZbran(3);
                cout << "+Litchfield Repeater\n";
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
        cout << "1. $350 Vesta (+1 Hp)\n";
        cout << "2. $350 Trench Coat (+1 Hp)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
                if(checkObleceni(4, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(4, clothes);
                cout << "+Tranch Coat\n";
                cout<<"Máš $" << cash << " a " << player.hpStat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
        if(checkObleceni(1, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=350){
                cash-=350;
                getObleceni(1, clothes);
                cout << "+Vesta\n";
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
cout << "Pokračujeś dál po cestě, ale náhledné na tebe z lesa vyjel povoz.";
enter();
cout << "Ze zadku povozu vyskočil OBŘÍ chlap a zařval:";
enter();
cout << "Peníze nebo život!";
enter();
cout << "Ty mu ale svoje peníze určitě svoje peníze nedáš.";
enter();
enemy1.hp = 80;
enemy1.dmgStat = 4;
while(enemy1.hp > 0 && player.hp > 0) {  //miniboss
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřítel má: " << enemy1.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
        hitEnemy(enemy1, 1);
    break;
    case 2:
        hipEnemy(enemy1, 1);
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
}
if(enemy1.hp > 0) {
    cout << "Nepřítel na řadě";
    if (rand()%10<7) {
        enemyHip(enemy1, 1);
    } else {
        enemyHit(enemy1, 1);
    }
}
}
getXp();
getXp();
getGold(cash);
getGold(cash);

cout << "Jeho mrtvola s hlasitým ztaduněním padla na zem.";
enter();
cout << "Ještě se ale musíś vypořádat se zbydkem povozu.";
enter();
cout << "Ze zadu na tebe vykukujou dvě hlavy zakryté šátkem\na kočí už splaśených koňů taky dávno upustil a zaujmul pozici za povozem.";
enter();

enemy1.dmgStat = 2;
enemy1.hp = 30;
enemy2.dmgStat = 1;
enemy2.hp = 25;
enemy3.dmgStat = 2;
enemy3.hp = 35;

cout << "Začínáš.";
enter();

while(enemy1.hp+enemy2.hp+enemy3.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřátelé mají: " << enemy1.hp << "a " << enemy2.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
if((enemy1.hp > 0 && enemy2.hp > 0) || (enemy2.hp > 0 && enemy3.hp > 0) || (enemy1.hp > 0 && enemy3.hp > 0)){
    cout << "Střelíš:\n";
    if(enemy1.hp > 0) {
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    }
    if(enemy2.hp > 0) {
        cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    }
    if(enemy3.hp > 0) {
    cout << "Nepřítele 3? (" << enemy3.hp << ")\n";
    }
    if(enemy3.hp <= 0){
        vyber=getVyber(1, 2);
    } else if(enemy1.hp <= 0) {
        vyber=getVyber(2, 3);
    } else {
        vyber=getVyber(1, 3);
    }
    if(enemy2.hp <= 0 && vyber == 2){vyber=3;}
        if(vyber == 1){
            hitEnemy(enemy1, 1);
        } else if(vyber == 2){
            hitEnemy(enemy2, 2);
        } else {
        hitEnemy(enemy3, 3);
    }
    } else if (enemy1.hp > 0) {
        hitEnemy(enemy1, 1);
    } else if (enemy2.hp > 0){
        hitEnemy(enemy2, 2);
    } else if (enemy3.hp > 0){
        hitEnemy(enemy3, 2);
    }
    break;
    case 2: 
    if((enemy1.hp > 0 && enemy2.hp > 0) || (enemy2.hp > 0 && enemy3.hp > 0) || (enemy1.hp > 0 && enemy3.hp > 0)){
    cout << "Střelíš:\n";
    if(enemy1.hp > 0) {
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    }
    if(enemy2.hp > 0) {
        cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    }
    if(enemy3.hp > 0) {
    cout << "Nepřítele 3? (" << enemy3.hp << ")\n";
    }
    if(enemy3.hp <= 0){
        vyber=getVyber(1, 2);
    } else if(enemy1.hp <= 0) {
        vyber=getVyber(2, 3);
    } else {
        vyber=getVyber(1, 3);
    }
    if(enemy2.hp <= 0 && vyber == 2){vyber=3;}
        if(vyber == 1){
            hipEnemy(enemy1, 1);
        } else if(vyber == 2){
            hipEnemy(enemy2, 2);
        } else {
        hipEnemy(enemy3, 3);
    }
    } else if (enemy1.hp > 0) {
        hipEnemy(enemy1, 1);
    } else if (enemy2.hp > 0){
        hipEnemy(enemy2, 2);
    } else if (enemy3.hp > 0){
        hipEnemy(enemy3, 2);
    }
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
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
    if (rand()%10<6) {
        enemyHit(enemy2, 2);
    } else {
        enemyHip(enemy2, 2);
    }
}
if(enemy3.hp > 0) {
    cout << "3. nepřítel na řadě";
    if (rand()%10<7) {
        enemyHit(enemy3, 3);
    } else {
        enemyHip(enemy3, 3);
    }
}
}
getGold(cash);
getXp();
getGold(cash);
getXp();
getGold(cash);
getXp();

cout << "Šel ses kouknou do vozu co sebou měli a našel si pár věcí na lehké ošetření.";
doHeal(60);
heal[1]+=2;
enter();
cout << "Si teď uprostřed povozu a slyšíš z blízkých skal odraz klepání kopyt.";
enter();
cout << "Zbytek bandy asi měl zrovna večeři.";
enter();

enemy1.hp = 30;
enemy1.dmgStat = 3;
enemy2.hp = 40;
enemy2.dmgStat = 2;
while(enemy1.hp+enemy2.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
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
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
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
getGold(cash);
getXp();
getGold(cash);
getXp();

cout << "Už asi nikdo další nepřijede";
enter();
cout << "Nechceš to ale riskovat, tak radśi vezmeš jednoho nesplašeného koně\n a odjedeš nejrychjleji do Snake River Village";
enter();
doHeal(100);
do{
cout << "Chceš jít do nějákého obchodu?" << endl;
cout << "   1-Obchod se zbraněmi" << endl;
cout << "   2-Obchod s oblblečením" << endl;
cout << "   3-Potraviny" << endl;
cout << "   4-Jít dál" << endl;
cout << "   [Máš $ " << cash << "]" << endl;
vyber=getVyber(1,4);

switch (vyber) {                                                                        // zbrane
    case 1 :
    do{
        cout << "Dnešní nabídka:\n";
        cout << "1. $850 Carabine (2 dmg, 2 acc)\n";
        cout << "2. $800 Winchester Shotgun (2 dmg, 1 acc)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
            if (cash>=850){
                cash-=850;
                getZbran(5);
                cout << "+Carabine\n";
                cout<<"Máš $" << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($" << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=800){
                cash-=800;
                getZbran(6);
                cout << "+Winchester Shotgun\n";
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
        cout << "1. $570 Kovový Plát (+2 Hp)\n";
        cout << "2. $420 Pozlacený Pásek (+1 Hp)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
                if(checkObleceni(4, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=570){
                cash-=570;
                getObleceni(5, clothes);
                cout << "+Tranch Coat\n";
                cout<<"Máš $" << cash << " a " << player.hpStat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($ " << cash << ")\n";
            }
        break;
        case 2:
        if(checkObleceni(1, clothes)){
            cout << "Už máš tenhle kus oblečení.\n";
        }else if (cash>=420){
                cash-=420;
                getObleceni(6, clothes);
                cout << "+Pozlacený Pásek\n";
                cout<<"Máš $" << cash << " a " << player.hpStat << "hp levl.\n";
            }else{
                cout<<"Nemáš dost peněz! ($ " << cash << ")\n";
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
        cout << "1. $ 150 Zavaŕovaný Ananas (+25 % max hp)\n";
        cout << "2. $ 350 Marinované Hovézí (+100 % max hp)\n";

    vyber=getVyber(1,2);
        
    switch (vyber) {
        case 1:
            if (cash>=150){
                cash-=150;
                ++heal[vyber];
                cout << "+Zavaŕovaný Ananas\n";
                cout<<"Máš $ " << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($ " << cash << ")\n";
            }
        break;
        case 2:
         if (cash>=350){
                cash-=350;
                ++heal[vyber];
                cout << "+Marinované Hovézí\n";
                cout<<"Máš $ " << cash << ".\n";
            }else{
                cout<<"Nemáš dost peněz! ($ " << cash << ")\n";
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

case 4:
cout << "Note: Tohle je poslední vesnice předkoncem\n   Vážně chceś pokračovat?";
opakovat=getAn();
if(opakovat == 'n'){
    vyber=1;
}
break;

default : 
        cout << "----------------------------\n\n\n";
        cout << "Spatny Input: RESTARTUJ HRU!\n\n\n";
        cout << "----------------------------\n";
    break;
}
}while(vyber != 4);

cout << "Pokračuješ se svým koněm po Grand Tetonu";
enter();
cout << "Najednou z křový na tebe vybéhnou dva zjevné hlídači osady.";
enter();
cout << "Jeden se tě se zbraní v ruce ptá:";
enter();
cout << "CO TADY CHCEŠ??";
enter();
cout << "Ty ale víš co chceš takže rychle skočíš za kámen a necháś koné v běhnout mezi ně,\n aby si mohl mít první tah ty";
enter();

enemy1.hp = 30;
enemy1.dmgStat = 3;
enemy2.hp = 40;
enemy2.dmgStat = 2;
while(enemy1.hp+enemy2.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
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
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
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

cout << "Teď musíš jít co nejdřív dovnitř osady než se na tebe sletí zbytek klanu.";
enter();
cout << "Už ale po pár metrech na tebe béží nějaký nasvalený hovado s obrovskou puškou.";
enter();

enemy1.hp = 80;
enemy1.dmgStat = 4;
while(enemy1.hp > 0 && player.hp > 0) {  //miniboss2
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřítel má: " << enemy1.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
        hitEnemy(enemy1, 1);
    break;
    case 2:
        hipEnemy(enemy1, 1);
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
}
if(enemy1.hp > 0) {
    cout << "Nepřítel na řadě";
    if (rand()%10<7) {
        enemyHip(enemy1, 1);
    } else {
        enemyHit(enemy1, 1);
    }
}
}
getXp();
getXp();

cout << "Našel si u něj nějáký rum, který ti pomohl se oklepat z ran.";
doHeal(35);
enter();
cout << "Utíkáš rychle dál a slyšíš jak v dálce povykují nějéjáké dalśí hlasy.";
enter();
cout << "Když přiběhneš blíž tak slyšíš jen jednoho jak řve:\n          Uchraňte posla boží, ať se ho nic ani nedotkne.";
enter();
cout << "Vidíš jak schvávají někoho do Chaty u skály za osadou a sbíhají se okolo tebe\n a ty se dáváś do krytí.";
enter();

enemy1.dmgStat = 4;
enemy1.hp = 40;
enemy2.dmgStat = 3;
enemy2.hp = 50;
enemy3.dmgStat = 2;
enemy3.hp = 60;

cout << "Začínáš.";
enter();

while(enemy1.hp+enemy2.hp+enemy3.hp > 0 && player.hp > 0) {
cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřátelé mají: " << enemy1.hp << "a " << enemy2.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
if((enemy1.hp > 0 && enemy2.hp > 0) || (enemy2.hp > 0 && enemy3.hp > 0) || (enemy1.hp > 0 && enemy3.hp > 0)){
    cout << "Střelíš:\n";
    if(enemy1.hp > 0) {
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    }
    if(enemy2.hp > 0) {
        cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    }
    if(enemy3.hp > 0) {
    cout << "Nepřítele 3? (" << enemy3.hp << ")\n";
    }
    if(enemy3.hp <= 0){
        vyber=getVyber(1, 2);
    } else if(enemy1.hp <= 0) {
        vyber=getVyber(2, 3);
    } else {
        vyber=getVyber(1, 3);
    }
    if(enemy2.hp <= 0 && vyber == 2){vyber=3;}
        if(vyber == 1){
            hitEnemy(enemy1, 1);
        } else if(vyber == 2){
            hitEnemy(enemy2, 2);
        } else {
        hitEnemy(enemy3, 3);
    }
    } else if (enemy1.hp > 0) {
        hitEnemy(enemy1, 1);
    } else if (enemy2.hp > 0){
        hitEnemy(enemy2, 2);
    } else if (enemy3.hp > 0){
        hitEnemy(enemy3, 2);
    }
    break;
    case 2: 
    if((enemy1.hp > 0 && enemy2.hp > 0) || (enemy2.hp > 0 && enemy3.hp > 0) || (enemy1.hp > 0 && enemy3.hp > 0)){
    cout << "Střelíš:\n";
    if(enemy1.hp > 0) {
    cout << "Nepřítele 1? (" << enemy1.hp << ")\n";
    }
    if(enemy2.hp > 0) {
        cout << "Nepřítele 2? (" << enemy2.hp << ")\n";
    }
    if(enemy3.hp > 0) {
    cout << "Nepřítele 3? (" << enemy3.hp << ")\n";
    }
    if(enemy3.hp <= 0){
        vyber=getVyber(1, 2);
    } else if(enemy1.hp <= 0) {
        vyber=getVyber(2, 3);
    } else {
        vyber=getVyber(1, 3);
    }
    if(enemy2.hp <= 0 && vyber == 2){vyber=3;}
        if(vyber == 1){
            hipEnemy(enemy1, 1);
        } else if(vyber == 2){
            hipEnemy(enemy2, 2);
        } else {
        hipEnemy(enemy3, 3);
    }
    } else if (enemy1.hp > 0) {
        hipEnemy(enemy1, 1);
    } else if (enemy2.hp > 0){
        hipEnemy(enemy2, 2);
    } else if (enemy3.hp > 0){
        hipEnemy(enemy3, 2);
    }
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
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
    if (rand()%10<6) {
        enemyHit(enemy2, 2);
    } else {
        enemyHip(enemy2, 2);
    }
}
if(enemy3.hp > 0) {
    cout << "3. nepřítel na řadě";
    if (rand()%10<7) {
        enemyHit(enemy3, 3);
    } else {
        enemyHip(enemy3, 3);
    }
}
}

cout << "Tábořiště po posledním výstŕelu utichlo.";
enter();
cout << "Všude kolem sebe vidíš mrtvoly v různých rituálních pozicích.";
enter();
cout << "Tam si mohl skončit i ty.";
enter();
cout << "Už jen poslední věc je ten poslední spasitel.";
enter();
cout << "Všude na stěnách vidíš nápisy jako : Lid žehnej Quadraterru.";
enter();
cout << "Před chatou kde se ukrývá, ale vidíš velký oltář z klacků..";
enter();
cout << "Na něm leží mrtvola přibitá hřebíky k oltáři je ověšená řetízkem.";
enter();
cout << "Řetízek má na sobě křesadlo, lahvičku s vodou, vějíř a malou sklenici s hlínou.";
enter();
cout << "Seš si určitě jistý že se s tímto tenhle souboj vyhraješ a vydáváš se do chaty.";
enter();
cout << "Vešel si do chaty a na zemi vidíš že podlaha se skládá ze čtyř částí.";
enter();
cout << "Jedna část je jako rozorané pole, druhá je z dřevéné podlahy z podkteré vydíš se vypařovat kouř,\ntřetí je pokrytá kobercem peří a čtvrtá je mělká prohlubeň naplněná vodou.";
enter();
cout << "Uprostřed místnosti leží drobná žena.";
enter();
cout << "Chvíli udiveně koukáś, ale najednou se celá místnost osvítí\na ty vidíś jak žena uprostřed poletuje nad zemí.";
enter();
cout << "Nevíś co se děje, ale asi s tím budeš muset bojovat pomocí toho co máš.";
enter();
cout << "Si naplněn odhodláním.";
doHeal(25);
enter();
cout << "Quarterra začíná.";
enter();

boss.hpMax = 100;
boss.hpMax = 10;

while(boss.hp > 0 && player.hp > 0) {  //boss

bossAtt();

cout << "Vyber akci\n";
cout << "1. Střelit ADS\n";
cout << "2. Střelit Hip-Firem\n";
cout << "3. Menší heal ("<< heal[1] <<")\n";
cout << "4. Větší heal ("<< heal[2] <<")\n";
cout << "[Nepřítel má: " << boss.hp <<"hp]\n";

vyber=getVyber(1, 4);
switch(vyber){
    case 1:
    vyber = rand()%11 + 10 + (player.dmgStat*6);
    boss.hp -= vyber;
    cout <<"Quadraterra -" << vyber << "hp\n";
    break;
    case 2:
    if(rand()%100 + playerAcc()*5 > 40) {
    vyber = rand()%16 + 10 + (playerDmg()*4)*1.2;
    boss.hp -= vyber;
    cout << "Quadraterra -" << vyber << "hp\n";
        }
    }else {
        cout << "Vedle!\n";
    }
    break;
    case 3:
    if(heal[1]>0) {
        heal[1]-=1;
        doHeal(25);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
    case 4:
    if(heal[2]>0) {
        heal[2]-=1;
        doHeal(100);
    } else {
        cout << "Nemas heal, ale aspoň sis odpočinul.\n";
        doHeal(10);
    }
    break;
}
}
cout << "Uťal si hlavu klanu.";
enter();
cout << "Už můžeš jít v klidu spát.";
enter();
cout << "Díky za dohrání";
enter();
}