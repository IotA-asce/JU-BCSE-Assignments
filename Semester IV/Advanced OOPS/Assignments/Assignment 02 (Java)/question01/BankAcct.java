// package java_assignment.question01;

import javax.swing.JOptionPane;

// import jdk.nashorn.internal.scripts.JO;

import java.util.Calendar;

import javax.swing.*;

public class BankAcct 
{
    private String accountNumber = "";
    private double balance;
    private double interestRate;

    private double InitialBalance;
    private int mm,yy;

    Calendar calendar;
    // private 

    public BankAcct ()
    {
        interestRate = 7.75;
    }

    public void NewAccount()
    {
        calendar = Calendar.getInstance();

        balance = Double.parseDouble(
                            JOptionPane.showInputDialog(
                                null, 
                                "Enter Initial deposit "
                        )
                    );
        InitialBalance = balance;

        String s = JOptionPane.showInputDialog(
                            null, 
                            "Current Interest rate : 7.75% "
                            + "Do you wish to initialize to a different amount(yes/no)?"
                    );
        if (s.equalsIgnoreCase("yes"))
        {
            interestRate = Integer.parseInt( JOptionPane.showInputDialog(
                null,
                "new interest rate : ",
                JOptionPane.INITIAL_VALUE_PROPERTY        
                )
            );
        }
        
        mm = calendar.get(Calendar.MONTH);
        yy = calendar.get(Calendar.YEAR);

        accountNumber = "" + mm + yy + calendar.get(Calendar.DATE) + calendar.get(Calendar.HOUR) + calendar.get(Calendar.MINUTE) + calendar.get(Calendar.SECOND); 

        JOptionPane.showMessageDialog(
            null, 
            "Account number : " + accountNumber 
            +"\nBalance : " + balance
            +"\nInterest rate : " + interestRate
            +"\n\nDated : " + calendar.get(Calendar.DATE) + "/" + mm + "/" + yy,
            "Account", 
            JOptionPane.INFORMATION_MESSAGE
        );
        // return true;
    }

    public void ShowBalance()
    {   


        /*
        +   update balance wrt interest rate
        */
        calendar = Calendar.getInstance();
        int dd, mm, yy;
        dd = calendar.get(Calendar.DATE);
        mm = calendar.get(Calendar.MONTH);
        yy = calendar.get(Calendar.YEAR);

        JOptionPane.showMessageDialog(
            null, 
            "Balance : " + balance + "\n\nDated : " + dd + "/" + mm + "/" + yy, 
            "Current balance", 
            JOptionPane.INFORMATION_MESSAGE
        );
    }

    public void ChanceInterestRate(Double ir)
    {
        interestRate = ir;
    }

    public double ShowInterestRate()
    {
        return interestRate;
    }

    public boolean MatchAccNo(String s)
    {
        if(s.equals(accountNumber))
        {
            return true;
        }
        return false;
    }

    public double ShowInterestAmount()
    {
        calendar = Calendar.getInstance();
        int y = calendar.get(Calendar.YEAR);

        return balance * (y - yy) * interestRate;
    }
}

/*
    int i = Integer.parseInt(
                                JOptionPane.showInputDialog(
                                    null, "message"
                                )
                            );

    JOptionPane.showMessageDialog(
        null,
        "message",
        "title",
        JOptionPane.INFORMATION_TYPE
    );
*/
