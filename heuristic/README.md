# heuristic

##  Famous Algorithm

### local search
flow
1, generate one random initial solution
2, search a neighbor solution with some method.
3. check condition and if the solution is better than the old one, update it.
4, repeat process until satisfying condtions.

### multiple start local search
apply local search method with multple initial solution.

### iterated local search
1, apply local seach method
2, change the solution randomly and apply local search again.

### variable neighborhood search
change the neighborhood size in each iterations.
If not success, broaden the neighborhood.

### guided local search
modify objective function.
https://en.wikipedia.org/wiki/Guided_local_search

### 2-opt
heuristic algorithm for the traveling salesman problem
one of the local search method.

### taboo search
refer https://ja.wikipedia.org/wiki/%E3%82%BF%E3%83%96%E3%83%BC%E3%82%B5%E3%83%BC%E3%83%81

### Simulated Annealing
a method for packing problem
This method has many application.
refer https://en.wikipedia.org/wiki/Simulated_annealing

#### related method
great delude method
thresholding accepting method

### Bottom Left Fill method (BFL)
a method for square packing problems.

### genetic algorithm
refer https://en.wikipedia.org/wiki/Genetic_algorithm
