#include <stdio.h>
#include <string.h>

typedef struct{
    int year;
    int month;
    int day;
}date_t;

typedef struct{
    double capacity;
    double level;
}gas_t;

typedef struct{
    char make[20];
    char model[20];
    int odomenter;
    date_t manu_date;
    date_t pur_date;
    gas_t tank;
}auto_t;

void print_car(auto_t car)
{
    printf("Make: %s\n",car.make);
    printf("Model: %s\n",car.model);
    printf("Odometer: %d\n",car.odomenter);
    printf("Manufacture Date: %d/%d/%d\n",car.manu_date.year,car.manu_date.month,car.manu_date.day);
    printf("Purchase Date: %d/%d/%d\n",car.pur_date.year,car.pur_date.month,car.pur_date.day);
    printf("Tank: %.1lf/%.1lf (%2.1lf%%)\n\n",car.tank.level,car.tank.capacity,(car.tank.level/car.tank.capacity)*100);
}

int 
main(void)
{
    char model[20], make[20];
    int odometer;
    int m_year,m_month,m_day;
    int p_year,p_month,p_day;
    int capacity,level;

    auto_t new_car;
    gas_t tank;
    date_t manu;
    date_t purc;

    printf("Enter make: ");
    scanf("%s",new_car.make);
    printf("Enter model: ");
    scanf("%s",new_car.model);
    printf("Enter Odometer Reading: ");
    scanf("%d",&new_car.odomenter);
    printf("Enter manufacture date (YY MM DD): ");
    scanf("%d %d %d",&manu.year,&manu.month,&manu.day);
    printf("Enter purchase date (YY MM DD): ");
    scanf("%d %d %d",&purc.year,&purc.month,&purc.day);
    printf("Enter tank capacity and level: ");
    scanf("%lf %lf",&tank.capacity,&tank.level);
    printf("\n\n");

    new_car.tank = tank;
    new_car.manu_date = manu;
    new_car.pur_date = purc;

    print_car(new_car);

    return 0;
}