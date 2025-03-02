# [Platinum III] 빵 정렬 - 5000 

[문제 링크](https://www.acmicpc.net/problem/5000) 

### 성능 요약

메모리: 7640 KB, 시간: 56 ms

### 분류

자료 구조, 수학, 세그먼트 트리

### 제출 일자

2024년 10월 18일 13:57:41

### 문제 설명

<p>상근이는 빵집에서 일한다. 상근이의 퇴근하기 전에 하는 마지막 업무는 빵을 사장이 원하는 순서대로 정렬하는 것이다.</p>

<p>최근에 상근이는 선영이에게 신기한 기술을 하나 배웠다. 이제 상근이는 기술을 이용해 서로 인접해 있는 빵 세 개를 동시에 주걱으로 던질 수 있다. 놀라운 점은 빵이 땅으로 내려올 때는 가장 오른쪽에 있던 빵이 가장 왼쪽으로 가고, 나머지 빵은 한 칸씩 오른쪽으로 이동하게 된다는 점이다. 즉, 빵의 순서가 [1,2,3,4]일 때, [2,3,4]를 주걱을 이용해서 던지면, 빵이 땅에 내려온 후의 순서는 [1,4,2,3]이 되는 것이다.</p>

<p>이제 상근이가 퇴근할 시간이다. 상근이의 앞에는 지금 빵이 놓여져 있다. 지금 놓여져있는 빵의 순서와 사장이 원하는 순서가 주어졌을 때, 선영이에게 배운 기술만을 사용해서 빵을 정렬할 수 있는지 없는지를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 빵의 개수 n (3 ≤ n ≤ 100,000)이 주어진다. 둘째 줄에는 빵의 현재 순서가 주어지고, 셋째 줄에는 사장이 원하는 빵의 순서가 주어진다. 빵은 1부터 n까지 숫자로 나타낼 수 있다. 두 빵의 번호가 같은 경우는 없다.</p>

### 출력 

 <p>만약, 상근이가 선영이에게 배운 기술만을 사용해서 사장이 원하는 순서를 만들 수 있으면 "Possible"을, 불가능하면 "Impossible"을 출력한다.</p>

