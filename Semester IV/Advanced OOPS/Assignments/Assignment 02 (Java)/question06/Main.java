package java_assignment.question06;

import java.util.InputMismatchException;
import java.util.Scanner;

/*
For every person in an institute details like name, address (consists of
premises number, street, city, pin and state), phone number, e-mail id are
maintained. A person is either a student or a faculty. For student roll

number and course of study are also be maintained. For faculty employee
id, department and specialisation are to be stored. One should be able to
view the object details and set the attributes. For address, one may change
it partially depending on the choice. Design and implement the classes.
*/

public class Main {
    public static void main(String[] args) {
        Person_List persons = new Person_List();
        Scanner scan = new Scanner(System.in);

        int choice = -1;
        boolean trace = true;
        while(trace)
        {
            System.out.println("1 : Add new entry");
            System.out.println("2 : Show specific person");
            System.out.println("0 : exit");
            try{
            System.out.print("Enter choice : ");
            choice = scan.nextInt();
            }catch(InputMismatchException exc)
            {
                exc.printStackTrace();
                choice = 0;
            }

            switch(choice)
            {
                case 1:
                    persons.Input();
                    break;
                case 2:
                    persons.ShowPerson();
                    break;
                case 0:
                    System.out.println("Exit initiated");
                    trace = false;
                    break;
                default:
                    System.out.println("Invalid input");
                    break;
            }
        }
    }
}
