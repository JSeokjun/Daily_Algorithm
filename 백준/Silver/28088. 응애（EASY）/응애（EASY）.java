import java.util.*;

public class Main {

    public static void main(String[] args) {
        int N, M, K;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        K = sc.nextInt();
        sc.nextLine(); 

        int[] eungae = new int[N];
        int[] count = new int[N];

        Arrays.fill(eungae, 0);
        Arrays.fill(count, 0);

        for(int i=0; i<M; i++) {
            int idx;
            idx = Integer.parseInt(sc.nextLine());
            eungae[idx] = 1;
        }

        int num = M;

        for(int i=0; i<K; i++) {
            num = 0;

            for(int j=0; j<N; j++) {
                if(eungae[j] == 1) {
                    if(j == 0) {
                        count[N-1]++;
                        count[1]++;
                    }
                    else if(j == N-1) {
                        count[0]++;
                        count[N-2]++;
                    }
                    else {
                        count[j-1]++;
                        count[j+1]++;
                    }
                }
            }

            for(int j=0; j<N; j++) {
                if(count[j] == 1) {
                    eungae[j] = 1;
                    num++;
                }
                else eungae[j] = 0;
            }

            Arrays.fill(count, 0);
        }

        System.out.println(num);

        sc.close();
    }

}