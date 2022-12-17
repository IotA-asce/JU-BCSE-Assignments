package Java;

import java.util.Scanner;

public class State {
    public int[][] maze;
    public int MAZE_SIZE = 10;
    public int I, J;

    State() {
        maze = new int[MAZE_SIZE][MAZE_SIZE];
    }

    State(int MAZE_SIZE) {
        this.MAZE_SIZE = MAZE_SIZE;
        maze = new int[MAZE_SIZE][MAZE_SIZE];
    }

    State(int MAZE_SIZE, int[][] maze) {
        this.MAZE_SIZE = MAZE_SIZE;
        this.maze = new int[MAZE_SIZE][MAZE_SIZE];

        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze.length; j++) {
                this.maze[i][j] = maze[i][j];        
            }
        }
    }

    State(int MAZE_SIZE, int[][] maze, int I, int J) {
        this.MAZE_SIZE = MAZE_SIZE;
        this.maze = new int[MAZE_SIZE][MAZE_SIZE];

        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze.length; j++) {
                this.maze[i][j] = maze[i][j];        
            }
        }

        this.I = I;
        this.J = J;
        this.maze[I][J] = -1;
    }

    public void initMaze() {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze.length; j++) {
                System.out.print("for (" + i + ", " + j + ") : ");
                String inp = scanner.nextLine();
                maze[i][j] = Integer.parseInt(inp);
            }
        }
        System.out.println("Maze entered is -> \n");
        printMaze();
    }

    public void updatePos(int i, int j) {
        this.I = i;
        this.J = j;
    }

    public boolean matchPosition (int ei, int ej) {
        return (ei == this.I && ej == this.J) ? true : false;
    }   

    public State move(int direction) {
        // for direction
        // 1 : UP : (i+1, j)
        // 2 : DOWN : (i-1, j)
        // 3 : LEFT : (i, j-1)
        // 4 : RIGHT : (i, j+1)
        if (direction == 1) {

            if (validatePosition(I - 1, J)) {
                maze[I][J] = 0;
                maze[I - 1][J] = -1;
                I = I-1;
                return new State(MAZE_SIZE, maze, I, J);
            }

            return null;

        }
        else if (direction == 2) {
            
            if (validatePosition(I + 1, J)) {
                maze[I][J] = 0;
                maze[I + 1][J] = -1;
                I = I+1;
                return new State(MAZE_SIZE, maze, I, J);

            }
            
            return null;

        }
        else if (direction == 3) {
            
            if (validatePosition(I, J - 1)) {
                maze[I][J] = 0;
                maze[I][J-1] = -1;
                J = J - 1;
                return new State(MAZE_SIZE, maze, I, J);

            }

            return null;
            
        }
        else if (direction == 4) {
            
            if (validatePosition(I, J + 1)) {
                maze[I][J] = 0;
                maze[I][J + 1] = -1;
                J = J + 1;
                return new State(MAZE_SIZE, maze, I, J);

            }

            return null;

        }
        else{
            return null;
        }

    }



    public boolean validatePosition(int i, int j) {
        return (i < 0 || j < 0 || i >= MAZE_SIZE || j >= MAZE_SIZE || maze[i][j] == 1) ? false : true;
    }

    public void printMaze() {
        for (int i = 0; i < maze.length; i++) {
            for (int j = 0; j < maze.length; j++) {
                System.out.print(maze[i][j] + " ");
            }
            System.out.println();
        }
    }

}
