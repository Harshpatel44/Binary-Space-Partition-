# Binary-Space-Partition-
We need to partition the space using binary space partition tree (BSP tree) unless a specific condition is specified.


We have an Euclidean space ( x-axis is (0,100) and y-axis is (0,100)) in which n points are ramdomly generated
e.g. n1=(4,5)
n2= (10,12)
.
.
and so on n20=(45,10)

We need to partition the space using binary space partition tree (BSP tree) 

say after first partition, there are 8 points in the first partition and 12 points in the second partition

Once we have seperated the points of each partition we need to check following condition

For partition one

center_x = sum(x-coordinates of all the points of first partition)/number of points in the partition
center_y = sum(y-coordinates of all the points of first partition)/number of points in the partition


now we have the center of first partition i.e., (center_x, center_y)

Next, we need to check whether the Euclidean distance of each point of first partition from its center is less than or equal to the Range (R)
if the above condition is true, we are not required to further partition the first partition.

otherwise, we will again partition the first partition using BSP. 
say the number of points in first partition of the initial first partition is 3 and 
the number of points in second partition of the initial first partition is 5, (i.e., first of first (3) + second of first (5) = 8))
Then again we will check whether all the points of each partition are located with in R distance to their respective centers.

This procedure must be followed until all the points of each partition are located with in R distance to their respective centers.





In the Output 
1. It asks the user for R.
2. Then X and Y coordinates for the space
3. Then Number of Elements (N)
4. Then all the random points created are displayed.
5. finally the main result is displayed i.e. partition Number ,no. of points in that partition , points with its id