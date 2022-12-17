package Java;

public class Main {
    public static void main(String[] args) throws InterruptedException {
        Operations operations = new Operations();
        int [][] maze = {
            {0,1,1,0,1},
            {0,0,0,0,0},
            {0,1,1,0,1},
            {1,0,0,0,0},
            {0,0,1,0,0}
        };
        State state = operations.initMazeDetails(5, 0, 0, 4, 0, maze);
        operations.searchRoute(state);

        /**
         * 0 1 1 0 1
         * 0 0 0 0 0
         * 0 1 1 0 1
         * 1 0 0 0 0
         * 0 0 1 0 0
         */
    }
}
