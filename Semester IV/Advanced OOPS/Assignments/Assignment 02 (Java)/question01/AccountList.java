// package java_assignment.question01;

import java.util.ArrayList;
import javax.swing.*;
import javax.swing.JOptionPane;

public class AccountList 
{
    ArrayList<BankAcct> accounts = new ArrayList<>();
    
    public void Operations()
    {
        boolean trace = true;

        while (trace){
            int choice = -1;
            BankAcct temp = new BankAcct();

            try{
                    choice = Integer.parseInt(
                    JOptionPane.showInputDialog(
                        null,
                        "1 : Add new account\n"
                        +"2 : Change interest\n"
                        +"3 : Show Interest rate\n"
                        +"4 : Show Balance\n" 
                        +"5 : Show Interest amount\n"
                        +"0 : exit\n"
                        ,
                        "",
                        JOptionPane.INFORMATION_MESSAGE
                    )
                );
            }catch(NumberFormatException e){
                e.printStackTrace();
                choice = -1;
            }
            
            switch(choice)
            {
                case 1:
                    temp.NewAccount();
                    accounts.add(temp);

                    break;
                case 2:
                    
                    double interestRate = Double.parseDouble(JOptionPane.showInputDialog(null, "\nNew Interest rate : "));

                    for (int i = 0; i < accounts.size(); i++)
                    {
                        accounts.get(i).ChanceInterestRate(interestRate);
                    }

                    break;
                case 3:
                    JOptionPane.showMessageDialog(null, "Current interest rate : " + accounts.get(0).ShowInterestRate(), "Interest rate : ", JOptionPane.INFORMATION_MESSAGE);
                    break;
                case 4:
                    int index = -1;
                    String s = JOptionPane.showInputDialog(null, "Enter account number : ");
                    for (int i = 0; i < accounts.size(); i++)
                    {
                        if(accounts.get(i).MatchAccNo(s))
                        {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1)
                    {
                        JOptionPane.showMessageDialog(null, "Wrong account number", "Error", JOptionPane.ERROR_MESSAGE);
                    }else{
                        accounts.get(index).ShowBalance();
                    }

                    break;
                case 5:
                    int ind = -1;
                    String p = JOptionPane.showInputDialog(null, "Enter account number : ");
                    for (int i = 0; i < accounts.size(); i++)
                    {
                        if(accounts.get(i).MatchAccNo(p))
                        {
                            ind = i;
                            break;
                        }
                    }

                    if (ind == -1)
                    {
                        JOptionPane.showMessageDialog (null, "Wrong account number", "Error", JOptionPane.ERROR_MESSAGE);
                    }else{
                        JOptionPane.showMessageDialog(null, "Interest amount : " + accounts.get(ind).ShowInterestAmount(), "Interest Amount", JOptionPane.INFORMATION_MESSAGE);
                    }

                    break;
                case 0:
                    trace = false;

                    break;
                default:

            }
        }    

    }
}
