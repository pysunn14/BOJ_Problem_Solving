# [Gold II] Triangles - 27477 

[문제 링크](https://www.acmicpc.net/problem/27477) 

### 성능 요약

메모리: 17964 KB, 시간: 152 ms

### 분류

그리디 알고리즘, 구현

### 제출 일자

2025년 5월 4일 03:11:28

### 문제 설명

<p>Gildong has a square board consisting of $n$ rows and $n$ columns of square cells, each consisting of a single digit (from $0$ to $9$). The cell at the $j$-th column of the $i$-th row can be represented as $(i,j)$, and the length of the side of each cell is $1$. Gildong likes big things, so for each digit $d$, he wants to find a triangle such that:</p>

<ul>
	<li>Each vertex of the triangle is in the center of a cell.</li>
	<li>The digit of every vertex of the triangle is $d$.</li>
	<li>At least one side of the triangle is parallel to one of the sides of the board. You may assume that a side of length $0$ is parallel to both sides of the board.</li>
	<li>The area of the triangle is maximized.</li>
</ul>

<p>Of course, he can’t just be happy with finding these triangles as is. Therefore, for each digit $d$, he’s going to change the digit of exactly one cell of the board to $d$, then find such a triangle. He changes it back to its original digit after he is done with each digit. Find the maximum area of the triangle he can make for each digit.</p>

<p>Note that he can put multiple vertices of the triangle on the same cell, and the triangle can be a <a href="https://en.wikipedia.org/wiki/Degeneracy_(mathematics)#Triangle">degenerate triangle</a>; i.e. the area of the triangle can be $0$. Also, note that he is allowed to change the digit of a cell from $d$ to $d$.</p>

### 입력 

 <p>Each test contains one or more test cases. The first line contains the number of test cases $t$ ($1\le t\le 1000$).</p>

<p>The first line of each test case contains one integer $n$ ($1\le n\le 2000$) --- the number of rows and columns of the board.</p>

<p>The next $n$ lines of each test case each contain a string of $n$ digits without spaces. The $j$-th digit of the $i$-th line is the digit of the cell at $(i,j)$. Each digit is one of the characters from $0$ to $9$.</p>

<p>It is guaranteed that the sum of $n^2$ in all test cases doesn’t exceed $4\cdot 10^6$.</p>

### 출력 

 <p>For each test case, print one line with $10$ integers. The $i$-th integer is the maximum area of triangle Gildong can make when $d=i-1$, multiplied by $2$.</p>

