import java.util.*;
import java.net.*;
import java.io.*;

public class Client {
    private static int MAX = 100000;

    public static void clientConnection(int port) throws IOException {
        System.out.println("initiating client");
        Socket socket = new Socket("localhost", port);
        Scanner scan = new Scanner(System.in);
        ErrorEncoding errEncode = new ErrorEncoding();

        // *** to read from file
        String[] dataList = new String[MAX];
        int k = 0;
        File dataFile = new File("data.txt");
        try {
            Scanner readFromFile = new Scanner(dataFile);
            while (readFromFile.hasNextLine()) {
                String temp = readFromFile.nextLine();
                // System.out.println(temp);
                if (temp.length() < 16)
                    continue;
                dataList[k++] = temp.substring(0, temp.length());
                // dataList[k++] = readFromFile.nextLine();
            }
            readFromFile.close();
        } catch (FileNotFoundException e) {
            System.out.println("file not found");
        }

        String isManual = "";
        System.out.println("manual entry Y/N");
        isManual = scan.nextLine();

        if (isManual.equalsIgnoreCase("Y")) {
            int l = 0, cur = 0;
            boolean isComplete = false;
            while (!isComplete) {
                if (l == 1000) {
                    break;
                }
                String data = dataList[l++];
                System.out.println("data" + data);
                // *** for reading from terminal
                // System.out.print("Enter the data : ");
                // String data = scan.nextLine();

                boolean moveForward = false;

                while (!moveForward) {
                    System.out.println("Options available :");
                    System.out.println(
                            "\nEncode data with VRC and send        (1)" + "\nEncode data with LRC and send        (2)"
                                    + "\nEncode data with checksum and send   (3)"
                                    + "\nEncode data with CRC and send        (4)"
                                    + "\nExit program                         (0)");

                    System.out.print("\nEnter choice : ");
                    int choice = 0;
                    try {
                        choice = scan.nextInt();
                        scan.nextLine();
                    } catch (InputMismatchException e) {
                        System.out.println("invalid input");
                    }

                    PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                    switch (choice) {
                        // *** we send a 3 bit extension to the given data while sending corresponding
                        // to the category of encoding
                        // 001 for the VRC
                        // 010 for LRC
                        // 011 for CheckSum
                        // 100 for CRC

                        case 1:
                            // encoding data with VRC
                            String dataVRC = errEncode.encodeVRC(data);
                            System.out.println("Encoded data : " + dataVRC);

                            String yn1 = "";

                            System.out.print("Do you wish to inject error in the data (Y/N) : ");
                            yn1 = scan.nextLine();

                            if (yn1.equalsIgnoreCase("y")) {
                                System.out.println(
                                        "options available" + "\nSingle bit error : (1)" + "\nBurst error : (2)");

                                String option = scan.nextLine();
                                switch (option) {
                                    case "1":
                                        System.out.print("enter position to insert error : ");
                                        int pos = scan.nextInt();
                                        scan.nextLine();
                                        char[] datV = new char[dataVRC.length()];
                                        dataVRC.getChars(0, dataVRC.length(), datV, 0);

                                        if (dataVRC.toCharArray()[pos] == '0') {
                                            datV[pos] = '1';
                                        } else {
                                            datV[pos] = '0';
                                        }
                                        dataVRC = String.copyValueOf(datV, 0, datV.length);
                                        System.out.println("Error insertion successful");

                                        break;
                                    case "2":
                                        System.out.println("enter range to insert error");
                                        System.out.print("Starting index : ");
                                        int sIndex = scan.nextInt();
                                        scan.nextLine();
                                        System.out.print("End index : ");
                                        int eIndex = scan.nextInt();
                                        scan.nextLine();

                                        if (sIndex > eIndex) {
                                            System.out.println("invalid inputs data being send without error");
                                            break;
                                        }

                                        datV = new char[dataVRC.length()];
                                        dataVRC.getChars(0, dataVRC.length(), datV, 0);
                                        for (int i = sIndex; i < eIndex; i++) {
                                            if (datV[i] == '0') {
                                                datV[i] = '1';
                                            } else {
                                                datV[i] = '0';
                                            }
                                        }
                                        dataVRC = String.copyValueOf(datV, 0, datV.length);
                                        System.out.println("Error insertion successful");
                                        break;

                                    default:
                                        System.out.println("Invalid input");
                                        break;
                                }
                            }

                            dataVRC += "001";
                            out.println(dataVRC);
                            break;
                        case 2:
                            String dataLRC = errEncode.encodeLRC(data);
                            System.out.println("Encoded data : " + dataLRC);
                            yn1 = "";
                            System.out.print("Do you wish to inject error in the data (Y/N) : ");
                            yn1 = scan.nextLine();

                            if (yn1.equalsIgnoreCase("y")) {
                                System.out.println(
                                        "options available" + "\nSingle bit error : (1)" + "\nBurst error : (2)");
                                String option = scan.nextLine();
                                switch (option) {
                                    case "1":
                                        System.out.print("enter position to insert error : ");
                                        int pos = scan.nextInt();
                                        scan.nextLine();
                                        char[] datL = new char[dataLRC.length()];
                                        dataLRC.getChars(0, datL.length, datL, 0);

                                        if (datL[pos] == '0') {
                                            datL[pos] = '1';
                                        } else {
                                            datL[pos] = '0';
                                        }
                                        dataLRC = String.copyValueOf(datL, 0, datL.length);

                                        System.out.println("Error insertion successful");

                                        break;
                                    case "2":
                                        System.out.println("enter range to insert error");
                                        System.out.print("Starting index : ");
                                        int sIndex = scan.nextInt();
                                        scan.nextLine();
                                        System.out.print("End index : ");
                                        int eIndex = scan.nextInt();
                                        scan.nextLine();

                                        if (sIndex > eIndex) {
                                            System.out.println("invalid inputs data being send without error");
                                            break;
                                        }
                                        datL = new char[dataLRC.length()];
                                        dataLRC.getChars(0, datL.length, datL, 0);
                                        for (int i = sIndex; i < eIndex; i++) {
                                            if (datL[i] == '0') {
                                                datL[i] = '1';
                                            } else {
                                                datL[i] = '0';
                                            }
                                        }
                                        dataLRC = String.copyValueOf(datL, 0, datL.length);
                                        System.out.println("Error insertion successful");
                                        break;

                                    default:
                                        System.out.println("Invalid input");
                                        break;
                                }
                            }

                            dataLRC += "010";
                            out.println(dataLRC);
                            break;
                        case 3:
                            String dataCks = errEncode.encodeCheckSum(data);
                            System.out.println("Encoded data : " + dataCks);
                            yn1 = "";
                            System.out.print("Do you wish to inject error in the data (Y/N) : ");
                            yn1 = scan.nextLine();

                            if (yn1.equalsIgnoreCase("y")) {
                                System.out.println(
                                        "options available" + "\nSingle bit error : (1)" + "\nBurst error : (2)");
                                String option = scan.nextLine();
                                switch (option) {
                                    case "1":
                                        System.out.print("enter position to insert error : ");
                                        int pos = scan.nextInt();
                                        scan.nextLine();
                                        char[] datCk = new char[dataCks.length()];
                                        dataCks.getChars(0, dataCks.length(), datCk, 0);

                                        if (dataCks.toCharArray()[pos] == '0') {
                                            datCk[pos] = '1';
                                        } else {
                                            datCk[pos] = '0';
                                        }
                                        dataCks = String.copyValueOf(datCk, 0, datCk.length);
                                        System.out.println("Error insertion successful");

                                        break;
                                    case "2":
                                        System.out.println("enter range to insert error");
                                        System.out.print("Starting index : ");
                                        int sIndex = scan.nextInt();
                                        scan.nextLine();
                                        System.out.print("End index : ");
                                        int eIndex = scan.nextInt();
                                        scan.nextLine();

                                        if (sIndex > eIndex) {
                                            System.out.println("invalid inputs data being send without error");
                                            break;
                                        }
                                        datCk = new char[dataCks.length()];
                                        dataCks.getChars(0, dataCks.length(), datCk, 0);
                                        for (int i = sIndex; i < eIndex; i++) {
                                            if (datCk[i] == '0') {
                                                datCk[i] = '1';
                                            } else {
                                                datCk[i] = '0';
                                            }
                                        }
                                        dataCks = String.copyValueOf(datCk, 0, datCk.length);
                                        System.out.println("Error insertion successful");
                                        break;

                                    default:
                                        System.out.println("Invalid input");
                                        break;
                                }
                            }

                            dataCks += "011";
                            out.println(dataCks);
                            break;
                        case 4:
                            String dataCRC = errEncode.encodeCRC(data);
                            System.out.println("encoded data : " + dataCRC);
                            yn1 = "";

                            System.out.print("Do you wish to inject error in the data (Y/N) : ");
                            yn1 = scan.nextLine();

                            if (yn1.equalsIgnoreCase("y")) {
                                System.out.println(
                                        "options available" + "\nSingle bit error : (1)" + "\nBurst error : (2)");
                                String option = scan.nextLine();
                                switch (option) {
                                    case "1":
                                        System.out.print("enter position to insert error : ");
                                        int pos = scan.nextInt();
                                        scan.nextLine();
                                        char[] errDataCRC = new char[dataCRC.length()];
                                        dataCRC.getChars(0, dataCRC.length(), errDataCRC, 0);

                                        if (dataCRC.toCharArray()[pos] == '0') {
                                            errDataCRC[pos] = '1';
                                        } else {
                                            errDataCRC[pos] = '0';
                                        }
                                        dataCRC = String.copyValueOf(errDataCRC, 0, errDataCRC.length);
                                        System.out.println("Error insertion successful");

                                        break;
                                    case "2":
                                        System.out.println("enter range to insert error");
                                        System.out.print("Starting index : ");
                                        int sIndex = scan.nextInt();
                                        scan.nextLine();
                                        System.out.print("End index : ");
                                        int eIndex = scan.nextInt();
                                        scan.nextLine();

                                        if (sIndex > eIndex) {
                                            System.out.println("invalid inputs data being send without error");
                                            break;
                                        }
                                        errDataCRC = new char[dataCRC.length()];
                                        dataCRC.getChars(0, dataCRC.length(), errDataCRC, 0);
                                        for (int i = sIndex; i < eIndex; i++) {
                                            if (errDataCRC[i] == '0') {
                                                errDataCRC[i] = '1';
                                            } else {
                                                errDataCRC[i] = '0';
                                            }
                                        }
                                        dataCRC = String.copyValueOf(errDataCRC, 0, errDataCRC.length);
                                        System.out.println("Error insertion successful");
                                        break;

                                    default:
                                        System.out.println("Invalid input");
                                        break;
                                }
                            }

                            dataCRC += "100";
                            out.println(dataCRC);
                            break;
                        case 0:
                            isComplete = true;
                            out.println("1111111111111111111");
                            System.exit(0);
                            break;
                        default:
                            break;
                    }
                    // String yn = "";
                    // boolean yes = true;
                    // while (yes) {
                    // System.out.print("Do you wish to operate on the same data (Y/N) : ");
                    // yn = scan.nextLine();

                    // if (yn.equalsIgnoreCase("y")) {

                    // // moveForward = true;
                    // } else {
                    // yes = false;
                    // }
                    // }
                }
            }
        }

        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
        if (isManual.equalsIgnoreCase("N")) {

            int l = 0;
            boolean isComplete = false;

            System.out.println("Insert single bit error (1) : ");
            System.out.println("Insert burse error bit  (2) : ");
            String ch = scan.nextLine();
            System.out.print("Status : ");
            while (!isComplete) {
                if (l == 100000) {
                    System.out.println("exhausted data");
                    break;
                }
                if(l%10000 == 0){
                    System.out.print("#");
                }

                if (l > k) {
                    System.out.println("end");
                    break;
                }
                if (dataList[l] == null) {
                    isComplete = true;
                    break;
                }
                String data = dataList[l++];

                String dataVRC = errEncode.encodeVRC(data);
                String dataLRC = errEncode.encodeLRC(data);
                String dataCks = errEncode.encodeCheckSum(data);
                String dataCRC = errEncode.encodeCRC(data);

                if (ch.equals("1")) {
                    int pos = (int) Math.round((Math.random() * 16));
                    char[] errDataCRC = new char[dataCRC.length()];
                    dataCRC.getChars(0, dataCRC.length(), errDataCRC, 0);

                    if (dataCRC.toCharArray()[pos] == '0') {
                        errDataCRC[pos] = '1';
                    } else {
                        errDataCRC[pos] = '0';
                    }
                    dataCRC = String.copyValueOf(errDataCRC, 0, errDataCRC.length);

                    pos = (int) Math.round((Math.random() * 16));
                    char[] errDataVRC = new char[dataVRC.length()];
                    dataVRC.getChars(0, dataVRC.length(), errDataVRC, 0);

                    if (dataVRC.toCharArray()[pos] == '0') {
                        errDataVRC[pos] = '1';
                    } else {
                        errDataVRC[pos] = '0';
                    }
                    dataVRC = String.copyValueOf(errDataVRC, 0, errDataVRC.length);

                    pos = (int) Math.round((Math.random() * 16));
                    char[] errDataCks = new char[dataCks.length()];
                    dataCks.getChars(0, dataCks.length(), errDataCks, 0);

                    if (dataVRC.toCharArray()[pos] == '0') {
                        errDataCks[pos] = '1';
                    } else {
                        errDataCks[pos] = '0';
                    }
                    dataCks = String.copyValueOf(errDataCks, 0, errDataCks.length);

                    pos = (int) Math.round((Math.random() * 16));
                    char[] errDataLRC = new char[dataLRC.length()];
                    dataLRC.getChars(0, dataLRC.length(), errDataLRC, 0);

                    if (dataLRC.toCharArray()[pos] == '0') {
                        errDataLRC[pos] = '1';
                    } else {
                        errDataLRC[pos] = '0';
                    }
                    dataLRC = String.copyValueOf(errDataLRC, 0, errDataLRC.length);
                }
                else if(ch.equals("2")){

                    int sIndex = (int) Math.round((Math.random() * 7));                             // CRC burst error
                    int eIndex = (int) Math.round((Math.random() * 5)) + sIndex;

                    char[] errDataCRC = new char[dataCRC.length()];
                    dataCRC.getChars(0, dataCRC.length(), errDataCRC, 0);
                    for (int i = sIndex; i < eIndex; i++) {
                        if (errDataCRC[i] == '0') {
                            errDataCRC[i] = '1';
                        } else {
                            errDataCRC[i] = '0';
                        }
                    }
                    dataCRC = String.copyValueOf(errDataCRC, 0, errDataCRC.length);

                    sIndex = (int) Math.round((Math.random() * 7));
                    eIndex = (int) Math.round((Math.random() * 5)) + sIndex;                        // Cks

                    char[] errDataCks = new char[dataCks.length()];
                    dataCks.getChars(0, dataCks.length(), errDataCks, 0);
                    for (int i = sIndex; i < eIndex; i++) {
                        if (errDataCks[i] == '0') {
                            errDataCks[i] = '1';
                        } else {
                            errDataCks[i] = '0';
                        }
                    }
                    dataCks = String.copyValueOf(errDataCks, 0, errDataCks.length);

                    sIndex = (int) Math.round((Math.random() * 7));                                  // LRC
                    eIndex = (int) Math.round((Math.random() * 5)) + sIndex;

                    char[] errDataLRC = new char[dataLRC.length()];
                    dataLRC.getChars(0, dataLRC.length(), errDataLRC, 0);
                    for (int i = sIndex; i < eIndex; i++) {
                        if (errDataLRC[i] == '0') {
                            errDataLRC[i] = '1';
                        } else {
                            errDataLRC[i] = '0';
                        }
                    }
                    dataLRC = String.copyValueOf(errDataLRC, 0, errDataLRC.length);

                    sIndex = (int) Math.round((Math.random() * 7));
                    eIndex = (int) Math.round((Math.random() * 5)) + sIndex;                        // VRC

                    char[] errDataVRC = new char[dataVRC.length()];
                    dataVRC.getChars(0, dataVRC.length(), errDataVRC, 0);
                    for (int i = sIndex; i < eIndex; i++) {
                        if (errDataVRC[i] == '0') {
                            errDataVRC[i] = '1';
                        } else {
                            errDataVRC[i] = '0';
                        }
                    }
                    dataVRC = String.copyValueOf(errDataVRC, 0, errDataVRC.length);

                }   

                dataVRC += "001";
                dataLRC += "010";
                dataCks += "011";
                dataCRC += "100";
                out.println(dataVRC);
                out.println(dataLRC);
                out.println(dataCks);
                out.println(dataCRC);
            }
        }

        // out.println(data);

        socket.close();
        scan.close();
    
    }

    public static void main(String[] args) throws IOException {
        clientConnection(5000);
    }
}
