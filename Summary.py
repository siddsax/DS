class Lec_3:
   def __init__(self): 
   def Queues(arrays):
   def Queues(lists):
   	    string_s = "Need_head_and_tail_pointer."
   	    string_q = "Head of list is front of queue and tail \
   	               of list is back of queue."
        string_r = "To remove the last element of the list \
                   we need the pointer to second last element"
   def Double_ended_Queues(doubly_linkedlists):
        string_j = "can add/remove fromboth ends"
   def Stack(Double_ended_queues):   	
   def Queues(Circular_lists):
   	    string_i = "needs only one head pointer"
   	    string_m = "to add a new element at head, \
   	               add it just after head and copy"
   	    string_k = "to remove an element, remove \
   	               head and then copy \
   	               correspondingly and change head \
   	               pointer"       
   def vector(arrays):
        string_l = "add a new element at some rank \
                    and shift others"   	
   def vector(Doubly_linked_lists):
   	    string u = "Find where to insert O(N) and insert O(1)"
   def list(list)
   	    string_y = "it is the data type that is implemented \
   	                using linked or doubly linked list data \
   	                structures"
   self.position = "a pointer to something"	                
   def Sequence():
   	    string_p = "has both ranks and positions, can be\
   	                implemeneted via array of pointer and \
   	                a data structure which holds the rank \
   	                in itself as well."
class Lec_4:
    self.Dictionary_defination = "It is a data type which \
                                  enables search via key." 
    def binarySearch():
    	k = "Divide and Conquer in sorted array"
    	string m = "start with mid and then return upper\
    	            or lower half"
        string complexity = "O(logn)"    	            
    class Hashing():
        self.defianation = "a mapping to an array where each \
                            element of the array is a linked \
                            list. A f unction maps each \
                            element to a number via which it is \
                            added to an array " 
        self.load_fdef Open_addressing:
        	actor = "ratio of number of elements in the array\
                            and slots per element" 
        self.sorted_loading = "We keep the linked list sorted"                                           
        self.time_insertion = O(1+alpha/2-1/2*m)
        self.time_search = O(1+alpha)
    class Dictionary_via_:  
    	def size():
    	def findElement(key):
    	    string j = "search using a key"
class Lec_5:
	  self.Hash_functions = "Maps to a hash table indice"
	  class Hash_code_map:
	      self.defination = "Key -> integer"
	      def Polynomial_accumulation(key):
            j = "to convert string to integers make a polynmial \
	              that has the coefficient as the ascii value of \
	              string and put some value of x. 33,34... are good"
    class Compression_map:
        self.defination = "integer -> indice"
        def remainder:
            divisor_1 = "don't take power of two as it is like \
                      dealing with last few digits of the number"
            divisor_2 = "take it as a prime to prevent patterns"
        def map_bw_0_and_1:
            step_1 = "map from (0 to K) to (0 to KA), A < 1"
            step_2 = "take fractional part"
            step_3 = "map to 0 to m-1 by multiplying with m"
        def MAD:
            define = "|ak+b|modN, and N are coprime"              
        def Universal_Hashing:
        class Open_Addresing:
        	  self.defination = "Add probe number 'i' to the hash \
        	                    function. We do not do chaining, rather there is just a single list or array."
        	  def Linear_probe():
        	  	  s = "give a key by the hash function and move ahead if that is already filled."
        	      search = "move until you find an empty space after getting the hash position. "              
        	      deletion = "put a cross rather than emptying it. We can put data here if required actually."
        	  def doubleHashing():
        	      s = "two hashing function, the second one chooses the offset required for probing" 
        	  def analysisDoubleHashing():
        	      load_factor = alpha 
        	      empty = 1-load_factor
        	      Exp_probes_to_find_empty_loation = 1/empty       
                time_for_one_probe = -(1/alpha)*log(1-alpha)
                return "Cant Understand Properly"
class Lec_6:
	  self.root = "top"
	  self.node = "nodes which has a child"
	  self.leaf = "nodes with no children"
	  self.depth_or_level = "the position of a node vertically"
	  self.height = "Max depth of a node"
	  self.ordered_tree = "children are ordered, ascending or descending"
	  self.binary_tree = "one or two children only"
	  self.Complete_binary_tree = "ith level has 2^i nodes"
	  self.height_binary_tree = "between n and log(n+1)-1"
	  self.no_of_leaves = "it is always less than 1 + no of internal nodes proved by induction on this inequality"
	  class Node:
	  	  def __init__(self,c1,c2,p,d):
	  	  	  self.child_1 = c1
	  	  	  self.child_2 = c2
	  	  	  self.parent = p
	  	  	  self.data = d
	  self.Unbounded_tree = "We use link lists as childs so each node has a reference to parent, left most child and its right sibling. "
class Lec_7:
	  self.tree_walks = "transversing a tree"
	  def preorder_traversal(node):
	  	  s_1 = "visit the node"
	  	  s_2 = "visit the left subtree"
	  	  s_3 = "visit the right subtree"
	  def postorder_traveral(node):	  
	  	  s_1 = "visit the left subtree"
	  	  s_2 = "visit the right subtree"
	  	  s_3 = "visit the node"
	  def inorder_traversal():
	  def euler_tour_travel():
	       spl = "each node visited thrice"
	  ques = "you can make a tree from its inorder and preorder traversal as at each step we can break a tree to its subtree"    	
	  note = "Practice its code"	  
class Lec_8:
	  ordered_dict = "there is a sense of ordering between the keys which is different from hashing."
	  class Unordered list:
	  	  search = O(n)  
	  	  inserting = O(1)
	  	  successor_function = O(n)
	  class Ordered_list:
	      search = O(n)
	      inserting = O(n)
	      successor = O(1)
	      min = O(1)	 
	      def implemenetation(arrays):
	          search = O(logn)
	          inserting = O(n) # due to inserting takes shifting of elements
	          deleting = O(n)  
	  class Binary_Search_tree:
	      self.defination = "whole Left subtree has smaller keys, right has larger key"
	      height = logN
	      self.search_time = O(height)
	      def TreeSuccessor(x):
	      	  method = "recursion with two cases"
	      	  case_1 = "right subtree is not null then the leftmost node of right "
	      	  case_2 = "right subtree is null then in that case the ancestor of it which has that node in its left subtree is the sucessor."
	      	  time = O(h)
	      time_insertion = O(h)
class Lec_9:
	  def deletion(tree,node):
	  	  c1 = "trivial for leaf"
	  	  c2 = "for once child just delete it and put child in its position like a linked list"
	  	  c3 = "for two children we need to replace it with its predecessor or successor"
	  exp_insertion_time_for_binarty_trees = O(NlogN)
class Lec_10:
    def Quick_Sort	  
class Lec_11:
	   self.topic = "AVL Trees"
	   self.heightBalance = "  "
	   self.level = "max height of a sub tree (here we add 1 to the normal heights for example leaves have height 2 )"
	   f1 = "they have O(logN) height, proof by considering the min number of nodes that can be there with h height."
	   f2 = "if closest child is at level k, then height (normal height) is 2k-1 at most"
	   f3 = "if closest leaf is at level k then all nodes at levels 1,2,...,k-2 have 2 children"
	   f3_2 = "leaf closest to the root is at height at least  (h+1)/2"





	  





