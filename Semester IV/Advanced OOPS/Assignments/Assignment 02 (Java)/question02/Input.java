// package java_assignment.question02;

// import java.util.InputMismatchException;
// import java.util.Scanner;

// public class Input {
//     private Scanner scan = new Scanner(System.in);
//     private int choice;
//     private float fact = 1.5f;

//     public void InputAndOperate()
//     {
//         System.out.println("Enter choice");
//         System.out.println("\n1 : Kilometre to Mile");
//         System.out.println("2 : Mile to Kilometre");
//         System.out.print("\nChoice : ");

//         try {
//             choice = scan.nextInt();
//         }catch (InputMismatchException ex)
//         {
// //            ex.printStackTrace();
//             System.out.println("invalid");
//         }

//         switch (choice)
//         {
//             case 1:
//                 float km = 0f;
//                 try {
//                     System.out.print("Km(s) = ");
//                     km = scan.nextFloat();
//                     System.out.println( km + "Km(s) = " + ( km/fact ) + "Mile(s)");
//                 }catch (InputMismatchException ex)
//                 {
//                     System.out.println("Invalid input");
//                 }
//                 break;
//             case 2:
//                 float mi = 0f;
//                 try {
//                     System.out.print("Mile(s) = ");
//                     mi = scan.nextFloat();
//                     System.out.println( mi + "Mile(s) = " + ( mi * fact ) + "Km(s)");
//                 }catch (InputMismatchException ex)
//                 {
//                     System.out.println("Invalid input");
//                 }
//                 break;
//             default:
//                 System.out.println("Not available");
//                 break;
//         }
//     }
// }
