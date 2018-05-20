// Dynamic Programming
// It should have the following two properties
// 1. optimal substructure
// 2. overlapping sub problems
// 
// For solving overlapping sub problems, we can use top-down or bottom-up approach.
// 1. top-down approach:
//    This is called memoization. The bigger problem is gradually broken
//    down into overlapping sub problems. For instance Fibonacci(5) is Fibonacci(4) plus
//    Fibonacci(3). The sub problems results are memoized.
// 2. bottom-up approach:
//    This is called tabulation. The bigger is built by building solutions to the smaller
//    sub problems and gradually building it to the bigger problem.
//   
