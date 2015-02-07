Maximum path sum II
===================

- Original problem: http://projecteuler.net/index.php?section=problems&id=67

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

```
   3
  7 4
 2 4 6
8 5 9 3
```

That is, 3 + 7 + 4 + 9 = 23.
Find the maximum total from top to bottom in triangle.txt, a 15K text file containing a triangle with one-hundred rows.


Proposed solution
-----------------

- Time complexity: O(n^2)
- Space complexity: O(n^2)
Where n is the number of rows of the triangle (1000, for the problem).

The idea is to compute partial sum triangles and advance one row at a time.
For example, for the triangle above have the following steps:

```
3
```

```
  3
10 7
```

```
    3
  10  7
12  14 13
```

```
       3
    10   7
  12  14  13
20  19  23  16
```

Now just iterate over the last row and get the highest number, which will take more O(n) steps...

