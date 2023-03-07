# Number of subarrays with maximum values in given range
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of N elements and L and R, print the number of sub-arrays such that the value of the maximum array element in that subarray is at least L and at most R.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {2, 0, 11, 3, 0}
L = 1 and R = 10
<strong>Output :</strong> 4
<strong>Explanation:
</strong>The sub-arrays {2}, {2, 0}, {3} and {3, 0}
have maximum in range 1-10.


</span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> Arr[] = {3, 4, 1}
L = 2 and R = 4
<strong>Output :</strong> 5

</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>countSubarrays()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, element <strong>L, </strong>integer <strong>R,</strong> and return the number of subarray with the maximum&nbsp;in range L-R. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span><br>
&nbsp;</p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ L ≤ R ≤ 10<sup>6</sup></span></p>
</div>