import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class NodeOperation {

    private Node node;

    // public void addElementsToTree() {
    // Scanner scanner = new Scanner(System.in);

    // String choice = "Y";

    // while (choice.equalsIgnoreCase("Y")){

    // System.out.print("Enter value : ");
    // String value = scanner.nextLine();
    // System.out.print("Enter no of branches : ");
    // Integer branches = Integer.parseInt(scanner.nextLine());
    // System.out.print("Enter parent val[-1 for root] : ");
    // String parent = scanner.nextLine();

    // if(parent.equalsIgnoreCase("-1")){
    // // root assigning
    // node = new Node(value, branches);
    // } else {
    // dfsInsertion(parent, value, branches, node);
    // }

    // System.out.println("To enter another item just press enter, \nto conclude
    // insertion type exit");
    // String inputExit = scanner.nextLine();
    // if(inputExit.equalsIgnoreCase("exit")){
    // choice = "exit";
    // return ;
    // }
    // }

    // // scanner.close();
    // }

    // public void dfsInsertion(String parent, String value, int branches, Node nd){
    // if(nd.getValue().equalsIgnoreCase(parent)){
    // for (int i = 0; i < nd.getBranchNumber(); i++) {
    // if(nd.branch[i] == null){
    // nd.branch[i] = new Node(value, branches);
    // }
    // }
    // }

    // else {
    // for (int i = 0; i < nd.getBranchNumber(); i++) {
    // if(nd.branch[i] != null) {
    // dfsInsertion(parent, value, branches, nd.branch[i]);
    // }
    // }
    // }
    // }

    public void addElementsToTree() {
        node = new Node("1", 3);

        node.branch[0] = new Node("8", 3);
        node.branch[1] = new Node("5", 0);
        node.branch[2] = new Node("2", 1);

        node.branch[0].branch[0] = new Node("6", 2);
        node.branch[0].branch[1] = new Node("4", 0);
        node.branch[0].branch[2] = new Node("3", 0);

        node.branch[0].branch[0].branch[0] = new Node("10", 0);
        node.branch[0].branch[0].branch[1] = new Node("7", 0);

        node.branch[2].branch[0] = new Node("9", 0);

    }

    public void searchDfs(String value) {
        dfs(value, node, new ArrayList<String>());
        if (!searchStateDFS) {
            System.out.println("Cannot find value");
        }
    }

    public void searchBFS(String value) {
        bfs(value, node, 0);
        if (!searchStateBFS){
            System.out.println("not found in bfs");
        }
    }

    private boolean searchStateDFS = false;
    private boolean searchStateBFS = false;

    private void dfs(String value, Node nd, ArrayList<String> trace) {
        if (nd == null) {
            return;
        }

        else if (nd.getValue().equalsIgnoreCase(value)) {
            searchStateDFS = true;
            System.out.println(value + "found");
            System.out.println("Printing trace: ");
            trace.add(nd.getValue());
            for (String string : trace) {
                System.out.print(string);
            }
        }

        else if (nd.branch != null) {
            trace.add(nd.getValue() + "->");
            for (int i = 0; i < nd.getBranchNumber(); i++) {
                dfs(value, nd.branch[i], trace);
            }
        } else if (nd.branch == null) {
            if (trace.size() >= 1) {
            }
        } else {
            return;
        }
    }

    Integer level = 0;
    ArrayList<Node> neighbours = new ArrayList<>();
    Integer n = 10;

    public void bfs(String value, Node nd, int level) {
        if(nd == null) {
            return;
        }        
        if (nd.getValue().equalsIgnoreCase(value)){
            System.out.println(
                "\n\n" + value + " found at level " + level
            );
            searchStateBFS = true;
        }
        if (nd.branch != null) {

            for (int i = 0; i < nd.branch.length; i++) {
                bfs(value, nd.branch[i], level+1);
            }
        }
    }
}
