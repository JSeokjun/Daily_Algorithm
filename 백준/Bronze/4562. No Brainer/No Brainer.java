import java.util.*;
 
public class Main {
    public static void main(String[] args) {
    
    	
    	Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
    	int count = 0;
    	
    	while(true) {
    		
    	count++;
        if(count>n)
        	break;
        
    	int X, Y = 0;
    	X = sc.nextInt();
    	Y = sc.nextInt();
    	if(X>=Y) System.out.println("MMM BRAINS");
    	else 	 System.out.println("NO BRAINS");
    	
    	
    	}
    	
    	sc.close();
    }
    
}
   