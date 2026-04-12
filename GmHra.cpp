#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>
using namespace std;

int main(){
    cout << "                                 $$$$$$ $$$$$ $$  $ $$$$$$      $$$$   $$   $$$$$$ $$$$$ $$$$$                                  " << endl;
    cout << "                                    $   $$     $ $     $        $  $   $$$  $$   $ $      $  $$                                 " << endl;
    cout << "                                    $   $$$$    $$     $        $$$$   $ $    $$   $$$$  $$  $$                                 " << endl;
    cout << "                                    $   $$     $$$     $        $  $$ $$ $$ $   $$ $     $$  $$                                 " << endl;
    cout << "                                    $   $$     $ $$    $        $   $ $$$$$ $$  $$ $     $$  $$                                 " << endl;
    cout << "                                    $   $$$$$ $@  $$   $        $$$$$ $   $ $$$$$$ $$$$$ $$$$$                                 " << endl;
    cout << "                                                                                                                                " << endl;
    cout << "                       $$$$$$$$$ $$$$$$$$    $$$$$$$$$                                          $$$$$$$$$                       " << endl;
    cout << "           $$$$$$$$$$  $$$$$$$$$ $$$$$$$$$$  $$$$$$$$$  $$$   $$$  $$$$$$$$$$ $$$$$$$$$$$ $$$$  $$$$$$$$$  $$$$   $$$           " << endl;
    cout << "           $$$    $$$  $$@         $$$   $$$  $$        $$$$ $$$$$ $$$    $$$     $$$     $$$   $$    $$$  $$$$   $$$           " << endl;
    cout << "           $$$$$$$$$$  $$          $$$  $$$$  $$        $$$$$$$$$$ $$$$$$@$$$     $$$     $$$   $$@   $$$  $$$$$  $$$           " << endl;
    cout << "           $$$  $$$    $$$$$       $$$  $$$$  $$$$$     $$$$$$$$$$ $$$$$$$$$$     $$$     $$$$  $$$   $$$  $$$$$$ $$$           " << endl;
    cout << "           $$$  $$$    $$$$$$$     $$$  $$$$  $$$$$$    $$$$$$$$$$ $$$$           $$$     $$$$  $$$   $$$  $$$ $$$$$$           " << endl;
    cout << "           $$$  $$$$   $$          $$$  $$$$  $$        $$$ $$ $$$ $$$$           $$$     $$$$  $$$   $$$  $$$  $$@$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$        $$$ $$ $$$ $$$$           $$$     $$$$  $$$    $$  $$$  $$$$$           " << endl;
    cout << "           $$$   $$$   $$          $$$   $$$  $$      @ $$$    $$$ $$$$           $$$     $$$$  $$$    $$  $$$   $$$$           " << endl;
    cout << "           $$$    $$$  $$$$$$$$$  $$$$$$$$$$  $$$$$$$$$ $$$    $$$ $$$$           $$$     $$$$  $$$$$$$$$  $$$    $$$           " << endl;
    cout << "           $$$    @$$            @$$$$$$$$              $$$    $$  $$$$           $$$     $$$   $$$$$$$$$   $$    $$$           " << endl;
int dmg_stat;
int acc_stat;
int hp_stat;
int rng_stat;
int clas = 1;
int vyber;
string classs[4]={"Gunslinger" ,"Outlaw" ,"Sherif" , "Gold Digger"};
cout << "[    ACC=presnost   ]" << endl ;
cout << "[    DMG=poskozeni  ]" << endl ;
cout << "[     HP=zivoty     ]" << endl ;
cout << "[     RNG=stesti    ]" << endl ;
cout << " |ACC|DMG|HP|RNG|" << endl;
cout << "Vyberte si postavu:" << endl;
cout << "1.       Gunslinger" << endl;
cout << "          |3|2|2|1|" << endl;
cout << "2.           Outlaw" << endl;
cout << "          |2|3|2|1|" << endl;
cout << "3.           Sherif" << endl;
cout << "          |2|2|3|1|" << endl;
cout << "4.      Gold Digger" << endl;
cout << "          |1|1|1|5|" << endl;
cout << "-------------------" << endl;
do{
do{
    if(clas<0||clas>4){
    cout << "Zadejte cisla 1,2,3 nebo 4." << endl;
    }
cin>> clas;
}while(clas<0||clas>4);
switch (clas) {
    case 1:
        cout << "Vybral is postavu " << classs[clas] << "." << endl;
        acc_stat = 3;
        dmg_stat = 2;
        hp_stat = 2;
        rng_stat = 1;
        break;
    case 2:
        cout << "Vybral is postavu " << classs[clas] << "." << endl;
        acc_stat = 2;
        dmg_stat = 3;
        hp_stat = 2;
        rng_stat = 1;
        break;
    case 3:
        cout << "Vybral is postavu " << classs[clas] << "." << endl;
        acc_stat = 2;
        dmg_stat = 2;
        hp_stat = 3;
        rng_stat = 1;
        break;
    case 4:
        cout << "Vybral is postavu " << classs[clas] << "." << endl;
        acc_stat = 1;
        dmg_stat = 1;
        hp_stat = 1;
        rng_stat = 5;
        break;
 }
 cout << "mas:" << endl;
 cout << "presnost " << acc_stat << endl;
 cout << "poskozeni " << dmg_stat << endl;
 cout << "zivoty " << hp_stat << endl;
 cout << "stesti " << rng_stat << endl;
 cout << "note: to ze mas zivozy na 3ce neznamena to ze mas 4 zivoty" << endl;
 cout << "prejes si zmenit postavu? (a/n):";
 do{
    if(vyber!=41&&vyber!=110){
        cout << endl << "zadejte a nebo n (malym)0" << endl;
    }
cin >> vyber;
}while(vyber!=41&&vyber!=110);
}while();
}