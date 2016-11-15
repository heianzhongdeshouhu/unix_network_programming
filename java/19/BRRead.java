// use BufferedReader to read characters from console.

import java.io.*;

public class BRRead {
    public static void main(String[] args) throws IOException {
        char c;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("input characters, press 'q' to exit.");

        // read characters
        do {
            c = (char)br.read();
            System.out.println(c);
        } while (c != 'q'); 
    }
}
