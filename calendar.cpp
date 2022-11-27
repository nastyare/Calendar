/********************
* Рексиус Анастасия *
* ПИ-221            *
* Календарь         *
*********************/

#include <bits/stdc++.h>

using namespace std;

int dayNumber(int day, int month, int year) {
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  year -= month < 3;
  return ( year + year/4 - year/100 +
           year/400 + t[month-1] + day) % 7;
}

string getMonthName(int monthNumber) {
  string months[] = {"Январь", "Февраль", "Март",
                     "Апрель", "Май", "Июнь",
                     "Июль", "Август", "Сентябрь",
                     "Октрябрь", "Ноябрь", "Декабрь"
                    };
  return (months[monthNumber]);
}

int numberOfDays(int monthNumber, int year) {
  enum daysInMonth {februaryInNotLeapYear = 28, februaryInleapYear, daysInFourMonths, daysInSevenMonths};
  
  if (monthNumber == 0) {                  //январь
      return (daysInSevenMonths);
  }
  if (monthNumber == 1) {                 //февраль 
      if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0) {
          return (februaryInleapYear);
      }
      else {
          return (februaryInNotLeapYear);
      }
  }
  if (monthNumber == 2) {                 //март
        return (daysInSevenMonths);
  }
  if (monthNumber == 3) {                //апрель
        return (daysInFourMonths);
  }
  if (monthNumber == 4) {                //май
        return (daysInSevenMonths);
  }
  if (monthNumber == 5) {                //июнь
        return (daysInFourMonths);
  }
  if (monthNumber == 6) {                //июль
        return (daysInSevenMonths);
  }
  if (monthNumber == 7) {                //август
        return (daysInSevenMonths);
  }
  if (monthNumber == 8) {                //сентябрь
        return (daysInFourMonths);
  }
  if (monthNumber == 9) {                //октябрь
        return (daysInSevenMonths);
  }
  if (monthNumber == 10) {               //ноябрь
        return (daysInFourMonths);
  }
  if (monthNumber == 11) {              //декабрь
      return (daysInSevenMonths);
  }
}
 
void printCalendar(int year) { //вывод заданного года
  printf ("         Календарь - %d\n\n", year);
  int days;
  int current = dayNumber (1, 1, year); // дни
  int maxCountOfMonths = 12; 
  int maxCountOfDays = 6; 

  for (int indexMonth = 0; indexMonth < maxCountOfMonths; indexMonth++) { 
      days = numberOfDays (indexMonth, year);
      printf("\n  -------------%s--------------\n", //выводится месяц
      getMonthName (indexMonth).c_str());
      printf("   Вс   Пн   Вт   Ср   Чт   Пт   Сб\n"); //выводятся дни недели

      int amountOfDaysInWeek;
      for (amountOfDaysInWeek = 0; amountOfDaysInWeek < current; amountOfDaysInWeek++)
          printf("     ");
 
      for (int indexDay = 1; indexDay <= days; indexDay++) {
          printf("%5d", indexDay);
          if (++amountOfDaysInWeek > maxCountOfDays) {
              amountOfDaysInWeek = 0;
              printf("\n");
          }
      }
 
      if (amountOfDaysInWeek)
          printf("\n");
 
      current = amountOfDaysInWeek;
    }
  return;
}

int main() {
    int year = 0;
    cout << "Введите год: ";
    cin >> year;
    printCalendar(year);
}
