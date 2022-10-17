#include <stdio.h>

//проверка на ввод новой СС
int input_new_number_system() {
    int arg;
    printf("Enter a new number system between 2 and 16:\t");
    while (scanf("%d", &arg)!=1 || (arg<2 || arg>16)){
        while (getchar() != '\n');
        printf("Error! Please try again!\nEnter:\t");
    }
    return arg;
}

//проверка на ввод числа для преобразование в другую СС
double input_number(){
	double arg;
    printf("Enter a new number:\t");
    while (scanf("%lf", &arg)!=1 || arg==0){
        while (getchar() != '\n');
        printf("Error! Please try again!\nEnter:\t");
    }
    return arg;
}

//определение размера массива для целой части
//для new_number_system_for_base
int size_for_massive(int arg, int base){
	int i = 0, j;
	for(j = arg ; j <= base ; i++) j *= arg;
	return i;
}

//получение целой части числа в новой СС 
void new_number_system_for_base(int base, int arg){
	int size = size_for_massive(arg, base);
	if (size==0) printf("%d", 0);
	int new_base[size], i;
	for (i=0; base != 0; i++){
		new_base[i] = base % arg;
		base /= arg;
	}
	for (i-=1; i>=0; i--) printf("%X", new_base[i]);
}

//получение дробной части числа в новой СС
void new_number_system_for_fraction(double fraction, int arg)
{
	int i;
	for(i = 0;(fraction != (int)fraction) && (i < 6); i++){
		fraction *= arg;
		printf("%X", (int)fraction);
		fraction -= (int)fraction;}
}

int main(){
	int arg = input_new_number_system();
	double num = input_number();
 	double fraction = num - (int)num; //дробная часть
 	int base = (int)num; //целая часть
 	new_number_system_for_base(base, arg);//СС целой
 	if (fraction!=0.0000000) printf(".");//разделитель
 	new_number_system_for_fraction(fraction, arg);//СС дробной
 	printf("\n");
	return 0;
}