P = int(input())

for i in range(1, P+1):
    L = list(map(int, input().split()))
    cnt = 0  # 뒤로 물러난 횟수
    result = []  # 정렬된 학생들의 리스트
    
    for j in range(1, 21):
        # 현재 학생을 result 리스트의 적절한 위치에 삽입
        current = L[j]
        k = 0
        
        # 자신보다 키가 큰 첫 번째 학생 찾기
        while k < len(result) and result[k] < current:
            k += 1
            
        # 뒤로 물러난 학생 수 계산 (현재 result 길이 - 삽입 위치)
        cnt += len(result) - k

        # 현재 학생을 k 위치에 삽입
        result.insert(k, current)
    
    print(i, cnt)