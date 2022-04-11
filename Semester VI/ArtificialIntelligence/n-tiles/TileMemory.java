import java.util.ArrayList;
import java.util.Scanner;

public class TileMemory {
    
    private Integer[][] startTiles;
    private Integer[][] endTiles;
    private Integer TILE_SIZE = 9;
    // private Integer CHOICE = 0;       // choice details below
    private Integer Ei = 0;
    private Integer Ej = 0;
    private Integer count = 0;
    private Integer lowestLevel = 4;
    private ArrayList<Integer> list = new ArrayList<>();
    /*
        0   :   DFS ( Depth First Search )
        1   :   BFS ( Breadth First Search )
    */
    
    private void initTiles(Integer tile_size) {

        this.TILE_SIZE = tile_size;
        startTiles = new Integer[TILE_SIZE][TILE_SIZE];
        endTiles = new Integer[TILE_SIZE][TILE_SIZE];
        
    }

    public void printTiles(){
        
        System.out.println("TILE : \n");
        String tile_output = "\t";

        for (int i = 0; i < TILE_SIZE; i++) {
            for (int j = 0; j < TILE_SIZE; j++) {
                tile_output += startTiles[i][j] + "  ";
            }
            tile_output += "\n\t";
        }

        System.out.println(tile_output);
    }

    public void printTiles(Integer flagInteger){
        
        /*
        for the end tile setup
        any integer value
        */

        System.out.println("TILE : \n");
        String tile_output = "\t";

        for (int i = 0; i < TILE_SIZE; i++) {
            for (int j = 0; j < TILE_SIZE; j++) {
                tile_output += endTiles[i][j] + "  ";
            }
            tile_output += "\n\t";
        }

        System.out.println(tile_output);
    }

    public void inputTiles(){

        Scanner scan = new Scanner(System.in);
        System.out.print("\n\nTile size : ");
        
        String tileSize = scan.nextLine();
        this.TILE_SIZE = Integer.parseInt(tileSize);
        initTiles(this.TILE_SIZE);

        System.out.println("\n\nEnter the value tile orientation below : ([Number] for tile nos, [E]mpty for blank)\n\n");

        for (int i = 0; i < TILE_SIZE; i++) {
            for (int j = 0; j < TILE_SIZE; j++) {
                
                System.out.print("Enter for tile (" + i + ", " + j + ") : ");
                String ti = scan.nextLine();

                if(ti.equalsIgnoreCase("E") || ti.equalsIgnoreCase("Empty") || ti.equalsIgnoreCase("0")){
                    this.startTiles[i][j] = 0;
                    this.Ei = i;
                    this.Ej = j;
                }else{
                    this.startTiles[i][j] = Integer.parseInt(ti);
                }

            }
        }

        System.out.println("\n\nInput complete...");
        printTiles();
        // scan.close();
    }

    public void inputTiles(Integer flagInteger){

        // Scanner scan = new Scanner(System.in);
        // scan.close();
        // String flag = scan.nextLine();
        Scanner scanner = new Scanner(System.in);

        System.out.println("\n\nEnter the value tile orientation below : ([Number] for tile nos, [E]mpty for blank)\n\n");
        String ti = "";
        for (int i = 0; i < TILE_SIZE; i++) {
            for (int j = 0; j < TILE_SIZE; j++) {
                
                System.out.print("Enter for tile (" + i + ", " + j + ") : ");
                ti = scanner.nextLine();

                if(ti.equalsIgnoreCase("E") || ti.equalsIgnoreCase("Empty") || ti.equalsIgnoreCase("0")){
                    this.endTiles[i][j] = 0;
                }else{
                    this.endTiles[i][j] = Integer.parseInt(ti);
                }

            }
        }

        System.out.println("\n\nInput complete...");
        printTiles(1);
        // scanner.close();
    }
    
