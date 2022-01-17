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

import java.awt.*;
import java.util.Calendar;
import java.util.Locale;

public class Customer {
    private String id = "";
    private String name = "";
    private double loan_amount = 0f;
    private String phone_number = "";
    private boolean previleged;

    public void SetValues(String name, String phone_number, boolean privileged, int count)
    {
        this.id = "CUSTID" + count + "L";
        this.name = String.valueOf( name.toCharArray(),0,name.length() );
        this.phone_number = String.valueOf( phone_number.toCharArray(),0,phone_number.length() );
        this.previleged = privileged;
    }       // add customer id

    public boolean SearchCustomerID( String cid ) { return id.equals(cid); }

    public void UpdateName( String name)
    {
        this.name = String.valueOf(name.toCharArray(),0,name.length());
    }

    public void UpdatePhone(String phone_number)
    { this.phone_number = String.valueOf(phone_number.toCharArray(),0,phone_number.length()); }

    public double CurrentLoan()
    {
        return loan_amount;
    }

    public boolean IsPrevileged()
    { return previleged;}

    public void UpdateLoanAmounr(double amt) { loan_amount += amt; }

    public void ShowDetails()   // only for debugging
    {
        System.out.println("\nCustomer id : " + id);
        System.out.println("Customer name : " + name);
        System.out.println("Loan amount : " + loan_amount);
        System.out.println("Phone number : " + phone_number);
        System.out.println("Privileged : " + previleged);
    }
}
