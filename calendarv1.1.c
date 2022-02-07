
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getFirstDay(int year){
  int d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int main(){   
    int jour, mois, an;
    int year, month, day, daysInMonth, weekDay=0, startingDay;
    time_t now = time(NULL);
    printf("===========================================================================\n");
    printf("\t  saisir une date au format jj mm aaaa: ");
    scanf(" %d %d %d", &jour, &mois, &an);
    if(jour<31 && mois<13 && an<3000)
       printf("\t  Date : %d/%d/%d",jour,mois,an);
    else{
        printf("\t  Date incorrect!!!");  
        struct tm *local = localtime(&now);     
        jour = local->tm_mday;          
        mois = local->tm_mon + 1;     
        an = local->tm_year + 1900;  
        //printf("%s", ctime(&now));
        printf("\n\t  Date du jour: %02d/%02d/%d\n", jour, mois, an);
        printf("\t  ------------------------");
       }
    year=an;
    char *months[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
    int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
 // year bisexstile
    if((year%4==0&&year%100!=0)||year%400==0)
        monthDay[1]=29;
        startingDay=getFirstDay(year);
    for(month=0;month<12;month++){ // boucle sur les mois de l'année
        printf("\n\n\t  =================== %s %d ====================\n",months[month],year);
        printf("\n\t  Sun\t  Mon\t  Tue\t  Wed\t  Thu\t  Fri\t  Sat\n");

        for(weekDay=0;(weekDay<startingDay);weekDay++) 
            printf("\t     ");

        
        daysInMonth=monthDay[month];// chaque mois avec les jours correspondant
        for(day=1;day<=daysInMonth;day++){ 
            printf("\t%5d",day); //chiffre décimal sur cinq caractères
        
        if(++weekDay>6){// de 0 a 6 Sunday ->Satuday
            printf("   \n"); // on saute une ligne
            weekDay=0;
            }
        startingDay=weekDay;
       }
    }
   printf("\n===========================================================================\n");
}