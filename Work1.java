package ClassWorks;

import java.util.Scanner;

class Customer{
    String name;
    String accountNumber;
    double balance;
    Customer(String name,String accountNumber,double balance){
        this.name = name;
        this.accountNumber = accountNumber;
        this.balance = balance;
    }
    void deposit(double amount){
        if(amount >= 0){        //确保进去的值是大于等于0的
            balance += amount;
        }
    }
    void withdraw(double amount){
        if(amount >= 0){
            if(balance >= amount){
                balance -= amount;
            }else{
                System.out.println("Withdrawal failed:Insufficient funds!");
            }
        }
    }
    void checkBalance(){
        System.out.println("Account balance: "+balance);
    }
    String getName(){
        return name;
    }
//    void setName(String name){
//        this.name = name;
//    }
//    String getAccountNumber(){
//        return accountNumber;
//    }
//    void setAccountNumber(String accountNumber){
//        this.accountNumber = accountNumber;
//    }
//    double getBalance(){
//        return balance;
//    }
    void setBalance(double balance){
        this.balance = balance;
    }
}

public class Work1 {
//    private static void clearScreen() {         本来是想弄清屏的idea里面显示不出来就注释掉了，在清屏后面写进去的代码也没有添加清屏操作
//        System.out.print("\033[H\033[2J");
//        System.out.flush();
//    }
private static void displayMenu() {              //菜单
    System.out.println("+--------------------------------------------------+");
    System.out.println("| Banking System Menu                              |");
    System.out.println("| 1. Check Balance                                 |");//剩余资金
    System.out.println("| 2. Deposit                                       |");//存钱
    System.out.println("| 3. Withdraw                                      |");//取钱
    System.out.println("| 4. Exit                                          |");//退出
    System.out.println("+--------------------------------------------------+");
}
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please enter customer's name: ");//输入用户名
        String name = scanner.nextLine();

        System.out.print("Please enter bank account number: ");//输入账号
        String accountNumber = scanner.nextLine();

        Customer customer = new Customer(name, accountNumber, 0.0);

//        clearScreen();
        System.out.println("Welcome " + customer.getName() + ", you have entered the system.");//欢迎界面
        System.out.print("Please enter initial balance(enter 0 to skip): ");//输入初始资金
        double initialBalance = scanner.nextDouble();
        if(initialBalance > 0){//判断
            customer.setBalance(initialBalance);
        }


        boolean running = true;
        while(running) {
            displayMenu();
            System.out.print("Enter your choice (1-4): ");
            int choice;
            while (true) {
                if (scanner.hasNextInt()) {
                    choice = scanner.nextInt();
                    if (choice >= 1 && choice <= 4) {
                        break;
                    } else {
                        System.out.println("Invalid choice. Please enter a number between 1 and 4.");
                    }
                } else {
                    System.out.println("Invalid input. Please enter a number.");
                    scanner.next();
                }
                scanner.nextLine();
                displayMenu();
                System.out.print("Enter your choice (1-4): ");
            }
            switch (choice) {
                case 1:
                    customer.checkBalance();
                    break;
                case 2:
                    System.out.print("Please enter deposit amount(enter 0 to finish): ");
                    while (!scanner.hasNextDouble()) {
                        System.out.println("Invalid input. Please enter a valid number.");
                        scanner.next();
                    }
                    double depositAmount = scanner.nextDouble();
                    customer.deposit(depositAmount);
                    break;
                case 3:
                    System.out.print("Please enter withdrawal amount(enter 0 to finish): ");
                    while (!scanner.hasNextDouble()) {
                        System.out.println("Invalid input. Please enter a valid number.");
                        scanner.next();
                    }
                    double withdrawAmount = scanner.nextDouble();
                    customer.withdraw(withdrawAmount);
                    break;
                case 4:
                    System.out.println("Exiting the system. Goodbye!");
                    running = false;
                    break;
                default:
                    System.out.println("Invalid choice. Please enter a number between 1 and 4.");
            }

//            clearScreen();
//            System.out.println("Welcome " + customer.getName() + ", you have entered the system.");
        }
        scanner.close();
    }
}

//        Customer customer = new Customer("Alice","123456789",1000.0);
//        customer.deposit(500.0);
//        customer.withdraw(300.0);
//        customer.checkBalance();
