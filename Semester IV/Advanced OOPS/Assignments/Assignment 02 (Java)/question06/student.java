package java_assignment.question06;

/*
For every person in an institute details like name, address (consists of
premises number, street, city, pin and state), phone number, e-mail id are
maintained. A person is either a student or a faculty. For student roll

number and course of study are also be maintained. For faculty employee
id, department and specialisation are to be stored. One should be able to
view the object details and set the attributes. For address, one may change
it partially depending on the choice. Design and implement the classes.
*/

class student extends Person_dets {
    private String roll = "";
    private String course = "";
    Address address = new Address();

    public void SetDetails(String name, String premise_number, String street, String city, String pin, String state,
            String phone_number, String email_id, String roll, String course) {
        this.name = name;
        this.address.premise_number = premise_number;
        this.address.street = street;
        this.address.city = city;
        this.address.pin = pin;
        this.address.state = state;
        this.phone_number = phone_number;
        this.email_id = email_id;
        this.roll = roll;
        this.course = course;
    }

    public boolean ShowDetails(String roll) {
        if (!this.roll.equals(roll)){
            return false;
        }

        else{
            System.out.println("Name : " + name);
            System.out.println("::Address::");
            System.out.println("premise number : " + address.premise_number);
            System.out.println("Street : " + address.street);
            System.out.println("City : " + address.city);
            System.out.println("Pin : " + address.pin);
            System.out.println("State : " + address.state);
            System.out.println("phone number : " + phone_number);
            System.out.println("Email id : " + email_id);
            System.out.println("Course : " + course);
            return true;
        }
    }

    public boolean CheckExistence(String roll)
    {
        if(this.roll.equals(roll))
        {
            return true;
        }else{
            return false;
        }
    }
}
