package java_assignment.question05;

/*
Each customer of a bank has customer id, name, and current loan amount
and phone number. One can change the attributes like name, phone
number. A customer may ask for loan of certain amount. It is granted
provided the sum of current loan amount and asked amount does not
exceed credit limit (fixed amount for all customer). A customer may be a
privileged amount. For such customers credit limit is higher. Once a loan is
sanctioned necessary updates should be made. Any type of customer
should be able to find his credit limit, current loan amount and amount of
loan he can seek. Design and implement the classes.
 */

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        boolean trace = true;
        int choice = -1;
        Scanner scan = new Scanner(System.in);
        CustomerList customerList = new CustomerList();

         while(trace)
         {
             System.out.println("1 : Add new customer");
             System.out.println("2 : Apply for loan");
             System.out.println("3 : Check credit limit");
             System.out.println("4 : Check current loan amount");
             System.out.println("5 : Loan that can be seeked");
             System.out.println("0 : Exit");
             System.out.print("\n\tChoice : ");

             try{
                 choice = scan.nextInt();
             }catch(InputMismatchException ex)
             {
                 System.out.println("Invalid input");
                 choice = -1;
             }
             switch(choice){
                 case 0:
                     System.out.println("Exit initiated");
                     trace = false;
                     break;
                 case 1:
                     customerList.AddNewCustomer();
                     break;
                 case 2:
                     customerList.ApplyForLoan();
                     break;
                 case 3:
                     customerList.CheckCreditLimit();
                     break;
                 case 4:
                     customerList.CheckCurrentLoanAmount();
                     break;
                 case 5:
                     customerList.LoanThatCanBeSeeked();
                     break;
                 case 13:
                     customerList.ShowAllCustomers();
                     break;
                 default:
                     System.out.println("invalid choice");
                     break;
             }
         }
    }
}
