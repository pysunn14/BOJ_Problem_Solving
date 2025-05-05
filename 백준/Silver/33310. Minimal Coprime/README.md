# [Silver IV] Minimal Coprime - 33310 

[문제 링크](https://www.acmicpc.net/problem/33310) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

애드 혹, 사칙연산, 수학, 정수론

### 제출 일자

2025년 5월 5일 17:25:36

### 문제 설명

<p style="text-align: center;"><small><em>Today, Little John used all his savings to buy a segment. He wants to build a house on this segment.</em></small></p>

<p>A segment of positive integers $[l,r]$ is called <em>coprime</em> if $l$ and $r$ are coprime<sup>1</sup>.</p>

<p>A coprime segment $[l,r]$ is called <em>minimal coprime</em> if it does not contain<sup>2</sup> any coprime segment not equal to itself. To better understand this statement, you can refer to the notes.</p>

<p>Given $[l,r]$, a segment of positive integers, find the number of minimal coprime segments contained in $[l,r]$.</p>

<hr>
<p><sup>1</sup>Two integers $a$ and $b$ are coprime if they share only one positive common divisor. For example, the numbers $2$ and $4$ are not coprime because they are both divided by $2$ and $1$, but the numbers $7$ and $9$ are coprime because their only positive common divisor is $1$.</p>

<p><sup>2</sup>A segment $[l',r']$ is contained in the segment $[l,r]$ if and only if $l \le l' \le r' \le r$.</p>

### 입력 

 <p>Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). The description of the test cases follows.</p>

<p>The only line of each test case consists of two integers $l$ and $r$ ($1 \le l \le r \le 10^9$).</p>

### 출력 

 <p>For each test case, output the number of minimal coprime segments contained in $[l,r]$, on a separate line.</p>

