

int nBST(int n) {
 if (n == 0 || n == 1) return 1;
 int count = 0;
 for i=1; i<=n; i++
  count += nBST(i-1) * nBST(n-i); //product rule
 return count;
}

n = 3

i = 1 -> count = nBST(0) + nBST(2)
               = 1 + nBST(2)
               k = 1 -> count = nBST(0) + nBST(1) = 2
               = 1 + 2 = 3
i = 2 -> count = nBST(1) + nBST(1)
               = 1 + 1 = 2
i = 3 -> count = nBST(2) + nBST(0)
               = nBST(2) + 1 = 3

count = 3 + 2 + 3 = 8

n = 3
(2*3)! / (4!*3!) = 6*5/ (3*2) = 5 ????

12!/ (7!*6*) =  11  3 4 = 132
