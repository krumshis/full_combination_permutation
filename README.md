# full_combination_permutation
Find palindromes by traversing all possible combinations and their permutations from input of N strings.
####Five Dwarves ( Gimli, Fili, Ilif, Ilmig and Mark) met at the Prancing Pony and played a word game to determine which combinations of their names resulted in a palindrome. Write a program in that prints out all of those combinations.

This solution approaches the problem head on, using descrete mathematics - combinations and permutations. It constructs all possible combinations of words from the input set. The order of words in combination is not important, the only restriction is each word can be present only once in a subset. If the size of the whole input set is N, the size r of any combinations can be between 1 and N and there are N!/r!*(N-r)! such combinations for each r from 1 to N. For each combination the program tries all possible permutations, so if the size of a combination/subset is r, the number of possible permutations is r!. Each permutation is checked for being palindromic and if yes - printed to stdout and palindrome count is increased. The original input is sorted in ascending order to allow for usage of std::next_permutation. Obviously, this approach is extremely time consuming, however it guarantees full set of results regardless of input type.

Here is input and output that I got from provided input solving this problem. The code is written on the public platform https://www.codechef.com/ide using C++14 (G++4.9.2).

__INPUT:__  5 names _Mark, Ilif, Gimli, Fili, Ilmig_
__OUTPUT:__
1. Fili Ilif 
2. Ilif Fili 
3. Gimli Ilmig 
4. Ilmig Gimli 
5. Fili Gimli Ilmig Ilif 
6. Fili Ilmig Gimli Ilif 
7. Gimli Fili Ilif Ilmig 
8. Gimli Ilif Fili Ilmig 
9. Ilif Gimli Ilmig Fili 
10. Ilif Ilmig Gimli Fili 
11. Ilmig Fili Ilif Gimli 
12. Ilmig Ilif Fili Gimli 
Computing palindromes took 572 microseconds
Num of palindromes: 12

