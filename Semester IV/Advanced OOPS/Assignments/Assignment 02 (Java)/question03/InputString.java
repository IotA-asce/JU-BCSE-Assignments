package java_assignment.question03;



import java.util.Scanner;

public class InputString {
    private String input = "";
    private Scanner scan = new Scanner(System.in);

    public void TakeStringInput()
    {
        System.out.print("Enter the string : ");
        input = scan.nextLine();

        ComputeOccurance co = new ComputeOccurance(input);
        co.part5();
    }
}
