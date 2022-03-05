package com.company;
import java.util.Scanner;
abstract class Begin {
    String num1, num2;
    String[] A1; // А потому что array
    String[] A2;
    int n1, n2, l;
    public Begin (String num1, String num2){
        this.num1 = num1;
        this.num2 = num2;
        A1 = num1.split("/");
        A2 = num2.split("/");
    }
}
class Num extends Begin {
    int x[] = new int[4];

    public Num (String num1, String num2) {
        super(num1, num2);

        for (int i=0; i<2; i++) {
            x[0] = Integer.valueOf(A1[i]); //числитель первого
            i++;
            x[1] = Integer.valueOf(A1[i]); //знаменатель второго
            i++;
        }
        for (int i=0; i<2; i++) {
            x[2] = Integer.valueOf(A2[i]); //числитель второго
            i++;
            x[3] = Integer.valueOf(A2[i]); //знаменатель второго
            i++;
        }
    }
    //исключение несуществующих дробей
    public void Ex() {
        if (x[1]==0 || x[3]==0) {
            System.out.println("Знаменатель равен 0, так нельзя");
            System.exit(0);
        }
    }
    //сложение
    public void addition() {
        if (x[1] == x[3]) {
            n1 = x[0] + x[2];
            n2 = x[1];
            System.out.println(n1+"/"+n2);
        } else {
            n1 = x[0] * x[3] + x[2] * x[1];
            n2 = x[1] * x[3];
            System.out.println(n1+"/"+n2);
        }
    }
    //вычитание
    public void substraction(){
        if(x[1]==x[3]){
            n1 = x[0]-x[2];
            n2 = x[1];
            System.out.println(n1+"/"+n2);
        }
        else {
            n1 = x[0] * x[3] - x[2] * x[1];
            n2 = x[1] * x[3];
            System.out.println(n1+"/"+n2);
        }
    }
    //умножение
    public void mult() {
        n1 = x[0] * x[2];
        n2 = x[1] * x[3];
        System.out.println(n1+"/"+n2);
    }
    //деление
    public void devision(){
        n1 = x[0] * x[3];
        n2 = x[1] * x[2];
        System.out.println(n1+"/"+n2);
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Первая дробь: ");
        String f = in.nextLine();
        System.out.println("Вторая дробь: ");
        String s = in.nextLine();
        in.close();
        Num n = new Num (f,s);
        n.Ex();
//вывод решения
        System.out.print("Сумма: ");
        n.addition();
        System.out.print("Разность: ");
        n.substraction();
        System.out.print("Произведение: ");
        n.mult();
        System.out.print("Частное: ");
        n.devision();
    }
}