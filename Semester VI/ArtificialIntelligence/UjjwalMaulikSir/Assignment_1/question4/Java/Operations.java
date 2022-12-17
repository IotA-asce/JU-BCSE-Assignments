package Java;

import java.util.Scanner;

public class Operations {
    private int sI, sJ;
    private int eI, eJ;


    public void initMazeDetails(State state) {

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter MAZE size : ");
        int MAZE_SIZE = Integer.parseInt(scanner.nextLine());
        state = new State(MAZE_SIZE);

        state.initMaze();

        System.out.print("Enter starting pos(i) : ");
        sI = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter starting pos(j) : ");
        sJ = Integer.parseInt(scanner.nextLine());

        System.out.print("Enter ending pos(i) : ");
        eI = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter ending pos(j) : ");
        eJ = Integer.parseInt(scanner.nextLine());

        state.updatePos(sI, sJ);

    }

    public State initMazeDetails (int MAZE_SIZE, int sI, int sJ, int eI, int eJ, int[][] maze) {
        this.sI = sI;
        this.sJ = sJ;
        this.eI = eI;
        this.eJ = eJ;

        State state = new State(MAZE_SIZE, maze, sI, sJ);
        state.printMaze();
        state.updatePos(sI, sJ);

        return state;
    }

    public void searchRoute(State state) throws InterruptedException {
        System.out.println("Starting search");
        System.out.println (dfs(state, 0, "Start"));
    }

    public String dfs(State state, int depth, String trace) throws InterruptedException {

        if(state != null){

            System.out.println("\n"+trace);
            state.printMaze();
        }
        if (depth > 0 || state == null) {
            return trace;
        } 
        else if (state.matchPosition(eI,eJ)) {
            System.out.println(
                "route found : " + trace + ""
            );
            Thread.sleep(5000);
            return trace + "END : ROUTE FOUND";
        }
        else {

            // dfs(state.move(1), depth + 1, trace + "->UP");
            dfs(state.move(2), depth + 1, trace + "->DOWN");
            // dfs(state.move(3), depth + 1, trace + "->LEFT");
            dfs(state.move(4), depth + 1, trace + "->RIGHT");
        }

        return trace;
    }

}
