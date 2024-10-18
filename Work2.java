package ClassWorks;

import java.util.Scanner;

class Student {
    String name;

    public Student(String name){
        this.name = name;
    }

    public boolean hasRoots(double a, double b, double c){
        double delta = b * b - 4 * a * c;
        return delta >= 0;
    }

    public void findRoots(double a, double b, double c){
        double delta = b * b - 4 * a * c;
        if(delta > 0){
            double root1 = (-b + Math.sqrt(delta)) / (2 * a);
            double root2 = (-b - Math.sqrt(delta)) / (2 * a);
            System.out.println("The modified equation has two real roots： " + root1 + " and " + root2 + ".");
        }else if(delta == 0) {
            double root = -b/ (2 * a);
            System.out.println("The modified equation has only one real root: " + root);
        }else{
            System.out.println("The modified equation does not have real roots.");
        }
    }
}

public class Work2{

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter student's name: ");
        String studentName = scanner.nextLine();

        Student student = new Student(studentName);

        System.out.print("Enter coefficients a, b, c (separated by space)");
        String input = scanner.nextLine();
        String[] coefficients = input.split("\\s+");
        double a = Double.parseDouble(coefficients[0]);
        double b = Double.parseDouble(coefficients[1]);
        double c = Double.parseDouble(coefficients[2]);

        if (student.hasRoots(a, b, c)) {
            student.findRoots(a, b, c);
        }else{
            System.out.println("The modified equation does not have real roots.");
        }
        scanner.close();
    }
}
