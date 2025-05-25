class Solution {
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int dh[] = {-1, 0, 1, 0};
        int dw[] = {0, 1, 0, -1};
        
        for (int i=0; i<4; i++) {
            int next_h = h + dh[i];
            int next_w = w + dw[i];
            
            if (next_h < 0 || next_h >= board.length || next_w < 0 || next_w >= board.length) {
                continue;
            }
            
            if (board[h][w].equals(board[next_h][next_w])) {
                answer++;
            }
        }
        
        return answer;
    }
}