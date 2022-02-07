#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Regular text
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"

//Regular background
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"

//Reset
#define COLOR_RESET "\e[0m"

int getFirstDay(int year){
  int d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
  return d;
}

int main(){   
    int jour, mois, an;
    int year, month, day, daysInMonth, weekDay=0, firstDay;
    int newDate;
    time_t now = time(NULL);
// date
while(newDate==1){
        printf("========================================================================\n");
        printf("\t  Saisir une date au format jj mm aaaa: ");
        int scan=scanf(" %d %d %d", &jour, &mois, &an);        
        if(scan!=3){
            printf("\t  Failure ce n'est pas des chiffres\n");
            exit(EXIT_FAILURE);
            }
        else if(jour<32 && mois<13 && an<3000)
            printf("\t  Date : %d/%d/%d", jour, mois, an);
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
    //--------------------------------------------------
        year=an;
        char *months[]={"January","February","  March "," April "," May "," June "," July ","August","September","October","November","December"};
        int monthDay[]={31,28,31,30,31,30,31,31,30,31,30,31};
    // year bisexstile
        if((year%4==0&&year%100!=0)||year%400==0)
            monthDay[1]=29;
            firstDay=getFirstDay(year);
        for(month=0;month<12;month++){ // boucle sur les mois de l'année
            printf("\n\n\t  =================== %s %d ====================\n",months[month],year);
            printf("\n\t  Sun\t  Mon\t  Tue\t  Wed\t  Thu\t  Fri\t  Sat\n");
        
            for(weekDay=0;weekDay<firstDay;weekDay++) 
                printf("\t     "); 
            daysInMonth=monthDay[month];// chaque mois avec les jours correspondant
            for(day=1;day<=daysInMonth;day++){ 
                if(day==jour && (month+1)==mois){
                printf(RED);
                printf("\t%5d",day); //chiffre décimal sur cinq caractères
                printf(COLOR_RESET);
                }
                else 
                printf("\t%5d",day); 
                if(++weekDay>6){// de 0 a 6 Sunday ->Satuday
                printf("   \n"); // on saute une ligne
                weekDay=0;
                }
            firstDay=weekDay;
            }
        }
       printf("\nVoulez vous saisir une autre date ? 1[Yes] 2[No]: ");
       scanf("%d",&newDate);
       printf("\n");
    }
   printf("\n========================================================================\n");
}
