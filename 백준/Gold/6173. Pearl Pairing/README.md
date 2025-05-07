# [Gold II] Pearl Pairing - 6173 

[문제 링크](https://www.acmicpc.net/problem/6173) 

### 성능 요약

메모리: 2288 KB, 시간: 16 ms

### 분류

애드 혹, 해 구성하기, 그리디 알고리즘

### 제출 일자

2025년 5월 7일 19:53:16

### 문제 설명

<p>At Bessie's recent birthday party, she received N (2 <= N <= 100,000; N%2 == 0) pearls, each painted one of C different colors (1 <= C <= N).</p>

<p>Upon observing that the number of pearls N is always even, her creative juices flowed and she decided to pair the pearls so that each pair of pearls has two different colors.</p>

<p>Knowing that such a set of pairings is always possible for the supplied testcases, help Bessie perform such a pairing. If there are multiple ways of creating a pairing, any solution suffices.</p>

### 입력 

 <ul>
	<li>Line 1: Two space-separated integers: N and C</li>
	<li>Lines 2..C + 1: Line i+1 tells the count of pearls with color i: C_i</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Lines 1..N/2: Line i contains two integers a_i and b_i indicating that Bessie can pair two pearls with respective colors a_i and b_i.</li>
</ul>

