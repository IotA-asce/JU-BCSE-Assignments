package java_assignment.question03;

import java.util.StringTokenizer;

/*
Take a String input that contains multiple words. Do the following: i)
number of times 'a' appears ii) number of times "and" appears iii) whether
it starts with "The" or not iv) put the String into an array of characters v)
display the tokens in the String (tokens are the substrings separated by
space or @ or .)
*/

class ComputeOccurance{
    private String input = "";
    private char[] input_stringToChar;

    ComputeOccurance(String inputString)
    {
        this.input = String.valueOf(inputString.toCharArray(),0,inputString.length());
    }

    public void part1()
    {
        // occurance of 'a'
        int count_a = 0;
        for(int i = 0; i < input.length(); i++)
        {
            if (input.charAt(i) == 'a')
            {
                count_a++;
            }
        }

        System.out.println("Occurance of \'a' : " + count_a);
    }

    public void part2()
    {
        // occurance of 'and'

        int count_and = 0;

        for (int i = 0; i < input.length()-2; i++)
        {
            if(String.valueOf(input.toCharArray(),i,3).equalsIgnoreCase("and")){
                count_and++;
            }
        }

        System.out.println("Occurance of \"and\" : " + count_and);
    }

    public void part3()
    {
        // starts with 'the' ?
        
        boolean the_atFirst = false;

        if(String.valueOf(input.toCharArray(),0,3).equalsIgnoreCase("the")){
            the_atFirst = true;
            System.out.println("Search result : " + the_atFirst);
        }else{
            System.out.println("Search result : " + the_atFirst);
        }
    }

    public void part4()
    {
        // put the string in an array of characters
        /*for (int i = 0; i < input.length(); i++)    // traditional approach
        {
            input_stringToChar[i] = input.charAt(i);
        }*/

        // java approach : 

        input_stringToChar = new char[input.length()];
        input.getChars(0, input.length(), input_stringToChar, 0);
    }

    public void part5()
    {
        // display the tokens in the String
        // (tokens are the substrings separated by
        // space or @ or .)

        StringTokenizer st_space = new StringTokenizer(input, " ");
        System.out.println("\ntokens seperated by space\n");
        while (st_space.hasMoreTokens())
        {
            String token1String = st_space.nextToken();
            System.out.println(token1String);
        }

        StringTokenizer st_atTheRate = new StringTokenizer(input, "@");
        System.out.println("\ntokens seperated by space\n");
        while (st_atTheRate.hasMoreTokens())
        {
            String token2String = st_atTheRate.nextToken();
            System.out.println(token2String);
        }

        StringTokenizer st_dot = new StringTokenizer(input, ".");
        System.out.println("\ntokens seperated by '.'\n");
        while (st_dot.hasMoreTokens())
        {
            String token3String = st_dot.nextToken();
            System.out.println(token3String);
        }

        StringTokenizer st = new StringTokenizer(input, " @.");
        System.out.println("\ntokens seperated by either space or @ or .\n");
        while (st.hasMoreTokens())
        {
            String token4String = st.nextToken();
            System.out.println(token4String);
        }
    }
}
