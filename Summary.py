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
                                  enambles search via key." 
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
class Lec_5:
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
	  
	  	  




