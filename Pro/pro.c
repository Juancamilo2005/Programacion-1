#include <stdio.h>
#include <math.h>

float calculate_monthly_payment(float principal, float rate, int time) {
    float monthly_interest = rate / 12;
    return principal * (monthly_interest / (1 - pow(1 + monthly_interest, -time * 12)));
}

int main(int argc, char const *argv[]) {
    int time, i;
    float loan_amount, interest, monthly_payment, balance, total_interest, yearly_interest, monthly_interest;
    printf("Ingrese el tiempo: ");
    scanf("%d", &time);
    printf("Ingrese el monto del préstamo: ");
    scanf("%f", &loan_amount);
    printf("Ingrese la tasa de interés: ");
    scanf("%f", &interest);


    monthly_interest = interest / 12;
    total_interest = 0;
    balance = loan_amount;

    printf("Año\tInteres\tPago mensual\n");
    for (i = 1; i <= time; i++) {
        yearly_interest = balance *(monthly_interest/100);
        total_interest += yearly_interest;
        monthly_payment = calculate_monthly_payment(loan_amount, interest, time);
        balance -= monthly_payment - yearly_interest;
        printf("%d\t%.2f\t%.2f\n", i, yearly_interest, monthly_payment);  
    }

    printf("El total de intereses a pagar es: %.2f\n", total_interest);

    return 0;
}
