import java.util.Scanner;

/**
 * Main
 */
public class Main {

    public static void main(String[] args) {
        NodeOperation nodeOperation = new NodeOperation();
        nodeOperation.addElementsToTree(); 


        Scanner scanner = new Scanner(System.in);
        System.out.print(
            "Enter number to be searched : "
        );
        String findValue = scanner.next();
        System.out.print(
            "Number entered is : " + 
            findValue
        );
        nodeOperation.searchDfs(findValue);
        nodeOperation.searchBFS(findValue);
        // scanner.close();
    }
}