__OTHER INPUT:__ 9 names: _Mark, Bib, Gimim, Tom, Mimig, Ilif, Gimli, Fili, Ilmig_  
__OTHER OUTPUT:__
1. Bib 
2. Fili Ilif 
3. Ilif Fili 
4. Gimim Mimig 
5. Mimig Gimim 
6. Gimli Ilmig 
7. Ilmig Gimli 
8. Fili Bib Ilif 
9. Ilif Bib Fili 
10. Gimim Bib Mimig 
11. Mimig Bib Gimim 
12. Gimli Bib Ilmig 
13. Ilmig Bib Gimli 
14. Fili Gimim Mimig Ilif 
15. Fili Mimig Gimim Ilif 
16. Gimim Fili Ilif Mimig 
17. Gimim Ilif Fili Mimig 
18. Ilif Gimim Mimig Fili 
19. Ilif Mimig Gimim Fili 
20. Mimig Fili Ilif Gimim 
21. Mimig Ilif Fili Gimim 
22. Fili Gimli Ilmig Ilif 
23. Fili Ilmig Gimli Ilif 
24. Gimli Fili Ilif Ilmig 
25. Gimli Ilif Fili Ilmig 
26. Ilif Gimli Ilmig Fili 
27. Ilif Ilmig Gimli Fili 
28. Ilmig Fili Ilif Gimli 
29. Ilmig Ilif Fili Gimli 
30. Gimim Gimli Ilmig Mimig 
31. Gimim Ilmig Gimli Mimig 
32. Gimli Gimim Mimig Ilmig 
33. Gimli Mimig Gimim Ilmig 
34. Ilmig Gimim Mimig Gimli 
35. Ilmig Mimig Gimim Gimli 
36. Mimig Gimli Ilmig Gimim 
37. Mimig Ilmig Gimli Gimim 
38. Fili Gimim Bib Mimig Ilif 
39. Fili Mimig Bib Gimim Ilif 
40. Gimim Fili Bib Ilif Mimig 
41. Gimim Ilif Bib Fili Mimig 
42. Ilif Gimim Bib Mimig Fili 
43. Ilif Mimig Bib Gimim Fili 
44. Mimig Fili Bib Ilif Gimim 
45. Mimig Ilif Bib Fili Gimim 
46. Fili Gimli Bib Ilmig Ilif 
47. Fili Ilmig Bib Gimli Ilif 
48. Gimli Fili Bib Ilif Ilmig 
49. Gimli Ilif Bib Fili Ilmig 
50. Ilif Gimli Bib Ilmig Fili 
51. Ilif Ilmig Bib Gimli Fili 
52. Ilmig Fili Bib Ilif Gimli 
53. Ilmig Ilif Bib Fili Gimli 
54. Gimim Gimli Bib Ilmig Mimig 
55. Gimim Ilmig Bib Gimli Mimig 
56. Gimli Gimim Bib Mimig Ilmig 
57. Gimli Mimig Bib Gimim Ilmig 
58. Ilmig Gimim Bib Mimig Gimli 
59. Ilmig Mimig Bib Gimim Gimli 
60. Mimig Gimli Bib Ilmig Gimim 
61. Mimig Ilmig Bib Gimli Gimim 
62. Fili Gimim Gimli Ilmig Mimig Ilif 
63. Fili Gimim Ilmig Gimli Mimig Ilif 
64. Fili Gimli Gimim Mimig Ilmig Ilif 
65. Fili Gimli Mimig Gimim Ilmig Ilif 
66. Fili Ilmig Gimim Mimig Gimli Ilif 
67. Fili Ilmig Mimig Gimim Gimli Ilif 
68. Fili Mimig Gimli Ilmig Gimim Ilif 
69. Fili Mimig Ilmig Gimli Gimim Ilif 
70. Gimim Fili Gimli Ilmig Ilif Mimig 
71. Gimim Fili Ilmig Gimli Ilif Mimig 
72. Gimim Gimli Fili Ilif Ilmig Mimig 
73. Gimim Gimli Ilif Fili Ilmig Mimig 
74. Gimim Ilif Gimli Ilmig Fili Mimig 
75. Gimim Ilif Ilmig Gimli Fili Mimig 
76. Gimim Ilmig Fili Ilif Gimli Mimig 
77. Gimim Ilmig Ilif Fili Gimli Mimig 
78. Gimli Fili Gimim Mimig Ilif Ilmig 
79. Gimli Fili Mimig Gimim Ilif Ilmig 
80. Gimli Gimim Fili Ilif Mimig Ilmig 
81. Gimli Gimim Ilif Fili Mimig Ilmig 
82. Gimli Ilif Gimim Mimig Fili Ilmig 
83. Gimli Ilif Mimig Gimim Fili Ilmig 
84. Gimli Mimig Fili Ilif Gimim Ilmig 
85. Gimli Mimig Ilif Fili Gimim Ilmig 
86. Ilif Gimim Gimli Ilmig Mimig Fili 
87. Ilif Gimim Ilmig Gimli Mimig Fili 
88. Ilif Gimli Gimim Mimig Ilmig Fili 
89. Ilif Gimli Mimig Gimim Ilmig Fili 
90. Ilif Ilmig Gimim Mimig Gimli Fili 
91. Ilif Ilmig Mimig Gimim Gimli Fili 
92. Ilif Mimig Gimli Ilmig Gimim Fili 
93. Ilif Mimig Ilmig Gimli Gimim Fili 
94. Ilmig Fili Gimim Mimig Ilif Gimli 
95. Ilmig Fili Mimig Gimim Ilif Gimli
96. Ilmig Gimim Fili Ilif Mimig Giml 
97. Ilmig Gimim Ilif Fili Mimig Gimi 
98. Ilmig Ilif Gimim Mimig Fili Gimi 
99. Ilmig Ilif Mimig Gimim Fili Gimli 
100. Ilmig Mimig Fili Ilif Gimim Gimli 
101. Ilmig Mimig Ilif Fili Gimim Gimli 
102. Mimig Fili Gimli Ilmig Ilif Gimim 
103. Mimig Fili Ilmig Gimli Ilif Gimim 
104. Mimig Gimli Fili Ilif Ilmig Gimim 
105. Mimig Gimli Ilif Fili Ilmig Gimim 
106. Mimig Ilif Gimli Ilmig Fili Gimim 
107. Mimig Ilif Ilmig Gimli Fili Gimim 
108. Mimig Ilmig Fili Ilif Gimli Gimim 
109. Mimig Ilmig Ilif Fili Gimli Gimim 
110. Fili Gimim Gimli Bib Ilmig Mimig Ilif 
111. Fili Gimim Ilmig Bib Gimli Mimig Ilif 
112. Fili Gimli Gimim Bib Mimig Ilmig Ilif 
113. Fili Gimli Mimig Bib Gimim Ilmig Ilif 
114. Fili Ilmig Gimim Bib Mimig Gimli Ilif 
115. Fili Ilmig Mimig Bib Gimim Gimli Ilif 
116. Fili Mimig Gimli Bib Ilmig Gimim Ilif 
117. Fili Mimig Ilmig Bib Gimli Gimim Ilif 
118. Gimim Fili Gimli Bib Ilmig Ilif Mimig 
119. Gimim Fili Ilmig Bib Gimli Ilif Mimig 
120. Gimim Gimli Fili Bib Ilif Ilmig Mimig 
121. Gimim Gimli Ilif Bib Fili Ilmig Mimig 
122. Gimim Ilif Gimli Bib Ilmig Fili Mimig 
123. Gimim Ilif Ilmig Bib Gimli Fili Mimig 
124. Gimim Ilmig Fili Bib Ilif Gimli Mimig 
125. Gimim Ilmig Ilif Bib Fili Gimli Mimig 
126. Gimli Fili Gimim Bib Mimig Ilif Ilmig 
127. Gimli Fili Mimig Bib Gimim Ilif Ilmig 
128. Gimli Gimim Fili Bib Ilif Mimig Ilmig 
129. Gimli Gimim Ilif Bib Fili Mimig Ilmig 
130. Gimli Ilif Gimim Bib Mimig Fili Ilmig
131. Gimli Ilif Mimig Bib Gimim Fili Ilmi 
132. Gimli Mimig Fili Bib Ilif Gimim Ilmig 
133. Gimli Mimig Ilif Bib Fili Gimim Ilmig 
134. Ilif Gimim Gimli Bib Ilmig Mimig Fili 
135. Ilif Gimim Ilmig Bib Gimli Mimig Fili 
136. Ilif Gimli Gimim Bib Mimig Ilmig Fili 
137. Ilif Gimli Mimig Bib Gimim Ilmig Fili 
138. Ilif Ilmig Gimim Bib Mimig Gimli Fili 
139. Ilif Ilmig Mimig Bib Gimim Gimli Fili 
140. Ilif Mimig Gimli Bib Ilmig Gimim Fili 
141. Ilif Mimig Ilmig Bib Gimli Gimim Fili 
142. Ilmig Fili Gimim Bib Mimig Ilif Gimli 
143. Ilmig Fili Mimig Bib Gimim Ilif Gimli 
144. Ilmig Gimim Fili Bib Ilif Mimig Gimli 
145. Ilmig Gimim Ilif Bib Fili Mimig Gimli 
146. Ilmig Ilif Gimim Bib Mimig Fili Gimli 
147. Ilmig Ilif Mimig Bib Gimim Fili Gimli 
148. Ilmig Mimig Fili Bib Ilif Gimim Gimli 
149. Ilmig Mimig Ilif Bib Fili Gimim Gimli 
150. Mimig Fili Gimli Bib Ilmig Ilif Gimim 
151. Mimig Fili Ilmig Bib Gimli Ilif Gimim 
152. Mimig Gimli Fili Bib Ilif Ilmig Gimim
153. Mimig Gimli Ilif Bib Fili Ilmig Gimim 
154. Mimig Ilif Gimli Bib Ilmig Fili Gimim 
155. Mimig Ilif Ilmig Bib Gimli Fili Gimim 
156. Mimig Ilmig Fili Bib Ilif Gimli Gimim 
157. Mimig Ilmig Ilif Bib Fili Gimli Gimim 
Computing palindromes took 1.0206e+06 microseconds
Num of palindromes: 157
