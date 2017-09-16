import java.io.*;
import java.util.*;
 
public class Main {
    static int N;
    static long [] x;
    static long [] y;
     
    public static  void main(String arg[]) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    long ans = 0;
    long [] x = new long[N+1];
    long [] y = new long[N+1];
     
    for (int i=1;i<=N;i++){     
    StringTokenizer st =  new StringTokenizer(br.readLine()); 
      x[i] = Long.parseLong(st.nextToken());
      y[i] = Long.parseLong(st.nextToken());      
 
    }
    for(int i=1;i<=N;i++){   
        int j = i%N + 1;
        ans += (long)x[i]*y[j] - (long)x[j]*y[i];
    }
    ans = Math.abs(ans);
    System.out.printf("%d.%d\n", ans/2 ,ans%2 ==0 ? 0:5);
    }
}