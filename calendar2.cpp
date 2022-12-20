/********************
* Рексиус Анастасия *
* ПИ-221            *
* Календарь         *
*********************/

#include <bits/stdc++.h>

using namespace std;

string getMonthName(int monthNumber) {
  string months[] = {"Январь", "Февраль", "Март",
                     "Апрель", "Май", "Июнь",
                    };
  return (months[monthNumber]);
}

string getSecondMonthName(int monthNumber) {
  string months[] = {"Июль", "Август", "Сентябрь",
                     "Октрябрь", "Ноябрь", "Декабрь"
                    };
  return (months[monthNumber]);
}

int numberOfDays(int monthNumber, int year) {
  enum daysInMonth { monthWithTwentyDays = 20 };
  
  if (monthNumber == 0) {                  //январь
    return (monthWithTwentyDays);
  }
  if (monthNumber == 1) {                 //февраль 
    return (monthWithTwentyDays);
  }
  if (monthNumber == 2) {                 //март
    return (monthWithTwentyDays);
  }
  if (monthNumber == 3) {                //апрель
    return (monthWithTwentyDays);
  }
  if (monthNumber == 4) {                //май
    return (monthWithTwentyDays);
  }
  if (monthNumber == 5) {                //июнь
    return (monthWithTwentyDays);
  }
  if (monthNumber == 6) {                //июль
    return (monthWithTwentyDays);
  }
  if (monthNumber == 7) {                //август
    return (monthWithTwentyDays);
  }
  if (monthNumber == 8) {                //сентябрь
    return (monthWithTwentyDays);
  }
  if (monthNumber == 9) {                //октябрь
    return (monthWithTwentyDays);
  }
  if (monthNumber == 10) {               //ноябрь
    return (monthWithTwentyDays);
  }
  if (monthNumber == 11) {              //декабрь
    return (monthWithTwentyDays);
  }
  return 0;
}
 
void printCalendar(int year) { //вывод заданного года
  printf ("         Календарь - %d\n\n", year);
  int days;
  int current = 0; 
  int maxCountOfMonths = 12; 
  int maxCountOfDays = 4;
  int amountOfDaysInWeek, amountOfDaysInWeek2; 
  for (int indexMonth = 0; indexMonth < 6; ++indexMonth) { 
    days = numberOfDays (indexMonth, year);
    cout << left << "\n  --------" << getMonthName (indexMonth) << "--------"
         << right << setw(20) << "--------" << getSecondMonthName (indexMonth) << "-------\n"; //выводится месяц
    cout << left << "   Пн   Вт   Ср   Чт"
         << right << setw(45) << "   Пн   Вт   Ср   Чт\n"; //выводятся дни
    for (amountOfDaysInWeek = 0; amountOfDaysInWeek < current; ++amountOfDaysInWeek) { 
      cout << "     ";
    }
    
    int indexDay2 = 1; 
    for (int indexDay = 1; indexDay <= days; ++indexDay) { //месяца слева
      if (amountOfDaysInWeek >= maxCountOfDays) {
        amountOfDaysInWeek = 0;
        
        cout << "\t\t    "; //отступы между столбцами
        if (indexDay2 == 1) {
          for (amountOfDaysInWeek2 = 0; amountOfDaysInWeek2 < current; ++amountOfDaysInWeek2) { 
            cout << "     "; 
          }
        }
        
        for ( ; indexDay2 <= days; ++indexDay2) { //месяца справа 
          if (amountOfDaysInWeek2 >= maxCountOfDays) {
            amountOfDaysInWeek2 = 0;
            cout << "\n";
            break; //прервать вывод, потому что след месяц снова слева 
          }
          printf("%5d", indexDay2);
          ++amountOfDaysInWeek2;
        }
      }
      printf("%5d", indexDay);
      ++amountOfDaysInWeek;
    }
    
    for (int dayIndex = 0; dayIndex <= (maxCountOfDays - amountOfDaysInWeek - 1); ++dayIndex) { //отступы для
      cout << "     ";                                                                          //последней недели правого 
    }                                                                                           //столбца 
    cout << "\t\t    ";                                                 
    
    for ( ; indexDay2 <= days; ++indexDay2) { //последняя неделя правых месяцев
      if (amountOfDaysInWeek2 >= maxCountOfDays) {
        amountOfDaysInWeek2 = 0;
        cout << "\n";
        break;
      }
      printf("%5d", indexDay2);
      ++amountOfDaysInWeek2;
    }
    
    if (amountOfDaysInWeek) { 
      cout << "\n";
    }
  } 
}

int main() {
  int year = 0;
  cout << "Введите год: ";
  cin >> year;
  cout << endl;
  printCalendar(year);
}