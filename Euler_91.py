#The points P (x1, y1) and Q (x2, y2) are plotted at integer co-ordinates and are joined to the origin, O(0,0), to form ΔOPQ.


#There are exactly fourteen triangles containing a right angle that can be formed when 
#each co-ordinate lies between 0 and 2 inclusive; that is,
#0 ≤ x1, y1, x2, y2 ≤ 2.


#Given that 0 ≤ x1, y1, x2, y2 ≤ 50, how many right triangles can be formed?

O = (0,0)

x1=y1=x2=y2=n=duplicate=0

right = 0

r=3


  

  

import array as arr
import matplotlib.pyplot as plt 

PQfound = arr.array("i") #empty array of integer for found sets of PQ pairs

import numpy as np

for x1 in range(0, r):
    for y1 in range(0, r):
        for x2 in range(0, r):
            for y2 in range(0, r):
                
                P = (x1,y1)
                Q = (x2,y2)
                print (P,Q)
                
                if x1 == y1 == 0 or x2 == y2 == 0 or (x1 == x2 and y1 == y2): #if either point is at origin or if both points same
                    print ("................skipped - point at origin or both points same")
                    #break #(removed by SR as jumping completely out of rest of y2 for loop)
                else:
                
                    #P = (x1,y1)
                    #Q = (x2,y2)
                
                    #if P == Q:
                    #    break
                
                    vQP = tuple(np.subtract(P, Q))

                    vOQ = tuple(np.subtract(Q, O))
                
                    vOP = tuple(np.subtract(P, O))

                    #vQP = P - Q
                    #vOQ = Q - O
                
                    #print (P,Q," [",np.dot(vQP,vOQ),",",np.dot(vOP,vOQ),",",np.dot(vQP,vOP),"]")
                
                    if np.dot(vQP, vOQ) == 0 or np.dot(vOP, vOQ) == 0 or np.dot(vQP, vOP) == 0:
                        
                        #check for duplicates - added by SR as lots more dups now
                        duplicate = 0
                        n = 0
                        for n in range(0, right):
                            
                            if (PQfound[n*4]==x2 and PQfound[n*4+1]==y2 and PQfound[n*4+2]==x1 and PQfound[n*4+3]==y1):
                                duplicate=1
                                print("................skipped - duplicates of PQ pairs already found")
                                break

                        if duplicate == 0: 
                            print("================ *** unique right triangle found==> P =", P, ",", "Q =",Q)
                            PQfound.extend([x1, y1, x2, y2])
                            right += 1
                            #print ("PQfound = ", PQfound)
                            
                            # line 1 points 
                            a1 = [0,P[0],Q[0],0]
                            b1 = [0,P[1],Q[1],0] 
                            # plotting the line 1 points  
                            plt.plot(a1, b1, label = "line 1") 
                            
                            # naming the x axis 
                            plt.xlabel('x - axis') 
                            # naming the y axis 
                            plt.ylabel('y - axis') 
                            # giving a title to my graph 
                            plt.title('Two lines on same graph!') 
                              
                            # show a legend on the plot 
                            plt.legend()
                              
                            # function to show the plot 
                            plt.show()

print("------------------------------------------------------------")
for n in range(0, right):
    print("P = (",PQfound[n*4],",",PQfound[n*4+1],"), Q = (",PQfound[n*4+2],",",PQfound[n*4+3],")")
    
print("Number of unique right triangles found:",right)    