package java_assignments.question08;

public class Employee {
    private String empcode = new String();
    private String empname = new String();
    private double basic_salary;
    private String grade = new String();
    private String dept = new String();

    Employee(){
        basic_salary = 0;
    }

    public void SetDetails(String code, String name, double bas_sal, String grade, String dept){
        this.empcode = code;
        this.empname = name;
        this.basic_salary = bas_sal;
        this.grade = grade;
        this.dept = dept;
    }

    public boolean MatchEmCode(String empcode){
        if (this.empcode.equals(empcode)){
            return true;
        }else{
            return false;
        }
    }

    public String ShowDetails() {
//        System.out.println(empcode);
//        System.out.println(empname);
//        System.out.println(grade);
//        System.out.println(basic_salary);
//        System.out.println(dept);
        return "employee code : " + empcode + "\nName : " + empname + "\nGrade : " + grade + "\nBasic salary : " + basic_salary + "\nDept : " + dept;
    }

}

