
public class ErrorDetection {

    public static void main(String[] args) {
        // System.out.print( checkVRC("1000011100000001") );
    }
    
    public boolean checkVRC(String input) {
        String[] dataList = new String[2];
        dataList[0] = input.substring(0,8);
        dataList[1] = input.substring(9, 17);

        int[] parity = new int[2];

        for(int i = 0; i < 2; i++){
            int sum = 0;
            for(int j = 0; j < 8; j++){
                sum += dataList[i].charAt(j) - 48;
            }
            if(sum%2 == 0){
                parity[i] = 0;
            }else{
                parity[i] = 1;
            }
        }
        if(parity[0] == input.charAt(8) - 48 && parity[1] == input.charAt(17) - 48){
            return true;
        }else{
            return false;
        }
    }
    
    public boolean checkLRC(String input) {
        String data = input.substring(0, 16);
        String parity = input.substring(16, input.length());

        String[] dataList = new String[2];
        dataList[0] = data.substring(0,8);
        dataList[1] = data.substring(8, 16);

        String temp = "";

        for(int i = 0; i < 8; i++){
            int x = (dataList[0].charAt(i) - 48) + (dataList[1].charAt(i) - 48);
            if(x%2 == 0){
                temp += "0";
            }else{
                temp += "1";
            }
        }

        return parity.equals(temp);
    }

    public boolean checkChecksum(String input){
        String data = input.substring(0,16);
        String cks = input.substring(16, input.length());

        char[] c_data = new char[data.length()];
        int nob = 0, sum = 0;

        for(int i = 0; i < data.length(); i++){

            nob = (int)(Math.floor(Math.log(data.charAt(i) - 48) / Math.log(2))) + 1;

            c_data[i] = (char)((((1 << nob) - 1) ^ (data.charAt(i) - 48)) + 48);

            sum += (int)(c_data[i] - 48);
        }
        String sumS = helperDecToBinary(sum);

        return cks.equals(sumS);
    }

    private String helperDecToBinary(int n){
        StringBuilder sb = new StringBuilder();
        while(n > 0){
            if(n % 2 == 0){
                sb.append("0");
            }else{
                sb.append("1");
            }
            n /= 2;
        }
        sb.reverse();

        return sb.toString();
    }


    public boolean checkCRC(String input){

        // we implement CRC-10 : x^10 + x^9 + x^5 + x^4 + x + 1
        // 11000110011
        String data = input.substring(0, 16);
        String crc = input.substring(16, input.length());

        String div = "11000110011";
        String pad = "";
        int div_len = div.length();
        for(int i = 0; i < div_len - 1; i++){
            pad += 0;
        }
        String remainder = mod2div(data, div);
        pad += remainder;

        return pad.equals(crc);

    }

    private String mod2div(String divd, String divs) {
        int pick = divs.length();
        String temp = divd.substring(0, pick);

        int n = divd.length();

        while (pick < n) {
            if (temp.charAt(0) == '1') {
                temp = xor1(divs, temp) + divd.charAt(pick);
            } else {
                String t = "";
                for (int i = 0; i < pick; i++) {
                    t += '0';
                }
                temp = xor1(t, temp) + divd.charAt(pick);
            }

            pick++;
        }

        if (temp.charAt(0) == '1') {
            temp = xor1(divs, temp);
        } else {
            String t = "";
            for (int i = 0; i < pick; i++) {
                t += '0';
            }
            temp = xor1(t, temp);
        }
        return temp;
    }

    private String xor1(String a, String b){
        String res = "";
        int n = b.length();

        for(int i = 0; i < n; i++){
            if(a.charAt(i) == b.charAt(i)){
                res += "0";
            }else{
                res += "1";
            }
        }

        return res;
    }

}