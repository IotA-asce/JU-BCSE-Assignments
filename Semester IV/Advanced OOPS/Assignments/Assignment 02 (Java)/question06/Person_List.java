package java_assignment.question06;

import java.util.ArrayList;
import java.util.Scanner;

public class Person_List 
{
    private ArrayList<student> students = new ArrayList<>();
    private ArrayList<Faculty> faculties = new ArrayList<>();
    private Scanner scan = new Scanner(System.in);


    public void Input()
    {
        System.out.println("Enter entry type \'F' for faculty and \'S' for student");
        System.out.print("Input type : ");
        String ty = scan.nextLine();
        if (ty.equalsIgnoreCase("f"))
        {
            // input type faculty
            /*
            input list
            name, address(premise number, street, city, pin, state), phone number, email,

            id, department, specialization
            */
            Faculty temp = new Faculty();

            System.out.print("Enter name : ");
            String name = scan.nextLine();


            System.out.println("\n::Enter address below::");

            System.out.print("Enter premise number : ");
            String premise_number = scan.nextLine();

            System.out.print("Enter street : ");
            String street = scan.nextLine();

            System.out.print("Enter city : ");
            String city = scan.nextLine();

            System.out.print("Enter pin : ");
            String pin = scan.nextLine();

            System.out.print("Enter state : ");
            String state = scan.nextLine();


            System.out.print("Enter phone number : ");
            String phone_number = scan.nextLine();


            System.out.print("Enter email : ");
            String email_id = scan.nextLine();
            
            boolean alreadyExists = false;
            boolean trace = true;
            String id = "";

            while(trace)
            {
                System.out.print("Enter id : ");
                id = scan.nextLine();
                // search for existence of id

                for(Faculty f : faculties)
                {
                    if(f.CheckExistence(id)){
                        alreadyExists = true;
                        break;
                    }
                }
                if(alreadyExists)
                {
                    System.out.println("id already exists, re-enter");
                }else{
                    trace = false;
                }
                alreadyExists = false;

            }
            System.out.print("Enter department : ");
            String department = scan.nextLine();
            System.out.print("Enter specialization : ");
            String specialization = scan.nextLine();

            temp.SetDetails(name, premise_number, street, city, pin, state, phone_number, email_id, id, department, specialization);

            faculties.add(temp);
        }
        else if(ty.equalsIgnoreCase("s"))
        {
            // input type student
            /*
            input list
            name, address(premise number, street, city, pin, state), phone number, email,

            roll, course
            */

            student temp = new student();

            System.out.print("Enter name : ");
            String name = scan.nextLine();


            System.out.println("\n::Enter address below::");

            System.out.print("Enter premise number : ");
            String premise_number = scan.nextLine();

            System.out.print("Enter street : ");
            String street = scan.nextLine();

            System.out.print("Enter city : ");
            String city = scan.nextLine();

            System.out.print("Enter pin : ");
            String pin = scan.nextLine();

            System.out.print("Enter state : ");
            String state = scan.nextLine();


            System.out.print("Enter phone number : ");
            String phone_number = scan.nextLine();


            System.out.print("Enter email : ");
            String email_id = scan.nextLine();
            
            boolean alreadyExists = false;
            boolean trace = true;
            String roll = "";

            while(trace)
            {
                System.out.print("Enter roll : ");
                roll = scan.nextLine();
                // search for existence of id

                for(student s : students)
                {
                    if(s.CheckExistence(roll)){
                        alreadyExists = true;
                        break;
                    }
                }
                if(alreadyExists)
                {
                    System.out.println("roll already exists, re-enter");
                }else{
                    trace = false;
                }
                alreadyExists = false;

            }
            System.out.print("Enter course : ");
            String course = scan.nextLine();

            temp.SetDetails(name, premise_number, street, city, pin, state, phone_number, email_id, roll, course);

            students.add(temp);
        }
    }

    public void ShowPerson()
    {
        System.out.print("Is the person Faculty(f) or Student(s)?");
        String type = scan.nextLine();

        if(type.equalsIgnoreCase("f"))
        {
            System.out.print("Enter id : ");
            String t_id = scan.nextLine();
            for(Faculty f : faculties)
            {
                if(f.ShowDetails(t_id))
                {

                }else{
                    System.out.println("Not found");
                }
            }
        }else if(type.equalsIgnoreCase("s")){
            System.out.print("Enter roll : ");
            String t_roll = scan.nextLine();
            for(student s : students)
            {
                if(s.ShowDetails(t_roll))
                {

                }else{
                    System.out.println("Not found");
                }
            }
        }
    }
}
