import java.io.*;
import java.net.*;

public class Server {
    private static int countVRC = 0;
    private static int countLRC = 0;
    private static int countCks = 0;
    private static int countCRC = 0;
    private static int count = 1;

    public static void serverConnection(int port) throws IOException {
        System.out.println("Waiting for sender(client)");

        ErrorDetection errDetection = new ErrorDetection();
        ServerSocket serverSocket = new ServerSocket(port);
        Socket socket = serverSocket.accept();

        System.out.println("Connection has been established");
        boolean isComplete = false;
        BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        try{
            FileWriter fileCRC = new FileWriter("errorCRC.txt");
            FileWriter fileCks = new FileWriter("errorCKs.txt");
            FileWriter fileLRC = new FileWriter("errorLRC.txt");
            FileWriter fileVRC = new FileWriter("errorVRC.txt");
            FileWriter record = new FileWriter("record.txt");
            System.out.print("Status : ");
            while (!isComplete) {
                // System.out.println("count : " + count++);
                count++;
                if(count%5000 == 0){
                    System.out.print("#");
                }
    
                if(count == 100000)
                    break;
    
                String data = in.readLine();
                // *** if we need to send the data back to the client the following steps be
                // implemented
                /*
                 * PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                 * out.println(data);
                 */
                if (data == null)
                    break;
                int len = data.length();
                String category = data.substring(len - 3, len);
                data = data.substring(0, len - 3);
    
                // System.out.println("category : " + category);
    
                // System.out.println("Recieved data : " + data);
    
                if (category.equals("001")) {
                    if (errDetection.checkVRC(data)) {
                        // System.out.println("\nThe encoded data does not appear to have any error");
                    } else {
                        // System.out.println("\nThe encoded data appears to be erroneous");
                        fileVRC.write(data + "\n");
                        countVRC++;
                    }
                } else if (category.equals("010")) {
                    if (errDetection.checkLRC(data)) {
                        // System.out.println("\nThe encoded data does not appear to have any error");
                    } else {
                        // System.out.println("\nThe encoded data appears to be erroneous");
                        fileLRC.write(data + "\n");
                        countLRC++;
                    }
                } else if (category.equals("011")) {
                    if (errDetection.checkChecksum(data)) {
                        // System.out.println("\nThe encoded data does not appear to have any error");
                    } else {
                        // System.out.println("\nThe encoded data appears to be erroneous");
                        fileCks.write(data + "\n");
                        countCks++;
                    }
                } else if (category.equals("100")) {
                    if (errDetection.checkCRC(data)) {
                        // System.out.println("\nThe encoded data does not appear to have any error");
                    } else {
                        // System.out.println("\nThe encoded CRC data appears to be erroneous : " + data);
                        fileCRC.write(data + "\n");
                        countCRC++;
                    }
                } else if (category.equals("111")) {
                    isComplete = true;
                    break;
                } else {
                    System.out.println("error");
                }
            }

            System.out.println("\n\nerror detection percentage : ");
            System.out.println("VRC : " + (double)((countVRC * 100) / (count / 4)));
            System.out.println("LRC : " + (double)((countLRC * 100) / (count / 4)));
            System.out.println("Cks : " + (double)((countCks * 100) / (count / 4)));
            System.out.println("CRC : " + (double)((countCRC * 100) / (count / 4)));
            record.write((   
                            "VRC : " + (double)((countVRC * 100) / (count / 4)) + "\n" +
                            "LRC : " + (double)((countLRC * 100) / (count / 4)) + "\n" +
                            "Cks : " + (double)((countCks * 100) / (count / 4)) + "\n" +
                            "CRC : " + (double)((countCRC * 100) / (count / 4)) + "\n" 
            )); 

            serverSocket.close();socket.close();in.close();
            fileCRC.close();
            fileCks.close();
            fileLRC.close();
            fileVRC.close();
            record.close();
        }
        catch(Exception e){
            e.printStackTrace();
        }

    }

    public static void main(String[] args) throws IOException {
        serverConnection(5000);
    }
}
