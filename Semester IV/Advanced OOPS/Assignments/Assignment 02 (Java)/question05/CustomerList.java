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

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

public class CustomerList {
    private ArrayList<Customer> customers = new ArrayList<>();
    private Scanner scan = new Scanner(System.in);
    private static int count = 0;
    private final double[] CREDIT_LIMIT = {50000,70000};

    public void AddNewCustomer()
    {
        String name;
        String phone_number;

        Customer temp = new Customer();
        try{
            System.out.print("\n\nName         : ");
            name = scan.nextLine();
            System.out.print("Phone number : ");
            phone_number = scan.nextLine();
            System.out.print("Is privileged (Y/n)? : ");
            String s = scan.nextLine();

            temp.SetValues(name, phone_number, s.equalsIgnoreCase("y"), count);
        }catch(InputMismatchException ex)
        {
            ex.printStackTrace();
            System.out.println("Invalid input");
        }
        customers.add(temp);
        // temp = null;
    }

    public boolean ApplyForLoan()
    {
        String s = scan.nextLine();
        double loanAmt = 0;
        boolean found = false;

        for (Customer c : customers)
        {
            if(c.SearchCustomerID(s))
            {
                found = true;
                try{
                    System.out.println("Current loan amount : " + c.CurrentLoan());

                    System.out.print("Enter loan to be opted : ");
                    loanAmt = scan.nextDouble();
                    if (c.IsPrevileged() && (loanAmt + c.CurrentLoan()) < CREDIT_LIMIT[1])
                    {
                        c.UpdateLoanAmounr(loanAmt);
                    }
                    else if (!c.IsPrevileged() && (loanAmt + c.CurrentLoan()) < CREDIT_LIMIT[0])
                    {
                        c.UpdateLoanAmounr(loanAmt);
                    }else{
                        System.out.println("Loan amount not available");
                        return false;
                    }

                }catch(InputMismatchException ex)
                {
                    System.out.println("Invalid input");
                    return false;
                }
                // break;
            }
        }

        if(!found)
        {
            System.out.println("Invalid customer id");
            return false;
        }
     return true;
    }

    public void CheckCreditLimit()
    {
        System.out.print("Enter customer id : ");
        String s = scan.nextLine();
        boolean found = false;

        for (Customer c : customers)
        {
            if(c.SearchCustomerID(s))
            {
                found = true;
                if(c.IsPrevileged())
                {
                    System.out.println("Credit limit : " + CREDIT_LIMIT[1]);
                }else{
                    System.out.println("Credit limit : " + CREDIT_LIMIT[0]);
                }
                break;
            }
        }
        if(!found)
        {
            System.out.println("Customer not found");
        }
    }

    public void CheckCurrentLoanAmount()
    {
        System.out.print("Enter customer id : ");
        String s = scan.nextLine();
        boolean found = false;

        for (Customer c : customers)
        {
            if(c.SearchCustomerID(s))
            {
                found = true;
                System.out.println("Current loan amount : " + c.CurrentLoan());
                break;
            }
        }
        if(!found)
        {
            System.out.println("Customer not found");
        }
    }

    public void LoanThatCanBeSeeked()
    {
        System.out.print("Enter customer id : ");
        String s = scan.nextLine();
        boolean found = false;

        for (Customer c : customers)
        {
            if(c.SearchCustomerID(s))
            {
                found = true;
                if(c.IsPrevileged())
                {
                    System.out.println("Credit available : " + (CREDIT_LIMIT[1] - c.CurrentLoan()));
                }else{
                    System.out.println("Credit available : " + (CREDIT_LIMIT[0] - c.CurrentLoan()));
                }
                break;
            }
        }
        if(!found)
        {
            System.out.println("Customer not found");
        }
    }

    public void ShowAllCustomers() // no 13, only for debugging
    {
        for (Customer c:
             customers) {
            c.ShowDetails();
        }
    }
}
