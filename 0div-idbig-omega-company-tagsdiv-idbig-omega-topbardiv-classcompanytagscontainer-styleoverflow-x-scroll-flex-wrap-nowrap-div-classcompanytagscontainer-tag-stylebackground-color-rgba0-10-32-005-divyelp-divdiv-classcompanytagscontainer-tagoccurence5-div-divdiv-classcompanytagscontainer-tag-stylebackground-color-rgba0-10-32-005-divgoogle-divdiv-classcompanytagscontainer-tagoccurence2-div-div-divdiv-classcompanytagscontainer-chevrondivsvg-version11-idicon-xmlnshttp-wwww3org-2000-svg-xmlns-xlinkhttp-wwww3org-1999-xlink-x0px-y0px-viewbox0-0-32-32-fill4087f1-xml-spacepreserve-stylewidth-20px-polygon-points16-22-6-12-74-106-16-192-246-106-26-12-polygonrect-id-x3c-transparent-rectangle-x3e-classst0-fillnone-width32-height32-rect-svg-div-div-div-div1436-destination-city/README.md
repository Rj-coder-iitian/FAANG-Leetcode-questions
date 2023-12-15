<h2><a href="https://leetcode.com/problems/destination-city/"><div id="big-omega-company-tags"><div id="big-omega-topbar"><div class="companyTagsContainer" style="overflow-x: scroll; flex-wrap: nowrap;"><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Yelp</div><div class="companyTagsContainer--tagOccurence">5</div></div><div class="companyTagsContainer--tag" style="background-color: rgba(0, 10, 32, 0.05);"><div>Google</div><div class="companyTagsContainer--tagOccurence">2</div></div></div><div class="companyTagsContainer--chevron"><div><svg version="1.1" id="icon" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px" viewBox="0 0 32 32" fill="#4087F1" xml:space="preserve" style="width: 20px;"><polygon points="16,22 6,12 7.4,10.6 16,19.2 24.6,10.6 26,12 "></polygon><rect id="_x3C_Transparent_Rectangle_x3E_" class="st0" fill="none" width="32" height="32"></rect></svg></div></div></div></div>1436. Destination City</a></h2><h3>Easy</h3><hr><div><p>You are given the array <code>paths</code>, where <code>paths[i] = [cityA<sub>i</sub>, cityB<sub>i</sub>]</code> means there exists a direct path going from <code>cityA<sub>i</sub></code> to <code>cityB<sub>i</sub></code>. <em>Return the destination city, that is, the city without any path outgoing to another city.</em></p>

<p>It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> paths = [["London","New York"],["New York","Lima"],["Lima","Sao Paulo"]]
<strong>Output:</strong> "Sao Paulo" 
<strong>Explanation:</strong> Starting at "London" city you will reach "Sao Paulo" city which is the destination city. Your trip consist of: "London" -&gt; "New York" -&gt; "Lima" -&gt; "Sao Paulo".
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> paths = [["B","C"],["D","B"],["C","A"]]
<strong>Output:</strong> "A"
<strong>Explanation:</strong> All possible trips are:&nbsp;
"D" -&gt; "B" -&gt; "C" -&gt; "A".&nbsp;
"B" -&gt; "C" -&gt; "A".&nbsp;
"C" -&gt; "A".&nbsp;
"A".&nbsp;
Clearly the destination city is "A".
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> paths = [["A","Z"]]
<strong>Output:</strong> "Z"
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= paths.length &lt;= 100</code></li>
	<li><code>paths[i].length == 2</code></li>
	<li><code>1 &lt;= cityA<sub>i</sub>.length, cityB<sub>i</sub>.length &lt;= 10</code></li>
	<li><code>cityA<sub>i</sub> != cityB<sub>i</sub></code></li>
	<li>All strings consist of lowercase and uppercase English letters and the space character.</li>
</ul>
</div>