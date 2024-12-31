# [Gold IV] Cocoa Coalition - 18020 

[문제 링크](https://www.acmicpc.net/problem/18020) 

### 성능 요약

메모리: 2020 KB, 시간: 20 ms

### 분류

브루트포스 알고리즘, 수학, 정수론

### 제출 일자

2025년 1월 1일 01:06:41

### 문제 설명

<p>Alice and Bob decide to share a chocolate bar, which is an n by m rectangular grid of chocolate cells. They decide that Alice should get a < n · m pieces and that Bob should get b = n · m − a pieces. To split the chocolate bar, they repeatedly take a single piece of chocolate and break it either horizontally or vertically, creating two smaller pieces of chocolate. See Figure C.1 for an example.</p>

<p>What is the minimum number of splits that Alice and Bob need to perform in order to split the n-by-m chocolate bar into two piles consisting of a and b chocolate cells?</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5ed07e45-41bb-4bbd-b27f-183a0495f7f5/-/preview/" style="width: 245px; height: 202px;"></p>

<p>Figure C.1: Illustration of a solution to Sample Input 2, showing the original 10-by-10 chocolate bar split three times into pieces of size 10-by-2, 10-by-5, 3-by-3 and 7-by-3. Giving Alice the 10-by-5 and 7-by-3 pieces, she gets a total of 50 + 21 = 71 chocolate cells.</p>

### 입력 

 <p>The input consists of a single line, containing the three integers n, m and a (1 ≤ n, m ≤ 10<sup>6</sup>, 1 ≤ a < n · m).</p>

### 출력 

 <p>Output the minimum number of splits needed to achieve the desired division of chocolate.</p>

