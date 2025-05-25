class Solution {
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        
        for (int i=0; i<mats.length; i++) {
            if (mats[i] > park.length || mats[i] > park[i].length) {
                continue;
            }

            boolean is_possible = true;
            
            for (int j=0; j<=park.length-mats[i]; j++) {
                for (int k=0; k<=park[j].length-mats[i]; k++) {
                    if (!park[j][k].equals("-1")) {
                        continue;
                    }
                    is_possible = true;
                        
                    for (int l=j; l<j+mats[i]; l++) {
                        for (int m=k; m<k+mats[i]; m++) {
                            if (!park[l][m].equals("-1")) {
                                is_possible = false;
                                break;
                            }
                        }
                        if (!is_possible) {
                            break;
                        }
                    }
                    
                    if (is_possible) {
                        if (mats[i] > answer) {
                            answer = mats[i];
                        }
                        break;
                    }
                }
                if (is_possible) {
                    break;
                }
            }
        }
            
        return answer;
    }
}