    public void SelectChoice(){

        Scanner scan = new Scanner(System.in);
        System.out.print("Enter choice of operation, [D]fs or [B]fs : ");
        String ch = scan.nextLine();
        if(ch.equalsIgnoreCase("D") || ch.equalsIgnoreCase("DFS")){
            // dfs
            Integer[][] tempTiles = startTiles;
            try {
                System.out.println(Ei + ", " + Ej);
                tileSearchDFS(tempTiles, Ei, Ej, 0, "");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }else{

            //bfs
        }

        System.out.println("NO OF TIMES MATCH FOUND : " + count);
        System.out.println("lowest LEVEL : " + lowestLevel);
        scan.close();
    }

    // private Integer[] up = {  0, -1  };
    // private Integer[] dn = {  0,  1  };
    // private Integer[] lt = { -1,  0  };
    // private Integer[] rt = {  1,     };

    private boolean matchTiles(Integer[][] match){
        
        boolean isMatch = true;
        
        for(int i = 0; i < TILE_SIZE; i++){
            for(int j = 0; j < TILE_SIZE; j++){
                if(match[i][j] != endTiles[i][j]){
                    isMatch = false;
                    break;
                }
            }
        }

        return isMatch;
    }

    public void tileSearchDFS(Integer[][] tempTiles, Integer ei, Integer ej, Integer L, String path) throws InterruptedException{

        // ei, ej   :   position of empty space
        // L        :   level of operation
        
        System.out.println("\nLevel : " + L + " ::: " + ei + ", " + ej + "\n");
        printTiles();
        
        if(ei < 0 || ei >= TILE_SIZE){
            System.out.println("x error");
            return;
        }
        if(ej < 0 || ej >= TILE_SIZE){
            System.out.println("y error");
            return;
        }
        if(matchTiles(tempTiles)){
            System.out.println("\n\nMatch found at level : " + L + "\n\n");
            System.out.println(path);
            Thread.sleep(5000);
            count++;
            
            lowestLevel = lowestLevel < L ? lowestLevel : L;



            return;

        }
        if(L > 5){
            System.out.println("overflow");
            return;
        }

        // System.out.println("187");


        // System.out.println("\nLevel : " + L + "\n");
        // printTiles();

        Integer[][] tempTilesMod = tempTiles;

        // System.out.println("195");
        // System.out.println("ej-1 : " + (ej-1));
        // System.out.println("ej+1 : " + (ej+1));
        // System.out.println("ei-1 : " + (ei-1));
        // System.out.println("ei+1 : " + (ei+1));

        if(ej - 1 >= 0 ) {
            System.out.println("1");
            tempTilesMod = tempTiles;
            
            Integer swap  = tempTilesMod[ei][ej];
            tempTilesMod[ei][ej] = tempTilesMod[ei][ej - 1];
            tempTilesMod[ei][ej - 1] = swap;
            ej -= 1;

            // printTiles();
            tileSearchDFS(tempTilesMod, ei, ej, L + 1, path + 1);
        }
        if(ej + 1 < TILE_SIZE){
            System.out.println("2");

            tempTilesMod = tempTiles;
            
            Integer swap  = tempTilesMod[ei][ej];
            tempTilesMod[ei][ej] = tempTilesMod[ei][ej + 1];
            tempTilesMod[ei][ej + 1] = swap;
            ej += 1;
            // printTiles();
            tileSearchDFS(tempTilesMod, ei, ej, L + 1, path + 2);

        }
        if(ei - 1 >= 0){
            System.out.println("3");

            tempTilesMod = tempTiles;
            
            Integer swap  = tempTilesMod[ei][ej];
            tempTilesMod[ei][ej] = tempTilesMod[ei - 1][ej];
            tempTilesMod[ei-1][ej] = swap;
            ei -= 1;
            
            // printTiles();
            tileSearchDFS(tempTilesMod, ei, ej, L + 1, path + 3);

        } 
        if(ei + 1 < TILE_SIZE){
            System.out.println("4");

            tempTilesMod = tempTiles;
            
            Integer swap  = tempTilesMod[ei][ej];
            tempTilesMod[ei][ej] = tempTilesMod[ei + 1][ej];
            tempTilesMod[ei + 1][ej] = swap;
            ei += 1;
            
            // printTiles();
            tileSearchDFS(tempTilesMod, ei, ej, L + 1, path + 4);

        }

        
    }

    public void bfs(){

    }

}
