import java.io.FileWriter;
import java.io.IOException;

public class GenerateDataWord {
    public static void main(String[] args) {
        // File dataFile = new File("data.txt");
        try {
            FileWriter fileWriter = new FileWriter("data.txt");
            System.out.print("status : ");
            for (long i = 0; i < 100000; i++) {
                if(i%10000 == 0){
                    System.out.print("#");
                }
                String dat = "";
                for (int j = 0; j < 16; j++) {
                    long z = Math.round((Math.random() * 10));
                    if (z % 2 == 0) {
                        dat += "0";
                    } else {
                        dat += "1";
                    }
                }
                dat += "\n";
                fileWriter.write(dat);
            }

            fileWriter.close();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
}
